//------------------------------------------------------
// @brief	��޼ު�Ă̎�ނ̊��׽
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectTypeConstant.h"
#include "Vector3.h"

class ObjectBase
{
protected:
	Vector3 moveDir;	// �ړ�����

public:
	ObjectBase();				// �ݽ�׸�
	virtual ~ObjectBase();		// �޽�׸�

	virtual void Initialize() {}	// ������
	virtual void Finalize() {}		// �I������
	virtual void Update() {}		// �X�V
	virtual void Render() {}		// �`��

	virtual ObjectType GetType() = 0;	// ��޼ު�Ă̎�ނ��擾:�K������


	// �O������̕ύX
	void SetMoveDir(const Vector3& cameraDir);
};

