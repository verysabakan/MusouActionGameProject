//------------------------------------------------------
// @brief	(���)���ق̂��߂̊��
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include "ObjectBase.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
ObjectBase::ObjectBase()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
ObjectBase::~ObjectBase()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	��Ұ���ID�̾��
//------------------------------------------------------
void ObjectBase::SetAnimID(int mH, ACTION_STATE no)
{
	MV1DetachAnim(mH, attachiIndex);
	attachiIndex = MV1AttachAnim(modelHandle, 0, animHandle[static_cast<int>(no)], TRUE);
	totalTime = MV1GetAttachAnimTotalTime(modelHandle, attachiIndex);	// ��Ұ��݂�İ�َ��Ԃ��v��
	playTime = 0.0f;
}

//------------------------------------------------------
// @brief	�ڰт̍��W�̎擾
//------------------------------------------------------
Vector3 ObjectBase::GetFramePosition(int n)
{
	// �擾����VECTOR��Vector3�Ƃ��ĕԂ�
	auto vec = MV1GetFramePosition(modelHandle, n);
	auto vec3 = Vector3(vec.x, vec.y, vec.z);
	return vec3;
}