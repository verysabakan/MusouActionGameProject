//------------------------------------------------------
// @brief	ﾒｲﾝ処理
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "GameTask.h"
#include "FrameRate.h"

#include "_Debug.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ﾃﾞﾊﾞｯｸﾞｳｨﾝﾄﾞｳｲﾝｽﾀﾝｽ
#ifdef _DEBUG
	_Debug::Instance();
#endif	// _DEBUG

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
		for (auto i = 0; i < lpFrameRate->GetStepNum(); i++)
		{
			gameTask->Update();
			gameTask->Render();
		}
	}

	gameTask->Finalize();	// 終了処理
	gameTask.reset();		// ﾘｿｰｽの開放

	return 0;	// 正常終了
}