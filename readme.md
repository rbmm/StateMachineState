## Web sign-in for Windows
how this implemented internally. problem here that app, which show web content, designed to run as Interactive User ( RunAs = Interactive User under AppId)
but we on winlogon desktop and probably no user loged on (not unlock, but login)
idea was - log under special user account and then lock system. and then show WebDialog under this special account, on under default desktop, but on special lock band ( ZBID_LOCK )

at first credentil provider pass logon serialization for special account - WsiAccount
it is can be done with 

```
EXTERN_C
WINBASEAPI
HRESULT 
WINAPI
CflSetupAuthEnvironment(
	_Out_ void** ppvSerialization, _Out_ ULONG* pcbSerialization
	);
```

which internally call 

```
struct CAC 
{
	SIZE_T u;
	ULONG cbSerialization;
	PVOID pvRemote;
	UCHAR Serialization[];
};

EXTERN_C
WINBASEAPI
HRESULT
WINAPI
CamGetCandidateAccountCredz(_Inout_ ULONG* pcb, _Inout_ CAC** ppv);
```

(TCB privilege require for call this api)

and finally  (in service process)
```
HRESULT UserMgrCli::GetCandidateAccountCredz(void *,unsigned long *,unsigned char * *);
```

is called, then

```
HRESULT WsiEnvironmentAccountManager::GetWsiEnvironmentAccountNewCredz(unsigned char * *,unsigned long *);
HRESULT AccountManagerUtils::GenerateAccountPassword(unsigned short * *);
```

every time new, random password is generated for WsiAccount. it have  - 14 chars from [A..Z][0..9] set. as example `RUHJVMTP3DQP2T`

credential must implement `ICredentialProviderCredentialWithSubmissionOptions` interface (view full list of interfaces [here](https://github.com/rbmm/StateMachineState/blob/main/ni.h) )

as result after `GetSerialization`

```
HRESULT STDMETHODCALLTYPE GetSubmissionOptions(_Out_ SERIALIZATION_FLAGS * pdwFlags, _Out_ PWSTR* ppszContext);
```

is called. under `ppszContext` we can pass any string (system not interpret it)

as example

```
{
	"providerId":"{C5D7540A-CD51-453B-B22B05305BA03F07}",
	"scenarioContext":"YQB1AHQAaABvAG4AbAB5AD0AMQAsAHQAZQBuAGEAbgB0AGkAZAA9ADQAZQBkADkAZgA2ADAAMAAtADgANAA2ADAALQA0ADYAMAAyAC0AOAAzAGUANAAtADYAYgBmADIAZAA5ADYAMQAwADMANAAxAAAA",
	"scenarioId":"ms-lwh://AADWEBAUTH",
	"userSid":""
}
```

if special flags set in `GetSubmissionOptions`, winlogon, after logon (yet before desktop switch, but after run shell (explorer)) auto do system lock
and credentials providers begin called again
provider must implement `ICredentialProviderWithSessionContext` interface
as result, just after `SetUsageScenario`

```
HRESULT STDMETHODCALLTYPE SetSessionContext(PCWSTR pszContext);
```

will be called - here we got back string, passed to `GetSubmissionOptions`

with this, just after credential is adviced (in `Advice` call), we can query for `ICredentialProviderCredentialEvents5` and call 
`RequestWebDialogVisibilityChange(TRUE)` on it
credential must implement `ICredentialProviderCredentialWithWebDialog` interface
system call `GetWebDialogUrl` on it. here we return url, which want to show. say - `"ms-lwh://AADWEBAUTH"`
than winlogon call 
`WLGeneric_Request_Web_Unlock_Credz_Execute -> WluiPrepareWebDialog`
it do RPC call to logonUI
`WluirPrepareWebDialog` call `CLogonController::PrepareWebDialog(PCWSTR url)`
logonUI interact with explorer via com interfaces, and as result
`VisualsController::ShowWebDialog(PCWSTR url)` will be called inside explorer (on user desktop, for `WsiAccount` account )

this create window L"LockScreenBackstopFrame"::L"Backstop Window" in `ZBID_LOCK` band and show web dialog over it

finally winlogon switch to use `\Default` desktop, where `"Backstop Window"` and dialog

for demo code,  show `L"Backstop Window"` by self. it not show correct web dialog, but will give some idea, how it implemented and look like
demo block desktop on 10 seconds, before exit

also you can run (before demo) this [CTF](https://github.com/rbmm/CTF/blob/main/CTF.x64.exe) example. it show messagebox in `ZBID_ABOVELOCK_UX` band, as result will be visible on lock screen.
(CTF.x64.exe will be have very many AV "detects". but this say only about AV quality )