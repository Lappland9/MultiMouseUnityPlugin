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
}