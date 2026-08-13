using System.Runtime.InteropServices;

public static class MultiMouseNative
{
    private const string DllName = "MultiMousePlugin";

    // ========================================
    // Initialize / Shutdown
    // ========================================

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_Initialize();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void MultiMouse_Shutdown();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void MultiMouse_Update();


    // ========================================
    // Pairing
    // ========================================

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void MultiMouse_StartLeftPairing();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern void MultiMouse_StartRightPairing();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_IsLeftAssigned();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_IsRightAssigned();


    // ========================================
    // Movement
    // ========================================

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftDeltaX();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftDeltaY();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightDeltaX();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightDeltaY();

    // ========================================
    // Left-hand mouse : Left button
    // ========================================

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftButtonDown();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftButtonPressed();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftButtonReleased();


    // ========================================
    // Right-hand mouse : Left button
    // ========================================

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightButtonDown();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightButtonPressed();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightButtonReleased();


    // ========================================
    // Left-hand mouse : Right button
    // ========================================

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftRightButtonDown();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftRightButtonPressed();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetLeftRightButtonReleased();


    // ========================================
    // Right-hand mouse : Right button
    // ========================================

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightRightButtonDown();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightRightButtonPressed();

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern int MultiMouse_GetRightRightButtonReleased();
}