//------------------------------------------------------
// @brief	ｹﾞｰﾑ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "GameScene.h"
#include "Controller.h"
#include "GeneralManager.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT)
	: BaseScene(switcher)
{
	generalManager = std::make_unique<GeneralManager>(sT);
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
GameScene::~GameScene()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Initialize()
{
	// 各初期化処理
	generalManager->Initialize();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Finalize()
{
	// 各終了処理
	generalManager->Finalize();

	// ﾘｿｰｽの開放
	generalManager.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Update()
{
	// 各更新処理
	generalManager->Update();

	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (lpController.IsPushD(INPUT_TRG))
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ﾀｲﾄﾙ画面に切り替え
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void GameScene::Render()
{
	// 各描画処理
	generalManager->Update();
}
