//------------------------------------------------------
// @brief	ｹﾞｰﾑ自体の初期化、ﾌﾛｰ、終了
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "GameTask.h"
#include "SceneManager.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
GameTask::GameTask()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
GameTask::~GameTask()
{
	// 異常終了のﾁｪｯｸ
	assert(sceneManager == nullptr);
	assert(controll == nullptr);
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
	SetGraphMode(1200, 720, 32);		// (仮)
	ChangeWindowMode(TRUE);				// TRUE:ｳｨﾝﾄﾞｳ、FALSE:ﾌﾙｽｸﾘｰﾝ
	SetDrawScreen(DX_SCREEN_BACK);		// 背面に描画

	SetBackgroundColor(128, 128, 128);
	//zバッファを有効にする
	//SetUseZBuffer3D(true);
	//ｚバッファへの書き込みを有効にする
	//SetWriteZBuffer3D(true);
	

	// SceneManagerを生成
	sceneManager = std::make_unique<SceneManager>();

	// Controllerを生成
	controll = std::make_unique<Controller>();

	return 0;
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void GameTask::Finalize()
{
	// SceneManagerを開放
	sceneManager.release();

	// controllerを開放
	controll.release();

	// DxLibの後始末
	DxLib_End();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameTask::Update()
{
	// ｼｰﾝ別の更新
	sceneManager->Update((*controll));

	// ｺﾝﾄﾛｰﾗｰの更新
	controll->Update();
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void GameTask::Draw()
{
	// 画面を初期化
	ClearDrawScreen();

	// ｺﾝﾄﾛｰﾗｰの描画:入力ﾁｪｯｸ
	controll->Draw();

	// ｼｰﾝ別の描画
	sceneManager->Draw();

	// 裏画面の内容を表面に反映させる
	ScreenFlip();
}