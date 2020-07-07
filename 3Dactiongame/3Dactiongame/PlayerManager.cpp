//------------------------------------------------------
// @brief	��ڲ԰�̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "PlayerManager.h"
#include "Player.h"
#include "LoadModel.h"
#include "Camera.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
PlayerManager::PlayerManager()
{
	// -------------------------------------------
	// ���̓ǂݍ��ݕ��@�͌�ŕύX����
	// -------------------------------------------
	int playerModel;
	std::vector<int> playerAnim;
	// �K�v���ް��̓ǂݍ���
	LoadPlayerModelData(playerModel, playerAnim);

	// ��޼ު�Đ���
	player = std::make_unique<Player>(playerModel, playerAnim);
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
PlayerManager::~PlayerManager()
{

}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void PlayerManager::Initialize()
{
	player->Initialize();
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void PlayerManager::Finalize()
{
	// �e�I������
	player->Finalize();

	// ؿ���̊J��
	player.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void PlayerManager::Update(const Vector3& cameraDir)
{
	// �e�X�V����
	player->Update(cameraDir);
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void PlayerManager::Render()
{
	player->Render();
}

//------------------------------------------------------
// @brief	��ڲ԰���擾
//------------------------------------------------------
Player* PlayerManager::GetPlayer()
{
	return player.get();
}

