using UnityEngine;

public class MultiMouseTester : MonoBehaviour
{
    [Header("Controlled Objects")]
    [SerializeField]
    private Transform leftObject;

    [SerializeField]
    private Transform rightObject;

    [Header("Movement")]
    [SerializeField]
    private float sensitivity = 0.01f;

    private bool initialized = false;

    private bool waitingForLeft = false;
    private bool waitingForRight = false;

    private Vector3 leftBaseScale;
    private Vector3 rightBaseScale;

    private Quaternion leftBaseRotation;
    private Quaternion rightBaseRotation;


    void Start()
    {
        // ----------------------------------------
        // オブジェクトの初期状態を保存
        // ----------------------------------------
        if (leftObject != null)
        {
            leftBaseScale = leftObject.localScale;
            leftBaseRotation = leftObject.localRotation;
        }

        if (rightObject != null)
        {
            rightBaseScale = rightObject.localScale;
            rightBaseRotation = rightObject.localRotation;
        }


        // ----------------------------------------
        // MultiMouse初期化
        // ----------------------------------------
        int result =
            MultiMouseNative.MultiMouse_Initialize();

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

        // ========================================
        // Native入力更新
        // 必ず1フレームに1回だけ
        // ========================================
        MultiMouseNative.MultiMouse_Update();


        // ========================================
        // LEFT pairing
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
        // RIGHT pairing
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
        // Mouse movement
        // ========================================

        int leftX =
            MultiMouseNative.MultiMouse_GetLeftDeltaX();

        int leftY =
            MultiMouseNative.MultiMouse_GetLeftDeltaY();

        int rightX =
            MultiMouseNative.MultiMouse_GetRightDeltaX();

        int rightY =
            MultiMouseNative.MultiMouse_GetRightDeltaY();


        // 左マウス
        if (leftObject != null)
        {
            Vector3 movement = new Vector3(
                leftX,
                -leftY,
                0
            );

            leftObject.position +=
                movement * sensitivity;
        }


        // 右マウス
        if (rightObject != null)
        {
            Vector3 movement = new Vector3(
                rightX,
                -rightY,
                0
            );

            rightObject.position +=
                movement * sensitivity;
        }


        // ========================================
        // LEFT mouse buttons
        // ========================================

        if (leftObject != null)
        {
            bool leftButton =
                MultiMouseNative.MultiMouse_GetLeftButtonDown() != 0;

            bool rightButton =
                MultiMouseNative.MultiMouse_GetLeftRightButtonDown() != 0;


            // 左クリック中 → 大きくする
            if (leftButton)
            {
                leftObject.localScale =
                    leftBaseScale * 1.3f;
            }
            else
            {
                leftObject.localScale =
                    leftBaseScale;
            }


            // 右クリック中 → 傾ける
            if (rightButton)
            {
                leftObject.localRotation =
                    leftBaseRotation *
                    Quaternion.Euler(0, 0, 25);
            }
            else
            {
                leftObject.localRotation =
                    leftBaseRotation;
            }
        }


        // ========================================
        // RIGHT mouse buttons
        // ========================================

        if (rightObject != null)
        {
            bool leftButton =
                MultiMouseNative.MultiMouse_GetRightButtonDown() != 0;

            bool rightButton =
                MultiMouseNative.MultiMouse_GetRightRightButtonDown() != 0;


            // 左クリック中 → 大きくする
            if (leftButton)
            {
                rightObject.localScale =
                    rightBaseScale * 1.3f;
            }
            else
            {
                rightObject.localScale =
                    rightBaseScale;
            }


            // 右クリック中 → 傾ける
            if (rightButton)
            {
                rightObject.localRotation =
                    rightBaseRotation *
                    Quaternion.Euler(0, 0, -25);
            }
            else
            {
                rightObject.localRotation =
                    rightBaseRotation;
            }
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
    }
}