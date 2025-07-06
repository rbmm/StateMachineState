BOOL PrintNameOnly(PVOID pv, CModule* mod, PSTR buf, ULONG cch, char c = ',')
{
	if (pv)
	{
		ULONG disp = 0;
		PCSTR pcsz;
		if ((pcsz = mod->GetNameFromVa(pv, &disp)) && !disp)
		{
			if (buf == unDNameEx(buf, pcsz, cch, UNDNAME_NAME_ONLY))
			{
				DbgPrint("\t%hs%c\n", buf, c);
			}
			else
			{
				__debugbreak();
				return FALSE;
			}
		}
		else
		{
			__debugbreak();
			return FALSE;
		}
	}
	else
	{
		DbgPrint("\t0%c\n", c);
	}

	return TRUE;
}

BOOL PrintFSig(PVOID pv, CModule* mod, PSTR buf, ULONG cch)
{
	if (pv)
	{
		ULONG disp = 0;
		PCSTR pcsz;
		if ((pcsz = mod->GetNameFromVa(pv, &disp)) && !disp)
		{
			if (buf == unDNameEx(buf, pcsz, cch, UNDNAME_DEFAULT))
			{
				DbgPrint("%hs;\n", buf);
			}
			else
			{
				__debugbreak();
				return FALSE;
			}
		}
		else
		{
			__debugbreak();
			return FALSE;
		}
	}

	return TRUE;
}

BOOL PrintArr(PULONG pv, ULONG n, CModule* mod, PSTR buf, ULONG cch)
{
	if ((pv != 0) ^ (n != 0))
	{
		__debugbreak();
		return FALSE;
	}

	if (pv)
	{
		ULONG disp = 0;
		PCSTR pcsz;
		if ((pcsz = mod->GetNameFromVa(pv, &disp)) && !disp)
		{
			if (buf == unDNameEx(buf, pcsz, cch, UNDNAME_DEFAULT))
			{
				if (PSTR pc = strchr(buf, '*'))
				{
					PCSTR pf = pc;
					while (' ' == *++pf) ;
					strcpy(pc, pf);
				}
				DbgPrint("%hs[] = {", buf);
				do 
				{
					DbgPrint(" 0x%x,", *pv++);
				} while (--n);
				DbgPrint(" };\n");
			}
			else
			{
				__debugbreak();
				return FALSE;
			}
		}
		else
		{
			__debugbreak();
			return FALSE;
		}
	}

	return TRUE;
}

enum class wls { strct, arr, func, ul, ul2 };

void nmj(CModule* mod, _StateMachineState ** rpWLGeneric_States, wls s)
{
	DbgPrint("\n");
	ULONG flags = wls::arr == s ? UNDNAME_NAME_ONLY : UNDNAME_DEFAULT;
	while (_StateMachineState * pState = *rpWLGeneric_States++)
	{
		ULONG disp = 0;
		if (PCSTR pcsz = mod->GetNameFromVa(pState, &disp))
		{
			if (disp)
			{
				break;
			}

			char buf[0x100];
			if (buf == unDNameEx(buf, pcsz, _countof(buf), flags))
			{
				switch (s)
				{
				case wls::arr:
					DbgPrint("\t&%hs,\n", buf);
					continue;

				case wls::ul:
					PrintArr((PULONG)pState->pvTransition,    pState->nTransitions,  mod, buf, _countof(buf));
					continue;

				case wls::ul2:
					PrintArr((PULONG)pState->pvResetSignals, pState->nResetSignals, mod, buf, _countof(buf));
					continue;

				case wls::func:
					PrintFSig(pState->Enter,          mod, buf, _countof(buf));
					PrintFSig(pState->Execute,        mod, buf, _countof(buf));
					PrintFSig(pState->Exit,           mod, buf, _countof(buf));
					continue;

				case wls::strct:
					DbgPrint("%hs = {\n", buf);
					if (pState->name)
					{
						DbgPrint("\tL\"%ws\",\n", pState->name);
					}
					else
					{
						DbgPrint("\t0,\n");
					}

					PrintNameOnly(pState->Enter,          mod, buf, _countof(buf));
					PrintNameOnly(pState->Execute,        mod, buf, _countof(buf));
					PrintNameOnly(pState->Exit,           mod, buf, _countof(buf));
					DbgPrint("\t0x%x,\n", pState->nTransitions);
					PrintNameOnly(pState->pvTransition,   mod, buf, _countof(buf));
					DbgPrint("\t0x%x,\n", pState->nResetSignals);
					PrintNameOnly(pState->pvResetSignals, mod, buf, _countof(buf), ' ');

					DbgPrint("};\n\n");

					break;
				}
			}
			else
			{
				__nop();
			}
		}
		else
		{
			break;
		}
	}
}

void nmj(CModule* mod, _StateMachineSignal ** rpWLGeneric_Signals, wls s)
{
	DbgPrint("\n");
	ULONG flags = wls::arr == s ? UNDNAME_NAME_ONLY : UNDNAME_DEFAULT;

	while (_StateMachineSignal *pSignal = *rpWLGeneric_Signals++)
	{
		ULONG disp = 0;
		if (PCSTR pcsz = mod->GetNameFromVa(pSignal, &disp))
		{
			if (disp)
			{
				break;
			}

			char buf[0x100];
			if (buf == unDNameEx(buf, pcsz, _countof(buf), flags))
			{
				switch (s)
				{
				case wls::arr:
					DbgPrint("\t&%hs,\n", buf);
					continue;

				case wls::strct:
					DbgPrint("%hs = { ", buf);
					if (pSignal->name)
					{
						DbgPrint("L\"%ws\"", pSignal->name);
					}
					else
					{
						DbgPrint("\t0\n");
					}

					DbgPrint(", %x };\n", pSignal->b);
					continue;
				}
			}
			else
			{
				__nop();
			}
		}
		else
		{
			break;
		}
	}
}

void nmj()
{
	if (HMODULE hmod = LoadLibraryExW(L"winlogon.exe", 0, DONT_RESOLVE_DLL_REFERENCES))
	{
		CModule* mod;
		if (0 <= CModule::Create(hmod, &mod))
		{
			if (_StateMachineState ** rpWLGeneric_States = (_StateMachineState **)mod->GetVaFromName(
				"?g_rpWLGeneric_States@@3PAPEBU_StateMachineState@@A"))
			{
				DbgPrint("#if 0\n");
				nmj(mod, rpWLGeneric_States, wls::ul);
				nmj(mod, rpWLGeneric_States, wls::ul2);
				nmj(mod, rpWLGeneric_States, wls::func);
				nmj(mod, rpWLGeneric_States, wls::strct);
				DbgPrint("\nconst _StateMachineState * g_rpWLGeneric_States[] = {\n");
				nmj(mod, rpWLGeneric_States, wls::arr);
				DbgPrint("};\n#endif\n");
			}

			if (_StateMachineSignal ** rpWLGeneric_Signals = (_StateMachineSignal **)mod->GetVaFromName(
				"?g_rpWLGeneric_Signals@@3PAPEBU_StateMachineSignal@@A"))
			{
				nmj(mod, rpWLGeneric_Signals, wls::strct);
				DbgPrint("\n_StateMachineSignal const * g_rpWLGeneric_Signals[] = {\n");
				nmj(mod, rpWLGeneric_Signals, wls::arr);
				DbgPrint("};\n");
			}
		}
		FreeLibrary(hmod);
	}
}