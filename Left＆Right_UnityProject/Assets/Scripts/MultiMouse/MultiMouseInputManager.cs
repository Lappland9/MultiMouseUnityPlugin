using UnityEngine;

[DefaultExecutionOrder(-100)]
public class MultiMouseInputManager : MonoBehaviour
{
    public static MultiMouseInputManager Instance { get; private set; }

    // ========================================
    // Movement
    // ========================================

    public Vector2 LeftDelta { get; private set; }
    public Vector2 RightDelta { get; private set; }

    // ========================================
    // Left-hand mouse buttons
    // ========================================

    public bool LeftLeftButtonDown { get; private set; }
    public bool LeftLeftButtonPressed { get; private set; }
    public bool LeftLeftButtonReleased { get; private set; }

    public bool LeftRightButtonDown { get; private set; }
    public bool LeftRightButtonPressed { get; private set; }
    public bool LeftRightButtonReleased { get; private set; }

    // ========================================
    // Right-hand mouse buttons
    // ========================================

    public bool RightLeftButtonDown { get; private set; }
    public bool RightLeftButtonPressed { get; private set; }
    public bool RightLeftButtonReleased { get; private set; }

    public bool RightRightButtonDown { get; private set; }
    public bool RightRightButtonPressed { get; private set; }
    public bool RightRightButtonReleased { get; private set; }


    private bool initialized = false;

    private bool waitingForLeft = false;
    private bool waitingForRight = false;

    public bool IsReady =>
        initialized &&
        !waitingForLeft &&
        !waitingForRight;


    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
    }


    void Start()
    {
        int result =
            MultiMouseNative.MultiMouse_Initialize();

        if (result == 0)
        {
            Debug.LogError("MultiMouse Initialize Failed!");
            return;
        }

        initialized = true;

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

        // Native側の入力更新
        // このスクリプトだけが呼ぶ
        MultiMouseNative.MultiMouse_Update();


        // ========================================
        // Left pairing
        // ========================================

        if (waitingForLeft)
        {
            ClearInput();

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
        // Right pairing
        // ========================================

        if (waitingForRight)
        {
            ClearInput();

            if (MultiMouseNative.MultiMouse_IsRightAssigned() != 0)
            {
                waitingForRight = false;

                Debug.Log("RIGHT mouse assigned!");
                Debug.Log("MultiMouse ready!");
            }

            return;
        }


        // ========================================
        // Movement
        // ========================================

        LeftDelta = new Vector2(
            MultiMouseNative.MultiMouse_GetLeftDeltaX(),
            MultiMouseNative.MultiMouse_GetLeftDeltaY()
        );

        RightDelta = new Vector2(
            MultiMouseNative.MultiMouse_GetRightDeltaX(),
            MultiMouseNative.MultiMouse_GetRightDeltaY()
        );


        // ========================================
        // Left-hand mouse
        // ========================================

        LeftLeftButtonDown =
            MultiMouseNative.MultiMouse_GetLeftButtonDown() != 0;

        LeftLeftButtonPressed =
            MultiMouseNative.MultiMouse_GetLeftButtonPressed() != 0;

        LeftLeftButtonReleased =
            MultiMouseNative.MultiMouse_GetLeftButtonReleased() != 0;


        LeftRightButtonDown =
            MultiMouseNative.MultiMouse_GetLeftRightButtonDown() != 0;

        LeftRightButtonPressed =
            MultiMouseNative.MultiMouse_GetLeftRightButtonPressed() != 0;

        LeftRightButtonReleased =
            MultiMouseNative.MultiMouse_GetLeftRightButtonReleased() != 0;


        // ========================================
        // Right-hand mouse
        // ========================================

        RightLeftButtonDown =
            MultiMouseNative.MultiMouse_GetRightButtonDown() != 0;

        RightLeftButtonPressed =
            MultiMouseNative.MultiMouse_GetRightButtonPressed() != 0;

        RightLeftButtonReleased =
            MultiMouseNative.MultiMouse_GetRightButtonReleased() != 0;


        RightRightButtonDown =
            MultiMouseNative.MultiMouse_GetRightRightButtonDown() != 0;

        RightRightButtonPressed =
            MultiMouseNative.MultiMouse_GetRightRightButtonPressed() != 0;

        RightRightButtonReleased =
            MultiMouseNative.MultiMouse_GetRightRightButtonReleased() != 0;
    }


    private void ClearInput()
    {
        LeftDelta = Vector2.zero;
        RightDelta = Vector2.zero;

        LeftLeftButtonDown = false;
        LeftLeftButtonPressed = false;
        LeftLeftButtonReleased = false;

        LeftRightButtonDown = false;
        LeftRightButtonPressed = false;
        LeftRightButtonReleased = false;

        RightLeftButtonDown = false;
        RightLeftButtonPressed = false;
        RightLeftButtonReleased = false;

        RightRightButtonDown = false;
        RightRightButtonPressed = false;
        RightRightButtonReleased = false;
    }


    void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }

        if (!initialized)
        {
            return;
        }

        MultiMouseNative.MultiMouse_Shutdown();

        initialized = false;
    }
}