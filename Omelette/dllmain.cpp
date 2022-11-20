#include <windows.h>
#include <iostream>

#include "./cheat/main.h"


DWORD WINAPI MainThread(HMODULE instance)
{
    // FOR DEBUG PURPOSES
    AllocConsole();

    FILE* fDummy;

    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    // END DEBUG

    cheat::start(instance);

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
        DisableThreadLibraryCalls(hModule);

        CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(&MainThread), hModule, 0, 0);
    }

    return TRUE;
}
