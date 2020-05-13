//------------------------------------------------------
// @brief	ﾒｲﾝ処理
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "GameTask.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ｹﾞｰﾑｸﾗｽの生成
	GameTask* gameTask = new GameTask();

	// 初期化が失敗していれば終了
	if (gameTask->Initialize() == -1) 
	{
		delete(gameTask);	// ﾒﾓﾘ開放
		return -1;			// ｴﾗｰ終了
	}

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		gameTask->Update();
		gameTask->Draw();
	}

	gameTask->Finalize();
	delete(gameTask);

	return 0;	// 正常終了
}