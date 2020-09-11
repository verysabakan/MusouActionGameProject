//------------------------------------------------------
// @brief	��ׂ̍s�����
// 2020 9/8 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ActionStateConstant.h"

//------------------------------------------------------
// @brief	ObjectType�̐擪�̗v�f��Ԃ�
//------------------------------------------------------
ACTION_STATE begin(ACTION_STATE)
{
	return ACTION_STATE::ACTION_STATE_DEAD;
}

//------------------------------------------------------
// @brief	ObjectType�̖��[��Ԃ�
//------------------------------------------------------
ACTION_STATE end(ACTION_STATE)
{
	return ACTION_STATE::ACTION_STATE_NUM;
}

//------------------------------------------------------
// @brief	�������g��Ԃ�
//------------------------------------------------------
ACTION_STATE operator*(ACTION_STATE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	ObjectType��++�̌v�Z
//------------------------------------------------------
ACTION_STATE operator++(ACTION_STATE& id)
{
	// underlying_type����̫�Ă̊��^int���擾�����Z����
	return id = ACTION_STATE(std::underlying_type<ACTION_STATE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	ObjectType�ɑ΂��鑫���Z
//------------------------------------------------------
ACTION_STATE operator+(ACTION_STATE& id, int k)
{
	return static_cast<ACTION_STATE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	ObjectType�ɑ΂�������Z
//------------------------------------------------------
ACTION_STATE operator-(ACTION_STATE& id, int k)
{
	return static_cast<ACTION_STATE>(static_cast<int> (id) - k);
}