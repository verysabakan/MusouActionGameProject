//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "Stage.h"
#include "StageManager.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
StageManager::StageManager(const STAGE_TYPE& sT)
{
	// ��޼ު�Ă��\�z
	objList = std::make_shared<OBJECT_LIST>();
	AddList(objList, std::make_shared<Stage>(sT));
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
StageManager::~StageManager()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Initialize()
{
	// �e����������
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Initialize();
	}
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Finalize()
{
	// �e�I�������Aؿ���̊J��
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Finalize();
		(*i).reset();
	}
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Update()
{
	// �e�X�V����
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Update();
	}
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Render()
{
	// �e�`�揈��
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Render();
	}
}
