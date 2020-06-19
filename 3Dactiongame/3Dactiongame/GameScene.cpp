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
#include "Collider.h"
#include "PlayerManager.h"
#include "StageManager.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT)
	: BaseScene(switcher)
{
	// ｵﾌﾞｼﾞｪｸﾄを構築
	playerMnager = std::make_unique<PlayerManager>();
	stageManager = std::make_unique<StageManager>(sT);
	

	// playerがnullptrでない場合
	if (playerMnager->GetPlayer() != nullptr)
	{
		collider = std::make_unique<Collider>(playerMnager->GetPlayer(),
												stageManager->GetStage());
		camera = std::make_unique<Camera>(playerMnager->GetPlayer());
	}

	stageManager->GetStage();
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
	collider->Initialize();
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
	collider->Finalize();

	// ﾘｿｰｽの開放
	playerMnager.reset();
	stageManager.reset();
	camera.reset();
	collider.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Update(const Controller& controll)
{
	// 各更新処理
	playerMnager->Update(controll, camera->GetCameraDir());
	camera->Update();
	stageManager->Update();
	collider->Update();

	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (controll.IsPushC(INPUT_TRG)) {
		// ﾀｲﾄﾙ画面に切り替え
		sceneSwitcher->SwitchScene(eScene_Title);
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void GameScene::Render()
{
	/*
	//x座標
	DrawLine3D(VGet(-500.0f, 0.0f, 0.0f), VGet(+500.0f, 0.0f, 0.0f), 0xff0000);
	//ｙ座標
	DrawLine3D(VGet(0.0f, -500.0f, 0.0f), VGet(0.0f, 500.0f, 0.0f), 0x00ff00);
	//ｚ座標
	DrawLine3D(VGet(0.0f, 0.0f, -500.0f), VGet(0.0f, 0.0f, 500.0f), 0x0000ff);

	for (int x = 0; x < 11; x++)
	{
		DrawLine3D(VGet(-500.0f + 100.0f*x, 0.0f, -500.0f), VGet(-500.0f + 100.0f*x, 0.0f, 500.0f), 0x0000ff);
	}
	for (int z = 0; z < 11; z++)
	{
		DrawLine3D(VGet(-500.0f, 0.0f, -500.0f + 100.0f*z), VGet(500.0f, 0.0f, -500.0f + 100.0f*z), 0xff0000);
	}
	*/

	
	// 各描画処理
	playerMnager->Render();
	stageManager->Render();
	camera->Renderer();
	DrawString(0, 0, "ｹﾞｰﾑ画面", 0xffffff);
}