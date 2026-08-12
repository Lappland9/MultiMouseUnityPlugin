#include <iostream>
#include <Windows.h>

#include "HiddenWindow.h"
#include "RawInputManager.h"
#include "MouseManager.h"

int main()
{
    std::cout << "MultiMouse Test\n";

    // ----------------------------------------
    // MouseManager
    // ----------------------------------------
    MouseManager mouseManager;

    // ----------------------------------------
    // RawInputManager
    // ----------------------------------------
    RawInputManager rawInputManager(mouseManager);

    // ----------------------------------------
    // Hidden Window
    // ----------------------------------------
    HiddenWindow hiddenWindow(rawInputManager);

    if (!hiddenWindow.Create())
    {
        std::cout
            << "Hidden Window Create or Raw Input Register Failed\n";

        return -1;
    }

    std::cout << "Hidden Window Created!\n";

    // ----------------------------------------
    // ペアリング処理の状態
    // ----------------------------------------
    enum class PairingStep
    {
        Left,
        Right,
        Complete
    };

    PairingStep pairingStep = PairingStep::Left;

    // ----------------------------------------
    // 左手用マウスの登録開始
    // ----------------------------------------
    std::cout
        << "Left hand mouse: "
        << "Move the mouse you want to use for the LEFT hand."
        << std::endl;

    mouseManager.StartLeftPairing();

    // ----------------------------------------
    // Windowsメッセージループ
    // ----------------------------------------
    MSG msg{};

    while (true)
    {
        // ------------------------------------
        // Windowsメッセージを処理
        // ------------------------------------
        while (PeekMessageW(
            &msg,
            nullptr,
            0,
            0,
            PM_REMOVE))
        {
            // WM_QUITを受け取ったら終了
            if (msg.message == WM_QUIT)
            {
                return 0;
            }

            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }

        // ------------------------------------
        // 左手用マウスの登録確認
        // ------------------------------------
        if (pairingStep == PairingStep::Left &&
            mouseManager.IsLeftAssigned())
        {
            std::cout
                << "Left mouse assigned!"
                << std::endl;

            std::cout
                << "Right hand mouse: "
                << "Move the mouse you want to use for the RIGHT hand."
                << std::endl;

            mouseManager.StartRightPairing();

            pairingStep = PairingStep::Right;
        }

        // ------------------------------------
        // 右手用マウスの登録確認
        // ------------------------------------
        if (pairingStep == PairingStep::Right &&
            mouseManager.IsRightAssigned())
        {
            std::cout
                << "Right mouse assigned!"
                << std::endl;

            std::cout
                << "Pairing complete!"
                << std::endl;

            pairingStep = PairingStep::Complete;
        }

        // ------------------------------------
        // ペアリング完了後
        // ------------------------------------
        if (pairingStep == PairingStep::Complete)
        {
            const MouseState* leftMouse =
                mouseManager.GetMouse(MouseRole::Left);

            const MouseState* rightMouse =
                mouseManager.GetMouse(MouseRole::Right);

            // 左手マウス
            if (leftMouse != nullptr)
            {
                if (leftMouse->deltaX != 0 ||
                    leftMouse->deltaY != 0)
                {
                    std::cout
                        << "Left Mouse: "
                        << "dx=" << leftMouse->deltaX
                        << " dy=" << leftMouse->deltaY
                        << std::endl;
                }
            }

            // 右手マウス
            if (rightMouse != nullptr)
            {
                if (rightMouse->deltaX != 0 ||
                    rightMouse->deltaY != 0)
                {
                    std::cout
                        << "Right Mouse: "
                        << "dx=" << rightMouse->deltaX
                        << " dy=" << rightMouse->deltaY
                        << std::endl;
                }
            }

            // 今のフレームの入力をリセット
            mouseManager.BeginFrame();
        }

        // CPUを使い切らないように少し待つ
        Sleep(10);
    }

    return 0;
}