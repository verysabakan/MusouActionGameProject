//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰと地形の当たり判定
// 2020 7/22 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "PlayerAndTerrain.h"
#include "HitCheckConstant.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
PlayerAndTerrain::PlayerAndTerrain()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
PlayerAndTerrain::~PlayerAndTerrain()
{
	// 処理なし
}
/*
// 当たり判定の情報から、当たり判定に使用するカプセル形状を形成する２座標を取得する
void CharaBase_GetHitCapsulePos(
	// 当たり判定情報のアドレス
	const SCharaHitInfo* HitInfo,

	// 当たり判定を行うキャラクターの座標のアドレス
	const VECTOR* Position,

	// 計算後のカプセルの座標を格納するアドレス
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
// @brief	ﾌﾟﾚｲﾔｰと地形の判定処理
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

	// 水平方向に移動したかどうかのフラグ
	// ( false : 移動していない  true:移動した )
	bool                     MoveFlag;

	// ポリゴンに当たったかどうかを記憶しておく変数
	// ( false : 当たっていない  true : 当たった )
	int                      HitFlag;

	// キャラクターの周囲にあるポリゴンを検出した結果が代入される当たり判定結果構造体
	MV1_COLL_RESULT_POLY_DIM HitDim[PATCon::STAGE_OBJECT_MAX_NUM + 1];

	// 当たったオブジェクトの数
	int                      HitNum;

	// 当たったポリゴンのタイプ別の数
	int                      HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)];

	// 当たったタイプ別の各ポリゴンへのポインタ
	MV1_COLL_RESULT_POLY* HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_NUM)][PATCon::CHARA_MAX_HITCOLL];

	// ポリゴンの構造体にアクセスするために使用するポインタ
	MV1_COLL_RESULT_POLY* Poly;

	// 線分とポリゴンとの当たり判定の結果を代入する構造体
	HITRESULT_LINE           LineRes;

	// 移動前の座標	
	VECTOR                   OldPos;

	// 移動後の座標
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
	
	// 移動総距離を取得
	TotalMoveDistance = CBInfo->GetMoveSpeed().Magnitude();

	// 移動距離が０の場合は仮にＸ軸方向に移動したことにする
	if (TotalMoveDistance < 0.000001f)
	{
		MoveDirection = VGet(1.0f, 0.0f, 0.0f);
	}
	else
	{
		MoveDirection = VScale(CBInfo->GetMoveSpeed().ConvertVec(), 1.0f / TotalMoveDistance);
	}

	// ステージオブジェクトの数を取得する
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

	// 一度に移動する距離を算出
	OneMoveMaxDistance = StageHitTopInfo.Width * 2.0f;

	// 一度に移動する距離より移動距離が長い場合は複数回に分けて移動する
	CompMoveDistance = 0.0f;
	do
	{
		// 移動する距離を決定
		if (CompMoveDistance + OneMoveMaxDistance > TotalMoveDistance)
		{
			OneMoveDistance = TotalMoveDistance - CompMoveDistance;
		}
		else
		{
			OneMoveDistance = OneMoveMaxDistance;
		}

		// 移動ベクトルの算出
		TempMoveVector = VScale(MoveDirection, OneMoveDistance);

		// キャラクターの周囲にあるポリゴンを検索する際の検索距離を算出
		SearchDistance = PATCon::CHARA_ENUM_DEFAULT_SIZE + OneMoveDistance;

		// 移動する距離を足す
		CompMoveDistance += OneMoveDistance;

		// 移動前の座標を保存
		OldPos = CBInfo->GetPosition().ConvertVec();

		// 移動後の座標を算出
		NextPos = VAdd(OldPos, TempMoveVector);

		// 当たり判定に使用する座標を計算する
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


		// 当たり判定結果情報の数を初期化
		HitNum = 0;

		// キャラクターの周囲にあるステージポリゴンを取得する
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
		// キャラクターの周囲にあるコリジョンオブジェクトのポリゴンも取得する
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

		// x軸かy軸方向に 0.01f 以上移動した場合は「移動した」フラグを立てる
		MoveFlag = fabs(TempMoveVector.x) > 0.01f || fabs(TempMoveVector.z) > 0.01f;

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
						// それ以外の場合は床ポリゴンとする
						CollType = StageCollType::STAGECOLLTYPE_FLOOR;
					}

				// ポリゴンの数が上限に達していない場合はタイプ別のポリゴン配列に登録する
				if (HitPolyNum[static_cast<int>(CollType)] < PATCon::CHARA_MAX_HITCOLL)
				{
					HitPoly[static_cast<int>(CollType)][HitPolyNum[static_cast<int>(CollType)]] = &HitDim[j].Dim[i];
					HitPolyNum[static_cast<int>(CollType)] ++;
				}
			}
		}

		// 壁ポリゴンとの当たり判定処理
		if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)] != 0)
		{
			// 壁に当たったかどうかのフラグは初期状態では「当たっていない」にしておく
			HitFlag = false;

			// 移動したかどうかで処理を分岐
			if (MoveFlag)
			{
				// 移動していた場合は衝突した壁ポリゴンに対してスライドする処理を行う

				// 壁ポリゴンの数だけ繰り返し
				for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; i++)
				{
					// i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
					Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][i];

					// ポリゴンとキャラクターが当たっていなかったら次のループへ
					if (HitCheck_Capsule_Triangle(
						BottomPos1, BottomPos2, StageHitBottomInfo.Width,
						Poly->Position[0], Poly->Position[1],
						Poly->Position[2]) == FALSE &&
						HitCheck_Capsule_Triangle(
							TopPos1, TopPos2, StageHitTopInfo.Width,
							Poly->Position[0], Poly->Position[1],
							Poly->Position[2]) == FALSE) continue;

					/*
					// キャラクラータイプが敵弾だった場合はキャラを削除して終了
					if (CBInfo->Type == ECharaType_EnemyShot)
					{
						Chara_Delete(CInfo);
						for (k = 0; k < HitNum; k++)
						{
							MV1CollResultPolyDimTerminate(HitDim[k]);
						}
						return true;
					}*/

					// ここにきたらポリゴンとキャラクターが当たっているということなので、
					// ポリゴンに当たったフラグを立てる
					HitFlag = true;

					// 壁ポリゴンに当たったら壁に遮られない移動分だけ移動する

					// 法線のＸＺ値だけを抽出
					PolyXZNormal = Poly->Normal;
					PolyXZNormal.y = 0.0f;

					// 進行方向ベクトルと壁ポリゴンの法線ベクトルに垂直なベクトルを算出
					TempYVector = VCross(TempMoveVector, PolyXZNormal);

					// 算出したベクトルと壁ポリゴンの法線ベクトルに垂直なベクトルを算出
					SlideVec = VCross(PolyXZNormal, TempYVector);

					// Ｙ軸方向にはスライドしない
					SlideVec.y = 0.0f;

					// それを移動前の座標に足したものを新たな座標とする
					NextPos = VAdd(OldPos, SlideVec);

					// Ｙ座標には元の移動値を加算する
					NextPos.y += TempMoveVector.y;

					// 当たり判定に使用する座標を更新する
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

					// 新たな移動後座標で壁ポリゴンと当たるかどうかを判定する
					for (j = 0; j < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; j++)
					{
						// j番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
						Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][j];

						// 当たっていたらループから抜ける
						if (HitCheck_Capsule_Triangle(
							BottomPos1, BottomPos2, StageHitBottomInfo.Width,
							Poly->Position[0], Poly->Position[1],
							Poly->Position[2]) == TRUE ||
							HitCheck_Capsule_Triangle(
								TopPos1, TopPos2, StageHitTopInfo.Width,
								Poly->Position[0], Poly->Position[1],
								Poly->Position[2]) == TRUE) break;
					}

					// j が HitPolyNum[ static_cast<int>(StageCollType::STAGECOLLTYPE_WALL) ] だった場合は
					// どのポリゴンとも当たらなかったということなので
					// 『壁に当たったかどうか』のフラグを倒した上でループから抜ける
					if (j == HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)])
					{
						HitFlag = false;
						break;
					}
				}
			}
			else
			{
				// 移動していない場合は当たっているポリゴンがあるかどうかだけ確認

				// 壁ポリゴンの数だけ繰り返し
				for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; i++)
				{
					// i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
					Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][i];

					// ポリゴンに当たっていたら当たったフラグを立てた上でループから抜ける
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
						// キャラクラータイプが敵弾だった場合はキャラを削除して終了
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

			// 壁に当たっていたら壁から押し出す処理を行う
			if (HitFlag)
			{
				// 壁からの押し出し処理を試みる最大数だけ繰り返し
				for (k = 0; k < PATCon::CHARA_HIT_TRYNUM; k++)
				{
					// 壁ポリゴンの数だけ繰り返し
					for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; i++)
					{
						VECTOR PolyXZNormal;

						// i番目の壁ポリゴンのアドレスを壁ポリゴンポインタ配列から取得
						Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)][i];

						// キャラクターと当たっているかを判定
						if (HitCheck_Capsule_Triangle(
							BottomPos1, BottomPos2, StageHitBottomInfo.Width,
							Poly->Position[0], Poly->Position[1],
							Poly->Position[2]) == FALSE &&
							HitCheck_Capsule_Triangle(
								TopPos1, TopPos2, StageHitTopInfo.Width,
								Poly->Position[0], Poly->Position[1],
								Poly->Position[2]) == FALSE) continue;

						// 当たっていたらキャラクターを壁の法線方向に一定距離移動させる
						PolyXZNormal = Poly->Normal;
						PolyXZNormal.y = 0.0f;
						NextPos = VAdd(NextPos, VScale(PolyXZNormal,
							PATCon::CHARA_HIT_SLIDE_DISTANCE));

						// 当たり判定に使用する座標を更新する
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

						// 移動した上で壁ポリゴンと当たるかどうかを判定
						for (j = 0; j < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)]; j++)
						{
							// 当たっていたらループを抜ける
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

						// 全てのポリゴンと当たっていなかったらここでループ終了
						if (j == HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)])
						{
							break;
						}
					}

					// i が HitPolyNum[ static_cast<int>(StageCollType::STAGECOLLTYPE_WALL) ] ではない場合は
					// 全部のポリゴンで押し出しを試みる前に全ての壁ポリゴンと
					// 接触しなくなったということなのでループから抜ける
					if (i != HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_WALL)])
					{
						break;
					}
				}
			}
		}

		// 天井ポリゴンとの当たり判定
		if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_CEILING)] != 0)
		{
			float MinY;

			// 天井に頭をぶつける処理を行う

			// 一番低い天井にぶつける為の判定用変数を初期化
			MinY = 0.0f;

			// 当たったかどうかのフラグを倒す
			HitFlag = false;

			// 当たり判定用の線分の座標を算出
			LineTopPos = VAdd(NextPos, StageHitTopInfo.CenterPosition);
			LineTopPos.y += StageHitTopInfo.Height / 2.0f
				+ StageHitTopInfo.Width;

			LineBottomPos = VAdd(NextPos, StageHitBottomInfo.CenterPosition);
			LineBottomPos.y -= StageHitBottomInfo.Height / 2.0f
				+ StageHitBottomInfo.Width;

			// 天井ポリゴンの数だけ繰り返し
			for (i = 0; i < HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_CEILING)]; i++)
			{
				// i番目の天井ポリゴンのアドレスを天井ポリゴンポインタ配列から取得
				Poly = HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_CEILING)][i];

				// 足先から頭の高さまでの間でポリゴンと接触しているかどうかを判定
				LineRes = HitCheck_Line_Triangle(LineBottomPos, LineTopPos,
					Poly->Position[0], Poly->Position[1], Poly->Position[2]);

				// 接触していなかったら何もしない
				if (LineRes.HitFlag == FALSE)
				{
					continue;
				}
				/*
				// キャラクラータイプが敵弾だった場合は削除して終了
				if (CBInfo->Type == ECharaType_EnemyShot)
				{
					Chara_Delete(CInfo);
					for (k = 0; k < HitNum; k++)
					{
						MV1CollResultPolyDimTerminate(HitDim[k]);
					}
					return true;
				}*/

				// 既にポリゴンに当たっていて、且つ今まで検出した
				// 天井ポリゴンより高い場合は何もしない
				if (HitFlag && MinY < LineRes.Position.y)
				{
					continue;
				}

				// ポリゴンに当たったフラグを立てる
				HitFlag = true;

				// 接触したＹ座標を保存する
				MinY = LineRes.Position.y;
			}

			// 接触したポリゴンがあったかどうかで処理を分岐
			if (HitFlag)
			{
				// 接触した場合はキャラクターのＹ座標を接触座標を元に更新
				NextPos.y = MinY - (LineTopPos.y - LineBottomPos.y);

				// Ｙ軸方向の速度は反転
				CBInfo->SetMoveSpeedY(-CBInfo->GetMoveSpeed().y);
			}
		}

		// 床ポリゴンとの当たり判定
		if (HitPolyNum[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)] != 0)
		{
			float MaxY;
			int   MaxIndex;

			// ポリゴンに当たったかどうかのフラグを倒しておく
			HitFlag = false;

			// 一番高い床ポリゴンに接地させる為の判定用変数を初期化
			MaxY = 0.0f;
			MaxIndex = -1;

			// 当たり判定の線分の座標をセット
			LineTopPos = VAdd(NextPos, StageHitTopInfo.CenterPosition);
			LineTopPos.y += StageHitTopInfo.Height / 2.0f
				+ StageHitTopInfo.Width;

			LineBottomPos = VAdd(NextPos, StageHitBottomInfo.CenterPosition);
			LineBottomPos.y -= StageHitBottomInfo.Height / 2.0f
				+ StageHitBottomInfo.Width;

			// 下端の値を床判定用に補正
			if (CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP)
			{
				LineBottomPos.y += PATCon::CHARA_HIT_FLOOR_Y_ADJUST_JUMP;
			}
			else
			{
				LineBottomPos.y += PATCon::CHARA_HIT_FLOOR_Y_ADJUST_WALK;
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
				/*
				// キャラクラータイプが敵弾だった場合は削除して終了
				if (CBInfo->Type == ECharaType_EnemyShot)
				{
					Chara_Delete(CInfo);
					for (k = 0; k < HitNum; k++)
					{
						MV1CollResultPolyDimTerminate(HitDim[k]);
					}
					return true;
				}*/

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

			// 床ポリゴンに当たったかどうかで処理を分岐
			if (HitFlag)
			{
				// 当たった場合

				// 接触したポリゴンで一番高いＹ座標をキャラクターのＹ座標にする
				NextPos.y = MaxY;

				// Ｙ軸方向の移動速度は０に
				CBInfo->SetMoveSpeedY(0.0f);

				/*
				// 接触したポリゴンのマテリアルタイプを取得する
				CInfo->OnMaterialType = StageData_GetCollisionModelMaterialType(
					HitPoly[static_cast<int>(StageCollType::STAGECOLLTYPE_FLOOR)][MaxIndex]->MaterialIndex);
				*/

				// もしジャンプ中だった場合は着地状態に移行する
				if (CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP)
				{
					/*
					// 着地処理
					if (!Chara_Landed(CInfo))
					{
						return false;
					}
					*/
					// 優先度が一番低いやつ
					CBInfo->SetActionState(ACTION_STATE::ACTION_STATE_STANCE);
				}
			}
			else
			{
				// 床コリジョンに当たっていなくて且つジャンプ状態ではなかった場合は
				// ジャンプ状態に移行する
				if (!(CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP))
				{
					CBInfo->SetActionState(ACTION_STATE::ACTION_STATE_JUMP);
					/*
					// ｼﾞｬﾝﾌﾟ処理
					if (!Chara_Fall(CInfo))
					{
						return false;
					}
					*/
				}
			}
		}

		// 検出したキャラクターの周囲のポリゴン情報を開放する
		for (i = 0; i < HitNum; i++)
		{
			MV1CollResultPolyDimTerminate(HitDim[i]);
		}

		// 新しい座標を保存する
		CBInfo->SetPos(ConvertVec3(NextPos));

		// 全ての移動が完了していない場合はループ
	} while (CompMoveDistance + 0.001f < TotalMoveDistance);

	// ジャンプ中ではない場合は移動速度を０にする
	if (!(CBInfo->GetNowAction() == ACTION_STATE::ACTION_STATE_JUMP))
	{
		CBInfo->SetMoveSpeed(Vector3());
		CBInfo->SetActionState(ACTION_STATE::ACTION_STATE_STANCE);
	}

	// キャラクターの３Ｄモデルの座標を更新する
	//MV1SetPosition(CInfo->ModelHandle, CInfo->Position);

	return true;	// 正常終了

}