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
#include "Collider.h"
#include "PlayerManager.h"
#include "StageManager.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT)
	: BaseScene(switcher)
{
	// ��޼ު�Ă��\�z
	playerMnager = std::make_unique<PlayerManager>();
	stageManager = std::make_unique<StageManager>(sT);
	

	// player��nullptr�łȂ��ꍇ
	if (playerMnager->GetPlayer() != nullptr)
	{
		collider = std::make_unique<Collider>(playerMnager->GetPlayer(),
												stageManager->GetStage());
		camera = std::make_unique<Camera>(playerMnager->GetPlayer());
	}

	stageManager->GetStage();
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
	collider->Initialize();
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
	collider->Finalize();

	// ؿ���̊J��
	playerMnager.reset();
	stageManager.reset();
	camera.reset();
	collider.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Update()
{
	// �e�X�V����
	playerMnager->Update(camera->GetCameraDir());
	camera->Update();
	stageManager->Update();
	collider->Update();

	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (lpController.IsPushC(INPUT_TRG)) 
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ���ى�ʂɐ؂�ւ�
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameScene::Render()
{
	/*
	//x���W
	DrawLine3D(VGet(-500.0f, 0.0f, 0.0f), VGet(+500.0f, 0.0f, 0.0f), 0xff0000);
	//�����W
	DrawLine3D(VGet(0.0f, -500.0f, 0.0f), VGet(0.0f, 500.0f, 0.0f), 0x00ff00);
	//�����W
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

	
	// �e�`�揈��
	playerMnager->Render();
	stageManager->Render();
	camera->Renderer();
	DrawString(0, 0, "�ްщ��", 0xffffff);
}