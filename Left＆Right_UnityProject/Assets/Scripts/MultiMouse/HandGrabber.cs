using System.Collections.Generic;
using UnityEngine;

public class HandGrabber : MonoBehaviour
{
    public enum HandSide
    {
        Left,
        Right
    }

    [Header("Hand")]
    [SerializeField]
    private HandSide handSide;

    // 今、掴める範囲に入っている物体
    private readonly List<GrabbableObject> candidates
        = new List<GrabbableObject>();

    // 現在掴んでいる物体
    private GrabbableObject heldObject;


    void Update()
    {
        MultiMouseInputManager input =
            MultiMouseInputManager.Instance;

        if (input == null || !input.IsReady)
        {
            return;
        }


        bool grabDown;

        if (handSide == HandSide.Left)
        {
            grabDown =
                input.LeftLeftButtonDown;
        }
        else
        {
            grabDown =
                input.RightLeftButtonDown;
        }


        // ========================================
        // ボタンを押している → 掴む
        // ========================================

        if (grabDown && heldObject == null)
        {
            GrabbableObject target =
                FindClosestObject();

            if (target != null)
            {
                if (target.TryGrab(transform))
                {
                    heldObject = target;
                }
            }
        }


        // ========================================
        // ボタンを離している → 離す
        // ========================================

        if (!grabDown && heldObject != null)
        {
            heldObject.Release();
            heldObject = null;
        }
    }


    private GrabbableObject FindClosestObject()
    {
        GrabbableObject closest = null;
        float closestDistance = float.MaxValue;

        for (int i = candidates.Count - 1; i >= 0; i--)
        {
            GrabbableObject candidate =
                candidates[i];

            // 削除済みなど
            if (candidate == null)
            {
                candidates.RemoveAt(i);
                continue;
            }

            // 別の手が掴んでいる
            if (candidate.IsHeld)
            {
                continue;
            }

            float distance =
                Vector3.Distance(
                    transform.position,
                    candidate.transform.position
                );

            if (distance < closestDistance)
            {
                closestDistance = distance;
                closest = candidate;
            }
        }

        return closest;
    }


    private void OnTriggerEnter(Collider other)
    {
        GrabbableObject grabbable =
            other.GetComponentInParent<GrabbableObject>();

        if (grabbable == null)
        {
            return;
        }

        if (!candidates.Contains(grabbable))
        {
            candidates.Add(grabbable);
        }
    }


    private void OnTriggerExit(Collider other)
    {
        GrabbableObject grabbable =
            other.GetComponentInParent<GrabbableObject>();

        if (grabbable == null)
        {
            return;
        }

        candidates.Remove(grabbable);
    }


    void OnDisable()
    {
        // Play停止時などに掴んだまま残さない
        if (heldObject != null)
        {
            heldObject.Release();
            heldObject = null;
        }

        candidates.Clear();
    }
}