//------------------------------------------------------
// @brief	��޼ު�Ă��i�[���邽�߂�ؽ�(��������Ȃ���)
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <list>
#include <memory>
#include "ObjectBase.h"

using OBJECT_PTR = std::shared_ptr<ObjectBase>;			// �X�̵�޼ު���߲��
using OBJECT_LIST = std::list<OBJECT_PTR>;				// �X�̵�޼ު���߲����ؽ�
using OBJECT_LIST_PTR = std::shared_ptr<OBJECT_LIST>;	// OBJECT_PTR_LIST�ŏ��̱��ڽ
using OBJECT_WEAK_LIST = std::weak_ptr<OBJECT_LIST>;	// ��Q�ƁA���������߲��

using OBJECT_LIST_ITERATOR = OBJECT_LIST::iterator;		// OBJECT_LIST�̲�ڰ�

class ObjectList
{
protected:
	OBJECT_LIST_PTR objList;	// �i�[�p��ؽĂ��߲��

protected:
	void AddList(OBJECT_WEAK_LIST w, OBJECT_PTR o);	// ؽĂɒǉ�

public:
	ObjectList();				// �ݽ�׸�
	virtual ~ObjectList();		// �޽�׸�

};

