//------------------------------------------------------
// @brief	�ްщ��
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
// @brief	�ݽ�׸�
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT)
	: BaseScene(switcher)
{
	// ��޼ު�Ă��\�z
	if (!objListPtr) {
		objListPtr = std::make_shared<OBJECT_LIST>();
		if (!playerMnager) playerMnager = std::make_unique<PlayerManager>(objListPtr);
		if (!stageManager) stageManager = std::make_unique<StageManager>(sT);
	}
	
	// player��nullptr�łȂ��ꍇ
	if (playerMnager->GetPlayer() != nullptr)
	{
		fCollision = std::make_unique<FlexibleCollision>();
		camera = std::make_unique<Camera>(playerMnager->GetPlayer());
	}

	//------------------------------------------------------
	// �Ƃ肠�����̂��
	TorimaInitialize();

	//------------------------------------------------------
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
GameScene::~GameScene()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Initialize()
{
	// �e����������
	playerMnager->Initialize();
	stageManager->Initialize();
	camera->Initialize();
	fCollision->Initialize();

	// objList�̱����ް�
	for (auto itr = objListPtr->begin(); itr != objListPtr->end(); itr++)
	{
		
	}
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Finalize()
{
	// �e�I������
	playerMnager->Finalize();
	stageManager->Finalize();
	camera->Finalize();
	fCollision->Finalize();

	// ؿ���̊J��
	playerMnager.reset();
	stageManager.reset();
	camera.reset();
	fCollision.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Update()
{
	//------------------------------------------------------
	// �Ƃ肠�����̂��
	HitCheckStageAndPlayer(playerMnager->GetPlayer(), stageManager->GetStage());

	TorimaUpdate(playerMnager->GetPlayer());

	if (GameClear(playerMnager->GetPlayer()))
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ���ى�ʂɐ؂�ւ�
	}
	else if (GameOver(playerMnager->GetPlayer()))
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ���ى�ʂɐ؂�ւ�
	}

	//------------------------------------------------------

	// �e�X�V����
	playerMnager->Update(camera->GetCameraDir());
	camera->Update();
	stageManager->Update();
	//fCollision->HitCheck();

	

	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (CheckHitKey(KEY_INPUT_P)) 
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ���ى�ʂɐ؂�ւ�
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameScene::Render()
{
	// �e�`�揈��
	playerMnager->Render();
	stageManager->Render();
	camera->Renderer();
	DrawString(0, 0, "�ްщ��", 0xffffff);

	//------------------------------------------------------
	// �Ƃ肠�����̂��

	Draw();

	//------------------------------------------------------
}
