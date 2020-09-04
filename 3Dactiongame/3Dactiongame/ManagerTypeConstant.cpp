//------------------------------------------------------
// @brief	�Ȱ�ެ��̎��
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ManagerTypeConstant.h"

//------------------------------------------------------
// @brief	MANAGER_TYPE�̐擪�̗v�f��Ԃ�
//------------------------------------------------------
MANAGER_TYPE begin(MANAGER_TYPE)
{
	return MANAGER_TYPE::PLAYER_MANAGER;
}

//------------------------------------------------------
// @brief	MANAGER_TYPE�̖��[��Ԃ�
//------------------------------------------------------
MANAGER_TYPE end(MANAGER_TYPE)
{
	return MANAGER_TYPE::MANAGER_TYPE_NUM;
}

//------------------------------------------------------
// @brief	�������g��Ԃ�
//------------------------------------------------------
MANAGER_TYPE operator*(MANAGER_TYPE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	MANAGER_TYPE��++�̌v�Z
//------------------------------------------------------
MANAGER_TYPE operator++(MANAGER_TYPE& id)
{
	// underlying_type����̫�Ă̊��^int���擾�����Z����
	return id = MANAGER_TYPE(std::underlying_type<MANAGER_TYPE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	MANAGER_TYPE�ɑ΂��鑫���Z
//------------------------------------------------------
MANAGER_TYPE operator+(MANAGER_TYPE& id, int k)
{
	return static_cast<MANAGER_TYPE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	MANAGER_TYPE�ɑ΂�������Z
//------------------------------------------------------
MANAGER_TYPE operator-(MANAGER_TYPE& id, int k)
{
	return static_cast<MANAGER_TYPE>(static_cast<int> (id) - k);
}