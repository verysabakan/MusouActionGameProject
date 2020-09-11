//------------------------------------------------------
// @brief	(���)���ق̂��߂̊��
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <DxLib.h>
#include <vector>
#include "Vector3.h"
#include "ObjectTypeConstant.h"
#include "ActionStateConstant.h"

class ObjectBase
{
protected:
	//// ���݂̱�Ұ��݂̏�ԁAM:�ړ�
	//enum ANIM_STATE
	//{
	//	ANIM_DEAD,
	//	ANIM_DOWN,
	//	ANIM_DAMAGE,
	//	ANIM_STUN,
	//	ANIM_JUMP,
	//	ANIM_SKILL1,
	//	ANIM_SKILL2,
	//	ANIM_SKILL3,
	//	ANIM_ATTACK1,
	//	ANIM_ATTACK2,
	//	ANIM_BROCK,
	//	ANIM_WALK,
	//	ANIM_RUN,
	//	ANIM_STANCE
	//};

	//ANIM_STATE animState;		// ���݂���ڲ԰�̏��
	//ANIM_STATE oldAnimState;	// �O����ڲ԰�̏��

	ACTION_STATE actionState;		// ���݂���ڲ԰�̏��
	ACTION_STATE oldActionState;	// �O����ڲ԰�̏��

	int modelHandle;			// �����ް��p
	int collisionModelHandle;	// �ؼޮݗp���ق������
	int skyModelHandle;			// �����ق������
	std::vector<int> animHandle;	// ��Ұ����ް��p
	Vector3 target;		// �����Ă������
	Vector3 pos;		// XYZ������
	Vector3 rol;		// ��]
	Vector3 scl;		// �傫��
	Vector3 hitpos;		// ���苅�̒��S
	float hitR;			// ���苅�̔��a
	Vector3 moveDir;	// �ړ�����
	// ��Ұ���
	int attachiIndex;	// ��Ҕԍ��o�^
	float totalTime;	// �Đ�������
	float playTime;		// �Đ��ӏ�
	Vector3 moveSpeed;	// �ړ����x
	
	//------------------------------------------
	// �Ƃ肠�����̂��
	//------------------------------------------
	bool moveFlag = false;
	bool jumpFlag = false;
	float gravity;

public:
	ObjectBase();			// �ݽ�׸�
	virtual ~ObjectBase();			// �޽�׸�

	virtual void Initialize() {}	// ������
	virtual void Finalize() {}		// �I������
	virtual void Update() {}		// �X�V
	virtual void Render() {}		// �`��

	int GetCollisionModelHandle() { return collisionModelHandle; }	// �����蔻��p��������ق̎擾
	Vector3 GetPosition() { return pos; }	// �ʒu���擾
	Vector3 GetRotation() { return rol; }	// ��]���擾
	Vector3 GetTarget() { return target; }	// �ڕW���擾
	Vector3 GetHitSpherePositon() { return hitpos; }		// �����������̈ʒu�̎擾
	float GetHitRadiusPositon() { return hitR; }			// ���a�̎擾
	std::vector<int> GetAnimHandle() { return animHandle; }	// ��Ұ�������ق̎擾
	ACTION_STATE GetAnimState() { return actionState; }			// ���݂̱�Ұ��݂̎擾
	Vector3 GetFramePosition(int n);						// �ڰт̍��W�̎擾
	void SetAnimID(int mH, ACTION_STATE no);		// ��Ұ���ID�̾��

	virtual OBJECT_TYPE GetType() = 0;	// ��޼ު�Ă̎�ނ��擾:�K������
	//------------------------------------------
	// �Ƃ肠�����̂��
	//------------------------------------------
	//virtual OBJECT_TYPE GetType() override {}				// ��޼ު�Ă̎�ނ��擾

	bool JumpState()		// �ެ��ߒ�
	{
		if (actionState == ACTION_STATE::ACTION_STATE_JUMP)
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

	void SetMoveSpeedY(const float& y)
	{
		moveSpeed.y = y;
	}

	void SetGravity(const float& g)
	{
		gravity = g;
	}

	bool JumpFlag()
	{
		return jumpFlag;
	}

	Vector3 GetMoveSpeed()
	{
		return moveSpeed;
	}

	void SetPos(const Vector3& p)
	{
		pos = p;
	}

	void SetMoveDir(const Vector3& cameraDir)
	{
		moveDir = cameraDir;
	}
};