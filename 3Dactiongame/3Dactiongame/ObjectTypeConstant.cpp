//------------------------------------------------------
// @brief	��޼ު�Ă̎��
// 2020 7/27 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ObjectTypeConstant.h"

//------------------------------------------------------
// @brief	ObjectType�̐擪�̗v�f��Ԃ�
//------------------------------------------------------
ObjectType begin(ObjectType)
{
	return ObjectType::OBJECTTYPE_PLAYER;
}

//------------------------------------------------------
// @brief	ObjectType�̖��[��Ԃ�
//------------------------------------------------------
ObjectType end(ObjectType)
{
	return ObjectType::OBJECTTYPE_NUM;
}

//------------------------------------------------------
// @brief	�������g��Ԃ�
//------------------------------------------------------
ObjectType operator*(ObjectType& id)
{
	return id;
}

//------------------------------------------------------
// @brief	ObjectType��++�̌v�Z
//------------------------------------------------------
ObjectType operator++(ObjectType& id)
{
	// underlying_type����̫�Ă̊��^int���擾�����Z����
	return id = ObjectType(std::underlying_type<ObjectType>::type(id) + 1);
}

//------------------------------------------------------
// @brief	ObjectType�ɑ΂��鑫���Z
//------------------------------------------------------
ObjectType operator+(ObjectType& id, int k)
{
	return static_cast<ObjectType>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	ObjectType�ɑ΂�������Z
//------------------------------------------------------
ObjectType operator-(ObjectType& id, int k)
{
	return static_cast<ObjectType>(static_cast<int> (id) - k);
}
