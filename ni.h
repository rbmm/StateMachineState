#pragma once

/*

CredentialProvider
{
	d27c3481-5a1c-45b2-8aaa-c20ebbe8229e ICredentialProvider
	095c1484-1c0c-4388-9c6d-500e61bf84bd ICredentialProviderSetUserArray
	a09bcc29-d779-4513-bb59-b4db5d82d2b6 ICredentialProviderWithDisplayState
	cc4b9589-76f2-42b2-8736-41cd43b9194f ICredentialProviderWithSessionContext
	8a4e89fe-c09d-475e-88cb-f8f11e047c50 IAutoLogonProvider
};

CredentialProviderCredential
{
	63913a93-40c1-481a-818d-4072ff8c70cc ICredentialProviderCredential
	fd672c54-40ea-4d6e-9b49-cfb1a7507bd7 ICredentialProviderCredential2
	64a5010e-4363-41f8-9738-19045c20dabc ICredentialProviderCredential3
	4a54a3b6-a8d3-46a8-9080-811ba8ccb07d ICredentialProviderCredential4
	1ecf61d8-745e-4484-bcc7-182cea64c787 ICredentialProviderCredential5
	dbc6fb30-c843-49e3-a645-573e6f39446a ICredentialProviderCredentialWithFieldOptions
	19844e8f-93e3-425a-9485-56a35726fe1c ICredentialProviderCredentialWithSubmissionOptions
	5e6ab326-3948-4a3d-a4b9-707cc16e5eae ICredentialProviderCredentialWithWebDialog
	8c89cd69-6e00-4189-ab49-b036663d05d3 ICredentialProviderCredentialWithUIMode
	ac9888cd-1278-4d00-a05e-7b052c014553 ICredentialProviderCredentialWithHiddenCredUISubmitButton
	5881c1a8-5b25-41ab-9311-750f996c8615 ICredentialProviderCredentialWithDisabledCredUISubmitButton
	f6247cf9-061d-46e7-aaa7-0fde071a5c1a ICredentialProviderCredentialTileDataInfo
	62fb1df7-92ae-461b-ad46-59bb9c9d8a76 ICredentialProviderCredentialForPrimaryUser
	5289a2f4-4e0d-4105-b313-94f82c2e900e ICredentialMethodInfo
};

CredentialProviderCredentialEvents
{
	fa6fa76b-66b7-4b11-95f1-86171118e816 ICredentialProviderCredentialEvents
	B53C00B6-9922-4B78-B1F4-DDFE774DC39B ICredentialProviderCredentialEvents2
	2D8DEEB8-1322-4973-8DF9-B282F2468290 ICredentialProviderCredentialEvents3
	df50ea86-b7a9-4485-8f04-930a49686e5b ICredentialProviderCredentialEvents4
	c4a56475-d6f5-43e3-80ae-1aa99833cc05 ICredentialProviderCredentialEvents5
	c8df4b94-3179-4ece-9083-5c674a644374 ICredentialProviderCredentialCredUISubmitButtonEvents
	0e532f00-c69e-46a3-b7a3-85e53f13e6a7 ICredentialProviderCredentialUIModeEvents 
	7c5d038e-59f7-4551-a6f0-fa431e00dc56 ICredentialProviderCredentialSwitchProviderEvents 
	dd107cc8-d477-4e0e-920b-b072933fddd4 ICredentialProviderCredentialTileDataEvents 
};

CredentialProviderEvents
{
	34201e5a-a787-41a3-a5a4-bd6dcf2a854e ICredentialProviderEvents
	9b6b093b-aaf6-4418-9d07-574f6854f190 ICredentialProviderTileDataEvents
	8aa3ef4e-6a82-467d-a159-e0c97d057952 ICredentialProviderBioEvents
	1abbb96c-b973-43fe-820c-dbcfd3a7cc7d IGreetingFormatter
};

*/

//////////////////////////////////////////////////////////////////////////
// ICredentialProviderCredential

