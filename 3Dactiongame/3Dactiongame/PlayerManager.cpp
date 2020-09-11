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
	
	// ��޼ު�č\�z
	objList = std::make_shared<OBJECT_LIST>();
	AddList(objList, std::make_shared<Player>(playerModel, playerAnim));

	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		camera = std::make_unique<Camera>((*i));
	}
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
	// �e�I�������Aؿ���̊J��
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
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->SetMoveDir(camera->GetCameraDir());
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
