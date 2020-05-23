//------------------------------------------------------
// @brief	ｹﾞｰﾑ自体の初期化、ﾌﾛｰ、終了
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "GameTask.h"
#include "SceneManager.h"
#include "Controller.h"
#include "MainConstant.h"
#include "FrameRate.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
GameTask::GameTask()
{
	// ｵﾌﾞｼﾞｪｸﾄ生成
	sceneManager = std::make_unique<SceneManager>();
	controll = std::make_unique<Controller>();
	frameRate = std::make_unique<FrameRate>();
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
GameTask::~GameTask()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
int GameTask::Initialize()
{
	// DxLibの初期化処理
	if (DxLib_Init() == -1) {
		return -1;	// ｴﾗｰが起きたら終了
	}

	// 画面ﾓｰﾄﾞのｾｯﾄ
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);		// (仮)
	ChangeWindowMode(TRUE);				// TRUE:ｳｨﾝﾄﾞｳ、FALSE:ﾌﾙｽｸﾘｰﾝ
	SetDrawScreen(DX_SCREEN_BACK);		// 背面に描画
	SetBackgroundColor(BACKGROUND_COLOR, BACKGROUND_COLOR, BACKGROUND_COLOR);	// 背景色
	SetUseZBuffer3D(TRUE);				// zバッファを有効にする
	SetWriteZBuffer3D(TRUE);			//ｚバッファへの書き込みを有効にする
	
	// 初期化
	sceneManager->Initialize();

	return 0;
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void GameTask::Finalize()
{
	// 各終了処理
	sceneManager->Finalize();

	// ﾘｿｰｽの開放
	sceneManager.reset();
	controll.reset();
	frameRate.reset();

	// DxLibの後始末
	DxLib_End();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameTask::Update()
{
	// ﾌﾚｰﾑ計測固定
	frameRate->Update();

	// ｼｰﾝ別の更新
	sceneManager->Update(*controll);

	// ｺﾝﾄﾛｰﾗｰの更新
	controll->Update();
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void GameTask::Render()
{
	// 画面を初期化
	ClearDrawScreen();

	// ｼｰﾝ別の描画
	sceneManager->Render();

	// ｺﾝﾄﾛｰﾗｰの描画:入力ﾁｪｯｸ
	controll->Render();

	// 現在のﾌﾚｰﾑﾚｰﾄの描画
	frameRate->Render();

	// 裏画面の内容を表面に反映させる
	ScreenFlip();

	
}