MIDL_INTERFACE("F6247CF9-061D-46E7-AAA7-0FDE071A5C1A")
ICredentialProviderCredentialTileDataInfo : public IUnknown 
{
	virtual HRESULT STDMETHODCALLTYPE SetTileVisibility(_In_ BOOL bVisibile) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetTileVisibility(_Out_ PBOOL pbVisibile) = 0;
};

MIDL_INTERFACE("ac9888cd-1278-4d00-a05e-7b052c014553")
ICredentialProviderCredentialWithHiddenCredUISubmitButton : public IUnknown 
{
	virtual HRESULT STDMETHODCALLTYPE ShouldHideCredUISubmitButton(_Out_ PBOOL pbHide) = 0;
};

MIDL_INTERFACE("5881c1a8-5b25-41ab-9311-750f996c8615")
ICredentialProviderCredentialWithDisabledCredUISubmitButton : public IUnknown 
{
	virtual HRESULT STDMETHODCALLTYPE ShouldDisableCredUISubmitButton(_Out_ PBOOL pbDisable) = 0;
};

MIDL_INTERFACE("5e6ab326-3948-4a3d-a4b9-707cc16e5eae")
ICredentialProviderCredentialWithWebDialog : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE OnWebDialogVisiblityChange(BOOL bVisible) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetWebDialogUrl(_Out_ PWSTR* ppszUrl) = 0;
};

MIDL_INTERFACE("62fb1df7-92ae-461b-ad46-59bb9c9d8a76")
ICredentialProviderCredentialForPrimaryUser : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetShouldAssignPrimaryUser(BOOL *) = 0;
};

enum CREDENTIAL_PROVIDER_CREDENTIAL_UI_MODE {};
enum CREDENTIAL_METHOD_FLAGS {};

MIDL_INTERFACE("8c89cd69-6e00-4189-ab49-b036663d05d3")
ICredentialProviderCredentialWithUIMode : public IUnknown // +10
{
	virtual HRESULT STDMETHODCALLTYPE GetUIMode(_Out_ CREDENTIAL_PROVIDER_CREDENTIAL_UI_MODE *) = 0;
};

enum SERIALIZATION_FLAGS { all_flags = -1, zero_flag };

MIDL_INTERFACE("19844e8f-93e3-425a-9485-56a35726fe1c")
ICredentialProviderCredentialWithSubmissionOptions : public IUnknown 
{
	virtual HRESULT STDMETHODCALLTYPE GetSubmissionOptions(_Out_ SERIALIZATION_FLAGS * pdwFlags, _Out_ PWSTR* ppszContext) = 0;
};

MIDL_INTERFACE("5289a2f4-4e0d-4105-b313-94f82c2e900e")
ICredentialMethodInfo : public IUnknown // +20
{
	virtual HRESULT STDMETHODCALLTYPE GetCredentialMethod(_Out_ CREDENTIAL_METHOD_FLAGS *) = 0;
};

MIDL_INTERFACE("64a5010e-4363-41f8-9738-19045c20dabc")
ICredentialProviderCredential3 : ICredentialProviderCredential2
{
	virtual HRESULT STDMETHODCALLTYPE GetBitmapBufferValue(_In_ DWORD dwFieldID,
		_Out_ DWORD* pImageBufferSize, _Out_ BYTE** ppImageBuffer) = 0;
};

// no more supported, merged with ICredentialProviderCredential5
MIDL_INTERFACE("4a54a3b6-a8d3-46a8-9080-811ba8ccb07d")
ICredentialProviderCredential4 : ICredentialProviderCredential3
{
	virtual HRESULT STDMETHODCALLTYPE GetTextFieldMaxLength(_In_ DWORD dwFieldID, _Out_ DWORD* pMaxLength) = 0;
};

MIDL_INTERFACE("1ecf61d8-745e-4484-bcc7-182cea64c787")
ICredentialProviderCredential5 : ICredentialProviderCredential4
{
	virtual HRESULT STDMETHODCALLTYPE GetAccessibilityTextForField(_In_ DWORD dwFieldID, _Out_ PWSTR* ppszText) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetIsAccessibilityViewRawForField(_In_ DWORD dwFieldID, _Out_ BOOL* pbRaw) = 0;
};

