//------------------------------------------------------
// @brief	ﾒｲﾝ処理
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	SceneManager SceneManager;
	SceneManager.Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去

		SceneManager.Update();  //更新
		SceneManager.Draw();    //描画

	}

	SceneManager.Finalize();

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}