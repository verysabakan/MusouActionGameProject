//------------------------------------------------------
// @brief	�߯�ނɑΉ�����enum
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "PadButtonConstant.h"

//------------------------------------------------------
// @brief	PAD_BUTTON�̐擪�̗v�f��Ԃ�
//------------------------------------------------------
PAD_BUTTON begin(PAD_BUTTON)
{
	return PAD_BUTTON::PAD_UP;
}

//------------------------------------------------------
// @brief	PAD_BUTTON�̖��[��Ԃ�
//------------------------------------------------------
PAD_BUTTON end(PAD_BUTTON)
{
	return PAD_BUTTON::PAD_BUTTON_NUM;
}

//------------------------------------------------------
// @brief	�������g��Ԃ�
//------------------------------------------------------
PAD_BUTTON operator*(PAD_BUTTON& button)
{
	return button;
}

//------------------------------------------------------
// @brief	PAD_BUTTON��++�̌v�Z
//------------------------------------------------------
PAD_BUTTON operator++(PAD_BUTTON& button)
{
	// underlying_type����̫�Ă̊��^int���擾�����Z����
	return button = PAD_BUTTON(std::underlying_type<PAD_BUTTON>::type(button) + 1);
}

//------------------------------------------------------
// @brief	PAD_BUTTON�ɑ΂��鑫���Z
//------------------------------------------------------
PAD_BUTTON operator+(PAD_BUTTON& button, int k)
{
	return static_cast<PAD_BUTTON>(static_cast<int> (button) + k);
}

//------------------------------------------------------
// @brief	PAD_BUTTON�ɑ΂�������Z
//------------------------------------------------------
PAD_BUTTON operator-(PAD_BUTTON& button, int k)
{
	return static_cast<PAD_BUTTON>(static_cast<int> (button) - k);
}

//------------------------------------------------------
// @brief	PAD_BUTTON��int�ɕϊ����ĕԂ�
//------------------------------------------------------
int ConvertNum(const PAD_BUTTON& button)
{
	return static_cast<int>(button);
}