//////////////////////////////////////////////////////////////////////////
// ICredentialProviderCredentialEvents

MIDL_INTERFACE("2D8DEEB8-1322-4973-8DF9-B282F2468290")
ICredentialProviderCredentialEvents3 : public ICredentialProviderCredentialEvents2
{
	virtual HRESULT STDMETHODCALLTYPE SetFieldBitmapBuffer(_In_ ICredentialProviderCredential* pcpc,
		_In_ DWORD dwFieldID,
		_In_ DWORD imageBufferSize,
		_In_ BYTE const* pImageBuffer) = 0;
};

MIDL_INTERFACE("DF50EA86-B7A9-4485-8F04-930A49686E5B")
ICredentialProviderCredentialEvents4 : public ICredentialProviderCredentialEvents3
{
	virtual HRESULT STDMETHODCALLTYPE RequestSerialization() = 0;
	virtual HRESULT STDMETHODCALLTYPE RequestSelection() = 0;
};

MIDL_INTERFACE("c4a56475-d6f5-43e3-80ae-1aa99833cc05")
ICredentialProviderCredentialEvents5 : public ICredentialProviderCredentialEvents4
{
	virtual HRESULT STDMETHODCALLTYPE SetTextFieldMaxLength(
		_In_ ICredentialProviderCredential * pcpc, _In_ DWORD dwFieldID, _In_ DWORD MaxLength) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetAccessibilityTextForField(
		_In_ ICredentialProviderCredential *pcpc, _In_ DWORD dwFieldID, _In_ PCWSTR pcszText) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetRawAccessibilityViewForField(
		_In_ ICredentialProviderCredential *pcpc, _In_ DWORD dwFieldID, _In_ BOOL bRaw) = 0;

	virtual HRESULT STDMETHODCALLTYPE RequestWebDialogVisibilityChange(
		_In_ ICredentialProviderCredential *pcpc, _In_ BOOL bVisible) = 0;
};

MIDL_INTERFACE("0e532f00-c69e-46a3-b7a3-85e53f13e6a7")
ICredentialProviderCredentialUIModeEvents : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE SetUIMode(_In_ CREDENTIAL_PROVIDER_CREDENTIAL_UI_MODE)=0;
};

MIDL_INTERFACE("c8df4b94-3179-4ece-9083-5c674a644374")
ICredentialProviderCredentialCredUISubmitButtonEvents : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE SetCredUISubmitButtonState(_In_ BOOL, _In_ BOOL, _In_ BOOL) = 0;
};

MIDL_INTERFACE("7c5d038e-59f7-4551-a6f0-fa431e00dc56")
ICredentialProviderCredentialSwitchProviderEvents : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE SwitchCredentialProvider(_In_ const GUID &) = 0;
};

MIDL_INTERFACE("dd107cc8-d477-4e0e-920b-b072933fddd4")
ICredentialProviderCredentialTileDataEvents : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE RequestVisibilityChange() = 0;
};

//////////////////////////////////////////////////////////////////////////
// ICredentialProviderEvents

enum CREDENTIAL_PROVIDER_FEEDBACK_VISUAL_STATE{ vs_none };
enum BIO_FEEDBACK_PRIORITY{ bp_idle, bp_default };

MIDL_INTERFACE("8aa3ef4e-6a82-467d-a159-e0c97d057952") ICredentialProviderBioEvents : public IUnknown 
{
	// BioFeedbackVisualStateChangedWithPriority(upAdviseContext, state, str1, str2, bp_default);
	virtual HRESULT NTAPI BioFeedbackVisualStateChanged(
		_In_ ULONG_PTR upAdviseContext, 
		_In_ CREDENTIAL_PROVIDER_FEEDBACK_VISUAL_STATE state, 
		_In_ PCWSTR pszLabel, 
		_In_ PCWSTR pszAccessibility) = 0;

	virtual HRESULT NTAPI BioFeedbackVisualStateChangedWithPriority(
		_In_ ULONG_PTR upAdviseContext, 
		_In_ CREDENTIAL_PROVIDER_FEEDBACK_VISUAL_STATE state,
		_In_ PCWSTR pszLabel, 
		_In_ PCWSTR pszAccessibility,
		_In_ BIO_FEEDBACK_PRIORITY priority) = 0;

	// BioFeedbackVisualStateChangedWithPriority(upAdviseContext, 0, 0, 0, bp_idle);
	virtual HRESULT NTAPI CancelBioFeedbackVisualState(ULONG_PTR upAdviseContext) = 0;
};

