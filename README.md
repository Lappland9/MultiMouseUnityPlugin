# MultiMouse Unity Plugin

Unity上で**複数の物理マウスを個別の入力デバイスとして扱うためのWindows向けNative Plugin**です。

Windows Raw Input APIを利用して入力元のマウスを識別し、
C++で取得した入力をDLL経由でUnity C#へ渡しています。

現在は2台のマウスをそれぞれ `Left` / `Right` として登録し、
移動量や左右クリックを独立して取得できます。

---

## Motivation

通常のUnityのマウス入力では、複数の物理マウスを接続しても
「どのマウスから入力されたか」を区別して扱うことが難しいため、
Windows Raw Input APIを利用した独自の入力プラグインを制作しました。

このプラグインは、2台のマウスを同時に使用するゲームを制作するために開発しています。

---

## Features

- 複数の物理マウスをデバイス単位で識別
- 2台のマウスを `Left` / `Right` としてペアリング
- 各マウスのX/Y移動量を独立して取得
- 各マウスの左クリック・右クリックを独立して取得
- ボタンの押下状態（Down）を取得
- UnityのPlay / Stop後でも再初期化可能
- Unity C#からP/InvokeでNative Pluginを利用可能

---

## Architecture

```text
Physical Mouse A        Physical Mouse B
       │                       │
       └──────── Windows Raw Input ────────┘
                       │
                 WM_INPUT / hDevice
                       │
                RawInputManager
                       │
                  MouseManager
                       │
          Left / Right MouseState
                       │
                MultiMouseCore
                (Static Library)
                       │
                MultiMousePlugin
                     (DLL)
                       │
                  P/Invoke
                       │
                    Unity
                       │
              C# Input Manager
                       │
        LeftHand / RightHand Controller
```
## Native side

C++側は役割ごとに分離しています。

### HiddenWindow
Raw Inputを受け取るためのMessage-Only Windowを生成
WM_INPUTを受信

### RawInputManager
RegisterRawInputDevicesによるRaw Input登録
GetRawInputDataによる入力データ取得

### MouseManager
RAWINPUTHEADER.hDeviceを利用して物理マウスを識別
Left / Rightへのペアリング
移動量・クリック状態を管理

### MultiMouseCore
入力システム本体
Static Libraryとして実装

### MultiMousePlugin
Unityから利用するDLL
MultiMouseCoreの機能をC形式のAPIとして公開

---

## Unity side

C#では DllImport を使用し、Native Pluginの関数を呼び出しています。
```
[DllImport("MultiMousePlugin",CallingConvention = CallingConvention.Cdecl)]
public static extern int MultiMouse_GetLeftDeltaX();
```
Unity側ではNative APIを直接ゲームロジックから呼ぶのではなく、
MultiMouseInputManagerで1フレームに1回入力を更新し、
各ゲームオブジェクトからその状態を参照する構成にしています。

---

## Pairing

起動時にマウスを動かすことでLeft / Rightを割り当てます。
```
Start
  ↓
Move LEFT mouse
  ↓
hDeviceをLeftとして登録
  ↓
Move RIGHT mouse
  ↓
異なるhDeviceをRightとして登録
  ↓
Ready
```
同じ物理マウスをLeftとRightの両方へ登録できないようにしています。

---

## Input

取得できる主な入力は以下です。
```
Mouse movement
LeftDeltaX
LeftDeltaY


RightDeltaX
RightDeltaY
```
1フレーム内に複数回Raw Inputを受信した場合は、
移動量を加算してUnity側へ渡します。

Mouse buttons

各物理マウスについて、

  Left Button
  Right Button

を独立して取得できます。

現在のゲーム操作では、クリックを押している間の状態である
Down を主に使用しています。

---

## Example

現在のサンプルでは、
```
Left Mouse
    ↓
LeftHand


Right Mouse
    ↓
RightHand
```
として2つのオブジェクトを独立して操作できます。

また、左クリックを押している間は近くのオブジェクトを掴み、
ボタンを離すとオブジェクトを離す操作を実装しています。

---

## Project Structure
```
Repository
├─ MultiMouseCore
│  ├─ HiddenWindow
│  ├─ RawInputManager
│  ├─ MouseManager
│  └─ MultiMouseCore
│
├─ MultiMousePlugin
│  └─ Unity向けNative DLL
│
├─ MultiMouseTest
│  └─ C++単体テスト
│
└─ Left & Right_UnityProject
   └─ Unityサンプル / ゲームプロジェクト
```
---

#Build

## Native Plugin

Visual Studioで、
```
Configuration : Release
Platform      : x64
```
を選択します。

以下の順番でビルドします。
```
MultiMouseCore
      ↓
MultiMousePlugin
```
生成された
```
MultiMousePlugin.dll
```
をUnityプロジェクトの
```
Assets/Plugins/x86_64/
```
へ配置します。

---

# Current Limitations
```
Windows専用
現在は最大2台のマウスを想定
マウスごとのポーリングレートやセンサー性能によって、
オブジェクト移動の滑らかさに差が出る場合があります
Pressed / Released の瞬間イベントについては、
より確実なイベントキュー方式への変更を検討中
現在のGrab処理はプロトタイプ段階
```
