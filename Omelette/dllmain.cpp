#include <iostream>

#include "cheat/gui.h"
#include "cheat/main.h"


DWORD WINAPI GUIThread(LPVOID param)
{
    // Create GUI
    gui::CreateHWindow(L"Omelette");
    gui::CreateDevice();
    gui::CreateImGui();

    while (true)
    {
        gui::BeginRender();
        gui::Render();
        gui::EndRender();

        Sleep(10);
    }

    // Destroy GUI
    gui::DestroyImGui();
    gui::DestroyDevice();
    gui::DestroyHWindow();

    return 0;
}

DWORD WINAPI MainThread(LPVOID param)
{
    AllocConsole();

    FILE* fDummy;

    freopen_s(&fDummy, "CONIN$", "r", stdin);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONOUT$", "w", stdout);

    uintptr_t modBase = (uintptr_t)GetModuleHandle(NULL);

    CreateThread(NULL, 0, &GUIThread, NULL, 0, 0);

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
