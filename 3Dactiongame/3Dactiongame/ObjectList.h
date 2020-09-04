//------------------------------------------------------
// @brief	��޼ު�Ă��i�[���邽�߂�ؽ�
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <list>
#include <memory>
#include "ObjectBase.h"

using OBJECT_PTR = std::shared_ptr<ObjectBase>;			// �X�̵�޼ު���߲��
using OBJECT_LIST = std::list<OBJECT_PTR>;				// �X�̵�޼ު���߲����ؽ�
using OBJECT_LIST_PTR = std::shared_ptr<OBJECT_LIST>;	// OBJECT_PTR_LIST�ŏ��̱��ڽ
using OBJCT_WEAK_LIST = std::weak_ptr<OBJECT_LIST>;			// ��Q�ƁA���������߲��

using OBJECT_LIST_ITERATOR = OBJECT_LIST::iterator;		// OBJECT_LIST�̲�ڰ�

class ObjectList
{
protected:
	OBJECT_LIST_PTR objList;

public:
	ObjectList();				// �ݽ�׸�
	virtual ~ObjectList();	// �޽�׸�

	void AddList(OBJCT_WEAK_LIST w, OBJECT_PTR o);	// ؽĂɒǉ�
};

