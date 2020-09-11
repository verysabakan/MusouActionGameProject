//------------------------------------------------------
// @brief	��޼ު�Ă̎��
// 2020 7/27 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ObjectTypeConstant.h"

//------------------------------------------------------
// @brief	OBJECT_TYPE�̐擪�̗v�f��Ԃ�
//------------------------------------------------------
OBJECT_TYPE begin(OBJECT_TYPE)
{
	return OBJECT_TYPE::OBJECT_TYPE_PLAYER;
}

//------------------------------------------------------
// @brief	OBJECT_TYPE�̖��[��Ԃ�
//------------------------------------------------------
OBJECT_TYPE end(OBJECT_TYPE)
{
	return OBJECT_TYPE::OBJECT_TYPE_NUM;
}

//------------------------------------------------------
// @brief	�������g��Ԃ�
//------------------------------------------------------
OBJECT_TYPE operator*(OBJECT_TYPE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	OBJECT_TYPE��++�̌v�Z
//------------------------------------------------------
OBJECT_TYPE operator++(OBJECT_TYPE& id)
{
	// underlying_type����̫�Ă̊��^int���擾�����Z����
	return id = OBJECT_TYPE(std::underlying_type<OBJECT_TYPE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	OBJECT_TYPE�ɑ΂��鑫���Z
//------------------------------------------------------
OBJECT_TYPE operator+(OBJECT_TYPE& id, int k)
{
	return static_cast<OBJECT_TYPE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	OBJECT_TYPE�ɑ΂�������Z
//------------------------------------------------------
OBJECT_TYPE operator-(OBJECT_TYPE& id, int k)
{
	return static_cast<OBJECT_TYPE>(static_cast<int> (id) - k);
}