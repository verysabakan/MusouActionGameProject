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
	auto playerModel = MV1LoadModel("Model/Otameshi/Heracules/Model_Heracules_Green.mv1");

	// -----------------------------------------
	std::vector<int> playerAnim;
	auto i = 0;

	std::string dir_name = "Model/Otameshi/heracules/Animation";
	std::string extension = "mv1";

	HANDLE hFind;
	WIN32_FIND_DATA win32fd;
	std::string search_name = dir_name + "\\*." + extension;

	hFind = FindFirstFile(search_name.c_str(), &win32fd);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		throw std::runtime_error("file not found");
	}

	//���̃t�@�C�����������ǂݍ��ݑ�����
	do
	{
		//�f�B���N�g���Ȃ疳��
		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {}
		else
		{
			std::string fileName = win32fd.cFileName;
			fileName.insert(0, "Model/Otameshi/Heracules/Animation/");

			playerAnim.push_back(MV1LoadModel(fileName.c_str()));
			i++;
		}
	} while (FindNextFile(hFind, &win32fd));

	//����
	FindClose(hFind);
	// -----------------------------------------

	stage = MV1LoadModel("Model/Otameshi/room/droidroom.x");

	player = std::make_unique<Player>(playerModel ,playerAnim);

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
	auto Sscale = VGet(0.5f, 0.5f, 0.5f);
	auto Srol = VGet(0.0f, 0.0f, 0.0f);
	MV1SetPosition(stage, Spos);
	MV1SetRotationXYZ(stage, Srol);
	MV1SetScale(stage, Sscale );
	MV1DrawModel(stage);

	// �e�X�V����
	player->Render();
	DrawString(0, 0, "�ްщ��", 0xffffff);
}