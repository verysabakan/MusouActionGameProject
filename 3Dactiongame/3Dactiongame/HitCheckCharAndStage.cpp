//------------------------------------------------------
// @brief	��ڲ԰�ƽð�ނ̓����蔻��
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "HitCheckCharAndStage.h"
#include "Player.h"
#include "HitCheckConstant.h"
#include "Stage.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
HitCheckCharAndStage::HitCheckCharAndStage(Player* p, Stage* s)
{
	model = reinterpret_cast<ModelBase*>(p);
	stage = reinterpret_cast<StageModelBase*>(s);
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
HitCheckCharAndStage::~HitCheckCharAndStage()
{

}

//------------------------------------------------------
// @brief	���Ƃ̓����蔻��
//------------------------------------------------------
void HitCheckCharAndStage::HitTerrain()
{
	const int STAGE_OBJECT_MAX_NUM = 512;

	// �L�����N�^�[�̎��͂ɂ���|���S�������o�������ʂ��������铖���蔻�茋�ʍ\����
	MV1_COLL_RESULT_POLY_DIM HitDim[STAGE_OBJECT_MAX_NUM + 1];

	// ���������I�u�W�F�N�g�̐�
	int HitNum;

	// �L�����N�^�[�̎��͂ɂ���X�e�[�W�|���S�����擾����
	HitDim[HitNum] = MV1CollCheck_Sphere(
		stage->GetCollisionModelHandle(), -1,
		model->GetFramePosition(), SearchDistance);
}


