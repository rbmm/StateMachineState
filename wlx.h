struct _StateMachineSignal
{
	PCWSTR name;
	int b;
};

typedef ULONG _StateMachineTransition;

struct _StateMachineCallContext; 

struct _StateMachineState
{
	PCWSTR name;
	void (WINAPI *Enter)(_StateMachineCallContext *);
	ULONG (WINAPI *Execute)(_StateMachineCallContext *);
	void (WINAPI *Exit)(_StateMachineCallContext *);
	ULONG nTransitions;
	_StateMachineTransition * pvTransition;
	ULONG nResetSignals;
	ULONG* pvResetSignals;
};


_StateMachineTransition g_xWLGeneric_Start_Transition[] = { 0x0, 0x1, 0x0, 0x2, 0x6c, 0x0, 0x1, };
_StateMachineTransition g_xWLGeneric_NotifyCreateSession_Transition[] = { 0x0, 0x2, 0x0, 0x2, 0x6c, 0x0, 0x1, };
_StateMachineTransition g_xWLGeneric_Welcome_Transition[] = { 0x2, 0x6d, 0x0, 0x13, 0x6e, 0x0, 0x1, 0x6e, 0x0, };
_StateMachineTransition g_xWLGeneric_Welcome_Return_Transition[] = { 0x0, 0x2, };
_StateMachineTransition g_xWLGeneric_TimeoutHandler_Welcome_Transition[] = { 0x2, 0x2, 0x2, 0x13, 0x2, 0x2, };
_StateMachineTransition g_xWLGeneric_Killing_Scrnsaver_Welcome_Transition[] = { 0x0, 0x2, };
_StateMachineTransition g_xWLGeneric_PowerTransition_Welcome_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_Welcome_Hibernating_Transition[] = { 0x5, 0x2, };
_StateMachineTransition g_xWLGeneric_PowerTransition_ShowResumeMsg_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_AccessNotifyAsSystem_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_AccessNotifyAsUser_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_AccessNotify_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_DwmControl_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_DisplayLegalNotice_Transition[] = { 0x2, 0x2, 0x2, 0x13, 0x2, 0x2, 0x4, 0x2, };
_StateMachineTransition g_xWLGeneric_Request_Logon_Credz_Transition[] = { 0x2, 0x6d, 0x0, 0x13, 0x6d, 0x0, 0x4, 0x2, 0x2, };
_StateMachineTransition g_xWLGeneric_Request_Logon_Credz_Return_Transition[] = { 0x0, 0xe, };
_StateMachineTransition g_xWLGeneric_Authenticating_Transition[] = { 0x0, 0x12, 0x0, };
_StateMachineTransition g_xWLGeneric_MPRLogonNotify_Transition[] = { 0x0, 0x12, };
_StateMachineTransition g_xWLGeneric_Logon_ReportSuccessResult_Transition[] = { 0x2, 0x6d, 0x2, 0x13, 0x6d, 0x2, };
_StateMachineTransition g_xWLGeneric_Logon_Checking_LastLogonPolicy_Transition[] = { 0x0, 0x14, };
_StateMachineTransition g_xWLGeneric_Logon_ReportLastLogon_Transition[] = { 0x2, 0x6d, 0x0, 0x4, 0x6d, 0x0, 0xc, 0x6d, 0x0, };
_StateMachineTransition g_xWLGeneric_Logon_ReportFailedResult_Transition[] = { 0x2, 0x2, 0x2, 0x13, 0x2, 0x2, 0x4, 0x2, 0x2, 0x28, };
_StateMachineTransition g_xWLGeneric_WaitForDisconnectAfterFailedAuth_Transition[] = { 0x13, };
_StateMachineTransition g_xWLGeneric_SequentialLogonPrompt_Transition[] = { 0x13, 0x6d, 0x0, 0x2, 0x6d, 0x0, 0x4, 0x6d, 0x0, };
_StateMachineTransition g_xWLGeneric_FindDestinationSession_Transition[] = { 0x18, 0x2, 0x0, 0x13, 0x6d, 0x0, 0x2, 0x6d, 0x0, 0x4, };
_StateMachineTransition g_xWLGeneric_NotifyLogon_Transition[] = { 0x13, 0x68, 0x1, 0x2, 0x6a, 0x0, 0x0, };
_StateMachineTransition g_xWLGeneric_NotifyStartShell_Transition[] = { 0x1e, 0x21, 0x1, 0x11, 0x35, 0x1, 0x10, 0x36, 0x1, 0x12, };
_StateMachineTransition g_xWLGeneric_ShellStartup_Transition[] = { 0x1e, 0x21, 0x1, 0x2, 0x69, };
_StateMachineTransition g_xWLGeneric_Request_LogonChange_Credz_Transition[] = { 0x2, 0x2, 0x2, 0x13, 0x2, 0x2, 0x4, 0x2, 0x2, };
_StateMachineTransition g_xWLGeneric_ChangingLogonPassword_Transition[] = { 0x20, 0x1e, };
_StateMachineTransition g_xWLGeneric_MPRChangeLogonNotify_Transition[] = { 0x0, 0x1f, };
_StateMachineTransition g_xWLGeneric_ChangeLogon_ReportResult_Transition[] = { 0x2, 0x2, 0x2, 0x13, 0x2, 0x2, 0x4, };
_StateMachineTransition g_xWLGeneric_Logged_On_Transition[] = { 0x1e, 0x21, 0x1, 0x1f, 0x21, 0x1, 0x2, 0x69, 0x0, 0x4, 0x26, 0x0, 0xc, 0x41, 0x0, 0xd, 0x41, 0x0, 0x22, 0x65, 0x0, 0x24, 0x65, };
_StateMachineTransition g_xWLGeneric_DelayedSwitchDesktop_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_CredsAreStaleReminder_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_CloudPasswordExpiredReminder_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_NTLMIsDisabledReminder_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_DifferentCredsAreRequiredReminder_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_PowerTransition_Logged_On_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_Logged_On_Hibernating_Transition[] = { 0xc, 0x28, 0x0, };
_StateMachineTransition g_xWLGeneric_InitiateLock_On_Resume_Transition[] = { 0x0, 0x2a, };
_StateMachineTransition g_xWLGeneric_Logged_On_Resume_Transition[] = { 0xc, 0x5d, 0x1, };
_StateMachineTransition g_xWLGeneric_Locked_Resume_Transition[] = { 0xc, 0x5d, 0x1, };
_StateMachineTransition g_xWLGeneric_InitiateDisconnect_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_Logged_On_Disconnected_Transition[] = { 0xc, 0x5d, 0x1, 0x2, };
_StateMachineTransition g_xWLGeneric_No_Unlock_Disconnected_Transition[] = { 0x2, 0x69, 0x0, 0x14, };
_StateMachineTransition g_xWLGeneric_Logged_On_Reconnect_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_No_Unlock_Reconnect_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_ShellRestart_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_CAD_Transition[] = { 0x0, 0x32, 0x0, 0x1, 0x20, 0x0, 0xf, 0x33, 0x0, 0x4, 0x32, 0x2, 0x2, 0x32, 0x2, };
_StateMachineTransition g_xWLGeneric_CAD_Return_Transition[] = { 0x4, 0x20, 0x2, 0x2, 0x69, 0x0, 0x13, 0x20, };
_StateMachineTransition g_xWLGeneric_SecureCredUI_Operation_Transition[] = { 0x2, 0x20, 0x2, 0x13, 0x20, 0x2, 0x4, 0x20, 0x2, 0xc, };
_StateMachineTransition g_xWLGeneric_StartSecureLua_Transition[] = { 0x2, 0x20, 0x2, 0x13, 0x20, 0x2, 0x4, 0x20, 0x2, 0xc, 0x20, 0x2, 0xd, 0x20, };
_StateMachineTransition g_xWLGeneric_ReadyForSecureLua_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_HandleSecureLuaBeforeShell_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_AbortPendingLuaRequest_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_AppLauncher_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_TimeoutHandler_Logged_On_Transition[] = { 0x2, 0x20, 0x2, 0x1e, 0x20, 0x2, 0x13, 0x3b, };
_StateMachineTransition g_xWLGeneric_Killing_Scrnsaver_Logged_On_Transition[] = { 0x0, 0x41, };
_StateMachineTransition g_xWLGeneric_TO_Disconnected_Transition[] = { 0x13, };
_StateMachineTransition g_xWLGeneric_Request_Change_Credz_Transition[] = { 0x2, 0x40, 0x2, 0x13, 0x40, 0x2, 0x4, 0x40, 0x2, 0xc, 0x40, 0x2, 0x7, };
_StateMachineTransition g_xWLGeneric_ChangingPassword_Transition[] = { 0x20, 0x3e, };
_StateMachineTransition g_xWLGeneric_MPRChangeNotify_Transition[] = { 0x0, 0x3f, };
_StateMachineTransition g_xWLGeneric_Change_ReportResult_Transition[] = { 0x2, 0x40, 0x2, 0x13, 0x40, 0x2, 0x4, 0x40, 0x2, 0xc, };
_StateMachineTransition g_xWLGeneric_PostChangeActions_Transition[] = { 0x2, 0x20, 0x2, 0x13, 0x20, 0x2, 0x4, 0x20, };
_StateMachineTransition g_xWLGeneric_InitiateLock_Transition[] = { 0x0, 0x42, };
_StateMachineTransition g_xWLGeneric_Locked_Transition[] = { 0xc, 0x63, 0x1, 0x2, 0x69, 0x0, 0x4, 0x61, };
_StateMachineTransition g_xWLGeneric_Locked_Return_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_LockScreen_Transition[] = { 0xc, 0x63, 0x1, 0x2, 0x69, 0x0, 0x4, 0x42, 0x2, 0x13, 0x42, 0x2, };
_StateMachineTransition g_xWLGeneric_DisplayLegalNotice_Unlock_Transition[] = { 0x2, 0x69, 0x2, 0x13, 0x42, 0x2, 0x4, 0x42, };
_StateMachineTransition g_xWLGeneric_Request_Unlock_Credz_Transition[] = { 0xc, 0x63, 0x1, 0x2, 0x69, 0x0, 0x13, 0x42, 0x2, 0x4, 0x42, 0x2, };
_StateMachineTransition g_xWLGeneric_Request_Unlock_Credz_Return_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_Request_Web_Unlock_Credz_Transition[] = { 0xc, 0x63, 0x1, 0x2, 0x69, 0x0, 0x13, 0x42, 0x2, 0x4, 0x42, 0x2, };
_StateMachineTransition g_xWLGeneric_Unlocking_Transition[] = { 0x0, 0x4b, 0x0, 0x1, };
_StateMachineTransition g_xWLGeneric_Unlock_LogonUser_Transition[] = { 0x2, 0x4f, 0x2, 0x13, 0x4f, 0x2, 0x4, 0x4f, };
_StateMachineTransition g_xWLGeneric_Unlock_ReportSuccessResult_Transition[] = { 0x2, 0x4c, 0x2, 0x13, 0x4c, 0x2, 0x4, 0x4c, };
_StateMachineTransition g_xWLGeneric_Unlock_Checking_LastLogonPolicy_Transition[] = { 0x0, 0x4d, };
_StateMachineTransition g_xWLGeneric_Unlock_ReportLastLogon_Transition[] = { 0x2, 0x42, 0x2, 0x13, 0x42, 0x2, 0x4, 0x42, 0x2, };
_StateMachineTransition g_xWLGeneric_SequentialUnlockPrompt_Transition[] = { 0x13, 0x43, 0x2, 0x2, 0x43, 0x2, 0x4, 0x43, 0x2, };
_StateMachineTransition g_xWLGeneric_Unlock_ReportFailedResult_Transition[] = { 0x2, 0x42, 0x2, 0x13, 0x42, 0x2, 0x4, 0x42, 0x2, 0xc, };
_StateMachineTransition g_xWLGeneric_MPRLogonNotify_Unlock_Transition[] = { 0x0, 0x51, };
_StateMachineTransition g_xWLGeneric_Logon_ReportSuccessResult_Unlock_Transition[] = { 0x2, 0x43, 0x2, 0x13, 0x43, 0x2, };
_StateMachineTransition g_xWLGeneric_Logon_Checking_LastLogonPolicy_Unlock_Transition[] = { 0x0, 0x53, };
_StateMachineTransition g_xWLGeneric_Logon_ReportLastLogon_Unlock_Transition[] = { 0x2, 0x43, 0x2, 0x4, 0x43, 0x2, 0xc, 0x43, 0x2, };
_StateMachineTransition g_xWLGeneric_SequentialLogonPrompt_Unlock_Transition[] = { 0x13, 0x43, 0x2, 0x2, 0x43, 0x2, 0x4, 0x43, 0x2, };
_StateMachineTransition g_xWLGeneric_FindDestinationSession_Unlock_Transition[] = { 0x13, 0x43, 0x2, 0x2, 0x43, 0x2, 0x4, 0x43, 0x2, };
_StateMachineTransition g_xWLGeneric_Request_UnlockChange_Credz_Transition[] = { 0x2, 0x42, 0x2, 0x13, 0x42, 0x2, 0x4, 0x42, 0x2, };
_StateMachineTransition g_xWLGeneric_ChangingUnlockPassword_Transition[] = { 0x20, 0x58, };
_StateMachineTransition g_xWLGeneric_MPRChangeUnlockNotify_Transition[] = { 0x0, 0x59, };
_StateMachineTransition g_xWLGeneric_ChangeUnlock_ReportResult_Transition[] = { 0x2, 0x42, 0x2, 0x13, 0x42, 0x2, 0x4, };
_StateMachineTransition g_xWLGeneric_TimeoutHandler_Locked_Transition[] = { 0x2, 0x42, 0x2, 0x13, 0x42, 0x2, 0x4, };
_StateMachineTransition g_xWLGeneric_Killing_Scrnsaver_Locked_Transition[] = { 0x0, 0x42, };
_StateMachineTransition g_xWLGeneric_PostUnlockActions_Transition[] = { 0x0, 0x20, };
_StateMachineTransition g_xWLGeneric_CompleteLockRequest_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_Locked_Disconnected_Transition[] = { 0xc, 0x5d, 0x1, 0x2, };
_StateMachineTransition g_xWLGeneric_No_Unlock_DisconnectedLock_Transition[] = { 0x2, 0x69, 0x0, 0x14, };
_StateMachineTransition g_xWLGeneric_Locked_Reconnect_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_PowerTransition_Locked_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_Locked_Hibernating_Transition[] = { 0xc, 0x63, 0x1, };
_StateMachineTransition g_xWLGeneric_AbortPendingLockRequest_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_ReconnectionUpdate_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_DelayLock_Transition[] = { 0x1, 0x41, 0x0, 0x0, 0x20, 0x0, 0x2, 0x69, 0x0, 0x13, 0x32, 0x2, 0x4, };
_StateMachineTransition g_xWLGeneric_DelayLock_DisplayOffHandler_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_DelayLock_DisplayOnHandler_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_InitiateForceLogoff_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_NotifyEndShell_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_Logging_Off_Transition[] = { 0x10, 0x37, 0x1, 0x11, };
_StateMachineTransition g_xWLGeneric_LogoffNotify_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_PseudoLogging_Off1_Transition[] = { 0x0, };
_StateMachineTransition g_xWLGeneric_PseudoLogging_Off2_Transition[] = { 0xc, 0x63, };
_StateMachineTransition g_xWLGeneric_NotifyTerminateSession_Transition[] = { 0x18, 0x2, };

