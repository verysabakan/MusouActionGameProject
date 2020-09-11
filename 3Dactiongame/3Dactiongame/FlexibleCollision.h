//------------------------------------------------------
// @brief	�C�ӂ̵�޼ު�ē��m�̓����蔻����s��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "CollisionBase.h"

class FlexibleCollision
	:private CollisionBase
{
private:
	// �����蔻��e�[�u��
	std::unique_ptr<CollisionBase> colTable
		[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_NUM)]
		[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_NUM)];

	// make�������̂������Ă���ԍ����i�[
	std::vector<OBJECT_TYPE> useTypeList1;
	std::vector<OBJECT_TYPE> useTypeList2;

public:
	FlexibleCollision();			// �ݽ�׸�
	virtual ~FlexibleCollision();	// �޽�׸�

	void Initialize();		// ������
	void Finalize();		// �I������
	// void Update();		// �X�V
	// void Render();		// �`��

	virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) override;

};

