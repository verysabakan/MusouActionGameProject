//------------------------------------------------------
// @brief	�Ȱ�ެ��̎��
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �����蔻�������޼ު�Ă̎��
enum class MANAGER_TYPE
{
	PLAYER_MANAGER,		// ��ڲ԰
	STAGE_MANAGER,		// �ð��
	ENAMY_MANAGER,		// ��а
	SHOT_MANAGER,		// �e
	WEAPON_MANAGER,		// ����
	OBSTACLE_MANAGER,	// ��Q��
	TERRAIN_MANAGER,	// �n�`

	NONE,				// �����Ȃ�
	MANAGER_TYPE_NUM	// �Ȱ�ެ��̎�ސ�(�ő�l)
};

MANAGER_TYPE begin(MANAGER_TYPE);					// MANAGER_TYPE�̐擪�̗v�f��Ԃ�
MANAGER_TYPE end(MANAGER_TYPE);						// MANAGER_TYPE�̖��[��Ԃ�
MANAGER_TYPE operator*(MANAGER_TYPE& type);			// �������g��Ԃ�
MANAGER_TYPE operator++(MANAGER_TYPE& type);		// MANAGER_TYPE��++�̌v�Z
MANAGER_TYPE operator+(MANAGER_TYPE& type, int k);	// MANAGER_TYPE�ɑ΂��鑫���Z
MANAGER_TYPE operator-(MANAGER_TYPE& type, int k);	// MANAGER_TYPE�ɑ΂�������Z

