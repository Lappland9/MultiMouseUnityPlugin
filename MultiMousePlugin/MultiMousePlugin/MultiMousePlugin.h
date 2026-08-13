#pragma once

extern "C"
{
    __declspec(dllexport) int __cdecl MultiMouse_Initialize();
    __declspec(dllexport) void __cdecl MultiMouse_Shutdown();
    __declspec(dllexport) void __cdecl MultiMouse_Update();

    // Pairing
    __declspec(dllexport) void __cdecl MultiMouse_StartLeftPairing();
    __declspec(dllexport) void __cdecl MultiMouse_StartRightPairing();

    __declspec(dllexport) int __cdecl MultiMouse_IsLeftAssigned();
    __declspec(dllexport) int __cdecl MultiMouse_IsRightAssigned();

    // Movement
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftDeltaX();
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftDeltaY();

    __declspec(dllexport) int __cdecl MultiMouse_GetRightDeltaX();
    __declspec(dllexport) int __cdecl MultiMouse_GetRightDeltaY();
}