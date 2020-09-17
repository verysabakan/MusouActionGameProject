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
	if (DxLib_Init() == -1) 
	{
		return -1;	// ｴﾗｰが起きたら終了
	}

	// 画面ﾓｰﾄﾞのｾｯﾄ
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);		// ｽｸﾘｰﾝのｻｲｽﾞ
	ChangeWindowMode(TRUE);				// TRUE:ｳｨﾝﾄﾞｳ、FALSE:ﾌﾙｽｸﾘｰﾝ
	SetDrawScreen(DX_SCREEN_BACK);		// 背面に描画
	SetBackgroundColor(BACKGROUND_COLOR, BACKGROUND_COLOR, BACKGROUND_COLOR);	// 背景色
	//SetUseZBuffer3D(FALSE);			// zﾊﾞｯﾌｧを有効にするか(3Dのみ)
	//SetWriteZBuffer3D(FALSE);			// zﾊﾞｯﾌｧへの書き込みを有効にするか(3Dのみ)
	SetUseZBufferFlag(FALSE);			// zﾊﾞｯﾌｧを有効にするか
	SetWriteZBufferFlag(FALSE);			// zﾊﾞｯﾌｧへの書き込みを有効にするか
	SetUseLighting(TRUE);				// ﾗｲﾃｨﾝｸﾞ計算処理を使用するか

	// 初期化処理
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

	// DxLibの後始末
	DxLib_End();	
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameTask::Update()
{
	lpController->Update();	// ｺﾝﾄﾛｰﾗｰの更新
	sceneManager->Update();	// ｼｰﾝ別の更新
	lpFrameRate->Update();	// ﾌﾚｰﾑ計測固定
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void GameTask::Render()
{
	ClearDrawScreen();		// 画面を初期化

	sceneManager->Render();	// ｼｰﾝ別の描画
	lpController->Render();	// ｺﾝﾄﾛｰﾗｰの描画:入力ﾁｪｯｸ
	lpFrameRate->Render();	// 現在のﾌﾚｰﾑﾚｰﾄの描画

	ScreenFlip();			// 裏画面の内容を表面に反映させる
}