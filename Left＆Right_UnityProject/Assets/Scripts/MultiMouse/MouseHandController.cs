using UnityEngine;

public class MouseHandController : MonoBehaviour
{
    public enum HandSide
    {
        Left,
        Right
    }

    [Header("Hand")]
    [SerializeField]
    private HandSide handSide;

    [Header("Movement")]
    [SerializeField]
    private float sensitivity = 0.01f;


    void Update()
    {
        MultiMouseInputManager input =
            MultiMouseInputManager.Instance;

        if (input == null || !input.IsReady)
        {
            return;
        }


        Vector2 delta;

        if (handSide == HandSide.Left)
        {
            delta = input.LeftDelta;
        }
        else
        {
            delta = input.RightDelta;
        }


        Vector3 movement = new Vector3(
            delta.x,
            -delta.y,
            0.0f
        );

        transform.localPosition +=
            movement * sensitivity;
    }
}