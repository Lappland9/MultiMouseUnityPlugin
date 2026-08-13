using UnityEngine;

public class MultiMouseTester : MonoBehaviour
{
    private bool initialized = false;

    private bool waitingForLeft = false;
    private bool waitingForRight = false;

    void Start()
    {
        Debug.Log("MultiMouse Test Start");

        int result = MultiMouseNative.MultiMouse_Initialize();

        if (result == 0)
        {
            Debug.LogError("MultiMouse Initialize Failed!");
            return;
        }

        initialized = true;

        Debug.Log("MultiMouse Initialized!");
        Debug.Log("Move the LEFT mouse.");

        MultiMouseNative.MultiMouse_StartLeftPairing();

        waitingForLeft = true;
    }

    void Update()
    {
        if (!initialized)
        {
            return;
        }

        // Nativeë§ÇÃì¸óÕÇçXêV
        MultiMouseNative.MultiMouse_Update();


        // ========================================
        // Left Pairing
        // ========================================

        if (waitingForLeft)
        {
            if (MultiMouseNative.MultiMouse_IsLeftAssigned() != 0)
            {
                waitingForLeft = false;

                Debug.Log("LEFT mouse assigned!");
                Debug.Log("Move the RIGHT mouse.");

                MultiMouseNative.MultiMouse_StartRightPairing();

                waitingForRight = true;
            }

            return;
        }


        // ========================================
        // Right Pairing
        // ========================================

        if (waitingForRight)
        {
            if (MultiMouseNative.MultiMouse_IsRightAssigned() != 0)
            {
                waitingForRight = false;

                Debug.Log("RIGHT mouse assigned!");
                Debug.Log("Both mice assigned!");
            }

            return;
        }


        // ========================================
        // Input Test
        // ========================================

        int leftX =
            MultiMouseNative.MultiMouse_GetLeftDeltaX();

        int leftY =
            MultiMouseNative.MultiMouse_GetLeftDeltaY();

        int rightX =
            MultiMouseNative.MultiMouse_GetRightDeltaX();

        int rightY =
            MultiMouseNative.MultiMouse_GetRightDeltaY();


        if (leftX != 0 ||
            leftY != 0 ||
            rightX != 0 ||
            rightY != 0)
        {
            Debug.Log(
                $"Left: {leftX}, {leftY}" +
                $" | Right: {rightX}, {rightY}"
            );
        }
    }

    void OnDestroy()
    {
        if (!initialized)
        {
            return;
        }

        MultiMouseNative.MultiMouse_Shutdown();

        initialized = false;

        Debug.Log("MultiMouse Shutdown");
    }
}