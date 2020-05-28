//------------------------------------------------------
// @brief	���ق̂��߂̊��
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <DxLib.h>
#include <vector>
#include "Vector3.h"

class ModelBase
{
protected:
	int model;			// �����ް��p
	int modelID;
	std::vector<int> animID;		// ��Ұ����ް��p
	Vector3 target;		// �����Ă������
	Vector3 pos;		// XYZ������
	Vector3 rol;		// ��]
	Vector3 scl;		// �傫��
	Vector3 scale;
	Vector3 hitpos;		// ���苅�̒��S
	float hitR;			// ���苅�̔��a
	float angle;
	// ��Ұ���
	int attachiIndex;	// �A�j���ԍ��o�^
	float totalTime;	// �Đ�������
	float playTime;		// �Đ��ӏ�
public:

	ModelBase() {}			// �ݽ�׸�
	~ModelBase() {}			// �޽�׸�

	Vector3 GetPosition() { return pos; }	// �ʒu���擾
	Vector3 GetRotation() { return rol; }	// ��]���擾
	Vector3 GetTarget() { return target; }	// �ڕW���擾
	Vector3 GetHitSpherePositon() { return hitpos; }	// �����������̈ʒu�̎擾
	float GetHitRadiusPositon() { return hitR; }		// �̎擾
	int GetAmeID() { return modelID; }					// ��Ұ���ID�̎擾
	Vector3 GetFramePosition(int n)						// �ڰт̍��W�̎擾
	{ 
		// �擾����VECTOR��Vector3�Ƃ��ĕԂ�
		auto vec = MV1GetFramePosition(modelID, n);
		auto vec3 = Vector3(vec.x, vec.y, vec.z);
		return vec3;
	}
	void SetAnimID(int modelID, int no)					// ��Ұ���ID�̾��
	{
		MV1DetachAnim(modelID, attachiIndex);
		attachiIndex = MV1AttachAnim(modelID, 0, animID[no], TRUE);
		// ��Ұ��݂�İ�َ��Ԃ��v��
		totalTime = MV1GetAttachAnimTotalTime(modelID, attachiIndex);
		playTime = 0.0f;
	}
};