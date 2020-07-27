//------------------------------------------------------
// @brief	��޼ު�Ă̎��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �����蔻�������޼ު�Ă̎��
enum class ObjectType
{
	OBJECTTYPE_PLAYER,			// ��ڲ԰
	OBJECTTYPE_ENEMY,			// ��а
	OBJECTTYPE_SHOT,			// �e
	OBJECTTYPE_WEAPON,			// ����
	OBJECTTYPE_OBSTACLE,		// ��Q��
	OBJECTTYPE_TERRAIN,			// �n�`

	NONE,						// �����Ȃ�
	OBJECTTYPE_NUM				// �����蔻�������޼ު�Ă̎�ސ�(�ő�l)
};

ObjectType begin(ObjectType);					// ObjectType�̐擪�̗v�f��Ԃ�
ObjectType end(ObjectType);						// ObjectType�̖��[��Ԃ�
//ObjectType operator*(ObjectType& type);			// �������g��Ԃ�
ObjectType operator++(ObjectType& type);		// ObjectType��++�̌v�Z
ObjectType operator+(ObjectType& type, int k);	// ObjectType�ɑ΂��鑫���Z
ObjectType operator-(ObjectType& type, int k);	// ObjectType�ɑ΂�������Z
