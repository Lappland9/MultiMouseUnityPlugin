using UnityEngine;

public class GrabbableObject : MonoBehaviour
{
    private Rigidbody rb;

    private bool isHeld = false;

    private Transform originalParent;

    private bool originalUseGravity;
    private bool originalIsKinematic;

    public bool IsHeld => isHeld;


    void Awake()
    {
        rb = GetComponent<Rigidbody>();

        if (rb == null)
        {
            Debug.LogError(
                $"{gameObject.name} に Rigidbody がありません。"
            );
        }
    }


    public bool TryGrab(Transform hand)
    {
        // すでに別の手で掴まれている
        if (isHeld)
        {
            return false;
        }

        if (rb == null)
        {
            return false;
        }

        isHeld = true;

        // 元の状態を保存
        originalParent = transform.parent;

        originalUseGravity = rb.useGravity;
        originalIsKinematic = rb.isKinematic;

        // 掴んでいる間は物理演算から外す
        rb.useGravity = false;
        rb.isKinematic = true;

        // 手の子オブジェクトにする
        transform.SetParent(hand, true);

        return true;
    }


    public void Release()
    {
        if (!isHeld)
        {
            return;
        }

        isHeld = false;

        // 元の階層へ戻す
        transform.SetParent(originalParent, true);

        if (rb != null)
        {
            rb.isKinematic = originalIsKinematic;
            rb.useGravity = originalUseGravity;
        }
    }
}