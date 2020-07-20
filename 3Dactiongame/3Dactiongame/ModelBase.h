//------------------------------------------------------
// @brief	(���)���ق̂��߂̊��
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <DxLib.h>
#include <vector>
#include "Vector3.h"
#include "ObjectTypeBace.h"

class ModelBase
	:public ObjectTypeBace
{
protected:
	// ���݂̱�Ұ��݂̏�ԁAM:�ړ�
	enum ANIM_STATE
	{
		ANIM_DEAD,
		ANIM_DOWN,
		ANIM_DAMAGE,
		ANIM_STUN,
		ANIM_JUMP,
		ANIM_SKILL1,
		ANIM_SKILL2,
		ANIM_SKILL3,
		ANIM_ATTACK1,
		ANIM_ATTACK2,
		ANIM_BROCK,
		ANIM_WALK,
		ANIM_RUN,
		ANIM_STANCE
	};

	ANIM_STATE animState;		// ���݂���ڲ԰�̏��
	ANIM_STATE oldAnimState;	// �O����ڲ԰�̏��

	int modelHandle;				// �����ް��p
	std::vector<int> animHandle;	// ��Ұ����ް��p
	Vector3 target;		// �����Ă������
	Vector3 pos;		// XYZ������
	Vector3 rol;		// ��]
	Vector3 scl;		// �傫��
	Vector3 hitpos;		// ���苅�̒��S
	float hitR;			// ���苅�̔��a
	// ��Ұ���
	int attachiIndex;	// ��Ҕԍ��o�^
	float totalTime;	// �Đ�������
	float playTime;		// �Đ��ӏ�
	Vector3 moveSpeed;	// �ړ����x

	void SetAnimID(int mH, int no);		// ��Ұ���ID�̾��
	
	//------------------------------------------
	// �Ƃ肠�����̂��
	//------------------------------------------
	bool moveFlag = false;

public:
	ModelBase();			// �ݽ�׸�
	~ModelBase();			// �޽�׸�

	Vector3 GetPosition() { return pos; }	// �ʒu���擾
	Vector3 GetRotation() { return rol; }	// ��]���擾
	Vector3 GetTarget() { return target; }	// �ڕW���擾
	Vector3 GetHitSpherePositon() { return hitpos; }	// �����������̈ʒu�̎擾
	float GetHitRadiusPositon() { return hitR; }		// ���a�̎擾
	std::vector<int> GetAnimHandle() { return animHandle; }	// ��Ұ�������ق̎擾
	ANIM_STATE GetAnimState() { return animState; }			// ���݂̱�Ұ��݂̎擾
	Vector3 GetFramePosition(int n);					// �ڰт̍��W�̎擾

	virtual ObjectType GetType() override;				// ��޼ު�Ă̎�ނ��擾

	//------------------------------------------
	// �Ƃ肠�����̂��
	//------------------------------------------
	bool JumpState()		// �ެ��ߒ�
	{
		if (animState == ANIM_JUMP)
		{
			true;
		}
		return false;
	}

	float RiseY()
	{
		return moveSpeed.y;
	}

	bool MoveFlag()
	{
		return moveFlag;
	}

	void SetPosY(const float& y)
	{
		pos.y = y;
	}
};