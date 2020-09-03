#include <DxLib.h>
#include "toriaezu.h"
#include "HitCheckConstant.h"
#include "MainConstant.h"

#include "ModelBase.h"
#include "Stage.h"

// charaの374攻撃,1521,3565
// 

bool stageHitFlag = false;

// とりあえずのｽﾃｰｼﾞとの当たり判定
bool HitCheckStageAndPlayer(ModelBase* p, Stage* colS)
{
	auto pModelBase = p;
	auto sModelBase = dynamic_cast<StageModelBase*>(colS);

	const int STAGE_OBJECT_MAX_NUM = 128;	// 512
	const int CHARA_MAX_HITCOLL = 512;		// 2048

	
	
	int i;
	int j;
	int k;

	// 当たったポリゴンのタイプ別の数
	int HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)];
	// 当たったタイプ別の各ポリゴンへのポインタ
	MV1_COLL_RESULT_POLY* HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)][CHARA_MAX_HITCOLL];
	// 当たったオブジェクトの数
	int HitNum;
	// キャラクターの周囲にあるポリゴンを検出した結果が代入される当たり判定結果構造体
	MV1_COLL_RESULT_POLY_DIM HitDim[STAGE_OBJECT_MAX_NUM + 1];

	VECTOR* PolyNormal;
	StageCollType CollType;
	VECTOR nextPos;
	VECTOR TempMoveVector;

	float SearchDistance;

	SearchDistance = 200.0f;

	TempMoveVector = pModelBase->GetMoveSpeed().ConvertVec();

	// 移動後の座標を算出
	nextPos = VAdd(pModelBase->GetPosition().ConvertVec(), TempMoveVector);

	// 当たり判定結果情報の数を初期化
	HitNum = 0;

	// キャラクターの周囲にあるステージポリゴンを取得する
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

	// ｽﾃｰｼﾞ以外のｵﾌﾞｼﾞｪｸﾄの当たり判定を取る場合
	// キャラクターの周囲にあるコリジョンオブジェクトのポリゴンも取得する
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
	
	// 壁ポリゴンと床ポリゴンと天井ポリゴンの数を初期化する
	for (i = 0; i < static_cast<int>(StageCollType::STAGECOLLTYPE_NUM); i++)
	{
		HitPolyNum[i] = 0;
	}

	// 当たり判定結果情報の数だけ繰り返し
	for (j = 0; j < HitNum; j++)
	{
		// 検出されたポリゴンの数だけ繰り返し
		for (i = 0; i < HitDim[j].HitNum; i++)
		{
			// ポリゴンの法線のアドレスを取得
			PolyNormal = &HitDim[j].Dim[i].Normal;

			// 一定以上の傾斜は壁ポリゴンとして処理する
			if (PolyNormal->x * PolyNormal->x + PolyNormal->z * PolyNormal->z > 0.5f)
			{
				CollType = StageCollType::STAGECOLLTYPE_WALL;
			}
			else
			// 法線が下向きかどうかで処理を分岐
			if (PolyNormal->y <= 0.0f)
			{
				// ジャンプ中かつ上昇中の場合は天井ポリゴンとして処理し、
				// そうではない場合は壁ポリゴンとして処理する
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
				// それ以外の場合は床ポリゴンとする
				CollType = StageCollType::STAGECOLLTYPE_FLOOR;
			}

			// ポリゴンの数が上限に達していない場合はタイプ別のポリゴン配列に登録する
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

	// ポリゴンの構造体にアクセスするために使用するポインタ
	MV1_COLL_RESULT_POLY* Poly;
	// 線分とポリゴンとの当たり判定の結果を代入する構造体
	HITRESULT_LINE LineRes;

	// 床ポリゴンとの当たり判定
	if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)] != 0)
	{
		float MaxY;
		int   MaxIndex;

		// ポリゴンに当たったかどうかのフラグを倒しておく
		HitFlag = false;

		stageHitFlag = HitFlag;

		// 一番高い床ポリゴンに接地させる為の判定用変数を初期化
		MaxY = 0.0f;
		MaxIndex = -1;

		// 当たり判定の線分の座標をセット
		// (nextPos)
		LineTopPos = VAdd(nextPos, VECTOR{ 0.0f, 105.0f, 0.0f });
		LineTopPos.y += 10.0f / 2.0f
			+ 60.0f;

		// (nextPos)
		LineBottomPos = VAdd(nextPos, VECTOR{ 0.0f, 30.0f, 0.0f });
		//LineBottomPos.y -= 20.0f / 2.0f
			//+ 10.0f;

		// 下端の値を床判定用に補正
		if (pModelBase->JumpState())
		{
			LineBottomPos.y += CHARA_HIT_FLOOR_Y_ADJUST_JUMP;
		}
		else
		{
			LineBottomPos.y += CHARA_HIT_FLOOR_Y_ADJUST_WALK;
		}

		// 床ポリゴンの数だけ繰り返し
		for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)]; i++)
		{
			// i番目の床ポリゴンのアドレスを床ポリゴンポインタ配列から取得
			Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)][i];

			// 線分とポリゴンの当たり判定
			LineRes = HitCheck_Line_Triangle(LineTopPos, LineBottomPos,
				Poly->Position[0], Poly->Position[1], Poly->Position[2]);

			// 当たっていなかったら次のループへ
			if (LineRes.HitFlag == FALSE)
			{
				continue;
			}

			// キャラクラータイプが敵弾だった場合は削除して終了
			//if (CBInfo->Type == ECharaType_EnemyShot)
			//{
			//	Chara_Delete(CInfo);
			//	for (k = 0; k < HitNum; k++)
			//	{
			//		MV1CollResultPolyDimTerminate(HitDim[k]);
			//	}
			//	return true;
			//}

			// 既に当たったポリゴンがあり、
			// 且つ今まで検出した床ポリゴンより低い場合は次のループへ
			if (HitFlag && MaxY > LineRes.Position.y)
			{
				continue;
			}

			// ポリゴンに当たったフラグを立てる
			HitFlag = true;

			stageHitFlag = HitFlag;

			// 接触したＹ座標を保存する
			MaxY = LineRes.Position.y;

			// 接触したポリゴンのインデックスを保存する
			MaxIndex = i;
		}

		// 床ポリゴンに当たったかどうかで処理を分岐
		if (HitFlag)
		{
			// 当たった場合

			// 接触したポリゴンで一番高いＹ座標をキャラクターのＹ座標にする
			// (nextPos)
			nextPos.y = MaxY;

			// Ｙ軸方向の移動速度は０に
			pModelBase->SetMoveSpeedY(0.0f);

			// 接触したポリゴンのマテリアルタイプを取得する
			//CInfo->OnMaterialType = StageData_GetCollisionModelMaterialType(HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)][MaxIndex]->MaterialIndex);

			// もしジャンプ中だった場合は着地状態に移行する
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
			// 床コリジョンに当たっていなくて且つジャンプ状態ではなかった場合は
			//// ジャンプ状態に移行する
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

	// 検出したキャラクターの周囲のポリゴン情報を開放する
	for (i = 0; i < HitNum; i++)
	{
		MV1CollResultPolyDimTerminate(HitDim[i]);
	}

	// 新しい座標を保存する
	pModelBase->SetPos(ConvertVec3(nextPos));
	

	return true;	// 正常
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

// 読み込み
void TorimaInitialize()
{
	gameClear.image = LoadGraph("Image/torima/GameClear.png");
	gameOver.image = LoadGraph("Image/torima/GameOver.png");

	// 画像ｻｲｽﾞの取得
	GetGraphSize(gameClear.image, &gameClear.x, &gameClear.y);
	GetGraphSize(gameOver.image, &gameOver.x, &gameOver.y);
}

const float gravityAcc = -98.0f/60.0f;
float gravity;

// 更新
void TorimaUpdate(ModelBase* p)
{
	//------------ 重力
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

// ｹﾞｰﾑｸﾘｱ
bool GameClear(ModelBase* p)
{
	// ｸﾘｱ場所についたら
	//if ()
	{
		//gameClear.flag = true;
	}

	return false;	// 遷移しない
}

// ｹﾞｰﾑｵｰﾊﾞｰ
bool GameOver(ModelBase* p)
{
	// 下に落ちたら
	if (p->GetPosition().y < -50.0f)
	{
		gameOver.flag = true;
	}

	return false;	// 遷移しない
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