//------------------------------------------------------
// @brief	��ڲ԰�ƒn�`�̓����蔻��
// 2020 7/22 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "PlayerAndTerrain.h"
#include "HitCheckConstant.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
PlayerAndTerrain::PlayerAndTerrain()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
PlayerAndTerrain::~PlayerAndTerrain()
{
	// �����Ȃ�
}

/*
// �����蔻��̏�񂩂�A�����蔻��Ɏg�p����J�v�Z���`����`������Q���W���擾����
void CharaBase_GetHitCapsulePos(
	// �����蔻����̃A�h���X
	const SCharaHitInfo* HitInfo,

	// �����蔻����s���L�����N�^�[�̍��W�̃A�h���X
	const VECTOR* Position,

	// �v�Z��̃J�v�Z���̍��W���i�[����A�h���X
	VECTOR* CapsulePosition1,
	VECTOR* CapsulePosition2
)
{
	*CapsulePosition1 =
		*CapsulePosition2 = VAdd(*Position, HitInfo->CenterPosition);

	CapsulePosition1->y -= HitInfo->Height / 2.0f;
	CapsulePosition2->y += HitInfo->Height / 2.0f;
}*/

//------------------------------------------------------
// @brief	��ڲ԰�ƒn�`�̔��菈��
//------------------------------------------------------
bool PlayerAndTerrain::HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2)
{
	if (o1->GetNowAction() == ACTION_STATE::ACTION_STATE_ATTACK1)
	{
		return true;
	}
	int                      i;
	int                      j;
	int                      k;

	// ���������Ɉړ��������ǂ����̃t���O
	// ( false : �ړ����Ă��Ȃ�  true:�ړ����� )
	bool                     MoveFlag;

	// �|���S���ɓ����������ǂ������L�����Ă����ϐ�
	// ( false : �������Ă��Ȃ�  true : �������� )
	int                      HitFlag;

	// �L�����N�^�[�̎��͂ɂ���|���S�������o�������ʂ��������铖���蔻�茋�ʍ\����
	MV1_COLL_RESULT_POLY_DIM HitDim[PATCon::STAGE_OBJECT_MAX_NUM + 1];

	// ���������I�u�W�F�N�g�̐�
	int                      HitNum;

	// ���������|���S���̃^�C�v�ʂ̐�
	int                      HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)];

	// ���������^�C�v�ʂ̊e�|���S���ւ̃|�C���^
	MV1_COLL_RESULT_POLY* HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)][PATCon::CHARA_MAX_HITCOLL];

	// �|���S���̍\���̂ɃA�N�Z�X���邽�߂Ɏg�p����|�C���^
	MV1_COLL_RESULT_POLY* Poly;

	// �����ƃ|���S���Ƃ̓����蔻��̌��ʂ�������\����
	HITRESULT_LINE           LineRes;

	// �ړ��O�̍��W	
	VECTOR                   OldPos;

	// �ړ���̍��W
	VECTOR                   NextPos;

	VECTOR                   BottomPos1;
	VECTOR                   BottomPos2;
	VECTOR                   TopPos1;
	VECTOR                   TopPos2;
	VECTOR                   LineTopPos;
	VECTOR                   LineBottomPos;
	VECTOR* PolyNormal;
	float                    TotalMoveDistance;
	float                    CompMoveDistance;
	float                    OneMoveMaxDistance;
	float                    OneMoveDistance;
	float                    SearchDistance;
	VECTOR                   MoveDirection;
	VECTOR                   TempMoveVector;
	StageCollType           CollType;
	//int                      StageObjectNum;
	VECTOR                   SlideVec;
	VECTOR                   TempYVector;
	VECTOR                   PolyXZNormal;
	//int                      CollisionModelHandle;

	auto CBInfo = o1;
	auto stage = o2;
	
	// �ړ����������擾
	TotalMoveDistance = CBInfo->GetMoveSpeed().Magnitude();

	// �ړ��������O�̏ꍇ�͉��ɂw�������Ɉړ��������Ƃɂ���
	if (TotalMoveDistance < 0.000001f)
	{
		MoveDirection = VGet(1.0f, 0.0f, 0.0f);
	}
	else
	{
		MoveDirection = VScale(CBInfo->GetMoveSpeed().ConvertVec(), 1.0f / TotalMoveDistance);
	}

	// �X�e�[�W�I�u�W�F�N�g�̐����擾����
	//StageObjectNum = StageData_GetObjectNum();

	struct HitInfo
	{
		VECTOR CenterPosition = {};
		float Height = 0;
		float Width = 0;
	};

	HitInfo StageHitTopInfo;
	HitInfo StageHitBottomInfo;

	StageHitTopInfo.CenterPosition = VECTOR{ 0.0f, 105.0f, 0.0f };
	StageHitTopInfo.Width = 60.0f;
	StageHitTopInfo.Height = 10.0f;
	StageHitBottomInfo.CenterPosition = VECTOR{ 0.0f, 20.0f, 0.0f };
	StageHitBottomInfo.Width = 10.0f;
	StageHitBottomInfo.Height = 20.0f;

	// ��x�Ɉړ����鋗�����Z�o
	OneMoveMaxDistance = StageHitTopInfo.Width * 2.0f;

	// ��x�Ɉړ����鋗�����ړ������������ꍇ�͕�����ɕ����Ĉړ�����
	CompMoveDistance = 0.0f;
	do
	{
		// �ړ����鋗��������
		if (CompMoveDistance + OneMoveMaxDistance > TotalMoveDistance)
		{
			OneMoveDistance = TotalMoveDistance - CompMoveDistance;
		}
		else
		{
			OneMoveDistance = OneMoveMaxDistance;
		}

		// �ړ��x�N�g���̎Z�o
		TempMoveVector = VScale(MoveDirection, OneMoveDistance);

		// �L�����N�^�[�̎��͂ɂ���|���S������������ۂ̌����������Z�o
		SearchDistance = PATCon::CHARA_ENUM_DEFAULT_SIZE + OneMoveDistance;

		// �ړ����鋗���𑫂�
		CompMoveDistance += OneMoveDistance;

		// �ړ��O�̍��W��ۑ�
		OldPos = CBInfo->GetPosition().ConvertVec();

		// �ړ���̍��W���Z�o
		NextPos = VAdd(OldPos, TempMoveVector);

		// �����蔻��Ɏg�p������W���v�Z����
		/*
		CharaBase_GetHitCapsulePos(&CInfo->BaseInfo->StageHitTopInfo,
			&NextPos, &TopPos1, &TopPos2);

		CharaBase_GetHitCapsulePos(&CInfo->BaseInfo->StageHitBottomInfo,
			&NextPos, &BottomPos1, &BottomPos2);
		*/
		TopPos1 =
			TopPos2 = VAdd(NextPos, StageHitTopInfo.CenterPosition);
		TopPos1.y -= StageHitTopInfo.Height / 2.0f;
		TopPos2.y += StageHitTopInfo.Height / 2.0f;

		BottomPos1 =
			BottomPos2 = VAdd(NextPos, StageHitBottomInfo.CenterPosition);
		BottomPos1.y -= StageHitBottomInfo.Height / 2.0f;
		BottomPos2.y += StageHitBottomInfo.Height / 2.0f;


		// �����蔻�茋�ʏ��̐���������
		HitNum = 0;

		// �L�����N�^�[�̎��͂ɂ���X�e�[�W�|���S�����擾����
		HitDim[HitNum] = MV1CollCheck_Sphere(
			stage->GetCollisionModelHandle(), -1,
			CBInfo->GetPosition().ConvertVec(), SearchDistance);
		if (HitDim[HitNum].HitNum != 0)
		{
			HitNum++;
		}
		else
		{
			MV1CollResultPolyDimTerminate(HitDim[HitNum]);
		}

		/*
		// �L�����N�^�[�̎��͂ɂ���R���W�����I�u�W�F�N�g�̃|���S�����擾����
		for (i = 0; i < StageObjectNum; i++)
		{
			CollisionModelHandle = StageData_GetObjectCollisionModelHandle(i);

			if (CollisionModelHandle != -1)
			{
				HitDim[HitNum] = MV1CollCheck_Sphere(CollisionModelHandle, -1,
					CInfo->Position, SearchDistance);
				if (HitDim[HitNum].HitNum != 0)
				{
					HitNum++;
				}
				else
				{
					MV1CollResultPolyDimTerminate(HitDim[HitNum]);
				}
			}
		}*/

		// x����y�������� 0.01f �ȏ�ړ������ꍇ�́u�ړ������v�t���O�𗧂Ă�
		MoveFlag = fabs(TempMoveVector.x) > 0.01f || fabs(TempMoveVector.z) > 0.01f;

		// �ǃ|���S���Ə��|���S���ƓV��|���S���̐�������������
		for (i = 0; i < static_cast<int>(StageCollType::STAGECOLLTYPE_NUM); i++)
		{
			HitPolyNum[i] = 0;
		}

		// �����蔻�茋�ʏ��̐������J��Ԃ�
		for (j = 0; j < HitNum; j++)
		{
			// ���o���ꂽ�|���S���̐������J��Ԃ�
			for (i = 0; i < HitDim[j].HitNum; i++)
			{
				// �|���S���̖@���̃A�h���X���擾
				PolyNormal = &HitDim[j].Dim[i].Normal;

				// ���ȏ�̌X�΂͕ǃ|���S���Ƃ��ď�������
				if (PolyNormal->x * PolyNormal->x + PolyNormal->z * PolyNormal->z > 0.5f)
				{
					CollType = StageCollType::STAGECOLLTYPE_WALL;
				}
				else
					// �@�������������ǂ����ŏ����𕪊�
					if (PolyNormal->y <= 0.0f)
					{
						// �W�����v�����㏸���̏ꍇ�͓V��|���S���Ƃ��ď������A
						// �����ł͂Ȃ��ꍇ�͕ǃ|���S���Ƃ��ď�������
						if (CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP && CBInfo->GetMoveSpeed().y > 0.0f)
						{
							CollType = StageCollType::STAGECOLLTYPE_CEILING;
						}
						else
						{
							CollType = StageCollType::STAGECOLLTYPE_WALL;
						}
					}
					else
					{
						// ����ȊO�̏ꍇ�͏��|���S���Ƃ���
						CollType = StageCollType::STAGECOLLTYPE_FLOOR;
					}

				// �|���S���̐�������ɒB���Ă��Ȃ��ꍇ�̓^�C�v�ʂ̃|���S���z��ɓo�^����
				if (HitPolyNum[static_cast<int>(CollType)] < PATCon::CHARA_MAX_HITCOLL)
				{
					HitPoly[static_cast<int>(CollType)][HitPolyNum[static_cast<int>(CollType)]] = &HitDim[j].Dim[i];
					HitPolyNum[static_cast<int>(CollType)] ++;
				}
			}
		}

		// �ǃ|���S���Ƃ̓����蔻�菈��
		if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)] != 0)
		{
			// �ǂɓ����������ǂ����̃t���O�͏�����Ԃł́u�������Ă��Ȃ��v�ɂ��Ă���
			HitFlag = false;

			// �ړ��������ǂ����ŏ����𕪊�
			if (MoveFlag)
			{
				// �ړ����Ă����ꍇ�͏Փ˂����ǃ|���S���ɑ΂��ăX���C�h���鏈�����s��

				// �ǃ|���S���̐������J��Ԃ�
				for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; i++)
				{
					// i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
					Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][i];

					// �|���S���ƃL�����N�^�[���������Ă��Ȃ������玟�̃��[�v��
					if (HitCheck_Capsule_Triangle(
						BottomPos1, BottomPos2, StageHitBottomInfo.Width,
						Poly->Position[0], Poly->Position[1],
						Poly->Position[2]) == FALSE &&
						HitCheck_Capsule_Triangle(
							TopPos1, TopPos2, StageHitTopInfo.Width,
							Poly->Position[0], Poly->Position[1],
							Poly->Position[2]) == FALSE) continue;

					/*
					// �L�����N���[�^�C�v���G�e�������ꍇ�̓L�������폜���ďI��
					if (CBInfo->Type == ECharaType_EnemyShot)
					{
						Chara_Delete(CInfo);
						for (k = 0; k < HitNum; k++)
						{
							MV1CollResultPolyDimTerminate(HitDim[k]);
						}
						return true;
					}*/

					// �����ɂ�����|���S���ƃL�����N�^�[���������Ă���Ƃ������ƂȂ̂ŁA
					// �|���S���ɓ��������t���O�𗧂Ă�
					HitFlag = true;

					// �ǃ|���S���ɓ���������ǂɎՂ��Ȃ��ړ��������ړ�����

					// �@���̂w�y�l�����𒊏o
					PolyXZNormal = Poly->Normal;
					PolyXZNormal.y = 0.0f;

					// �i�s�����x�N�g���ƕǃ|���S���̖@���x�N�g���ɐ����ȃx�N�g�����Z�o
					TempYVector = VCross(TempMoveVector, PolyXZNormal);

					// �Z�o�����x�N�g���ƕǃ|���S���̖@���x�N�g���ɐ����ȃx�N�g�����Z�o
					SlideVec = VCross(PolyXZNormal, TempYVector);

					// �x�������ɂ̓X���C�h���Ȃ�
					SlideVec.y = 0.0f;

					// ������ړ��O�̍��W�ɑ��������̂�V���ȍ��W�Ƃ���
					NextPos = VAdd(OldPos, SlideVec);

					// �x���W�ɂ͌��̈ړ��l�����Z����
					NextPos.y += TempMoveVector.y;

					// �����蔻��Ɏg�p������W���X�V����
					/*
					CharaBase_GetHitCapsulePos(&CInfo->BaseInfo->StageHitTopInfo,
						&NextPos, &TopPos1, &TopPos2);

					CharaBase_GetHitCapsulePos(&CInfo->BaseInfo->StageHitBottomInfo,
						&NextPos, &BottomPos1, &BottomPos2);
					*/

					TopPos1 =
						TopPos2 = VAdd(NextPos, StageHitTopInfo.CenterPosition);
					TopPos1.y -= StageHitTopInfo.Height / 2.0f;
					TopPos2.y += StageHitTopInfo.Height / 2.0f;

					BottomPos1 =
						BottomPos2 = VAdd(NextPos, StageHitBottomInfo.CenterPosition);
					BottomPos1.y -= StageHitBottomInfo.Height / 2.0f;
					BottomPos2.y += StageHitBottomInfo.Height / 2.0f;

					// �V���Ȉړ�����W�ŕǃ|���S���Ɠ����邩�ǂ����𔻒肷��
					for (j = 0; j < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; j++)
					{
						// j�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
						Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][j];

						// �������Ă����烋�[�v���甲����
						if (HitCheck_Capsule_Triangle(
							BottomPos1, BottomPos2, StageHitBottomInfo.Width,
							Poly->Position[0], Poly->Position[1],
							Poly->Position[2]) == TRUE ||
							HitCheck_Capsule_Triangle(
								TopPos1, TopPos2, StageHitTopInfo.Width,
								Poly->Position[0], Poly->Position[1],
								Poly->Position[2]) == TRUE) break;
					}

					// j �� HitPolyNum[ static_cast<int>(StageCollType::STAGECOLLTYPE_WALL) ] �������ꍇ��
					// �ǂ̃|���S���Ƃ�������Ȃ������Ƃ������ƂȂ̂�
					// �w�ǂɓ����������ǂ����x�̃t���O��|������Ń��[�v���甲����
					if (j == HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)])
					{
						HitFlag = false;
						break;
					}
				}
			}
			else
			{
				// �ړ����Ă��Ȃ��ꍇ�͓������Ă���|���S�������邩�ǂ��������m�F

				// �ǃ|���S���̐������J��Ԃ�
				for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; i++)
				{
					// i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
					Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][i];

					// �|���S���ɓ������Ă����瓖�������t���O�𗧂Ă���Ń��[�v���甲����
					if (HitCheck_Capsule_Triangle(
						BottomPos1, BottomPos2, StageHitBottomInfo.Width,
						Poly->Position[0], Poly->Position[1],
						Poly->Position[2]) == TRUE ||
						HitCheck_Capsule_Triangle(
							TopPos1, TopPos2, StageHitTopInfo.Width,
							Poly->Position[0], Poly->Position[1],
							Poly->Position[2]) == TRUE)
					{
						/*
						// �L�����N���[�^�C�v���G�e�������ꍇ�̓L�������폜���ďI��
						if (CBInfo->Type == ECharaType_EnemyShot)
						{
							Chara_Delete(CInfo);
							for (k = 0; k < HitNum; k++)
							{
								MV1CollResultPolyDimTerminate(HitDim[k]);
							}
							return true;
						}*/

						HitFlag = true;
						break;
					}
				}
			}

			// �ǂɓ������Ă�����ǂ��牟���o���������s��
			if (HitFlag)
			{
				// �ǂ���̉����o�����������݂�ő吔�����J��Ԃ�
				for (k = 0; k < PATCon::CHARA_HIT_TRYNUM; k++)
				{
					// �ǃ|���S���̐������J��Ԃ�
					for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; i++)
					{
						VECTOR PolyXZNormal;

						// i�Ԗڂ̕ǃ|���S���̃A�h���X��ǃ|���S���|�C���^�z�񂩂�擾
						Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][i];

						// �L�����N�^�[�Ɠ������Ă��邩�𔻒�
						if (HitCheck_Capsule_Triangle(
							BottomPos1, BottomPos2, StageHitBottomInfo.Width,
							Poly->Position[0], Poly->Position[1],
							Poly->Position[2]) == FALSE &&
							HitCheck_Capsule_Triangle(
								TopPos1, TopPos2, StageHitTopInfo.Width,
								Poly->Position[0], Poly->Position[1],
								Poly->Position[2]) == FALSE) continue;

						// �������Ă�����L�����N�^�[��ǂ̖@�������Ɉ�苗���ړ�������
						PolyXZNormal = Poly->Normal;
						PolyXZNormal.y = 0.0f;
						NextPos = VAdd(NextPos, VScale(PolyXZNormal,
							PATCon::CHARA_HIT_SLIDE_DISTANCE));

						// �����蔻��Ɏg�p������W���X�V����
						/*
						CharaBase_GetHitCapsulePos(&CInfo->BaseInfo->StageHitTopInfo,
							&NextPos, &TopPos1, &TopPos2);

						CharaBase_GetHitCapsulePos(&CInfo->BaseInfo->StageHitBottomInfo,
							&NextPos, &BottomPos1, &BottomPos2);
						*/
						TopPos1 =
							TopPos2 = VAdd(NextPos, StageHitTopInfo.CenterPosition);
						TopPos1.y -= StageHitTopInfo.Height / 2.0f;
						TopPos2.y += StageHitTopInfo.Height / 2.0f;

						BottomPos1 =
							BottomPos2 = VAdd(NextPos, StageHitBottomInfo.CenterPosition);
						BottomPos1.y -= StageHitBottomInfo.Height / 2.0f;
						BottomPos2.y += StageHitBottomInfo.Height / 2.0f;

						// �ړ�������ŕǃ|���S���Ɠ����邩�ǂ����𔻒�
						for (j = 0; j < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; j++)
						{
							// �������Ă����烋�[�v�𔲂���
							Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][j];
							if (HitCheck_Capsule_Triangle(
								BottomPos1, BottomPos2,
								StageHitBottomInfo.Width,
								Poly->Position[0], Poly->Position[1],
								Poly->Position[2]) == TRUE ||
								HitCheck_Capsule_Triangle(
									TopPos1, TopPos2,
									StageHitTopInfo.Width,
									Poly->Position[0], Poly->Position[1],
									Poly->Position[2]) == TRUE) break;
						}

						// �S�Ẵ|���S���Ɠ������Ă��Ȃ������炱���Ń��[�v�I��
						if (j == HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)])
						{
							break;
						}
					}

					// i �� HitPolyNum[ static_cast<int>(StageCollType::STAGECOLLTYPE_WALL) ] �ł͂Ȃ��ꍇ��
					// �S���̃|���S���ŉ����o�������݂�O�ɑS�Ă̕ǃ|���S����
					// �ڐG���Ȃ��Ȃ����Ƃ������ƂȂ̂Ń��[�v���甲����
					if (i != HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)])
					{
						break;
					}
				}
			}
		}

		// �V��|���S���Ƃ̓����蔻��
		if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_CEILING)] != 0)
		{
			float MinY;

			// �V��ɓ����Ԃ��鏈�����s��

			// ��ԒႢ�V��ɂԂ���ׂ̔���p�ϐ���������
			MinY = 0.0f;

			// �����������ǂ����̃t���O��|��
			HitFlag = false;

			// �����蔻��p�̐����̍��W���Z�o
			LineTopPos = VAdd(NextPos, StageHitTopInfo.CenterPosition);
			LineTopPos.y += StageHitTopInfo.Height / 2.0f
				+ StageHitTopInfo.Width;

			LineBottomPos = VAdd(NextPos, StageHitBottomInfo.CenterPosition);
			LineBottomPos.y -= StageHitBottomInfo.Height / 2.0f
				+ StageHitBottomInfo.Width;

			// �V��|���S���̐������J��Ԃ�
			for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_CEILING)]; i++)
			{
				// i�Ԗڂ̓V��|���S���̃A�h���X��V��|���S���|�C���^�z�񂩂�擾
				Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_CEILING)][i];

				// ���悩�瓪�̍����܂ł̊ԂŃ|���S���ƐڐG���Ă��邩�ǂ����𔻒�
				LineRes = HitCheck_Line_Triangle(LineBottomPos, LineTopPos,
					Poly->Position[0], Poly->Position[1], Poly->Position[2]);

				// �ڐG���Ă��Ȃ������牽�����Ȃ�
				if (LineRes.HitFlag == FALSE)
				{
					continue;
				}
				/*
				// �L�����N���[�^�C�v���G�e�������ꍇ�͍폜���ďI��
				if (CBInfo->Type == ECharaType_EnemyShot)
				{
					Chara_Delete(CInfo);
					for (k = 0; k < HitNum; k++)
					{
						MV1CollResultPolyDimTerminate(HitDim[k]);
					}
					return true;
				}*/

				// ���Ƀ|���S���ɓ������Ă��āA�����܂Ō��o����
				// �V��|���S����荂���ꍇ�͉������Ȃ�
				if (HitFlag && MinY < LineRes.Position.y)
				{
					continue;
				}

				// �|���S���ɓ��������t���O�𗧂Ă�
				HitFlag = true;

				// �ڐG�����x���W��ۑ�����
				MinY = LineRes.Position.y;
			}

			// �ڐG�����|���S�������������ǂ����ŏ����𕪊�
			if (HitFlag)
			{
				// �ڐG�����ꍇ�̓L�����N�^�[�̂x���W��ڐG���W�����ɍX�V
				NextPos.y = MinY - (LineTopPos.y - LineBottomPos.y);

				// �x�������̑��x�͔��]
				CBInfo->SetMoveSpeedY(-CBInfo->GetMoveSpeed().y);
			}
		}

		// ���|���S���Ƃ̓����蔻��
		if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)] != 0)
		{
			float MaxY;
			int   MaxIndex;

			// �|���S���ɓ����������ǂ����̃t���O��|���Ă���
			HitFlag = false;

			// ��ԍ������|���S���ɐڒn������ׂ̔���p�ϐ���������
			MaxY = 0.0f;
			MaxIndex = -1;

			// �����蔻��̐����̍��W���Z�b�g
			LineTopPos = VAdd(NextPos, StageHitTopInfo.CenterPosition);
			LineTopPos.y += StageHitTopInfo.Height / 2.0f
				+ StageHitTopInfo.Width;

			LineBottomPos = VAdd(NextPos, StageHitBottomInfo.CenterPosition);
			LineBottomPos.y -= StageHitBottomInfo.Height / 2.0f
				+ StageHitBottomInfo.Width;

			// ���[�̒l��������p�ɕ␳
			if (CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP)
			{
				LineBottomPos.y += PATCon::CHARA_HIT_FLOOR_Y_ADJUST_JUMP;
			}
			else
			{
				LineBottomPos.y += PATCon::CHARA_HIT_FLOOR_Y_ADJUST_WALK;
			}

			// ���|���S���̐������J��Ԃ�
			for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)]; i++)
			{
				// i�Ԗڂ̏��|���S���̃A�h���X�����|���S���|�C���^�z�񂩂�擾
				Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)][i];

				// �����ƃ|���S���̓����蔻��
				LineRes = HitCheck_Line_Triangle(LineTopPos, LineBottomPos,
					Poly->Position[0], Poly->Position[1], Poly->Position[2]);

				// �������Ă��Ȃ������玟�̃��[�v��
				if (LineRes.HitFlag == FALSE)
				{
					continue;
				}
				/*
				// �L�����N���[�^�C�v���G�e�������ꍇ�͍폜���ďI��
				if (CBInfo->Type == ECharaType_EnemyShot)
				{
					Chara_Delete(CInfo);
					for (k = 0; k < HitNum; k++)
					{
						MV1CollResultPolyDimTerminate(HitDim[k]);
					}
					return true;
				}*/

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

			// ���|���S���ɓ����������ǂ����ŏ����𕪊�
			if (HitFlag)
			{
				// ���������ꍇ

				// �ڐG�����|���S���ň�ԍ����x���W���L�����N�^�[�̂x���W�ɂ���
				NextPos.y = MaxY;

				// �x�������̈ړ����x�͂O��
				CBInfo->SetMoveSpeedY(0.0f);

				/*
				// �ڐG�����|���S���̃}�e���A���^�C�v���擾����
				CInfo->OnMaterialType = StageData_GetCollisionModelMaterialType(
					HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)][MaxIndex]->MaterialIndex);
				*/

				// �����W�����v���������ꍇ�͒��n��ԂɈڍs����
				if (CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP)
				{
					/*
					// ���n����
					if (!Chara_Landed(CInfo))
					{
						return false;
					}
					*/
					// �D��x����ԒႢ���
					CBInfo->SetActionState(ACTION_STATE::ACTION_STATE_STANCE);
				}
			}
			else
			{
				// ���R���W�����ɓ������Ă��Ȃ��Ċ��W�����v��Ԃł͂Ȃ������ꍇ��
				// �W�����v��ԂɈڍs����
				if (!(CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP))
				{
					CBInfo->SetActionState(ACTION_STATE::ACTION_STATE_JUMP);
					/*
					// �ެ��ߏ���
					if (!Chara_Fall(CInfo))
					{
						return false;
					}
					*/
				}
			}
		}

		// ���o�����L�����N�^�[�̎��͂̃|���S�������J������
		for (i = 0; i < HitNum; i++)
		{
			MV1CollResultPolyDimTerminate(HitDim[i]);
		}

		// �V�������W��ۑ�����
		CBInfo->SetPos(ConvertVec3(NextPos));

		// �S�Ă̈ړ����������Ă��Ȃ��ꍇ�̓��[�v
	} while (CompMoveDistance + 0.001f < TotalMoveDistance);

	// �W�����v���ł͂Ȃ��ꍇ�͈ړ����x���O�ɂ���
	if (!(CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP))
	{
		CBInfo->SetMoveSpeed(Vector3());
		CBInfo->SetActionState(ACTION_STATE::ACTION_STATE_STANCE);
	}

	// �L�����N�^�[�̂R�c���f���̍��W���X�V����
	//MV1SetPosition(CInfo->ModelHandle, CInfo->Position);

	return true;	// ����I��

}