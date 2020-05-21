//------------------------------------------------------
// @brief	�ްщ��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "ModelBase.h"
#include "Player.h"
#include "Camera.h"
#include "GameScene.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// ��޼ު�Đ���
	playerModel = MV1LoadModel("Model/Otameshi/chanko/chanko.mv1");
	stage = MV1LoadModel("Model/Otameshi/chanko/Fukuoka_Ground.mv1");

	player = std::make_unique<Player>(playerModel);

	// player��nullptr�łȂ��ꍇ
	if (player != nullptr)
	{
		camera = std::make_unique<Camera>(player.get());
	}
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
	player->Initialize();
	camera->Initialize();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Finalize()
{
	// �e�I������
	player->Finalize();

	// ؿ���̊J��
	player.reset();
	camera.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Update(const Controller& controll)
{
	// �e�X�V����
	player->Update();
	camera->Update();

	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (CheckHitKey(KEY_INPUT_Y) == 1) {
		// ���ى�ʂɐ؂�ւ�
		sceneSwitcher->SwitchScene(eScene_Title);
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameScene::Render()
{
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

	// ���f���̍��W���Z�b�g
	auto Spos = VGet(0.0f, 200.0f, 0.0f);
	auto Sscale = VGet(100.0f, 100.0f, 100.0f);
	auto Srol = VGet(0.0f, 0.0f, 0.0f);
	MV1SetPosition(stage, Spos);
	MV1SetRotationXYZ(stage, Srol);
	MV1SetScale(stage, Sscale );
	MV1DrawModel(stage);

	// �e�X�V����
	player->Render();
	DrawString(0, 0, "�ްщ��", 0xffffff);
}