//------------------------------------------------------
// @brief	�C�ӂ̵�޼ު�ē��m�̓����蔻����s��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include "FlexibleCollision.h"
#include "PlayerAndTerrain.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
FlexibleCollision::FlexibleCollision()
{
	// ����̐���
	colTable[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_PLAYER)]
				[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_TERRAIN)]
		= std::make_unique<PlayerAndTerrain>();	// ��ڲ԰�ƒn�`�̓����蔻��
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
FlexibleCollision::~FlexibleCollision()
{
	// �e������
	for (auto i = begin(OBJECT_TYPE()); i < end(OBJECT_TYPE()); ++i)
	{
		for (auto j = begin(OBJECT_TYPE()); j < end(OBJECT_TYPE()); ++j)
		{
			// �ُ�I��������
			assert(colTable[static_cast<int>(i)][static_cast<int>(j)] == NULL);
		}
	}
}
//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void FlexibleCollision::Initialize()
{
	// �e������
	for (auto i = begin(OBJECT_TYPE()); i < end(OBJECT_TYPE()); ++i)
	{
		for (auto j = begin(OBJECT_TYPE()); j < end(OBJECT_TYPE()); ++j)
		{
			if (colTable[static_cast<int>(i)][static_cast<int>(j)] != nullptr)
			{
				useTypeList1.push_back(i);
				useTypeList2.push_back(j);
			}
		}
	}
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void FlexibleCollision::Finalize()
{
	// �e�I������
	for (auto i = begin(OBJECT_TYPE()); i < end(OBJECT_TYPE()); ++i)
	{
		for (auto j = begin(OBJECT_TYPE()); j < end(OBJECT_TYPE()); ++j)
		{
			// ؿ���̊J��
			colTable[static_cast<int>(i)][static_cast<int>(j)].reset();

			// �v�f�̏�����
			useTypeList1.clear();
			useTypeList2.clear();
		}
	}
}

//------------------------------------------------------
// @brief	�����蔻��
//------------------------------------------------------
bool FlexibleCollision::HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2)
{
	// �v�f�������Ă��邩����
	for (auto i = 0; i < useTypeList1.size(); i++)
	{
		for (auto j = 0; j < useTypeList2.size(); j++)
		{
			// list�ɓ����Ė�����ν����
			if (!(useTypeList1[i] == o1->GetType() 
				&& useTypeList2[j] == o2->GetType()))
			{
				continue;
			}

			// ؽĂɓ����Ă���Δ�������
			return colTable[static_cast<int>(o1->GetType())]
				[static_cast<int>(o2->GetType())]->HitCheck(o1, o2);
		}
	}
	return false;	// �����Ȃ�����(�ُ�I��)
}

