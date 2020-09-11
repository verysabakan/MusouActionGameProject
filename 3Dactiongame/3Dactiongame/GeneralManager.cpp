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

#include "toriaezu.h"

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

	//------------------------------------------------------
	// �Ƃ肠�����̂��
	TorimaInitialize();
	//------------------------------------------------------
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
	// �e�I������
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Finalize();
		i->reset();
	}
	fCollision->Finalize();

	// ؿ���̊J��
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
		(*i)->Update();	}

	// �S�Ă̍X�V���I�������̏���
	for (auto m1 = mgrList->begin(); m1 != mgrList->end(); m1++)
	{
		for (auto m2 = mgrList->begin(); m2 != mgrList->end(); m2++)
		{
			for (auto i = (*m1)->GetObjectList()->begin(); i != (*m1)->GetObjectList()->end(); i++)
			{
				for (auto j = (*m2)->GetObjectList()->begin(); j != (*m2)->GetObjectList()->end(); j++)
				{
					//fCollision->HitCheck((*i), (*j));
					//------------------------------------------------------
					// �Ƃ肠�����̂��
					if ((*i)->GetType() == OBJECT_TYPE::OBJECT_TYPE_PLAYER &&
						(*j)->GetType() == OBJECT_TYPE::OBJECT_TYPE_TERRAIN)
					{
						HitCheckStageAndPlayer((*i), (*j));
						TorimaUpdate((*i));
					}
					//------------------------------------------------------
				}
			}
		}
	}
	int f = 0;
	/*
	for (auto m1 = mgrList->begin(); m1 != mgrList->end(); m1++)
	{
		for (auto m2 = mgrList->begin(); m2 != mgrList->end(); m2++)
		{
			for (auto i = (*m1)->GetObjectList()->begin(); i != (*m1)->GetObjectList()->end(); i++)
			{
				for (auto j = (*m2)->GetObjectList()->begin(); j != (*m2)->GetObjectList()->end(); j++)
				{
					//fCollision->HitCheck((*i), (*j));
					//------------------------------------------------------
					// �Ƃ肠�����̂��
					if ((*i)->GetType() == OBJECT_TYPE::OBJECT_TYPE_PLAYER &&
						(*j)->GetType() == OBJECT_TYPE::OBJECT_TYPE_TERRAIN)
					{
						HitCheckStageAndPlayer((*i), (*j));
						TorimaUpdate((*i));
					}
					//------------------------------------------------------
				}
			}
		}
	}
	*/
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

	//------------------------------------------------------
	// �Ƃ肠�����̂��
	Draw();
	DrawString(0, 0, "�ްщ��", 0xffffff);
	//------------------------------------------------------
}