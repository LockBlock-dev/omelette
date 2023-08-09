#include <windows.h>
#include <iostream>

#include "./Source/Omelette.h"

#define DEBUG false


DWORD WINAPI MainThread(HMODULE instance)
{  
    if (DEBUG)
    {
        AllocConsole();

        FILE* fDummy;

        freopen_s(&fDummy, "CONOUT$", "w", stderr);
        freopen_s(&fDummy, "CONOUT$", "w", stdout);
    }

    cheat::start(instance);

    return EXIT_SUCCESS;
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
