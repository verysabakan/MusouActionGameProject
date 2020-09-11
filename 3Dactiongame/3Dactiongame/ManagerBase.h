//------------------------------------------------------
// @brief	�Ȱ�ެ��̊��
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

//#include "ManagerTypeConstant.h"
#include "ObjectList.h"

class ManagerBase
	:public ObjectList
{
public:
	ManagerBase();			// �ݽ�׸�
	virtual ~ManagerBase();	// �޽�׸�

	virtual void Initialize() {}	// ������
	virtual void Finalize() {}		// �I������
	virtual void Update() {}		// �X�V
	virtual void Render() {}		// �`��

	OBJECT_LIST_PTR GetObjectList();	// OBJECT_LIST_PTR�̎擾
};