enum GREETING_TYPE { 
	gt0,
	gt1,
	gt2,
	gt3,
	gt4,
	gt5,
	gt6,
};

struct GreetingParameters
{
	GREETING_TYPE type;
	BOOL bNotUseTime;
	union {
		PSID UserSid;
		ICredentialProviderUser * user;
	};
	BOOL bUseUserName;
};

MIDL_INTERFACE("1abbb96c-b973-43fe-820c-dbcfd3a7cc7d") IGreetingFormatter : public IUnknown
{
	virtual HRESULT NTAPI FormatGreeting(
		_In_ GREETING_TYPE gtype, 
		_In_opt_ PSID UserSid, 
		_Out_ PWSTR * ppsz) = 0;

	virtual HRESULT NTAPI FormatGreetingForCredentialProviderUser(
		_In_ GREETING_TYPE gtype, 
		_In_ ICredentialProviderUser * user, 
		_Out_ PWSTR * ppsz) = 0;

	virtual HRESULT NTAPI FormatGreetingBasedOnTime(
		_In_ GreetingParameters * params, 
		_Out_ PWSTR * ppsz) = 0;

	virtual HRESULT NTAPI FormatGreetingForCredentialProviderUserBasedOnTime(
		_In_ GreetingParameters * params, 
		_Out_ PWSTR * ppsz) = 0;
};

enum SUPPORTED_UI_FEATURE_FLAGS { eWebDlg = 1 };

MIDL_INTERFACE("9b6b093b-aaf6-4418-9d07-574f6854f190") ICredentialProviderTileDataEvents : public IUnknown
{
	virtual HRESULT WINAPI RequestVisibilityChange(ULONG64) = 0;
	virtual HRESULT WINAPI RequestLockScreenDismiss(ULONG64) = 0;
	virtual HRESULT WINAPI RequestOptionExpansion(ULONG64) = 0;
	virtual HRESULT WINAPI RequestSignInUIVisible(ULONG64) = 0;
	virtual HRESULT WINAPI QuerySupportedUIFeatures(SUPPORTED_UI_FEATURE_FLAGS *) = 0;
};

//////////////////////////////////////////////////////////////////////////
// ICredentialProvider

enum CREDENTIAL_PROVIDER_DISPLAY_STATE_FLAGS
{
	CPDSF_NONE = 0x00000000,                // default initialization value
	CPDSF_AWAKE = 0x00000001,               // display is awake, disappears when display goes black
	CPDSF_UNKNOWN_02 = 0x00000002,          // transitive flag, mostly absent, appears before/after CPDSF_AWAKE changes
	CPDSF_CURTAIN = 0x00000004,             // curtain is pulled on
	CPDSF_CURTAIN_MOVING = 0x00000008,      // curtain is moving, appears the when the curtain is being pulled
	CPDSF_STATION_LOCKED = 0x00000040,      // the station is locked. not sent to provider in change-password scenario.
	CPDSF_PROVIDER_VISIBLE = 0x00000080,    // providers screen active/visible. 
	CPDSF_NO_LOGGED_USERS = 0x00000400,     // there are no logged on users
	CPDSF_UNKNOWN_800 = 0x00000800,         // unknown flag that at least PIN (NGC) provided uses
	CPDSF_SHUTDOWN_STARTED = 0x00001000,    // shutdown started
	CPDSF_ACTIVE = 0x00010000,              // display activity related, disappears after some time when idle
	CPDSF_TBAL_LOGON = 0x00080000           // trusted boot auto-logon (TBAL)
};

