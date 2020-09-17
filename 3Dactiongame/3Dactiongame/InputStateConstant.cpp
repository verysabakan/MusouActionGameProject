//------------------------------------------------------
// @brief	��ׂ̍s�����
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "InputStateConstant.h"

//------------------------------------------------------
// @brief	INPUT_STATE�̐擪�̗v�f��Ԃ�
//------------------------------------------------------
INPUT_STATE begin(INPUT_STATE)
{
	return INPUT_STATE::INPUT_HOLD;
}

//------------------------------------------------------
// @brief	INPUT_STATE�̖��[��Ԃ�
//------------------------------------------------------
INPUT_STATE end(INPUT_STATE)
{
	return INPUT_STATE::INPUT_NUM;
}

//------------------------------------------------------
// @brief	�������g��Ԃ�
//------------------------------------------------------
INPUT_STATE operator*(INPUT_STATE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	INPUT_STATE��++�̌v�Z
//------------------------------------------------------
INPUT_STATE operator++(INPUT_STATE& id)
{
	// underlying_type����̫�Ă̊��^int���擾�����Z����
	return id = INPUT_STATE(std::underlying_type<INPUT_STATE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	INPUT_STATE�ɑ΂��鑫���Z
//------------------------------------------------------
INPUT_STATE operator+(INPUT_STATE& id, int k)
{
	return static_cast<INPUT_STATE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	INPUT_STATE�ɑ΂�������Z
//------------------------------------------------------
INPUT_STATE operator-(INPUT_STATE& id, int k)
{
	return static_cast<INPUT_STATE>(static_cast<int> (id) - k);
}