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
	modelBase = reinterpret_cast<ModelBase*>(p);
	stageModelBase = reinterpret_cast<StageModelBase*>(s);
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
	/*
	const int maxHitcoll = 2048;
	// ���������^�C�v�ʂ̊e�|���S���ւ̃|�C���^
	MV1_COLL_RESULT_POLY    *HitPoly[STAGECOLLTYPE_NUM][maxHitcoll];

	MV1_COLL_RESULT_POLY_DIM HitDim[STAGECOLLTYPE_NUM];
	StageCollType collType;

	int HitPolyNum[STAGECOLLTYPE_NUM];

	int HitNum = 0;

	// �ړ��x�N�g���̎Z�o
	//auto TempMoveVector = VScale(MoveDirection, OneMoveDistance);
	// �ړ���̍��W���Z�o
	//auto NextPos = VAdd((modelBase->GetPosition()).ConvertVec(), TempMoveVector);

	if (HitDim[HitNum].HitNum != 0)
	{
		HitNum++;
	}
	else
	{
		MV1CollResultPolyDimTerminate(HitDim[HitNum]);
	}

	// ��غ�݂̌�������
	float SearchDistance;
	SearchDistance = 200.0f;

	HitDim[HitNum] = MV1CollCheck_Sphere(
		stageModelBase->GetCollisionModelHandle(), -1,
		(modelBase->GetPosition()).ConvertVec(), SearchDistance);

	

	// �ǃ|���S���Ə��|���S���ƓV��|���S���̐�������������
	for (int i = 0; i < STAGECOLLTYPE_NUM; i++)
	{
		HitPolyNum[i] = 0;
	}

	// �����蔻�茋�ʏ��̐������J��Ԃ�
	for (int j = 0; j < HitNum; j++)
	{
		// ���o���ꂽ�|���S���̐������J��Ԃ�
		for (int i = 0; i < HitDim[j].HitNum; i++)
		{
			// �|���S���̖@���̃A�h���X���擾
			auto PolyNormal = &HitDim[j].Dim[i].Normal;

			// ���ȏ�̌X�΂͕ǃ|���S���Ƃ��ď�������
			if (PolyNormal->x * PolyNormal->x + PolyNormal->z * PolyNormal->z > 0.5f)
			{
				collType = STAGECOLLTYPE_WALL;
			}
			else
				// �@�������������ǂ����ŏ����𕪊�
				if (PolyNormal->y <= 0.0f)
				{
					// �W�����v�����㏸���̏ꍇ�͓V��|���S���Ƃ��ď������A
					// �����ł͂Ȃ��ꍇ�͕ǃ|���S���Ƃ��ď�������
					if (modelBase->JumpState() && modelBase->RiseY() > 0.0f)
					{
						collType = STAGECOLLTYPE_CEILING;
					}
					else
					{
						collType = STAGECOLLTYPE_WALL;
					}
				}
				else
				{
					// ����ȊO�̏ꍇ�͏��|���S���Ƃ���
					collType = STAGECOLLTYPE_FLOOR;
				}

			// �|���S���̐�������ɒB���Ă��Ȃ��ꍇ�̓^�C�v�ʂ̃|���S���z��ɓo�^����
			if (HitPolyNum[collType] < maxHitcoll)// 2048��������ő���غ�ݐ�
			{
				HitPoly[collType][HitPolyNum[collType]] = &HitDim[j].Dim[i];
				HitPolyNum[collType] ++;
			}
		}
	}

	// �����蔻��p�̐����̍��W���Z�o
	auto center = modelBase->GetPosition();
	center.y += 80;
	auto LineTopPos = center.ConvertVec();
	LineTopPos.y += 80;
	auto LineBottomPos = (modelBase->GetPosition()).ConvertVec();

	bool HitFlag = false;
	float MaxY = 0.0f;
	int MaxIndex;

	// ���|���S���̐������J��Ԃ�
	for (int i = 0; i < HitPolyNum[STAGECOLLTYPE_FLOOR]; i++)
	{
		// i�Ԗڂ̏��|���S���̃A�h���X�����|���S���|�C���^�z�񂩂�擾
		auto Poly = HitPoly[STAGECOLLTYPE_FLOOR][i];

		// �����ƃ|���S���̓����蔻��
		auto LineRes = HitCheck_Line_Triangle(LineTopPos, LineBottomPos,
			Poly->Position[0], Poly->Position[1], Poly->Position[2]);

		// �������Ă��Ȃ������玟�̃��[�v��
		if (LineRes.HitFlag == FALSE)
		{
			continue;
		}

		//// �L�����N���[�^�C�v���G�e�������ꍇ�͍폜���ďI��
		//if (CBInfo->Type == ECharaType_EnemyShot)
		//{
		//	Chara_Delete(CInfo);
		//	for (k = 0; k < HitNum; k++)
		//	{
		//		MV1CollResultPolyDimTerminate(HitDim[k]);
		//	}
		//	return true;
		//}

		// ���ɓ��������|���S��������A
		// �����܂Ō��o�������|���S�����Ⴂ�ꍇ�͎��̃��[�v��
		if (HitFlag && MaxY > LineRes.Position.y)
		{
			continue;
		}

		// �|���S���ɓ��������t���O�𗧂Ă�
		HitFlag = true;

		// �ڐG�����x���W��ۑ�����
		MaxY = LineRes.Position.y;

		// �ڐG�����|���S���̃C���f�b�N�X��ۑ�����
		MaxIndex = i;
	}

	if (HitFlag)
	{
		modelBase->SetPosY(MaxY);
	}
	*/
}


