#include <iostream>
#include <Windows.h>

#include "MultiMouseCore.h"

int main()
{
    std::cout << "MultiMouse Test\n";

    // ========================================
    // 初期化
    // ========================================
    if (!MultiMouseCore_Initialize())
    {
        std::cout << "MultiMouse Initialize Failed!\n";
        return 1;
    }

    std::cout << "MultiMouse Initialized!\n";


    // ========================================
    // 左手用マウスのペアリング
    // ========================================
    std::cout << "\n";
    std::cout << "Move the LEFT mouse to assign it.\n";

    MultiMouseCore_StartLeftPairing();

    while (true)
    {
        // Raw Inputを処理
        MultiMouseCore_Update();

        int leftX = MultiMouseCore_GetLeftDeltaX();
        int leftY = MultiMouseCore_GetLeftDeltaY();

        // 左マウスから入力が来たらペアリング成功
        if (leftX != 0 || leftY != 0)
        {
            std::cout
                << "Left Assigned: "
                << leftX << ", "
                << leftY
                << std::endl;

            break;
        }

        // ESCで終了
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            MultiMouseCore_Shutdown();
            return 0;
        }

        Sleep(10);
    }

    std::cout << "Left mouse assigned!\n";


    // ========================================
    // 右手用マウスのペアリング
    // ========================================
    std::cout << "\n";
    std::cout << "Move the RIGHT mouse to assign it.\n";

    MultiMouseCore_StartRightPairing();

    while (true)
    {
        // Raw Inputを処理
        MultiMouseCore_Update();

        int rightX = MultiMouseCore_GetRightDeltaX();
        int rightY = MultiMouseCore_GetRightDeltaY();

        // 右マウスから入力が来たらペアリング成功
        if (rightX != 0 || rightY != 0)
        {
            std::cout
                << "Right Assigned: "
                << rightX << ", "
                << rightY
                << std::endl;

            break;
        }

        // ESCで終了
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            MultiMouseCore_Shutdown();
            return 0;
        }

        Sleep(10);
    }

    std::cout << "Right mouse assigned!\n";


    // ========================================
    // ペアリング完了
    // ========================================
    std::cout << "\n";
    std::cout << "Both mice assigned!\n";
    std::cout << "Move both mice to test them.\n";
    std::cout << "Press ESC to exit.\n\n";


    // ========================================
    // 通常の入力確認ループ
    // ========================================
    while (true)
    {
        // 新しいフレームの入力を処理
        MultiMouseCore_Update();

        // 左マウス
        int leftX = MultiMouseCore_GetLeftDeltaX();
        int leftY = MultiMouseCore_GetLeftDeltaY();

        // 右マウス
        int rightX = MultiMouseCore_GetRightDeltaX();
        int rightY = MultiMouseCore_GetRightDeltaY();

        // どちらかに移動があった場合だけ表示
        if (leftX != 0 ||
            leftY != 0 ||
            rightX != 0 ||
            rightY != 0)
        {
            std::cout
                << "Left: "
                << leftX << ", "
                << leftY
                << " | Right: "
                << rightX << ", "
                << rightY
                << std::endl;
        }

        // ESCでテスト終了
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            break;
        }

        // CPU使用率を抑える
        Sleep(10);
    }


    // ========================================
    // 終了処理
    // ========================================
    MultiMouseCore_Shutdown();

    std::cout << "\n";
    std::cout << "MultiMouse Shutdown.\n";

    return 0;
}