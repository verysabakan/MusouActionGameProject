//------------------------------------------------------
// @brief	��޼ު�Ă̎��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �����蔻�������޼ު�Ă̎��
enum class OBJECT_TYPE
{
	OBJECT_TYPE_PLAYER,			// ��ڲ԰
	OBJECT_TYPE_ENEMY,			// ��а
	OBJECT_TYPE_SHOT,			// �e
	OBJECT_TYPE_WEAPON,			// ����
	OBJECT_TYPE_OBSTACLE,		// ��Q��
	OBJECT_TYPE_TERRAIN,			// �n�`

	NONE,						// �����Ȃ�
	OBJECT_TYPE_NUM				// �����蔻�������޼ު�Ă̎�ސ�(�ő�l)
};

OBJECT_TYPE begin(OBJECT_TYPE);						// OBJECT_TYPE�̐擪�̗v�f��Ԃ�
OBJECT_TYPE end(OBJECT_TYPE);						// OBJECT_TYPE�̖��[��Ԃ�
OBJECT_TYPE operator*(OBJECT_TYPE& type);			// �������g��Ԃ�
OBJECT_TYPE operator++(OBJECT_TYPE& type);			// OBJECT_TYPE��++�̌v�Z
OBJECT_TYPE operator+(OBJECT_TYPE& type, int k);	// OBJECT_TYPE�ɑ΂��鑫���Z
OBJECT_TYPE operator-(OBJECT_TYPE& type, int k);	// OBJECT_TYPE�ɑ΂�������Z
