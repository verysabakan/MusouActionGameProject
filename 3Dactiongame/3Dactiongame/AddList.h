//------------------------------------------------------
// @brief	ؽĂɉ�����
// 2020 7/30 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include <list>

// �������ߐ錾
class ObjectBase;

using OBJECT_PTR = std::shared_ptr<ObjectBase>;		// �X�̵�޼ު�Ă��߲��
using OBJECT_LIST = std::list<OBJECT_PTR>;				// �X�̵�޼ު�Ă��߲����ؽ�
using OBJECT_LIST_PTR = std::shared_ptr<OBJECT_LIST>;	// OBJECT_PTR_List�ŏ��̱��ڽ
using WEAK_LIST = std::weak_ptr<OBJECT_LIST>;			// ��Q�ƁA���������߲��

using OBJECT_LIST_ITERATOR = OBJECT_LIST::iterator;		// OBJECT_LIST�̲�ڰ�

// �ݽ�ݽ��������޼ު�Ă�ؽĂɉ�����
struct AddList
{
	// �ݽ�ݽ��������ؽĂɊi�[
	OBJECT_LIST_ITERATOR operator()(const WEAK_LIST& weakList, const OBJECT_PTR& objPtr)
	{
		weakList.lock()->push_back(objPtr);	// ؽĂ̖�����OBJECT_PTR��ǉ�
		OBJECT_LIST_ITERATOR itr = weakList.lock()->end();	// ����
		itr--;		// ��������O��ϲŽ(end�ł͖����̎��ɂȂ邽��)
		return itr;	// �^���_�̂���
	}
};