MIDL_INTERFACE("A09BCC29-D779-4513-BB59-B4DB5D82D2B6")
ICredentialProviderWithDisplayState : public IUnknown 
{
	virtual HRESULT STDMETHODCALLTYPE SetDisplayState(_In_ CREDENTIAL_PROVIDER_DISPLAY_STATE_FLAGS Flags) = 0;
};

struct __declspec(novtable)
ICredProviderCredentialSerialization : public IUnknown 
{
	// returned by ICredentialProviderCredential::GetSerialization
	virtual HRESULT STDMETHODCALLTYPE GetAuthenticationPackage(_Out_ ULONG * ulAuthenticationPackage) = 0;
	// returned by ICredentialProviderCredential::GetSerialization
	virtual HRESULT STDMETHODCALLTYPE GetCredentialProviderCLSID(_Out_ GUID * pclsidCredentialProvider) = 0;
	// returned by ICredentialProviderCredentialWithSubmissionOptions::GetSubmissionOptions
	virtual HRESULT STDMETHODCALLTYPE GetSerializationFlags(_Out_ SERIALIZATION_FLAGS *pdwFlags) = 0;
	// returned by ICredentialProviderCredential::GetSerialization
	virtual HRESULT STDMETHODCALLTYPE GetSerialization(_Out_ ULONG * pcbSerialization, byte** prgbSerialization) = 0;
	// returned by ICredentialProviderCredentialWithSubmissionOptions::GetSubmissionOptions
	virtual HRESULT STDMETHODCALLTYPE GetCredentialContext(_Out_ PWSTR* ppszContext) = 0;

	// in winlogon: 
	// HRESULT CGlobalStore::SetCredentialContext(_In_ PWSTR pszContext , CredentialContextType);
	// ULONG CGlobalStore::SetCredentials(CRED_PROV_CREDENTIAL *);
};

struct CRED_PROV_CREDENTIAL {
	ULONG dwFlags;// <-- SERIALIZATION_FLAGS
	DATA_BLOB Serialization; // { cbSerialization, rgbSerialization }
};

struct __declspec(novtable)
IAutoLogonManager : public IUnknown 
{
	virtual HRESULT STDMETHODCALLTYPE IgnoreAutoLogonMode() = 0;
	virtual BOOL STDMETHODCALLTYPE IsAutoLogonMode() = 0;
	virtual BOOL STDMETHODCALLTYPE IsSingleUserNoPasswordAutoLogonMode() = 0;
	virtual BOOL STDMETHODCALLTYPE IsAutoLogonNotSingleUserNoPasswordMode() = 0;
	virtual BOOL STDMETHODCALLTYPE IsSystemAutoLogon() = 0;
	virtual HRESULT STDMETHODCALLTYPE UpdateAutoLogonDefaultSID() = 0;
	virtual HRESULT STDMETHODCALLTYPE ResetAutoLogonSetting() = 0;
	virtual HRESULT STDMETHODCALLTYPE ClearSystemAutoLogonSetting() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetAutoLogonCredential(_Out_ PWSTR*, _Out_ PWSTR*, _Out_ PWSTR*) = 0;
	virtual BOOL STDMETHODCALLTYPE IsSingleUser() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetSerializedAutoLogonCredential(ICredProviderCredentialSerialization * *) = 0;
};

MIDL_INTERFACE("8A4E89FE-C09D-475E-88CB-F8F11E047C50")
IAutoLogonProvider : public IUnknown 
{
	virtual HRESULT STDMETHODCALLTYPE SetAutoLogonManager(IAutoLogonManager *) = 0;
};

MIDL_INTERFACE("cc4b9589-76f2-42b2-8736-41cd43b9194f")
ICredentialProviderWithSessionContext : public IUnknown 
{
	// returned by ICredentialProviderCredentialWithSubmissionOptions::GetSubmissionOptions
	virtual HRESULT STDMETHODCALLTYPE SetSessionContext(PCWSTR pszContext) = 0;
};

