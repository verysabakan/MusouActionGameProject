//------------------------------------------------------
// @brief	���͏��
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ���͏��
enum class INPUT_STATE
{
	INPUT_HOLD,	// ������
	INPUT_TRG,	// �������u��
	INPUT_UP,	// �b�����u��

	INPUT_NUM	// ��Ԃ̎�ސ�(�ő吔)
};

INPUT_STATE begin(INPUT_STATE);						// INPUT_STATE�̐擪�̗v�f��Ԃ�
INPUT_STATE end(INPUT_STATE);						// INPUT_STATE�̖��[��Ԃ�
INPUT_STATE operator*(INPUT_STATE& type);			// �������g��Ԃ�
INPUT_STATE operator++(INPUT_STATE& type);			// INPUT_STATE��++�̌v�Z
INPUT_STATE operator+(INPUT_STATE& type, int k);	// INPUT_STATE�ɑ΂��鑫���Z
INPUT_STATE operator-(INPUT_STATE& type, int k);	// INPUT_STATE�ɑ΂�������Z
