//------------------------------------------------------
// @brief	�����蔻����s���`���`������
// 2020 7/14 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "MakeForm.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
MakeForm::MakeForm()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
MakeForm::~MakeForm()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�����蔻��̏�񂩂��߾ق��`������2���W�̎擾
// @param	HitInfo	�����蔻����̃A�h���X
// @param	HitInfo	�����蔻����s���L�����N�^�[�̍��W�̃A�h���X
// @param	HitInfo	�v�Z��̃J�v�Z���̍��W���i�[����A�h���X
// @return	������Ă����true
//------------------------------------------------------
void GetHitCapsulePos(const VECTOR* Position, VECTOR* CapsulePosition1, VECTOR* CapsulePosition2)
{
	*CapsulePosition1 = *CapsulePosition2 = VAdd(*Position, VECTOR{ 0.0f, 105.0f, 0.0f });

	CapsulePosition1->y -= 10.0f / 2.0f;
	CapsulePosition2->y += 10.0f / 2.0f;
}


