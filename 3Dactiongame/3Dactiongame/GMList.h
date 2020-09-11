//------------------------------------------------------
// @brief	��޼ު�Ă��i�[���邽�߂�ؽ�
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <list>
#include <memory>
#include "ManagerBase.h"

using MANAGER_PTR = std::shared_ptr<ManagerBase>;			// �X�̵�޼ު���߲��
using MANAGER_LIST = std::list<MANAGER_PTR>;				// �X�̵�޼ު���߲����ؽ�
using MANAGER_LIST_PTR = std::shared_ptr<MANAGER_LIST>;		// MANAGER_PTR_LIST�ŏ��̱��ڽ
using MANAGER_WEAK_LIST = std::weak_ptr<MANAGER_LIST>;				// ��Q�ƁA���������߲��

using MANAGER_LIST_ITERATOR = MANAGER_LIST::iterator;		// OBJECT_LIST�̲�ڰ�

class GMList
{
protected:
	MANAGER_LIST_PTR mgrList;

protected:
	void AddList(MANAGER_WEAK_LIST w, MANAGER_PTR o);	// ؽĂɒǉ�

public:
	GMList();			// �ݽ�׸�
	virtual ~GMList();	// �޽�׸�

};



