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
	objList = std::make_shared<OBJECT_LIST>();
	AddList(objList, std::make_shared<Player>(playerModel, playerAnim));

	camera = std::make_unique<Camera>(GetPlayer());
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
	// �e����������
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Initialize();
	}
	camera->Initialize();
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void PlayerManager::Finalize()
{
	// �e�I�����Aؿ���̊J��
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		
		(*i)->Finalize();
		(*i).reset();
	}
	camera->Finalize();
	camera.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void PlayerManager::Update()
{
	// �e�X�V����
	SetPlayerMoveDir(camera->GetCameraDir());
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Update();
	}
	camera->Update();
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void PlayerManager::Render()
{
	// �e�`�揈��
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Render();
	}
	camera->Renderer();
}

//------------------------------------------------------
// @brief	ObjectBase�̎擾
//			���̂܂܂��ƈ�l�v���C�����ł��Ȃ��̂�
//			�����l�łł���悤�ɂ���
//------------------------------------------------------
ModelBase* PlayerManager::GetPlayer()
{
	return dynamic_cast<ModelBase*>(objList->begin()->get());
}

//------------------------------------------------------
// @brief	�e��ׂ������ڲ԰�̓��������̎󂯓n������
//------------------------------------------------------
void PlayerManager::SetPlayerMoveDir(const Vector3& cameraDir)
{
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->SetMoveDir(cameraDir);
	}
}

//------------------------------------------------------
// @brief	���߂̎擾(�ǂ����߂��m���߂�)
//------------------------------------------------------
bool PlayerManager::GetManagerType(MANAGER_TYPE type)
{
	return (type == MANAGER_TYPE::PLAYER_MANAGER);
}