//------------------------------------------------------
// @brief	��ׂ̍s�����
// 2020 9/8 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �����蔻�������޼ު�Ă̎��
enum class ACTION_STATE
{
	ACTION_STATE_DEAD,		// 
	ACTION_STATE_DOWN,		// 
	ACTION_STATE_DAMAGE,	// 
	ACTION_STATE_STUN,		// 
	ACTION_STATE_JUMP,		// 
	ACTION_STATE_SKILL1,	// 
	ACTION_STATE_SKILL2,	// 
	ACTION_STATE_SKILL3,	// 
	ACTION_STATE_ATTACK1,	// 
	ACTION_STATE_ATTACK2,	// 
	ACTION_STATE_BROCK,		// 
	ACTION_STATE_WALK,		// 
	ACTION_STATE_RUN,		// 
	ACTION_STATE_STANCE,	// 

	ACTION_STATE_NUM		// ��ׂ̍s���̏�Ԑ�(�ő�l)
};

ACTION_STATE begin(ACTION_STATE);					// ACTION_STATE�̐擪�̗v�f��Ԃ�
ACTION_STATE end(ACTION_STATE);						// ACTION_STATE�̖��[��Ԃ�
ACTION_STATE operator*(ACTION_STATE& type);			// �������g��Ԃ�
ACTION_STATE operator++(ACTION_STATE& type);		// ACTION_STATE��++�̌v�Z
ACTION_STATE operator+(ACTION_STATE& type, int k);	// ACTION_STATE�ɑ΂��鑫���Z
ACTION_STATE operator-(ACTION_STATE& type, int k);	// ACTION_STATE�ɑ΂�������Z
