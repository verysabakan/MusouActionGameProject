//------------------------------------------------------
// @brief	ｹﾞｰﾑ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "Camera.h"
#include "GameScene.h"
#include "Controller.h"
#include "LoadModel.h"
#include "PlayerManager.h"
#include "StageManager.h"
#include "FlexibleCollision.h"

#include "toriaezu.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT)
	: BaseScene(switcher)
{
	// ｵﾌﾞｼﾞｪｸﾄを構築
	if (!objListPtr) {
		objListPtr = std::make_shared<OBJECT_LIST>();
		if (!playerMnager) playerMnager = std::make_unique<PlayerManager>(objListPtr);
		if (!stageManager) stageManager = std::make_unique<StageManager>(sT);
	}
	
	// playerがnullptrでない場合
	if (playerMnager->GetPlayer() != nullptr)
	{
		fCollision = std::make_unique<FlexibleCollision>();
		camera = std::make_unique<Camera>(playerMnager->GetPlayer());
	}

	//------------------------------------------------------
	// とりあえずのやつ
	TorimaInitialize();

	//------------------------------------------------------
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
	playerMnager->Initialize();
	stageManager->Initialize();
	camera->Initialize();
	fCollision->Initialize();

	// objListのｱｯﾌﾟﾃﾞｰﾄ
	for (auto itr = objListPtr->begin(); itr != objListPtr->end(); itr++)
	{
		
	}
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Finalize()
{
	// 各終了処理
	playerMnager->Finalize();
	stageManager->Finalize();
	camera->Finalize();
	fCollision->Finalize();

	// ﾘｿｰｽの開放
	playerMnager.reset();
	stageManager.reset();
	camera.reset();
	fCollision.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Update()
{
	//------------------------------------------------------
	// とりあえずのやつ
	HitCheckStageAndPlayer(playerMnager->GetPlayer(), stageManager->GetStage());

	TorimaUpdate(playerMnager->GetPlayer());

	if (GameClear(playerMnager->GetPlayer()))
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ﾀｲﾄﾙ画面に切り替え
	}
	else if (GameOver(playerMnager->GetPlayer()))
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ﾀｲﾄﾙ画面に切り替え
	}

	//------------------------------------------------------

	// 各更新処理
	playerMnager->Update(camera->GetCameraDir());
	camera->Update();
	stageManager->Update();
	//fCollision->HitCheck();

	

	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (CheckHitKey(KEY_INPUT_P)) 
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
	playerMnager->Render();
	stageManager->Render();
	camera->Renderer();
	DrawString(0, 0, "ｹﾞｰﾑ画面", 0xffffff);

	//------------------------------------------------------
	// とりあえずのやつ

	Draw();

	//------------------------------------------------------
}
