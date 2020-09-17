//------------------------------------------------------
// @brief	�߯�ނɑΉ�����enum
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ���͏��
enum class PAD_BUTTON
{
	PAD_UP,
	PAD_DOWN,
	PAD_LEFT,
	PAD_RIGHT,
	PAD_1,
	PAD_2,
	PAD_3,
	PAD_4,
	PAD_BUTTON_NUM	// ��Ԃ̎�ސ�(�ő吔)
};

PAD_BUTTON begin(PAD_BUTTON);						// PAD_BUTTON�̐擪�̗v�f��Ԃ�
PAD_BUTTON end(PAD_BUTTON);							// PAD_BUTTON�̖��[��Ԃ�
PAD_BUTTON operator*(PAD_BUTTON& button);			// �������g��Ԃ�
PAD_BUTTON operator++(PAD_BUTTON& button);			// PAD_BUTTON��++�̌v�Z
PAD_BUTTON operator+(PAD_BUTTON& button, int k);	// PAD_BUTTON�ɑ΂��鑫���Z
PAD_BUTTON operator-(PAD_BUTTON& button, int k);	// PAD_BUTTON�ɑ΂�������Z

int ConvertNum(const PAD_BUTTON& button);	// PAD_BUTTON��int�ɕϊ����ĕԂ