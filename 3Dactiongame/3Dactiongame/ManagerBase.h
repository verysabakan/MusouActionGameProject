//------------------------------------------------------
// @brief	��޼ު�Ă��i�[���邽�߂�ؽ�
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ManagerTypeConstant.h"

class ManagerBase
{
public:
	ManagerBase();	// �ݽ�׸�
	virtual ~ManagerBase();	// �޽�׸�

	virtual void Initialize() {}	// ������
	virtual void Finalize() {}		// �I������
	virtual void Update() {}		// �X�V
	virtual void Render() {}		// �`��

	virtual bool GetManagerType(MANAGER_TYPE type) = 0;	// ��޼ު�Ă����ߎ擾�֐�
};