unsigned long g_xWLGeneric_Welcome_ResetSignals[] = { 0x3, 0xe, 0x7, 0x6, };
unsigned long g_xWLGeneric_TimeoutHandler_Welcome_ResetSignals[] = { 0xe, 0x7, };
unsigned long g_xWLGeneric_Welcome_Hibernating_ResetSignals[] = { 0x3, 0xe, 0xd, 0x7, };
unsigned long g_xWLGeneric_DisplayLegalNotice_ResetSignals[] = { 0x3, 0xe, };
unsigned long g_xWLGeneric_Request_Logon_Credz_ResetSignals[] = { 0x3, 0xe, 0xd, 0xc, };
unsigned long g_xWLGeneric_Authenticating_ResetSignals[] = { 0x7, };
unsigned long g_xWLGeneric_SequentialLogonPrompt_ResetSignals[] = { 0x7, 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_FindDestinationSession_ResetSignals[] = { 0x7, 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_NotifyStartShell_ResetSignals[] = { 0x2c, };
unsigned long g_xWLGeneric_ShellStartup_ResetSignals[] = { 0x23, 0x22, };
unsigned long g_xWLGeneric_Request_LogonChange_Credz_ResetSignals[] = { 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_ChangingLogonPassword_ResetSignals[] = { 0xd, 0x3, 0xe, 0x7, };
unsigned long g_xWLGeneric_Logged_On_ResetSignals[] = { 0x3, 0xe, 0x2c, 0x6, 0x12, };
unsigned long g_xWLGeneric_Logged_On_Hibernating_ResetSignals[] = { 0x7, };
unsigned long g_xWLGeneric_Logged_On_Resume_ResetSignals[] = { 0x23, 0x22, };
unsigned long g_xWLGeneric_InitiateDisconnect_ResetSignals[] = { 0x3, 0xe, 0xd, 0x7, };
unsigned long g_xWLGeneric_Logged_On_Reconnect_ResetSignals[] = { 0xd, 0x3, 0xe, 0x7, 0x4, 0x5, 0x2c, 0x1a, 0x1b, 0x1c, 0x1d, 0x23, 0x22, };
unsigned long g_xWLGeneric_No_Unlock_Reconnect_ResetSignals[] = { 0xd, 0x3, 0xe, 0x7, 0x4, 0x5, 0x2c, 0x1a, 0x1b, 0x1c, 0x1d, };
unsigned long g_xWLGeneric_ShellRestart_ResetSignals[] = { 0x23, 0x22, };
unsigned long g_xWLGeneric_CAD_ResetSignals[] = { 0x3, 0xe, 0xd, 0x2c, };
unsigned long g_xWLGeneric_SecureCredUI_Operation_ResetSignals[] = { 0x23, 0x22, };
unsigned long g_xWLGeneric_StartSecureLua_ResetSignals[] = { 0x12, 0x23, 0x22, };
unsigned long g_xWLGeneric_AppLauncher_ResetSignals[] = { 0x23, 0x22, };
unsigned long g_xWLGeneric_TimeoutHandler_Logged_On_ResetSignals[] = { 0x7, 0x3, 0xe, 0xd, };
unsigned long g_xWLGeneric_Killing_Scrnsaver_Logged_On_ResetSignals[] = { 0x3, 0xe, 0xd, 0x2c, };
unsigned long g_xWLGeneric_TO_Disconnected_ResetSignals[] = { 0x23, 0x22, };
unsigned long g_xWLGeneric_Request_Change_Credz_ResetSignals[] = { 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_ChangingPassword_ResetSignals[] = { 0xd, 0x3, 0xe, 0x7, };
unsigned long g_xWLGeneric_PostChangeActions_ResetSignals[] = { 0x2c, 0x3, 0xe, 0xd, };
unsigned long g_xWLGeneric_Locked_ResetSignals[] = { 0xd, 0xe, 0x7, 0x6, 0x0, 0x1e, 0x1f, };
unsigned long g_xWLGeneric_LockScreen_ResetSignals[] = { 0xd, 0x3, 0xe, 0x7, 0x6, 0x29, };
unsigned long g_xWLGeneric_DisplayLegalNotice_Unlock_ResetSignals[] = { 0x3, 0xe, };
unsigned long g_xWLGeneric_Request_Unlock_Credz_ResetSignals[] = { 0x3, 0xe, 0xd, 0x24, 0x27, };
unsigned long g_xWLGeneric_Request_Web_Unlock_Credz_ResetSignals[] = { 0x3, 0xe, 0xd, 0x24, };
unsigned long g_xWLGeneric_Unlocking_ResetSignals[] = { 0x7, 0x3, 0xe, };
unsigned long g_xWLGeneric_Unlock_LogonUser_ResetSignals[] = { 0x7, 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_SequentialUnlockPrompt_ResetSignals[] = { 0x7, 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_Unlock_ReportFailedResult_ResetSignals[] = { 0x3, 0xe, 0xd, };
unsigned long g_xWLGeneric_SequentialLogonPrompt_Unlock_ResetSignals[] = { 0x7, 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_FindDestinationSession_Unlock_ResetSignals[] = { 0x7, 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_Request_UnlockChange_Credz_ResetSignals[] = { 0xd, 0x3, 0xe, };
unsigned long g_xWLGeneric_ChangingUnlockPassword_ResetSignals[] = { 0xd, 0x3, 0xe, 0x7, };
unsigned long g_xWLGeneric_TimeoutHandler_Locked_ResetSignals[] = { 0xe, 0x7, };
unsigned long g_xWLGeneric_Killing_Scrnsaver_Locked_ResetSignals[] = { 0x3, 0xe, 0xd, 0x2c, };
unsigned long g_xWLGeneric_PostUnlockActions_ResetSignals[] = { 0x2c, 0x1a, 0x1b, 0x1c, 0x23, 0x22, };
unsigned long g_xWLGeneric_Locked_Reconnect_ResetSignals[] = { 0xd, 0x3, 0xe, 0x7, 0x4, 0x5, 0x2c, 0x1a, 0x1b, 0x1c, 0x1d, 0x23, 0x22, };
unsigned long g_xWLGeneric_PowerTransition_Locked_ResetSignals[] = { 0x7, };
unsigned long g_xWLGeneric_Locked_Hibernating_ResetSignals[] = { 0x3, 0xe, 0xd, };
unsigned long g_xWLGeneric_ReconnectionUpdate_ResetSignals[] = { 0x23, 0x22, };
unsigned long g_xWLGeneric_DelayLock_ResetSignals[] = { 0x2c, 0x24, };

unsigned long WLGeneric_Start_Execute(_StateMachineCallContext *);
void WLGeneric_Start_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_NotifyCreateSession_Execute(_StateMachineCallContext *);
void WLGeneric_NotifyCreateSession_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Welcome_Execute(_StateMachineCallContext *);
void WLGeneric_Welcome_Exit(_StateMachineCallContext *);
void WLGeneric_Welcome_Return_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_TimeoutHandler_Welcome_Execute(_StateMachineCallContext *);
void WLGeneric_TimeoutHandler_Welcome_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Killing_Scrnsaver_Welcome_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_PowerTransition_Welcome_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_Welcome_Hibernating_Execute(_StateMachineCallContext *);
void WLGeneric_Welcome_Hibernating_Exit(_StateMachineCallContext *);
void WLGeneric_PowerTransition_ShowResumeMsg_Enter(_StateMachineCallContext *);
void WLGeneric_AccessNotifyAsSystem_Enter(_StateMachineCallContext *);
void WLGeneric_AccessNotifyAsUser_Enter(_StateMachineCallContext *);
void WLGeneric_AccessNotify_Enter(_StateMachineCallContext *);
void WLGeneric_DwmControl_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_DisplayLegalNotice_Execute(_StateMachineCallContext *);
void WLGeneric_DisplayLegalNotice_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Request_Logon_Credz_Execute(_StateMachineCallContext *);
void WLGeneric_Request_Logon_Credz_Exit(_StateMachineCallContext *);
void WLGeneric_Request_Logon_Credz_Return_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Authenticating_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_MPRLogonNotify_Execute(_StateMachineCallContext *);
void WLGeneric_MPRLogonNotify_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Logon_ReportSuccessResult_Execute(_StateMachineCallContext *);
void WLGeneric_Logon_ReportSuccessResult_Exit(_StateMachineCallContext *);
void WLGeneric_Logon_Checking_LastLogonPolicy_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Logon_ReportLastLogon_Execute(_StateMachineCallContext *);
void WLGeneric_Logon_ReportLastLogon_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Logon_ReportFailedResult_Execute(_StateMachineCallContext *);
void WLGeneric_Logon_ReportFailedResult_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_WaitForDisconnectAfterFailedAuth_Execute(_StateMachineCallContext *);
void WLGeneric_WaitForDisconnectAfterFailedAuth_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_SequentialLogonPrompt_Execute(_StateMachineCallContext *);
void WLGeneric_SequentialLogonPrompt_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_FindDestinationSession_Execute(_StateMachineCallContext *);
void WLGeneric_FindDestinationSession_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_NotifyLogon_Execute(_StateMachineCallContext *);
void WLGeneric_NotifyLogon_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_NotifyStartShell_Execute(_StateMachineCallContext *);
void WLGeneric_NotifyStartShell_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_ShellStartup_Execute(_StateMachineCallContext *);
void WLGeneric_ShellStartup_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Request_LogonChange_Credz_Execute(_StateMachineCallContext *);
void WLGeneric_Request_LogonChange_Credz_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_ChangingLogonPassword_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_MPRChangeLogonNotify_Execute(_StateMachineCallContext *);
void WLGeneric_MPRChangeLogonNotify_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_ChangeLogon_ReportResult_Execute(_StateMachineCallContext *);
void WLGeneric_ChangeLogon_ReportResult_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Logged_On_Execute(_StateMachineCallContext *);
void WLGeneric_Logged_On_Exit(_StateMachineCallContext *);
void WLGeneric_DelayedSwitchDesktop_Enter(_StateMachineCallContext *);
void WLGeneric_CredsAreStaleReminder_Enter(_StateMachineCallContext *);
void WLGeneric_CloudPasswordExpiredReminder_Enter(_StateMachineCallContext *);
void WLGeneric_NTLMIsDisabledReminder_Enter(_StateMachineCallContext *);
void WLGeneric_DifferentCredsAreRequiredReminder_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_PowerTransition_Logged_On_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_Logged_On_Hibernating_Execute(_StateMachineCallContext *);
void WLGeneric_Logged_On_Hibernating_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_InitiateLock_On_Resume_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_Logged_On_Resume_Execute(_StateMachineCallContext *);
void WLGeneric_Logged_On_Resume_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Locked_Resume_Execute(_StateMachineCallContext *);
void WLGeneric_Locked_Resume_Exit(_StateMachineCallContext *);
void WLGeneric_InitiateDisconnect_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Logged_On_Disconnected_Execute(_StateMachineCallContext *);
void WLGeneric_Logged_On_Disconnected_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_No_Unlock_Disconnected_Execute(_StateMachineCallContext *);
void WLGeneric_No_Unlock_Disconnected_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Logged_On_Reconnect_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_No_Unlock_Reconnect_Execute(_StateMachineCallContext *);
void WLGeneric_ShellRestart_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_CAD_Execute(_StateMachineCallContext *);
void WLGeneric_CAD_Exit(_StateMachineCallContext *);
void WLGeneric_CAD_Return_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_SecureCredUI_Operation_Execute(_StateMachineCallContext *);
void WLGeneric_SecureCredUI_Operation_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_StartSecureLua_Execute(_StateMachineCallContext *);
void WLGeneric_StartSecureLua_Exit(_StateMachineCallContext *);
void WLGeneric_ReadyForSecureLua_Enter(_StateMachineCallContext *);
void WLGeneric_HandleSecureLuaBeforeShell_Enter(_StateMachineCallContext *);
void WLGeneric_AbortPendingLuaRequest_Enter(_StateMachineCallContext *);
void WLGeneric_AppLauncher_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_TimeoutHandler_Logged_On_Execute(_StateMachineCallContext *);
void WLGeneric_TimeoutHandler_Logged_On_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Killing_Scrnsaver_Logged_On_Execute(_StateMachineCallContext *);
void WLGeneric_TO_Disconnected_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Request_Change_Credz_Execute(_StateMachineCallContext *);
void WLGeneric_Request_Change_Credz_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_ChangingPassword_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_MPRChangeNotify_Execute(_StateMachineCallContext *);
void WLGeneric_MPRChangeNotify_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Change_ReportResult_Execute(_StateMachineCallContext *);
void WLGeneric_Change_ReportResult_Exit(_StateMachineCallContext *);
void WLGeneric_PostChangeActions_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_InitiateLock_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_Locked_Execute(_StateMachineCallContext *);
void WLGeneric_Locked_Exit(_StateMachineCallContext *);
void WLGeneric_Locked_Return_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_LockScreen_Execute(_StateMachineCallContext *);
void WLGeneric_LockScreen_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_DisplayLegalNotice_Unlock_Execute(_StateMachineCallContext *);
void WLGeneric_DisplayLegalNotice_Unlock_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Request_Unlock_Credz_Execute(_StateMachineCallContext *);
void WLGeneric_Request_Unlock_Credz_Exit(_StateMachineCallContext *);
void WLGeneric_Request_Unlock_Credz_Return_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Request_Web_Unlock_Credz_Execute(_StateMachineCallContext *);
void WLGeneric_Request_Web_Unlock_Credz_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Unlocking_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_Unlock_LogonUser_Execute(_StateMachineCallContext *);
void WLGeneric_Unlock_LogonUser_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Unlock_ReportSuccessResult_Execute(_StateMachineCallContext *);
void WLGeneric_Unlock_ReportSuccessResult_Exit(_StateMachineCallContext *);
void WLGeneric_Unlock_Checking_LastLogonPolicy_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Unlock_ReportLastLogon_Execute(_StateMachineCallContext *);
void WLGeneric_Unlock_ReportLastLogon_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_SequentialUnlockPrompt_Execute(_StateMachineCallContext *);
void WLGeneric_SequentialUnlockPrompt_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Unlock_ReportFailedResult_Execute(_StateMachineCallContext *);
void WLGeneric_Unlock_ReportFailedResult_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_MPRLogonNotify_Unlock_Execute(_StateMachineCallContext *);
void WLGeneric_MPRLogonNotify_Unlock_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Logon_ReportSuccessResult_Unlock_Execute(_StateMachineCallContext *);
void WLGeneric_Logon_ReportSuccessResult_Unlock_Exit(_StateMachineCallContext *);
void WLGeneric_Logon_Checking_LastLogonPolicy_Unlock_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Logon_ReportLastLogon_Unlock_Execute(_StateMachineCallContext *);
void WLGeneric_Logon_ReportLastLogon_Unlock_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_SequentialLogonPrompt_Unlock_Execute(_StateMachineCallContext *);
void WLGeneric_SequentialLogonPrompt_Unlock_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_FindDestinationSession_Unlock_Execute(_StateMachineCallContext *);
void WLGeneric_FindDestinationSession_Unlock_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Request_UnlockChange_Credz_Execute(_StateMachineCallContext *);
void WLGeneric_Request_UnlockChange_Credz_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_ChangingUnlockPassword_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_MPRChangeUnlockNotify_Execute(_StateMachineCallContext *);
void WLGeneric_MPRChangeUnlockNotify_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_ChangeUnlock_ReportResult_Execute(_StateMachineCallContext *);
void WLGeneric_ChangeUnlock_ReportResult_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_TimeoutHandler_Locked_Execute(_StateMachineCallContext *);
void WLGeneric_TimeoutHandler_Locked_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Killing_Scrnsaver_Locked_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_PostUnlockActions_Execute(_StateMachineCallContext *);
void WLGeneric_CompleteLockRequest_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_Locked_Disconnected_Execute(_StateMachineCallContext *);
void WLGeneric_Locked_Disconnected_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_No_Unlock_DisconnectedLock_Execute(_StateMachineCallContext *);
void WLGeneric_No_Unlock_DisconnectedLock_Exit(_StateMachineCallContext *);
unsigned long WLGeneric_Locked_Reconnect_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_PowerTransition_Locked_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_Locked_Hibernating_Execute(_StateMachineCallContext *);
void WLGeneric_Locked_Hibernating_Exit(_StateMachineCallContext *);
void WLGeneric_AbortPendingLockRequest_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_ReconnectionUpdate_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_DelayLock_Execute(_StateMachineCallContext *);
void WLGeneric_DelayLock_Exit(_StateMachineCallContext *);
void WLGeneric_DelayLock_DisplayOffHandler_Enter(_StateMachineCallContext *);
void WLGeneric_DelayLock_DisplayOnHandler_Enter(_StateMachineCallContext *);
void WLGeneric_InitiateForceLogoff_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_NotifyEndShell_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_Logging_Off_Execute(_StateMachineCallContext *);
void WLGeneric_LogoffNotify_Enter(_StateMachineCallContext *);
unsigned long WLGeneric_PseudoLogging_Off1_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_PseudoLogging_Off2_Execute(_StateMachineCallContext *);
unsigned long WLGeneric_NotifyTerminateSession_Execute(_StateMachineCallContext *);

_StateMachineState g_xWLGeneric_Start_State = {
	L"Start",
	0,
	WLGeneric_Start_Execute,
	WLGeneric_Start_Exit,
	0x7,
	g_xWLGeneric_Start_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_NotifyCreateSession_State = {
	L"NotifyCreateSession",
	0,
	WLGeneric_NotifyCreateSession_Execute,
	WLGeneric_NotifyCreateSession_Exit,
	0x7,
	g_xWLGeneric_NotifyCreateSession_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Welcome_State = {
	L"Welcome",
	0,
	WLGeneric_Welcome_Execute,
	WLGeneric_Welcome_Exit,
	0x9,
	g_xWLGeneric_Welcome_Transition,
	0x4,
	g_xWLGeneric_Welcome_ResetSignals 
};

_StateMachineState g_xWLGeneric_Welcome_Return_State = {
	L"Welcome_Return",
	WLGeneric_Welcome_Return_Enter,
	0,
	0,
	0x2,
	g_xWLGeneric_Welcome_Return_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_TimeoutHandler_Welcome_State = {
	L"TimeoutHandler_Welcome",
	0,
	WLGeneric_TimeoutHandler_Welcome_Execute,
	WLGeneric_TimeoutHandler_Welcome_Exit,
	0x6,
	g_xWLGeneric_TimeoutHandler_Welcome_Transition,
	0x2,
	g_xWLGeneric_TimeoutHandler_Welcome_ResetSignals 
};

_StateMachineState g_xWLGeneric_Killing_Scrnsaver_Welcome_State = {
	L"Killing_Scrnsaver_Welcome",
	0,
	WLGeneric_Killing_Scrnsaver_Welcome_Execute,
	0,
	0x2,
	g_xWLGeneric_Killing_Scrnsaver_Welcome_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_PowerTransition_Welcome_State = {
	L"PowerTransition_Welcome",
	0,
	WLGeneric_PowerTransition_Welcome_Execute,
	0,
	0x1,
	g_xWLGeneric_PowerTransition_Welcome_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Welcome_Hibernating_State = {
	L"Welcome_Hibernating",
	0,
	WLGeneric_Welcome_Hibernating_Execute,
	WLGeneric_Welcome_Hibernating_Exit,
	0x2,
	g_xWLGeneric_Welcome_Hibernating_Transition,
	0x4,
	g_xWLGeneric_Welcome_Hibernating_ResetSignals 
};

_StateMachineState g_xWLGeneric_PowerTransition_ShowResumeMsg_State = {
	L"PowerTransition_ShowResumeMsg",
	WLGeneric_PowerTransition_ShowResumeMsg_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_PowerTransition_ShowResumeMsg_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_AccessNotifyAsSystem_State = {
	L"AccessNotifyAsSystem",
	WLGeneric_AccessNotifyAsSystem_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_AccessNotifyAsSystem_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_AccessNotifyAsUser_State = {
	L"AccessNotifyAsUser",
	WLGeneric_AccessNotifyAsUser_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_AccessNotifyAsUser_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_AccessNotify_State = {
	L"AccessNotify",
	WLGeneric_AccessNotify_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_AccessNotify_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_DwmControl_State = {
	L"DwmControl",
	WLGeneric_DwmControl_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_DwmControl_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_DisplayLegalNotice_State = {
	L"DisplayLegalNotice",
	0,
	WLGeneric_DisplayLegalNotice_Execute,
	WLGeneric_DisplayLegalNotice_Exit,
	0x8,
	g_xWLGeneric_DisplayLegalNotice_Transition,
	0x2,
	g_xWLGeneric_DisplayLegalNotice_ResetSignals 
};

_StateMachineState g_xWLGeneric_Request_Logon_Credz_State = {
	L"Request_Logon_Credz",
	0,
	WLGeneric_Request_Logon_Credz_Execute,
	WLGeneric_Request_Logon_Credz_Exit,
	0x9,
	g_xWLGeneric_Request_Logon_Credz_Transition,
	0x4,
	g_xWLGeneric_Request_Logon_Credz_ResetSignals 
};

_StateMachineState g_xWLGeneric_Request_Logon_Credz_Return_State = {
	L"Request_Logon_Credz_Return",
	WLGeneric_Request_Logon_Credz_Return_Enter,
	0,
	0,
	0x2,
	g_xWLGeneric_Request_Logon_Credz_Return_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Authenticating_State = {
	L"Authenticating",
	0,
	WLGeneric_Authenticating_Execute,
	0,
	0x3,
	g_xWLGeneric_Authenticating_Transition,
	0x1,
	g_xWLGeneric_Authenticating_ResetSignals 
};

_StateMachineState g_xWLGeneric_MPRLogonNotify_State = {
	L"MPRLogonNotify",
	0,
	WLGeneric_MPRLogonNotify_Execute,
	WLGeneric_MPRLogonNotify_Exit,
	0x2,
	g_xWLGeneric_MPRLogonNotify_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logon_ReportSuccessResult_State = {
	L"Logon_ReportSuccessResult",
	0,
	WLGeneric_Logon_ReportSuccessResult_Execute,
	WLGeneric_Logon_ReportSuccessResult_Exit,
	0x6,
	g_xWLGeneric_Logon_ReportSuccessResult_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logon_Checking_LastLogonPolicy_State = {
	L"Logon_Checking_LastLogonPolicy",
	WLGeneric_Logon_Checking_LastLogonPolicy_Enter,
	0,
	0,
	0x2,
	g_xWLGeneric_Logon_Checking_LastLogonPolicy_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logon_ReportLastLogon_State = {
	L"Logon_ReportLastLogon",
	0,
	WLGeneric_Logon_ReportLastLogon_Execute,
	WLGeneric_Logon_ReportLastLogon_Exit,
	0x9,
	g_xWLGeneric_Logon_ReportLastLogon_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logon_ReportFailedResult_State = {
	L"Logon_ReportFailedResult",
	0,
	WLGeneric_Logon_ReportFailedResult_Execute,
	WLGeneric_Logon_ReportFailedResult_Exit,
	0xa,
	g_xWLGeneric_Logon_ReportFailedResult_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_WaitForDisconnectAfterFailedAuth_State = {
	L"WaitForDisconnectAfterFailedAuth",
	0,
	WLGeneric_WaitForDisconnectAfterFailedAuth_Execute,
	WLGeneric_WaitForDisconnectAfterFailedAuth_Exit,
	0x1,
	g_xWLGeneric_WaitForDisconnectAfterFailedAuth_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_SequentialLogonPrompt_State = {
	L"SequentialLogonPrompt",
	0,
	WLGeneric_SequentialLogonPrompt_Execute,
	WLGeneric_SequentialLogonPrompt_Exit,
	0x9,
	g_xWLGeneric_SequentialLogonPrompt_Transition,
	0x4,
	g_xWLGeneric_SequentialLogonPrompt_ResetSignals 
};

_StateMachineState g_xWLGeneric_FindDestinationSession_State = {
	L"FindDestinationSession",
	0,
	WLGeneric_FindDestinationSession_Execute,
	WLGeneric_FindDestinationSession_Exit,
	0xa,
	g_xWLGeneric_FindDestinationSession_Transition,
	0x4,
	g_xWLGeneric_FindDestinationSession_ResetSignals 
};

_StateMachineState g_xWLGeneric_NotifyLogon_State = {
	L"NotifyLogon",
	0,
	WLGeneric_NotifyLogon_Execute,
	WLGeneric_NotifyLogon_Exit,
	0x7,
	g_xWLGeneric_NotifyLogon_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_NotifyStartShell_State = {
	L"NotifyStartShell",
	0,
	WLGeneric_NotifyStartShell_Execute,
	WLGeneric_NotifyStartShell_Exit,
	0xa,
	g_xWLGeneric_NotifyStartShell_Transition,
	0x1,
	g_xWLGeneric_NotifyStartShell_ResetSignals 
};

_StateMachineState g_xWLGeneric_ShellStartup_State = {
	L"ShellStartup",
	0,
	WLGeneric_ShellStartup_Execute,
	WLGeneric_ShellStartup_Exit,
	0x5,
	g_xWLGeneric_ShellStartup_Transition,
	0x2,
	g_xWLGeneric_ShellStartup_ResetSignals 
};

_StateMachineState g_xWLGeneric_Request_LogonChange_Credz_State = {
	L"Request_LogonChange_Credz",
	0,
	WLGeneric_Request_LogonChange_Credz_Execute,
	WLGeneric_Request_LogonChange_Credz_Exit,
	0x9,
	g_xWLGeneric_Request_LogonChange_Credz_Transition,
	0x3,
	g_xWLGeneric_Request_LogonChange_Credz_ResetSignals 
};

_StateMachineState g_xWLGeneric_ChangingLogonPassword_State = {
	L"ChangingLogonPassword",
	0,
	WLGeneric_ChangingLogonPassword_Execute,
	0,
	0x2,
	g_xWLGeneric_ChangingLogonPassword_Transition,
	0x4,
	g_xWLGeneric_ChangingLogonPassword_ResetSignals 
};

_StateMachineState g_xWLGeneric_MPRChangeLogonNotify_State = {
	L"MPRChangeLogonNotify",
	0,
	WLGeneric_MPRChangeLogonNotify_Execute,
	WLGeneric_MPRChangeLogonNotify_Exit,
	0x2,
	g_xWLGeneric_MPRChangeLogonNotify_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_ChangeLogon_ReportResult_State = {
	L"ChangeLogon_ReportResult",
	0,
	WLGeneric_ChangeLogon_ReportResult_Execute,
	WLGeneric_ChangeLogon_ReportResult_Exit,
	0x7,
	g_xWLGeneric_ChangeLogon_ReportResult_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logged_On_State = {
	L"Logged_On",
	0,
	WLGeneric_Logged_On_Execute,
	WLGeneric_Logged_On_Exit,
	0x17,
	g_xWLGeneric_Logged_On_Transition,
	0x5,
	g_xWLGeneric_Logged_On_ResetSignals 
};

_StateMachineState g_xWLGeneric_DelayedSwitchDesktop_State = {
	L"DelayedSwitchDesktop",
	WLGeneric_DelayedSwitchDesktop_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_DelayedSwitchDesktop_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_CredsAreStaleReminder_State = {
	L"CredsAreStaleReminder",
	WLGeneric_CredsAreStaleReminder_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_CredsAreStaleReminder_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_CloudPasswordExpiredReminder_State = {
	L"CloudPasswordExpiredReminder",
	WLGeneric_CloudPasswordExpiredReminder_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_CloudPasswordExpiredReminder_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_NTLMIsDisabledReminder_State = {
	L"NTLMIsDisabledReminder",
	WLGeneric_NTLMIsDisabledReminder_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_NTLMIsDisabledReminder_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_DifferentCredsAreRequiredReminder_State = {
	L"DifferentCredsAreRequiredReminder",
	WLGeneric_DifferentCredsAreRequiredReminder_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_DifferentCredsAreRequiredReminder_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_PowerTransition_Logged_On_State = {
	L"PowerTransition_Logged_On",
	0,
	WLGeneric_PowerTransition_Logged_On_Execute,
	0,
	0x1,
	g_xWLGeneric_PowerTransition_Logged_On_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logged_On_Hibernating_State = {
	L"Logged_On_Hibernating",
	0,
	WLGeneric_Logged_On_Hibernating_Execute,
	WLGeneric_Logged_On_Hibernating_Exit,
	0x3,
	g_xWLGeneric_Logged_On_Hibernating_Transition,
	0x1,
	g_xWLGeneric_Logged_On_Hibernating_ResetSignals 
};

_StateMachineState g_xWLGeneric_InitiateLock_On_Resume_State = {
	L"InitiateLock_On_Resume",
	0,
	WLGeneric_InitiateLock_On_Resume_Execute,
	0,
	0x2,
	g_xWLGeneric_InitiateLock_On_Resume_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logged_On_Resume_State = {
	L"Logged_On_Resume",
	0,
	WLGeneric_Logged_On_Resume_Execute,
	WLGeneric_Logged_On_Resume_Exit,
	0x3,
	g_xWLGeneric_Logged_On_Resume_Transition,
	0x2,
	g_xWLGeneric_Logged_On_Resume_ResetSignals 
};

_StateMachineState g_xWLGeneric_Locked_Resume_State = {
	L"Locked_Resume",
	0,
	WLGeneric_Locked_Resume_Execute,
	WLGeneric_Locked_Resume_Exit,
	0x3,
	g_xWLGeneric_Locked_Resume_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_InitiateDisconnect_State = {
	L"InitiateDisconnect",
	WLGeneric_InitiateDisconnect_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_InitiateDisconnect_Transition,
	0x4,
	g_xWLGeneric_InitiateDisconnect_ResetSignals 
};

_StateMachineState g_xWLGeneric_Logged_On_Disconnected_State = {
	L"Logged_On_Disconnected",
	0,
	WLGeneric_Logged_On_Disconnected_Execute,
	WLGeneric_Logged_On_Disconnected_Exit,
	0x4,
	g_xWLGeneric_Logged_On_Disconnected_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_No_Unlock_Disconnected_State = {
	L"No_Unlock_Disconnected",
	0,
	WLGeneric_No_Unlock_Disconnected_Execute,
	WLGeneric_No_Unlock_Disconnected_Exit,
	0x4,
	g_xWLGeneric_No_Unlock_Disconnected_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logged_On_Reconnect_State = {
	L"Logged_On_Reconnect",
	0,
	WLGeneric_Logged_On_Reconnect_Execute,
	0,
	0x1,
	g_xWLGeneric_Logged_On_Reconnect_Transition,
	0xd,
	g_xWLGeneric_Logged_On_Reconnect_ResetSignals 
};

_StateMachineState g_xWLGeneric_No_Unlock_Reconnect_State = {
	L"No_Unlock_Reconnect",
	0,
	WLGeneric_No_Unlock_Reconnect_Execute,
	0,
	0x1,
	g_xWLGeneric_No_Unlock_Reconnect_Transition,
	0xb,
	g_xWLGeneric_No_Unlock_Reconnect_ResetSignals 
};

_StateMachineState g_xWLGeneric_ShellRestart_State = {
	L"ShellRestart",
	WLGeneric_ShellRestart_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_ShellRestart_Transition,
	0x2,
	g_xWLGeneric_ShellRestart_ResetSignals 
};

_StateMachineState g_xWLGeneric_CAD_State = {
	L"CAD",
	0,
	WLGeneric_CAD_Execute,
	WLGeneric_CAD_Exit,
	0xf,
	g_xWLGeneric_CAD_Transition,
	0x4,
	g_xWLGeneric_CAD_ResetSignals 
};

_StateMachineState g_xWLGeneric_CAD_Return_State = {
	L"CAD_Return",
	WLGeneric_CAD_Return_Enter,
	0,
	0,
	0x8,
	g_xWLGeneric_CAD_Return_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_SecureCredUI_Operation_State = {
	L"SecureCredUI_Operation",
	0,
	WLGeneric_SecureCredUI_Operation_Execute,
	WLGeneric_SecureCredUI_Operation_Exit,
	0xa,
	g_xWLGeneric_SecureCredUI_Operation_Transition,
	0x2,
	g_xWLGeneric_SecureCredUI_Operation_ResetSignals 
};

_StateMachineState g_xWLGeneric_StartSecureLua_State = {
	L"StartSecureLua",
	0,
	WLGeneric_StartSecureLua_Execute,
	WLGeneric_StartSecureLua_Exit,
	0xe,
	g_xWLGeneric_StartSecureLua_Transition,
	0x3,
	g_xWLGeneric_StartSecureLua_ResetSignals 
};

_StateMachineState g_xWLGeneric_ReadyForSecureLua_State = {
	L"ReadyForSecureLua",
	WLGeneric_ReadyForSecureLua_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_ReadyForSecureLua_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_HandleSecureLuaBeforeShell_State = {
	L"HandleSecureLuaBeforeShell",
	WLGeneric_HandleSecureLuaBeforeShell_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_HandleSecureLuaBeforeShell_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_AbortPendingLuaRequest_State = {
	L"AbortPendingLuaRequest",
	WLGeneric_AbortPendingLuaRequest_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_AbortPendingLuaRequest_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_AppLauncher_State = {
	L"AppLauncher",
	WLGeneric_AppLauncher_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_AppLauncher_Transition,
	0x2,
	g_xWLGeneric_AppLauncher_ResetSignals 
};

_StateMachineState g_xWLGeneric_TimeoutHandler_Logged_On_State = {
	L"TimeoutHandler_Logged_On",
	0,
	WLGeneric_TimeoutHandler_Logged_On_Execute,
	WLGeneric_TimeoutHandler_Logged_On_Exit,
	0x8,
	g_xWLGeneric_TimeoutHandler_Logged_On_Transition,
	0x4,
	g_xWLGeneric_TimeoutHandler_Logged_On_ResetSignals 
};

_StateMachineState g_xWLGeneric_Killing_Scrnsaver_Logged_On_State = {
	L"Killing_Scrnsaver_Logged_On",
	0,
	WLGeneric_Killing_Scrnsaver_Logged_On_Execute,
	0,
	0x2,
	g_xWLGeneric_Killing_Scrnsaver_Logged_On_Transition,
	0x4,
	g_xWLGeneric_Killing_Scrnsaver_Logged_On_ResetSignals 
};

_StateMachineState g_xWLGeneric_TO_Disconnected_State = {
	L"TO_Disconnected",
	WLGeneric_TO_Disconnected_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_TO_Disconnected_Transition,
	0x2,
	g_xWLGeneric_TO_Disconnected_ResetSignals 
};

_StateMachineState g_xWLGeneric_Request_Change_Credz_State = {
	L"Request_Change_Credz",
	0,
	WLGeneric_Request_Change_Credz_Execute,
	WLGeneric_Request_Change_Credz_Exit,
	0xd,
	g_xWLGeneric_Request_Change_Credz_Transition,
	0x3,
	g_xWLGeneric_Request_Change_Credz_ResetSignals 
};

_StateMachineState g_xWLGeneric_ChangingPassword_State = {
	L"ChangingPassword",
	0,
	WLGeneric_ChangingPassword_Execute,
	0,
	0x2,
	g_xWLGeneric_ChangingPassword_Transition,
	0x4,
	g_xWLGeneric_ChangingPassword_ResetSignals 
};

_StateMachineState g_xWLGeneric_MPRChangeNotify_State = {
	L"MPRChangeNotify",
	0,
	WLGeneric_MPRChangeNotify_Execute,
	WLGeneric_MPRChangeNotify_Exit,
	0x2,
	g_xWLGeneric_MPRChangeNotify_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Change_ReportResult_State = {
	L"Change_ReportResult",
	0,
	WLGeneric_Change_ReportResult_Execute,
	WLGeneric_Change_ReportResult_Exit,
	0xa,
	g_xWLGeneric_Change_ReportResult_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_PostChangeActions_State = {
	L"PostChangeActions",
	WLGeneric_PostChangeActions_Enter,
	0,
	0,
	0x8,
	g_xWLGeneric_PostChangeActions_Transition,
	0x4,
	g_xWLGeneric_PostChangeActions_ResetSignals 
};

_StateMachineState g_xWLGeneric_InitiateLock_State = {
	L"InitiateLock",
	0,
	WLGeneric_InitiateLock_Execute,
	0,
	0x2,
	g_xWLGeneric_InitiateLock_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Locked_State = {
	L"Locked",
	0,
	WLGeneric_Locked_Execute,
	WLGeneric_Locked_Exit,
	0x8,
	g_xWLGeneric_Locked_Transition,
	0x7,
	g_xWLGeneric_Locked_ResetSignals 
};

_StateMachineState g_xWLGeneric_Locked_Return_State = {
	L"Locked_Return",
	WLGeneric_Locked_Return_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_Locked_Return_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_LockScreen_State = {
	L"LockScreen",
	0,
	WLGeneric_LockScreen_Execute,
	WLGeneric_LockScreen_Exit,
	0xc,
	g_xWLGeneric_LockScreen_Transition,
	0x6,
	g_xWLGeneric_LockScreen_ResetSignals 
};

_StateMachineState g_xWLGeneric_DisplayLegalNotice_Unlock_State = {
	L"DisplayLegalNotice_Unlock",
	0,
	WLGeneric_DisplayLegalNotice_Unlock_Execute,
	WLGeneric_DisplayLegalNotice_Unlock_Exit,
	0x8,
	g_xWLGeneric_DisplayLegalNotice_Unlock_Transition,
	0x2,
	g_xWLGeneric_DisplayLegalNotice_Unlock_ResetSignals 
};

_StateMachineState g_xWLGeneric_Request_Unlock_Credz_State = {
	L"Request_Unlock_Credz",
	0,
	WLGeneric_Request_Unlock_Credz_Execute,
	WLGeneric_Request_Unlock_Credz_Exit,
	0xc,
	g_xWLGeneric_Request_Unlock_Credz_Transition,
	0x5,
	g_xWLGeneric_Request_Unlock_Credz_ResetSignals 
};

_StateMachineState g_xWLGeneric_Request_Unlock_Credz_Return_State = {
	L"Request_Unlock_Credz_Return",
	WLGeneric_Request_Unlock_Credz_Return_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_Request_Unlock_Credz_Return_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Request_Web_Unlock_Credz_State = {
	L"Request_Web_Unlock_Credz",
	0,
	WLGeneric_Request_Web_Unlock_Credz_Execute,
	WLGeneric_Request_Web_Unlock_Credz_Exit,
	0xc,
	g_xWLGeneric_Request_Web_Unlock_Credz_Transition,
	0x4,
	g_xWLGeneric_Request_Web_Unlock_Credz_ResetSignals 
};

_StateMachineState g_xWLGeneric_Unlocking_State = {
	L"Unlocking",
	0,
	WLGeneric_Unlocking_Execute,
	0,
	0x4,
	g_xWLGeneric_Unlocking_Transition,
	0x3,
	g_xWLGeneric_Unlocking_ResetSignals 
};

_StateMachineState g_xWLGeneric_Unlock_LogonUser_State = {
	L"Unlock_LogonUser",
	0,
	WLGeneric_Unlock_LogonUser_Execute,
	WLGeneric_Unlock_LogonUser_Exit,
	0x8,
	g_xWLGeneric_Unlock_LogonUser_Transition,
	0x4,
	g_xWLGeneric_Unlock_LogonUser_ResetSignals 
};

_StateMachineState g_xWLGeneric_Unlock_ReportSuccessResult_State = {
	L"Unlock_ReportSuccessResult",
	0,
	WLGeneric_Unlock_ReportSuccessResult_Execute,
	WLGeneric_Unlock_ReportSuccessResult_Exit,
	0x8,
	g_xWLGeneric_Unlock_ReportSuccessResult_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Unlock_Checking_LastLogonPolicy_State = {
	L"Unlock_Checking_LastLogonPolicy",
	WLGeneric_Unlock_Checking_LastLogonPolicy_Enter,
	0,
	0,
	0x2,
	g_xWLGeneric_Unlock_Checking_LastLogonPolicy_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Unlock_ReportLastLogon_State = {
	L"Unlock_ReportLastLogon",
	0,
	WLGeneric_Unlock_ReportLastLogon_Execute,
	WLGeneric_Unlock_ReportLastLogon_Exit,
	0x9,
	g_xWLGeneric_Unlock_ReportLastLogon_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_SequentialUnlockPrompt_State = {
	L"SequentialUnlockPrompt",
	0,
	WLGeneric_SequentialUnlockPrompt_Execute,
	WLGeneric_SequentialUnlockPrompt_Exit,
	0x9,
	g_xWLGeneric_SequentialUnlockPrompt_Transition,
	0x4,
	g_xWLGeneric_SequentialUnlockPrompt_ResetSignals 
};

_StateMachineState g_xWLGeneric_Unlock_ReportFailedResult_State = {
	L"Unlock_ReportFailedResult",
	0,
	WLGeneric_Unlock_ReportFailedResult_Execute,
	WLGeneric_Unlock_ReportFailedResult_Exit,
	0xa,
	g_xWLGeneric_Unlock_ReportFailedResult_Transition,
	0x3,
	g_xWLGeneric_Unlock_ReportFailedResult_ResetSignals 
};

_StateMachineState g_xWLGeneric_MPRLogonNotify_Unlock_State = {
	L"MPRLogonNotify_Unlock",
	0,
	WLGeneric_MPRLogonNotify_Unlock_Execute,
	WLGeneric_MPRLogonNotify_Unlock_Exit,
	0x2,
	g_xWLGeneric_MPRLogonNotify_Unlock_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logon_ReportSuccessResult_Unlock_State = {
	L"Logon_ReportSuccessResult_Unlock",
	0,
	WLGeneric_Logon_ReportSuccessResult_Unlock_Execute,
	WLGeneric_Logon_ReportSuccessResult_Unlock_Exit,
	0x6,
	g_xWLGeneric_Logon_ReportSuccessResult_Unlock_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logon_Checking_LastLogonPolicy_Unlock_State = {
	L"Logon_Checking_LastLogonPolicy_Unlock",
	WLGeneric_Logon_Checking_LastLogonPolicy_Unlock_Enter,
	0,
	0,
	0x2,
	g_xWLGeneric_Logon_Checking_LastLogonPolicy_Unlock_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logon_ReportLastLogon_Unlock_State = {
	L"Logon_ReportLastLogon_Unlock",
	0,
	WLGeneric_Logon_ReportLastLogon_Unlock_Execute,
	WLGeneric_Logon_ReportLastLogon_Unlock_Exit,
	0x9,
	g_xWLGeneric_Logon_ReportLastLogon_Unlock_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_SequentialLogonPrompt_Unlock_State = {
	L"SequentialLogonPrompt_Unlock",
	0,
	WLGeneric_SequentialLogonPrompt_Unlock_Execute,
	WLGeneric_SequentialLogonPrompt_Unlock_Exit,
	0x9,
	g_xWLGeneric_SequentialLogonPrompt_Unlock_Transition,
	0x4,
	g_xWLGeneric_SequentialLogonPrompt_Unlock_ResetSignals 
};

_StateMachineState g_xWLGeneric_FindDestinationSession_Unlock_State = {
	L"FindDestinationSession_Unlock",
	0,
	WLGeneric_FindDestinationSession_Unlock_Execute,
	WLGeneric_FindDestinationSession_Unlock_Exit,
	0x9,
	g_xWLGeneric_FindDestinationSession_Unlock_Transition,
	0x4,
	g_xWLGeneric_FindDestinationSession_Unlock_ResetSignals 
};

_StateMachineState g_xWLGeneric_Request_UnlockChange_Credz_State = {
	L"Request_UnlockChange_Credz",
	0,
	WLGeneric_Request_UnlockChange_Credz_Execute,
	WLGeneric_Request_UnlockChange_Credz_Exit,
	0x9,
	g_xWLGeneric_Request_UnlockChange_Credz_Transition,
	0x3,
	g_xWLGeneric_Request_UnlockChange_Credz_ResetSignals 
};

_StateMachineState g_xWLGeneric_ChangingUnlockPassword_State = {
	L"ChangingUnlockPassword",
	0,
	WLGeneric_ChangingUnlockPassword_Execute,
	0,
	0x2,
	g_xWLGeneric_ChangingUnlockPassword_Transition,
	0x4,
	g_xWLGeneric_ChangingUnlockPassword_ResetSignals 
};

_StateMachineState g_xWLGeneric_MPRChangeUnlockNotify_State = {
	L"MPRChangeUnlockNotify",
	0,
	WLGeneric_MPRChangeUnlockNotify_Execute,
	WLGeneric_MPRChangeUnlockNotify_Exit,
	0x2,
	g_xWLGeneric_MPRChangeUnlockNotify_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_ChangeUnlock_ReportResult_State = {
	L"ChangeUnlock_ReportResult",
	0,
	WLGeneric_ChangeUnlock_ReportResult_Execute,
	WLGeneric_ChangeUnlock_ReportResult_Exit,
	0x7,
	g_xWLGeneric_ChangeUnlock_ReportResult_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_TimeoutHandler_Locked_State = {
	L"TimeoutHandler_Locked",
	0,
	WLGeneric_TimeoutHandler_Locked_Execute,
	WLGeneric_TimeoutHandler_Locked_Exit,
	0x7,
	g_xWLGeneric_TimeoutHandler_Locked_Transition,
	0x2,
	g_xWLGeneric_TimeoutHandler_Locked_ResetSignals 
};

_StateMachineState g_xWLGeneric_Killing_Scrnsaver_Locked_State = {
	L"Killing_Scrnsaver_Locked",
	0,
	WLGeneric_Killing_Scrnsaver_Locked_Execute,
	0,
	0x2,
	g_xWLGeneric_Killing_Scrnsaver_Locked_Transition,
	0x4,
	g_xWLGeneric_Killing_Scrnsaver_Locked_ResetSignals 
};

_StateMachineState g_xWLGeneric_PostUnlockActions_State = {
	L"PostUnlockActions",
	0,
	WLGeneric_PostUnlockActions_Execute,
	0,
	0x2,
	g_xWLGeneric_PostUnlockActions_Transition,
	0x6,
	g_xWLGeneric_PostUnlockActions_ResetSignals 
};

_StateMachineState g_xWLGeneric_CompleteLockRequest_State = {
	L"CompleteLockRequest",
	WLGeneric_CompleteLockRequest_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_CompleteLockRequest_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Locked_Disconnected_State = {
	L"Locked_Disconnected",
	0,
	WLGeneric_Locked_Disconnected_Execute,
	WLGeneric_Locked_Disconnected_Exit,
	0x4,
	g_xWLGeneric_Locked_Disconnected_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_No_Unlock_DisconnectedLock_State = {
	L"No_Unlock_DisconnectedLock",
	0,
	WLGeneric_No_Unlock_DisconnectedLock_Execute,
	WLGeneric_No_Unlock_DisconnectedLock_Exit,
	0x4,
	g_xWLGeneric_No_Unlock_DisconnectedLock_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Locked_Reconnect_State = {
	L"Locked_Reconnect",
	0,
	WLGeneric_Locked_Reconnect_Execute,
	0,
	0x1,
	g_xWLGeneric_Locked_Reconnect_Transition,
	0xd,
	g_xWLGeneric_Locked_Reconnect_ResetSignals 
};

_StateMachineState g_xWLGeneric_PowerTransition_Locked_State = {
	L"PowerTransition_Locked",
	0,
	WLGeneric_PowerTransition_Locked_Execute,
	0,
	0x1,
	g_xWLGeneric_PowerTransition_Locked_Transition,
	0x1,
	g_xWLGeneric_PowerTransition_Locked_ResetSignals 
};

_StateMachineState g_xWLGeneric_Locked_Hibernating_State = {
	L"Locked_Hibernating",
	0,
	WLGeneric_Locked_Hibernating_Execute,
	WLGeneric_Locked_Hibernating_Exit,
	0x3,
	g_xWLGeneric_Locked_Hibernating_Transition,
	0x3,
	g_xWLGeneric_Locked_Hibernating_ResetSignals 
};

_StateMachineState g_xWLGeneric_AbortPendingLockRequest_State = {
	L"AbortPendingLockRequest",
	WLGeneric_AbortPendingLockRequest_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_AbortPendingLockRequest_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_ReconnectionUpdate_State = {
	L"ReconnectionUpdate",
	0,
	WLGeneric_ReconnectionUpdate_Execute,
	0,
	0x1,
	g_xWLGeneric_ReconnectionUpdate_Transition,
	0x2,
	g_xWLGeneric_ReconnectionUpdate_ResetSignals 
};

_StateMachineState g_xWLGeneric_DelayLock_State = {
	L"DelayLock",
	0,
	WLGeneric_DelayLock_Execute,
	WLGeneric_DelayLock_Exit,
	0xd,
	g_xWLGeneric_DelayLock_Transition,
	0x2,
	g_xWLGeneric_DelayLock_ResetSignals 
};

_StateMachineState g_xWLGeneric_DelayLock_DisplayOffHandler_State = {
	L"DelayLock_DisplayOffHandler",
	WLGeneric_DelayLock_DisplayOffHandler_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_DelayLock_DisplayOffHandler_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_DelayLock_DisplayOnHandler_State = {
	L"DelayLock_DisplayOnHandler",
	WLGeneric_DelayLock_DisplayOnHandler_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_DelayLock_DisplayOnHandler_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_InitiateForceLogoff_State = {
	L"InitiateForceLogoff",
	WLGeneric_InitiateForceLogoff_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_InitiateForceLogoff_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_NotifyEndShell_State = {
	L"NotifyEndShell",
	0,
	WLGeneric_NotifyEndShell_Execute,
	0,
	0x1,
	g_xWLGeneric_NotifyEndShell_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_Logging_Off_State = {
	L"Logging_Off",
	0,
	WLGeneric_Logging_Off_Execute,
	0,
	0x4,
	g_xWLGeneric_Logging_Off_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_LogoffNotify_State = {
	L"LogoffNotify",
	WLGeneric_LogoffNotify_Enter,
	0,
	0,
	0x1,
	g_xWLGeneric_LogoffNotify_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_PseudoLogging_Off1_State = {
	L"PseudoLogging_Off1",
	0,
	WLGeneric_PseudoLogging_Off1_Execute,
	0,
	0x1,
	g_xWLGeneric_PseudoLogging_Off1_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_PseudoLogging_Off2_State = {
	L"PseudoLogging_Off2",
	0,
	WLGeneric_PseudoLogging_Off2_Execute,
	0,
	0x2,
	g_xWLGeneric_PseudoLogging_Off2_Transition,
	0x0,
	0 
};

_StateMachineState g_xWLGeneric_NotifyTerminateSession_State = {
	L"NotifyTerminateSession",
	0,
	WLGeneric_NotifyTerminateSession_Execute,
	0,
	0x2,
	g_xWLGeneric_NotifyTerminateSession_Transition,
	0x0,
	0 
};


const _StateMachineState * g_rpWLGeneric_States[] = {

	&g_xWLGeneric_Start_State, // [0x0]
	&g_xWLGeneric_NotifyCreateSession_State, // [0x1]
	&g_xWLGeneric_Welcome_State, // [0x2]
	&g_xWLGeneric_Welcome_Return_State, // [0x3]
	&g_xWLGeneric_TimeoutHandler_Welcome_State, // [0x4]
	&g_xWLGeneric_Killing_Scrnsaver_Welcome_State, // [0x5]
	&g_xWLGeneric_PowerTransition_Welcome_State, // [0x6]
	&g_xWLGeneric_Welcome_Hibernating_State, // [0x7]
	&g_xWLGeneric_PowerTransition_ShowResumeMsg_State, // [0x8]
	&g_xWLGeneric_AccessNotifyAsSystem_State, // [0x9]
	&g_xWLGeneric_AccessNotifyAsUser_State, // [0xa]
	&g_xWLGeneric_AccessNotify_State, // [0xb]
	&g_xWLGeneric_DwmControl_State, // [0xc]
	&g_xWLGeneric_DisplayLegalNotice_State, // [0xd]
	&g_xWLGeneric_Request_Logon_Credz_State, // [0xe]
	&g_xWLGeneric_Request_Logon_Credz_Return_State, // [0xf]
	&g_xWLGeneric_Authenticating_State, // [0x10]
	&g_xWLGeneric_MPRLogonNotify_State, // [0x11]
	&g_xWLGeneric_Logon_ReportSuccessResult_State, // [0x12]
	&g_xWLGeneric_Logon_Checking_LastLogonPolicy_State, // [0x13]
	&g_xWLGeneric_Logon_ReportLastLogon_State, // [0x14]
	&g_xWLGeneric_Logon_ReportFailedResult_State, // [0x15]
	&g_xWLGeneric_WaitForDisconnectAfterFailedAuth_State, // [0x16]
	&g_xWLGeneric_SequentialLogonPrompt_State, // [0x17]
	&g_xWLGeneric_FindDestinationSession_State, // [0x18]
	&g_xWLGeneric_NotifyLogon_State, // [0x19]
	&g_xWLGeneric_NotifyStartShell_State, // [0x1a]
	&g_xWLGeneric_ShellStartup_State, // [0x1b]
	&g_xWLGeneric_Request_LogonChange_Credz_State, // [0x1c]
	&g_xWLGeneric_ChangingLogonPassword_State, // [0x1d]
	&g_xWLGeneric_MPRChangeLogonNotify_State, // [0x1e]
	&g_xWLGeneric_ChangeLogon_ReportResult_State, // [0x1f]
	&g_xWLGeneric_Logged_On_State, // [0x20]
	&g_xWLGeneric_DelayedSwitchDesktop_State, // [0x21]
	&g_xWLGeneric_CredsAreStaleReminder_State, // [0x22]
	&g_xWLGeneric_CloudPasswordExpiredReminder_State, // [0x23]
	&g_xWLGeneric_NTLMIsDisabledReminder_State, // [0x24]
	&g_xWLGeneric_DifferentCredsAreRequiredReminder_State, // [0x25]
	&g_xWLGeneric_PowerTransition_Logged_On_State, // [0x26]
	&g_xWLGeneric_Logged_On_Hibernating_State, // [0x27]
	&g_xWLGeneric_InitiateLock_On_Resume_State, // [0x28]
	&g_xWLGeneric_Logged_On_Resume_State, // [0x29]
	&g_xWLGeneric_Locked_Resume_State, // [0x2a]
	&g_xWLGeneric_InitiateDisconnect_State, // [0x2b]
	&g_xWLGeneric_Logged_On_Disconnected_State, // [0x2c]
	&g_xWLGeneric_No_Unlock_Disconnected_State, // [0x2d]
	&g_xWLGeneric_Logged_On_Reconnect_State, // [0x2e]
	&g_xWLGeneric_No_Unlock_Reconnect_State, // [0x2f]
	&g_xWLGeneric_ShellRestart_State, // [0x30]
	&g_xWLGeneric_CAD_State, // [0x31]
	&g_xWLGeneric_CAD_Return_State, // [0x32]
	&g_xWLGeneric_SecureCredUI_Operation_State, // [0x33]
	&g_xWLGeneric_StartSecureLua_State, // [0x34]
	&g_xWLGeneric_ReadyForSecureLua_State, // [0x35]
	&g_xWLGeneric_HandleSecureLuaBeforeShell_State, // [0x36]
	&g_xWLGeneric_AbortPendingLuaRequest_State, // [0x37]
	&g_xWLGeneric_AppLauncher_State, // [0x38]
	&g_xWLGeneric_TimeoutHandler_Logged_On_State, // [0x39]
	&g_xWLGeneric_Killing_Scrnsaver_Logged_On_State, // [0x3a]
	&g_xWLGeneric_TO_Disconnected_State, // [0x3b]
	&g_xWLGeneric_Request_Change_Credz_State, // [0x3c]
	&g_xWLGeneric_ChangingPassword_State, // [0x3d]
	&g_xWLGeneric_MPRChangeNotify_State, // [0x3e]
	&g_xWLGeneric_Change_ReportResult_State, // [0x3f]
	&g_xWLGeneric_PostChangeActions_State, // [0x40]
	&g_xWLGeneric_InitiateLock_State, // [0x41]
	&g_xWLGeneric_Locked_State, // [0x42]
	&g_xWLGeneric_Locked_Return_State, // [0x43]
	&g_xWLGeneric_LockScreen_State, // [0x44]
	&g_xWLGeneric_DisplayLegalNotice_Unlock_State, // [0x45]
	&g_xWLGeneric_Request_Unlock_Credz_State, // [0x46]
	&g_xWLGeneric_Request_Unlock_Credz_Return_State, // [0x47]
	&g_xWLGeneric_Request_Web_Unlock_Credz_State, // [0x48]
	&g_xWLGeneric_Unlocking_State, // [0x49]
	&g_xWLGeneric_Unlock_LogonUser_State, // [0x4a]
	&g_xWLGeneric_Unlock_ReportSuccessResult_State, // [0x4b]
	&g_xWLGeneric_Unlock_Checking_LastLogonPolicy_State, // [0x4c]
	&g_xWLGeneric_Unlock_ReportLastLogon_State, // [0x4d]
	&g_xWLGeneric_SequentialUnlockPrompt_State, // [0x4e]
	&g_xWLGeneric_Unlock_ReportFailedResult_State, // [0x4f]
	&g_xWLGeneric_MPRLogonNotify_Unlock_State, // [0x50]
	&g_xWLGeneric_Logon_ReportSuccessResult_Unlock_State, // [0x51]
	&g_xWLGeneric_Logon_Checking_LastLogonPolicy_Unlock_State, // [0x52]
	&g_xWLGeneric_Logon_ReportLastLogon_Unlock_State, // [0x53]
	&g_xWLGeneric_SequentialLogonPrompt_Unlock_State, // [0x54]
	&g_xWLGeneric_FindDestinationSession_Unlock_State, // [0x55]
	&g_xWLGeneric_Request_UnlockChange_Credz_State, // [0x56]
	&g_xWLGeneric_ChangingUnlockPassword_State, // [0x57]
	&g_xWLGeneric_MPRChangeUnlockNotify_State, // [0x58]
	&g_xWLGeneric_ChangeUnlock_ReportResult_State, // [0x59]
	&g_xWLGeneric_TimeoutHandler_Locked_State, // [0x5a]
	&g_xWLGeneric_Killing_Scrnsaver_Locked_State, // [0x5b]
	&g_xWLGeneric_PostUnlockActions_State, // [0x5c]
	&g_xWLGeneric_CompleteLockRequest_State, // [0x5d]
	&g_xWLGeneric_Locked_Disconnected_State, // [0x5e]
	&g_xWLGeneric_No_Unlock_DisconnectedLock_State, // [0x5f]
	&g_xWLGeneric_Locked_Reconnect_State, // [0x60]
	&g_xWLGeneric_PowerTransition_Locked_State, // [0x61]
	&g_xWLGeneric_Locked_Hibernating_State, // [0x62]
	&g_xWLGeneric_AbortPendingLockRequest_State, // [0x63]
	&g_xWLGeneric_ReconnectionUpdate_State, // [0x64]
	&g_xWLGeneric_DelayLock_State, // [0x65]
	&g_xWLGeneric_DelayLock_DisplayOffHandler_State, // [0x66]
	&g_xWLGeneric_DelayLock_DisplayOnHandler_State, // [0x67]
	&g_xWLGeneric_InitiateForceLogoff_State, // [0x68]
	&g_xWLGeneric_NotifyEndShell_State, // [0x69]
	&g_xWLGeneric_Logging_Off_State, // [0x6a]
	&g_xWLGeneric_LogoffNotify_State, // [0x6b]
	&g_xWLGeneric_PseudoLogging_Off1_State, // [0x6c]
	&g_xWLGeneric_PseudoLogging_Off2_State, // [0x6d]
	&g_xWLGeneric_NotifyTerminateSession_State, // [0x6e]
};

_StateMachineSignal g_xAction_Succeeded_Signal = { L"Action_Succeeded", 1 };
_StateMachineSignal g_xAction_Failed_Signal = { L"Action_Failed", 1 };
_StateMachineSignal g_xLogoff_NtUserCompleted_Signal = { L"Logoff_NtUserCompleted", 0 };
_StateMachineSignal g_xWinsrv_Sas_Signal = { L"Winsrv_Sas", 0 };
_StateMachineSignal g_xWinsrv_PowerMsgShow_Signal = { L"Winsrv_PowerMsgShow", 0 };
_StateMachineSignal g_xWinsrv_PowerMsgHide_Signal = { L"Winsrv_PowerMsgHide", 0 };
_StateMachineSignal g_xWinsrv_PowerResumeShow_Signal = { L"Winsrv_PowerResumeShow", 0 };
_StateMachineSignal g_xWinsrv_Timeout_Signal = { L"Winsrv_Timeout", 0 };
_StateMachineSignal g_xWinsrv_LogoffNotify_Signal = { L"Winsrv_LogoffNotify", 0 };
_StateMachineSignal g_xWinsrv_AccessNotify_Signal = { L"Winsrv_AccessNotify", 0 };
_StateMachineSignal g_xWinsrv_ShellRestart_Signal = { L"Winsrv_ShellRestart", 0 };
_StateMachineSignal g_xWinsrv_DwmControl_Signal = { L"Winsrv_DwmControl", 0 };
_StateMachineSignal g_xWinsrv_Lock_Signal = { L"Winsrv_Lock", 2 };
_StateMachineSignal g_xWinsrv_WinL_Signal = { L"Winsrv_WinL", 0 };
_StateMachineSignal g_xWinsrv_Kill_Scrnsaver_Signal = { L"Winsrv_Kill_Scrnsaver", 0 };
_StateMachineSignal g_xSecure_Request_Signal = { L"Secure_Request", 0 };
_StateMachineSignal g_xSecure_LuaStart_Signal = { L"Secure_LuaStart", 0 };
_StateMachineSignal g_xSecure_LuaReady_Signal = { L"Secure_LuaReady", 2 };
_StateMachineSignal g_xSecure_LuaEnd_Signal = { L"Secure_LuaEnd", 0 };
_StateMachineSignal g_xTS_Disconnected_Signal = { L"TS_Disconnected", 0 };
_StateMachineSignal g_xTS_Reconnected_Signal = { L"TS_Reconnected", 0 };
_StateMachineSignal g_xTS_PreConnect_Signal = { L"TS_PreConnect", 0 };
_StateMachineSignal g_xTS_NoUnlockReconnect_Signal = { L"TS_NoUnlockReconnect", 0 };
_StateMachineSignal g_xTS_RevertBack_Signal = { L"TS_RevertBack", 0 };
_StateMachineSignal g_xTS_SessionCreateFailed_Signal = { L"TS_SessionCreateFailed", 1 };
_StateMachineSignal g_xWl_ReconnectionUpdate_Signal = { L"Wl_ReconnectionUpdate", 0 };
_StateMachineSignal g_xWl_CredsAreStale_Signal = { L"Wl_CredsAreStale", 0 };
_StateMachineSignal g_xWl_CloudPasswordExpired_Signal = { L"Wl_CloudPasswordExpired", 0 };
_StateMachineSignal g_xWl_NTLMIsDisabled_Signal = { L"Wl_NTLMIsDisabled", 0 };
_StateMachineSignal g_xWl_DifferentCredsAreRequired_Signal = { L"Wl_DifferentCredsAreRequired", 0 };
_StateMachineSignal g_xWl_DelayedSwitchDesktop_Signal = { L"Wl_DelayedSwitchDesktop", 0 };
_StateMachineSignal g_xWl_ShellReadyOrTimedOut_Signal = { L"Wl_ShellReadyOrTimedOut", 0 };
_StateMachineSignal g_xMPR_Notify_Signal = { L"MPR_Notify", 1 };
_StateMachineSignal g_xWl_LogonFromUnlock_Signal = { L"Wl_LogonFromUnlock", 1 };
_StateMachineSignal g_xWl_DisplayOff_Signal = { L"Wl_DisplayOff", 0 };
_StateMachineSignal g_xWl_DisplayOn_Signal = { L"Wl_DisplayOn", 0 };
_StateMachineSignal g_xWl_HubScreen_Signal = { L"Wl_HubScreen", 0 };
_StateMachineSignal g_xWLGeneric_LogonUI_Ok_Signal = { L"LogonUI_Ok", 1 };
_StateMachineSignal g_xWLGeneric_LogonUI_Cancel_Signal = { L"LogonUI_Cancel", 1 };
_StateMachineSignal g_xWLGeneric_LogonUI_WebUnlock_Signal = { L"LogonUI_WebUnlock", 1 };
_StateMachineSignal g_xWLGeneric_Input_Timeout_Signal = { L"Input_Timeout", 1 };
_StateMachineSignal g_xWLGeneric_SasDisabled_Signal = { L"SasDisabled", 1 };
_StateMachineSignal g_xWLGeneric_NoRetryAllowed_Signal = { L"NoRetryAllowed", 1 };
_StateMachineSignal g_xWLGeneric_NoRetryAndDisconnect_Signal = { L"NoRetryAndDisconnect", 1 };
_StateMachineSignal g_xWLGeneric_App_Launcher_Signal = { L"App_Launcher", 0 };
_StateMachineSignal g_xWLGeneric_ChangePassword_Signal = { L"ChangePassword", 1 };
_StateMachineSignal g_xWLGeneric_ChangeIsAlreadyDone_Signal = { L"ChangeIsAlreadyDone", 1 };

_StateMachineSignal const * g_rpWLGeneric_Signals[] = {

	&g_xAction_Succeeded_Signal, // [0x0]
	&g_xAction_Failed_Signal, // [0x1]
	&g_xLogoff_NtUserCompleted_Signal, // [0x2]
	&g_xWinsrv_Sas_Signal, // [0x3]
	&g_xWinsrv_PowerMsgShow_Signal, // [0x4]
	&g_xWinsrv_PowerMsgHide_Signal, // [0x5]
	&g_xWinsrv_PowerResumeShow_Signal, // [0x6]
	&g_xWinsrv_Timeout_Signal, // [0x7]
	&g_xWinsrv_LogoffNotify_Signal, // [0x8]
	&g_xWinsrv_AccessNotify_Signal, // [0x9]
	&g_xWinsrv_ShellRestart_Signal, // [0xa]
	&g_xWinsrv_DwmControl_Signal, // [0xb]
	&g_xWinsrv_Lock_Signal, // [0xc]
	&g_xWinsrv_WinL_Signal, // [0xd]
	&g_xWinsrv_Kill_Scrnsaver_Signal, // [0xe]
	&g_xSecure_Request_Signal, // [0xf]
	&g_xSecure_LuaStart_Signal, // [0x10]
	&g_xSecure_LuaReady_Signal, // [0x11]
	&g_xSecure_LuaEnd_Signal, // [0x12]
	&g_xTS_Disconnected_Signal, // [0x13]
	&g_xTS_Reconnected_Signal, // [0x14]
	&g_xTS_PreConnect_Signal, // [0x15]
	&g_xTS_NoUnlockReconnect_Signal, // [0x16]
	&g_xTS_RevertBack_Signal, // [0x17]
	&g_xTS_SessionCreateFailed_Signal, // [0x18]
	&g_xWl_ReconnectionUpdate_Signal, // [0x19]
	&g_xWl_CredsAreStale_Signal, // [0x1a]
	&g_xWl_CloudPasswordExpired_Signal, // [0x1b]
	&g_xWl_NTLMIsDisabled_Signal, // [0x1c]
	&g_xWl_DifferentCredsAreRequired_Signal, // [0x1d]
	&g_xWl_DelayedSwitchDesktop_Signal, // [0x1e]
	&g_xWl_ShellReadyOrTimedOut_Signal, // [0x1f]
	&g_xMPR_Notify_Signal, // [0x20]
	&g_xWl_LogonFromUnlock_Signal, // [0x21]
	&g_xWl_DisplayOff_Signal, // [0x22]
	&g_xWl_DisplayOn_Signal, // [0x23]
	&g_xWl_HubScreen_Signal, // [0x24]
	&g_xWLGeneric_LogonUI_Ok_Signal, // [0x25]
	&g_xWLGeneric_LogonUI_Cancel_Signal, // [0x26]
	&g_xWLGeneric_LogonUI_WebUnlock_Signal, // [0x27]
	&g_xWLGeneric_Input_Timeout_Signal, // [0x28]
	&g_xWLGeneric_SasDisabled_Signal, // [0x29]
	&g_xWLGeneric_NoRetryAllowed_Signal, // [0x2a]
	&g_xWLGeneric_NoRetryAndDisconnect_Signal, // [0x2b]
	&g_xWLGeneric_App_Launcher_Signal, // [0x2c]
	&g_xWLGeneric_ChangePassword_Signal, // [0x2d]
	&g_xWLGeneric_ChangeIsAlreadyDone_Signal, // [0x2e]
};