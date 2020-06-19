//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰとｽﾃｰｼﾞの当たり判定
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "HitCheckCharAndStage.h"
#include "Player.h"
#include "HitCheckConstant.h"
#include "Stage.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
HitCheckCharAndStage::HitCheckCharAndStage(Player* p, Stage* s)
{
	modelBase = reinterpret_cast<ModelBase*>(p);
	stageModelBase = reinterpret_cast<StageModelBase*>(s);
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
HitCheckCharAndStage::~HitCheckCharAndStage()
{

}

//------------------------------------------------------
// @brief	床との当たり判定
//------------------------------------------------------
void HitCheckCharAndStage::HitTerrain()
{
	/*
	const int maxHitcoll = 2048;
	// 当たったタイプ別の各ポリゴンへのポインタ
	MV1_COLL_RESULT_POLY    *HitPoly[STAGECOLLTYPE_NUM][maxHitcoll];

	MV1_COLL_RESULT_POLY_DIM HitDim[STAGECOLLTYPE_NUM];
	StageCollType collType;

	int HitPolyNum[STAGECOLLTYPE_NUM];

	int HitNum = 0;

	// 移動ベクトルの算出
	//auto TempMoveVector = VScale(MoveDirection, OneMoveDistance);
	// 移動後の座標を算出
	//auto NextPos = VAdd((modelBase->GetPosition()).ConvertVec(), TempMoveVector);

	if (HitDim[HitNum].HitNum != 0)
	{
		HitNum++;
	}
	else
	{
		MV1CollResultPolyDimTerminate(HitDim[HitNum]);
	}

	// ﾎﾟﾘｺﾞﾝの検索距離
	float SearchDistance;
	SearchDistance = 200.0f;

	HitDim[HitNum] = MV1CollCheck_Sphere(
		stageModelBase->GetCollisionModelHandle(), -1,
		(modelBase->GetPosition()).ConvertVec(), SearchDistance);

	

	// 壁ポリゴンと床ポリゴンと天井ポリゴンの数を初期化する
	for (int i = 0; i < STAGECOLLTYPE_NUM; i++)
	{
		HitPolyNum[i] = 0;
	}

	// 当たり判定結果情報の数だけ繰り返し
	for (int j = 0; j < HitNum; j++)
	{
		// 検出されたポリゴンの数だけ繰り返し
		for (int i = 0; i < HitDim[j].HitNum; i++)
		{
			// ポリゴンの法線のアドレスを取得
			auto PolyNormal = &HitDim[j].Dim[i].Normal;

			// 一定以上の傾斜は壁ポリゴンとして処理する
			if (PolyNormal->x * PolyNormal->x + PolyNormal->z * PolyNormal->z > 0.5f)
			{
				collType = STAGECOLLTYPE_WALL;
			}
			else
				// 法線が下向きかどうかで処理を分岐
				if (PolyNormal->y <= 0.0f)
				{
					// ジャンプ中かつ上昇中の場合は天井ポリゴンとして処理し、
					// そうではない場合は壁ポリゴンとして処理する
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
					// それ以外の場合は床ポリゴンとする
					collType = STAGECOLLTYPE_FLOOR;
				}

			// ポリゴンの数が上限に達していない場合はタイプ別のポリゴン配列に登録する
			if (HitPolyNum[collType] < maxHitcoll)// 2048処理する最大ﾎﾟﾘｺﾞﾝ数
			{
				HitPoly[collType][HitPolyNum[collType]] = &HitDim[j].Dim[i];
				HitPolyNum[collType] ++;
			}
		}
	}

	// 当たり判定用の線分の座標を算出
	auto center = modelBase->GetPosition();
	center.y += 80;
	auto LineTopPos = center.ConvertVec();
	LineTopPos.y += 80;
	auto LineBottomPos = (modelBase->GetPosition()).ConvertVec();

	bool HitFlag = false;
	float MaxY = 0.0f;
	int MaxIndex;

	// 床ポリゴンの数だけ繰り返し
	for (int i = 0; i < HitPolyNum[STAGECOLLTYPE_FLOOR]; i++)
	{
		// i番目の床ポリゴンのアドレスを床ポリゴンポインタ配列から取得
		auto Poly = HitPoly[STAGECOLLTYPE_FLOOR][i];

		// 線分とポリゴンの当たり判定
		auto LineRes = HitCheck_Line_Triangle(LineTopPos, LineBottomPos,
			Poly->Position[0], Poly->Position[1], Poly->Position[2]);

		// 当たっていなかったら次のループへ
		if (LineRes.HitFlag == FALSE)
		{
			continue;
		}

		//// キャラクラータイプが敵弾だった場合は削除して終了
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

		// 接触したＹ座標を保存する
		MaxY = LineRes.Position.y;

		// 接触したポリゴンのインデックスを保存する
		MaxIndex = i;
	}

	if (HitFlag)
	{
		modelBase->SetPosY(MaxY);
	}
	*/
}


