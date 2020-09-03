#include <DxLib.h>
#include "toriaezu.h"
#include "HitCheckConstant.h"
#include "MainConstant.h"

#include "ModelBase.h"
#include "Stage.h"

// chara��374�U��,1521,3565
// 

bool stageHitFlag = false;

// �Ƃ肠�����̽ð�ނƂ̓����蔻��
bool HitCheckStageAndPlayer(ModelBase* p, Stage* colS)
{
	auto pModelBase = p;
	auto sModelBase = dynamic_cast<StageModelBase*>(colS);

	const int STAGE_OBJECT_MAX_NUM = 128;	// 512
	const int CHARA_MAX_HITCOLL = 512;		// 2048

	
	
	int i;
	int j;
	int k;

	// ���������|���S���̃^�C�v�ʂ̐�
	int HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)];
	// ���������^�C�v�ʂ̊e�|���S���ւ̃|�C���^
	MV1_COLL_RESULT_POLY* HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)][CHARA_MAX_HITCOLL];
	// ���������I�u�W�F�N�g�̐�
	int HitNum;
	// �L�����N�^�[�̎��͂ɂ���|���S�������o�������ʂ��������铖���蔻�茋�ʍ\����
	MV1_COLL_RESULT_POLY_DIM HitDim[STAGE_OBJECT_MAX_NUM + 1];

	VECTOR* PolyNormal;
	StageCollType CollType;
	VECTOR nextPos;
	VECTOR TempMoveVector;

	float SearchDistance;

	SearchDistance = 200.0f;

	TempMoveVector = pModelBase->GetMoveSpeed().ConvertVec();

	// �ړ���̍��W���Z�o
	nextPos = VAdd(pModelBase->GetPosition().ConvertVec(), TempMoveVector);

	// �����蔻�茋�ʏ��̐���������
	HitNum = 0;

	// �L�����N�^�[�̎��͂ɂ���X�e�[�W�|���S�����擾����
	HitDim[HitNum] = MV1CollCheck_Sphere(
		sModelBase->GetCollisionModelHandle(), -1,
		(pModelBase->GetPosition()).ConvertVec(), SearchDistance);
	if (HitDim[HitNum].HitNum != 0)
	{
		HitNum++;
	}
	else
	{
		MV1CollResultPolyDimTerminate(HitDim[HitNum]);
	}

	// �ð�ވȊO�̵�޼ު�Ă̓����蔻������ꍇ
	// �L�����N�^�[�̎��͂ɂ���R���W�����I�u�W�F�N�g�̃|���S�����擾����
	/*for (i = 0; i < StageObjectNum; i++)
	{
		CollisionModelHandle = StageData_GetObjectCollisionModelHandle(i);

		if (CollisionModelHandle != -1)
		{
			HitDim[HitNum] = MV1CollCheck_Sphere(CollisionModelHandle, -1,
				(pModelBase->GetPosition()).ConvertVec(), SearchDistance);
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
				if (pModelBase->JumpState()&& pModelBase->RiseY() > 0.0f)
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
			if (HitPolyNum[static_cast<int>(CollType)] < CHARA_MAX_HITCOLL)
			{
				HitPoly[static_cast<int>(CollType)][HitPolyNum[static_cast<int>(CollType)]] = &HitDim[j].Dim[i];
				HitPolyNum[static_cast<int>(CollType)] ++;
			}
		}
	}

	const float CHARA_HIT_FLOOR_Y_ADJUST_JUMP = -1.0f;
	const float CHARA_HIT_FLOOR_Y_ADJUST_WALK = -40.0f;

	bool HitFlag;
	VECTOR LineTopPos;
	VECTOR LineBottomPos;

	// �|���S���̍\���̂ɃA�N�Z�X���邽�߂Ɏg�p����|�C���^
	MV1_COLL_RESULT_POLY* Poly;
	// �����ƃ|���S���Ƃ̓����蔻��̌��ʂ�������\����
	HITRESULT_LINE LineRes;

	// ���|���S���Ƃ̓����蔻��
	if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)] != 0)
	{
		float MaxY;
		int   MaxIndex;

		// �|���S���ɓ����������ǂ����̃t���O��|���Ă���
		HitFlag = false;

		stageHitFlag = HitFlag;

		// ��ԍ������|���S���ɐڒn������ׂ̔���p�ϐ���������
		MaxY = 0.0f;
		MaxIndex = -1;

		// �����蔻��̐����̍��W���Z�b�g
		// (nextPos)
		LineTopPos = VAdd(nextPos, VECTOR{ 0.0f, 105.0f, 0.0f });
		LineTopPos.y += 10.0f / 2.0f
			+ 60.0f;

		// (nextPos)
		LineBottomPos = VAdd(nextPos, VECTOR{ 0.0f, 30.0f, 0.0f });
		//LineBottomPos.y -= 20.0f / 2.0f
			//+ 10.0f;

		// ���[�̒l��������p�ɕ␳
		if (pModelBase->JumpState())
		{
			LineBottomPos.y += CHARA_HIT_FLOOR_Y_ADJUST_JUMP;
		}
		else
		{
			LineBottomPos.y += CHARA_HIT_FLOOR_Y_ADJUST_WALK;
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

			// �L�����N���[�^�C�v���G�e�������ꍇ�͍폜���ďI��
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

			stageHitFlag = HitFlag;

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
			// (nextPos)
			nextPos.y = MaxY;

			// �x�������̈ړ����x�͂O��
			pModelBase->SetMoveSpeedY(0.0f);

			// �ڐG�����|���S���̃}�e���A���^�C�v���擾����
			//CInfo->OnMaterialType = StageData_GetCollisionModelMaterialType(HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)][MaxIndex]->MaterialIndex);

			// �����W�����v���������ꍇ�͒��n��ԂɈڍs����
			//if (pModelBase->JumpState())
			//{
			//	if (!Chara_Landed(CInfo))
			//	{
			//		return false;
			//	}
			//	CInfo->JumpState = false;
			//}
		}
		else
		{
			// ���R���W�����ɓ������Ă��Ȃ��Ċ��W�����v��Ԃł͂Ȃ������ꍇ��
			//// �W�����v��ԂɈڍs����
			//if (!CInfo->JumpState)
			//{
			//	CInfo->JumpState = true;
			//	if (!Chara_Fall(CInfo))
			//	{
			//		return false;
			//	}
			//}
		}
	}

	// ���o�����L�����N�^�[�̎��͂̃|���S�������J������
	for (i = 0; i < HitNum; i++)
	{
		MV1CollResultPolyDimTerminate(HitDim[i]);
	}

	// �V�������W��ۑ�����
	pModelBase->SetPos(ConvertVec3(nextPos));
	

	return true;	// ����
}

typedef struct
{
	bool flag = false;
	int image;
	int x;
	int y;
}SPRITE;
SPRITE gameClear;
SPRITE gameOver;

// �ǂݍ���
void TorimaInitialize()
{
	gameClear.image = LoadGraph("Image/torima/GameClear.png");
	gameOver.image = LoadGraph("Image/torima/GameOver.png");

	// �摜���ނ̎擾
	GetGraphSize(gameClear.image, &gameClear.x, &gameClear.y);
	GetGraphSize(gameOver.image, &gameOver.x, &gameOver.y);
}

const float gravityAcc = -98.0f/60.0f;
float gravity;

// �X�V
void TorimaUpdate(ModelBase* p)
{
	//------------ �d��
	if (stageHitFlag)
	{
		gravity = 0;
	}
	else
	{
		gravity += gravityAcc;
	}
	
	p->SetGravity(gravity);
}

// �ްѸر
bool GameClear(ModelBase* p)
{
	// �ر�ꏊ�ɂ�����
	//if ()
	{
		//gameClear.flag = true;
	}

	return false;	// �J�ڂ��Ȃ�
}

// �ްѵ��ް
bool GameOver(ModelBase* p)
{
	// ���ɗ�������
	if (p->GetPosition().y < -50.0f)
	{
		gameOver.flag = true;
	}

	return false;	// �J�ڂ��Ȃ�
}

void Draw()
{
	if (gameClear.flag)
	{
		DrawGraph(SCREEN_SIZE_X/2 - gameClear.x / 2, SCREEN_SIZE_Y / 2 - gameClear.y / 2, gameClear.image, true);
	}
	else if (gameOver.flag)
	{
		DrawGraph(SCREEN_SIZE_X / 2 - gameOver.x / 2, SCREEN_SIZE_Y / 2 - gameOver.y / 2, gameOver.image, true);
	}
}