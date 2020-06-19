//------------------------------------------------------
// @brief	(���)���ق̂��߂̊��
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include "ModelBase.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
ModelBase::ModelBase()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
ModelBase::~ModelBase()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	��Ұ���ID�̾��
//------------------------------------------------------
void ModelBase::SetAnimID(int mH, int no)
{
	MV1DetachAnim(mH, attachiIndex);
	attachiIndex = MV1AttachAnim(modelHandle, 0, animHandle[no], TRUE);
	// ��Ұ��݂�İ�َ��Ԃ��v��
	totalTime = MV1GetAttachAnimTotalTime(modelHandle, attachiIndex);
	playTime = 0.0f;
}

//------------------------------------------------------
// @brief	�ڰт̍��W�̎擾
//------------------------------------------------------
Vector3 ModelBase::GetFramePosition(int n)
{
	// �擾����VECTOR��Vector3�Ƃ��ĕԂ�
	auto vec = MV1GetFramePosition(modelHandle, n);
	auto vec3 = Vector3(vec.x, vec.y, vec.z);
	return vec3;
}