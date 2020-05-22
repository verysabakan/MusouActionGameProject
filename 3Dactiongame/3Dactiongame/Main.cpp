//------------------------------------------------------
// @brief	ﾒｲﾝ処理
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "GameTask.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ｹﾞｰﾑﾀｽｸの生成
	std::unique_ptr<GameTask> gameTask;
	gameTask = std::make_unique<GameTask>();

	// 初期化が失敗していれば終了
	if (gameTask->Initialize() == -1) 
	{
		gameTask.reset();	// ﾒﾓﾘ開放
		return -1;			// ｴﾗｰ終了
	}

	// ｴｽｹｰﾌﾟｷｰが押されるかｳｨﾝﾄﾞｳが閉じられるまでﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		gameTask->Update();
		gameTask->Render();
	}

	gameTask->Finalize();
	gameTask.reset();

	return 0;	// 正常終了
}