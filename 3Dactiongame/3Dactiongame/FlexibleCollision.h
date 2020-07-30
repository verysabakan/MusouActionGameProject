//------------------------------------------------------
// @brief	�C�ӂ̵�޼ު�ē��m�̓����蔻����s��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "CollisionBase.h"

class FlexibleCollision
	:private CollisionBase
{
private:
	// �����蔻��e�[�u��
	std::shared_ptr<CollisionBase> colTable[static_cast<int>(ObjectType::OBJECTTYPE_NUM)][static_cast<int>(ObjectType::OBJECTTYPE_NUM)];

public:
	FlexibleCollision();	// �ݽ�׸�
	virtual ~FlexibleCollision();	// �޽�׸�

	void Initialize();		// ������
	void Finalize();		// �I������
	// void Update();			// �X�V
	// void Render();	// �`��

	virtual bool HitCheck(const ObjectType& o1, const ObjectType& o2) override;

};

