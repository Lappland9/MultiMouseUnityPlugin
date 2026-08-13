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

    // Left-hand mouse : Left button
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftButtonDown();
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftButtonPressed();
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftButtonReleased();

    // Right-hand mouse : Left button
    __declspec(dllexport) int __cdecl MultiMouse_GetRightButtonDown();
    __declspec(dllexport) int __cdecl MultiMouse_GetRightButtonPressed();
    __declspec(dllexport) int __cdecl MultiMouse_GetRightButtonReleased();

    // Left-hand mouse : Right button
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftRightButtonDown();
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftRightButtonPressed();
    __declspec(dllexport) int __cdecl MultiMouse_GetLeftRightButtonReleased();

    // Right-hand mouse : Right button
    __declspec(dllexport) int __cdecl MultiMouse_GetRightRightButtonDown();
    __declspec(dllexport) int __cdecl MultiMouse_GetRightRightButtonPressed();
    __declspec(dllexport) int __cdecl MultiMouse_GetRightRightButtonReleased();
}