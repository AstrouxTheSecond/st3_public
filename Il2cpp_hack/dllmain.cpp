#include <Windows.h>
#include "Hooks/Hooks.hpp"
#include "Utilities/Globalize.hpp"

void Initialize()
{
    MH_Initialize();

    ST3::Modules::ModuleBase = (uintptr_t)GetModuleHandle(NULL);
    ST3::Modules::GameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

    AllocConsole();
    FILE* consoleFile;
    freopen_s(&consoleFile, "CONOUT$", "w", stdout);
    SetConsoleTitle("Slendytubbies 3 Public Cheat - Astroux#4200 - V2.46");
}

void MainThread()
{
    Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Camera::get_fieldOfView), &Hooks::get_fieldOfView, (LPVOID*)&Hooks::get_fieldOfView_org);
    MH_EnableHook(MH_ALL_HOOKS);

    printf("Slendytubbies 3 Public Cheat - astroux_st\n\n");
    printf("Press 'Insert' To Enable/Disable Speedhack\n");
    printf("Press 'Home' To Enable/Disable FOV Changer\n\n");
    printf("WARNING: DO NOT CLOSE THIS WINDOW, THE GAME WILL CRASH.\n");

    while (true)
    {
        if (GetAsyncKeyState(VK_HOME) & 1)
        {
            Variables::Hacks::FOVChanger = !Variables::Hacks::FOVChanger;
        }

        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            Variables::Hacks::Timescale = !Variables::Hacks::Timescale;
        }

        if (Variables::Hacks::Timescale)
            SetTimescale(2.5f);
        else
            SetTimescale(1.0f);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
        break;
    }
    return TRUE;
}

