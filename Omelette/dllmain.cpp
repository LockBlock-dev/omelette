#include <windows.h>
#include <iostream>
#include "./cheat/main.h"


DWORD WINAPI MainThread(LPVOID param)
{
    AllocConsole();

    FILE* fDummy;

    freopen_s(&fDummy, "CONIN$", "r", stdin);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONOUT$", "w", stdout);

    uintptr_t modBase = (uintptr_t)GetModuleHandle(NULL);

    cheat::start();

    FreeLibraryAndExitThread((HMODULE)param, 0);

    return 0;
}

BOOL APIENTRY DllMain(
    HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CreateThread(NULL, 0, &MainThread, hModule, 0, 0);
    }

    return TRUE;
}
