#include "stdafx.h"

struct ILockAppHostDataCallback;
enum LockAppHostShutdownOptions {};

MIDL_INTERFACE("c59766f7-d190-4f69-a822-05ca45b201e7") ILockAppHost : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE Initialize(GUID) = 0;
	virtual HRESULT STDMETHODCALLTYPE InitializeWithCallback(ILockAppHostDataCallback*) = 0;
	virtual HRESULT STDMETHODCALLTYPE Shutdown(LockAppHostShutdownOptions) = 0;
	virtual HRESULT STDMETHODCALLTYPE ShowWebDialog(PCWSTR url) = 0;
	virtual HRESULT STDMETHODCALLTYPE DismissWebDialog() = 0;
	virtual HRESULT STDMETHODCALLTYPE Lock(BOOL) = 0;
	virtual HRESULT STDMETHODCALLTYPE Unlock() = 0;
	virtual HRESULT STDMETHODCALLTYPE UpdateCredentialsRequired(BOOL) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetLockVisible(BOOL) = 0;
};

MIDL_INTERFACE("6119bcc6-cac2-4d37-9bbf-76a34697e7fb") ILockScreenDirector : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetController(ILockAppHost**) = 0;
};

MIDL_INTERFACE("a2aa05aa-47af-4b4a-8e77-6cd6efe35cda") ILockScreenDirectorPrivate : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE CreateController(HANDLE hProcess, ILockAppHost**) = 0;
	virtual HRESULT STDMETHODCALLTYPE DestroyController() = 0;
	virtual HRESULT STDMETHODCALLTYPE NotifyDesktopSwitch(BOOL) = 0;
	virtual HRESULT STDMETHODCALLTYPE RegisterBrokerEndpoint(HANDLE hProcess) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnregisterBrokerEndpoint() = 0;
};

MIDL_INTERFACE("5524fe34-8da7-40a8-8165-e8b37a8b4a4b") IProxyServerIdentity : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetServerProcessId(_Out_ ULONG * pdwProcessId) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetServerProcessHandle(_In_ ULONG dwDesiredAccess, _In_ BOOL bInheritHandle, _Out_ PHANDLE phProcess) = 0;
	virtual HRESULT STDMETHODCALLTYPE IsAppSilo(_Out_ BOOL*) = 0;
};

HRESULT GetLastErrorEx(ULONG dwError = GetLastError())
{
	NTSTATUS status = RtlGetLastNtStatus();
	return RtlNtStatusToDosErrorNoTeb(status) == dwError ? HRESULT_FROM_NT(status) : HRESULT_FROM_WIN32(dwError);
}

int ShowErrorBox(HWND hwnd, HRESULT dwError, PCWSTR lpCaption)
{
	int r = 0;
	LPCVOID lpSource = 0;
	ULONG dwFlags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS;

	if ((dwError & FACILITY_NT_BIT) || (0 > dwError && HRESULT_FACILITY(dwError) == FACILITY_NULL))
	{
		dwError &= ~FACILITY_NT_BIT;
	__nt:
		dwFlags = FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS;

		lpSource = GetModuleHandleW(L"ntdll");
	}

	PWSTR lpText;
	if (FormatMessageW(dwFlags, lpSource, dwError, 0, (PWSTR)&lpText, 0, 0))
	{
		r = MessageBox(hwnd, lpText, lpCaption, dwError ? MB_ICONERROR : MB_ICONINFORMATION);
		LocalFree(lpText);
	}
	else if (dwFlags & FORMAT_MESSAGE_FROM_SYSTEM)
	{
		goto __nt;
	}

	return r;
}

PWSTR GenName(PCWSTR name, PWSTR buf, ULONG cch, REFGUID guid)
{
	swprintf_s(buf, cch, L"Local\\LockAppHost%ws{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		name, guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

	return buf;
}

void WINAPI ep(void*)
{
	PCWSTR pcsz = L"--0";
	HRESULT hr;
	if (0 <= (hr = CoInitializeEx(0, COINIT_APARTMENTTHREADED)))
	{
		HANDLE hProcess = 0, h = 0;
		IServiceProvider* p;
		struct __declspec(uuid("c2f03a33-21f5-47fa-b4bb-156362a2f239")) ImmersiveShell;

		if (0 <= (hr = CoCreateInstance(__uuidof(ImmersiveShell), 0, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&p))))
		{
			ILockScreenDirectorPrivate* plsdp;
			hr = p->QueryService(__uuidof(ILockScreenDirector), IID_PPV_ARGS(&plsdp));
			p->Release();

			if (0 <= hr)
			{
				ILockAppHost* plah = 0;
				IProxyServerIdentity* psi;
				HANDLE hEvent[2] = {}, hSection = 0;
				GUID guid;
				BCryptGenRandom(0, (PBYTE)&guid, sizeof(guid), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
				WCHAR buf[0x80];

				if (0 <= (hr = plsdp->QueryInterface(IID_PPV_ARGS(&psi))))
				{
					BOOLEAN b;
					RtlAdjustPrivilege(SE_DEBUG_PRIVILEGE, TRUE, FALSE, &b);
					hr = psi->GetServerProcessHandle(PROCESS_DUP_HANDLE, FALSE, &hProcess);
					psi->Release();

					if (0 <= hr)
					{
						pcsz = L"--1";
						if ((hEvent[0] = CreateEventW(0, 0, 0, GenName(L"Event", buf, _countof(buf), guid))) &&
							(hEvent[1] = CreateEventW(0, 0, 0, GenName(L"SharedVisualEvent", buf, _countof(buf), guid))) &&
							(hSection = CreateFileMappingW(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, 0x1000,
								GenName(L"Data", buf, _countof(buf), guid))))
						{
							hr = ZwDuplicateObject(NtCurrentProcess(), NtCurrentProcess(),
								hProcess, &h, SYNCHRONIZE, 0, 0);
						}
						else
						{
							hr = GetLastErrorEx();
						}

						NtClose(hProcess);
					}

					if (0 <= hr)
					{
						hr = plsdp->CreateController(h, &plah);
						pcsz = L"--2";
					}
				}
				plsdp->Release();

				if (0 <= hr)
				{
					if (0 <= (hr = plah->Initialize(guid)))
					{
						pcsz = L"--3";
						hr = plah->ShowWebDialog(L"ms-lwh://AADWEBAUTH");

						pcsz = L"--3";
						if (0 <= hr)
						{
							Sleep(10000);
							plah->DismissWebDialog();
							plah->SetLockVisible(FALSE);
						}
						plah->Shutdown((LockAppHostShutdownOptions)0);
						plah->Release();
					}

					NtClose(hSection);
					NtClose(hEvent[1]);
					NtClose(hEvent[0]);
				}
			}
		}

		CoUninitialize();
	}

	if (hr)
	{
		ShowErrorBox(0, hr, pcsz);
	}
		
	ExitProcess(0);
}