class DECLSPEC_UUID("F8A0B131-5F68-486c-8040-7E8FC3C85BB6") WLIDCredentialProvider;
class DECLSPEC_UUID("D6886603-9D2F-4EB2-B667-1971041FA96B") NgcPinProvider;
class DECLSPEC_UUID("48b4e58d-2791-456c-9091-d524c6c706f2") DeviceNgcCredProvider;
class DECLSPEC_UUID("2135f72a-90b5-4ed3-a7f1-8bb705ac276a") PicturePasswordLogonProvider;
class DECLSPEC_UUID("cb82ea12-9f71-446d-89e1-8d0924e1256e") PINLogonProvider;
class DECLSPEC_UUID("edd749de-2ef1-4a80-98d1-81f20e6df58e") PlapLogonFilter;
class DECLSPEC_UUID("F8A1793B-7873-4046-B2A7-1F318747F427") FIDOCredentialProvider;
class DECLSPEC_UUID("8AF662BF-65A0-4D0A-A540-A338A999D36F") FaceCredentialProvider;
class DECLSPEC_UUID("C5D7540A-CD51-453B-B22B-05305BA03F07") CloudExperienceCredentialProvider;

//////////////////////////////////////////////////////////////////////////
// internal,private

struct IFieldData;

MIDL_INTERFACE("a349e249-9e81-484c-a6c5-10b1d670d7de")
ICredTileData : public IUnknown
{
	virtual ULONG STDMETHODCALLTYPE GetProviderId() = 0;
	virtual ULONG STDMETHODCALLTYPE GetCredentialId() = 0;
	virtual ULONG STDMETHODCALLTYPE GetFieldCount() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetFieldAt(_In_ ULONG dwIndex, _Out_ IFieldData **) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetClsid(_Out_ GUID * clsid) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetUserSid(_Out_ PWSTR* sid) = 0;
	virtual BOOL STDMETHODCALLTYPE IsPLAPTile() = 0;
	virtual BOOL STDMETHODCALLTYPE IsV2CredProv() = 0;
	virtual BOOL STDMETHODCALLTYPE IsEmptyTile() = 0;
	virtual BOOL STDMETHODCALLTYPE IsConnectedUser() = 0;
	virtual BOOL STDMETHODCALLTYPE IsPictureLoginMode() = 0;
	virtual BOOL STDMETHODCALLTYPE IsTileVisible() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCredProviderLogoBitmap(_Out_ HBITMAP* ) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCredProviderLogoBitmapStream(_In_ REFIID riid, _Out_ void ** ppvObject) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCredProviderLogoLabel(_Out_ PWSTR *) = 0;
	virtual BOOL STDMETHODCALLTYPE DoesCredentialSupportIHMAutomaticInvoke() = 0;
	virtual BOOL STDMETHODCALLTYPE ShouldShowCredUISubmitButton() = 0;
	virtual BOOL STDMETHODCALLTYPE ShouldEnableCredUISubmitButton() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetUIMode(_Out_ CREDENTIAL_PROVIDER_CREDENTIAL_UI_MODE * flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCredentialMethod(_Out_ CREDENTIAL_METHOD_FLAGS * flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetWebDialogUrl(_Out_ PWSTR * url) = 0;
	virtual BOOL STDMETHODCALLTYPE DoesTileAssignPrimaryUser() = 0;
};

enum WLUI_REQUEST_FLAGS{};
enum WLUI_SECURITY_OPTIONS{};
enum WLUI_STATE{};
enum WLUI_REQUEST_REASON{};
enum WLUI_REASON{};
struct WLUI_CREDPROV_RESPONSE;
struct CREDUI_CONTEXT;
struct CREDUI_INFO_INTERNAL_CONTEXT;
struct WLUI_INFORMATION;

class __declspec(uuid("0bdc6fc7-83e3-46a4-bfa0-1bc14dbf8b38")) LogonUIController;

struct __declspec(uuid("d31db316-e169-4263-8f34-99aa38b92275")) IWinLogonRPC : public IUnknown
{
	virtual HRESULT WINAPI Abort() = 0;
	virtual HRESULT WINAPI DisplayLocked(PCWSTR,PCWSTR,PCWSTR,PCWSTR,PCWSTR,WLUI_REQUEST_FLAGS) = 0;
	virtual HRESULT WINAPI WaitForLockScreenDismiss(BOOL*,BOOL*) = 0;
	virtual HRESULT WINAPI DisplayRequestCredentialsError(long,long,PCWSTR,PCWSTR,UINT,UINT *,BOOL*) = 0;
	virtual HRESULT WINAPI DisplayMessage(PCWSTR,PCWSTR,UINT,UINT *,BOOL*) = 0;
	virtual HRESULT WINAPI DisplaySequentialLogonPrompt(PCWSTR,UINT,UINT *,BOOL*) = 0;
	virtual HRESULT WINAPI DisplaySecurityOptions(WLUI_SECURITY_OPTIONS *,UINT *,BOOL*) = 0;
	virtual HRESULT WINAPI DisplayStatus(PCWSTR,WLUI_STATE,BOOL*) = 0;
	virtual HRESULT WINAPI DisplayStatusOnCredentialPage(WLUI_REQUEST_REASON,WLUI_REQUEST_FLAGS,PCWSTR,PCWSTR,WLUI_STATE,BOOL*) = 0;
	virtual HRESULT WINAPI DisplayTSDisconnectOptions(ULONG,ULONG *,ULONG,ULONG *,ULONG *,BOOL*) = 0;
	virtual HRESULT WINAPI DisplayWelcome(WLUI_REQUEST_FLAGS,PCWSTR,BOOL*,BOOL*) = 0;
	virtual HRESULT WINAPI NotifyIsReadyForDesktopSwitch() = 0;
	virtual HRESULT WINAPI ReleaseContext() = 0;
	virtual HRESULT WINAPI ReportResult(WLUI_REQUEST_REASON,long,long,PCWSTR,PCWSTR,PCWSTR,PWSTR*,WLUI_CREDPROV_RESPONSE *,BOOL*) = 0;
	virtual HRESULT WINAPI RequestCredentials(WLUI_REQUEST_REASON,WLUI_REQUEST_FLAGS,PCWSTR,CRED_PROV_CREDENTIAL *,UINT *,PWSTR*,PWSTR*,BOOL*) = 0;
	virtual HRESULT WINAPI PromptForCredentials(ULONG,CREDUI_CONTEXT,CREDUI_INFO_INTERNAL_CONTEXT,ULONG,ULONG,BYTE *,ULONG,int,ULONG,BYTE * *,ULONG *,BOOL *,ULONG *,ULONG *) = 0;
	virtual HRESULT WINAPI Shutdown() = 0;
	virtual HRESULT WINAPI DisplayTSDisconnectUI(ULONG,ULONG *,int,UINT *,BOOL*,BOOL*) = 0;
	virtual HRESULT WINAPI DisplayTSReconnectUI(ULONG,ULONG *,UINT *,BOOL*) = 0;
	virtual HRESULT WINAPI FinishOperation(WLUI_INFORMATION,ULONG,BOOL*) = 0;
	virtual HRESULT WINAPI InformLogonUI(WLUI_INFORMATION,WLUI_STATE,WLUI_REASON) = 0;
	virtual HRESULT WINAPI DelayLocked(WLUI_REQUEST_FLAGS,PCWSTR,ULONG64,PCWSTR,BOOL*) = 0;
	virtual HRESULT WINAPI GetShutdownResolverInfo(BOOL*,BOOL*,ULONG *) = 0;
	virtual HRESULT WINAPI DisplayLockSecure(PCWSTR,PCWSTR,PCWSTR,PCWSTR,WLUI_REQUEST_FLAGS,BOOL*) = 0;
	virtual HRESULT WINAPI DelayLockSecure(WLUI_REQUEST_FLAGS,ULONG64,PCWSTR,BOOL*) = 0;
	virtual HRESULT WINAPI ClearUIState() = 0;
	virtual HRESULT WINAPI PrepareWebDialog(PCWSTR) = 0;
	virtual HRESULT WINAPI WaitForWebDialogComplete(BOOL*) = 0;
};

// called by winlogon
// IWinLogonRPC* p;
// CoCreateInstance(__uuidof(LogonUIController), 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&p)))
