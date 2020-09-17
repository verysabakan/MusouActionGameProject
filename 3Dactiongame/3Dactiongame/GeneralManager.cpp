//------------------------------------------------------
// @brief	�Ȱ�ެ����i�[���邽�߂�ؽ�
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>

#include "GeneralManager.h"
#include "LoadModel.h"
#include "PlayerManager.h"
#include "StageManager.h"
#include "FlexibleCollision.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
GeneralManager::GeneralManager(const STAGE_TYPE& sT)
{
	// ����
	mgrList = std::make_shared<MANAGER_LIST>();
	AddList(mgrList, std::make_shared<PlayerManager>());
	AddList(mgrList, std::make_shared<StageManager>(sT));

	fCollision = std::make_unique<FlexibleCollision>();
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
GeneralManager::~GeneralManager()
{
	// �ُ�I��������
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		assert((*i) == NULL);
	}
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void GeneralManager::Initialize()
{
	// �e������
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Initialize();
	}
	fCollision->Initialize();
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void GeneralManager::Finalize()
{
	// �e�I�������Aؿ���̊J��
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Finalize();
		i->reset();
	}
	fCollision->Finalize();
	fCollision.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GeneralManager::Update()
{
	// �e�X�V
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Update();
	}

	// �S�Ă̍X�V���I�������̏���
	for (auto m1 = mgrList->begin(); m1 != mgrList->end(); m1++)
	{
		for (auto m2 = mgrList->begin(); m2 != mgrList->end(); m2++)
		{
			for (auto i = (*m1)->GetObjectList()->begin(); i != (*m1)->GetObjectList()->end(); i++)
			{
				for (auto j = (*m2)->GetObjectList()->begin(); j != (*m2)->GetObjectList()->end(); j++)
				{
					// �����蔻��
					fCollision->HitCheck((*i), (*j));
				}
			}
		}
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GeneralManager::Render()
{
	// �e�`��
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Render();
	}
}