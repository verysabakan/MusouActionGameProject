//------------------------------------------------------
// @brief	任意のｵﾌﾞｼﾞｪｸﾄ同士の当たり判定を行う
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include "FlexibleCollision.h"
#include "PlayerAndTerrain.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
FlexibleCollision::FlexibleCollision()
{
	/*
	colTable[SHAPE_CIRCLE][SHAPE_CIRCLE] = new CircleAndCircle();
	colTable[SHAPE_CIRCLE][SHAPE_RECT] = new CircleAndRect();
	colTable[SHAPE_RECT][SHAPE_CIRCLE] = new CircleAndRect();
	colTable[SHAPE_RECT][SHAPE_RECT] = new RectAndRect();
	*/
	
	colTable[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_PLAYER)]
				[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_TERRAIN)]
		= std::make_unique<PlayerAndTerrain>();	// ﾌﾟﾚｲﾔｰと地形の当たり判定
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
FlexibleCollision::~FlexibleCollision()
{
	// 処理なし
}
//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void FlexibleCollision::Initialize()
{
	// 各初期化
	for (OBJECT_TYPE i = begin(OBJECT_TYPE::OBJECT_TYPE_ENEMY); i < end(i); ++i)
	{
		for (OBJECT_TYPE j = begin(OBJECT_TYPE::OBJECT_TYPE_ENEMY); j < end(j); ++j)
		{
			if (colTable[static_cast<int>(i)][static_cast<int>(j)] != nullptr)
			{
				useTypeList1.push_back(i);
				useTypeList2.push_back(j);
			}
		}
	}
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void FlexibleCollision::Finalize()
{
	// 各終了処理
	for (OBJECT_TYPE i = begin(OBJECT_TYPE::OBJECT_TYPE_ENEMY); i < end(i); ++i)
	{
		for (OBJECT_TYPE j = begin(OBJECT_TYPE::OBJECT_TYPE_ENEMY); j < end(j); ++j)
		{
			// ﾘｿｰｽの開放
			colTable[static_cast<int>(i)][static_cast<int>(j)].reset();

			// 要素の初期化
			useTypeList1.clear();
			useTypeList2.clear();
		}
	}
}

//------------------------------------------------------
// @brief	当たり判定
//------------------------------------------------------
bool FlexibleCollision::HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2)
{
	// 要素が入っているかﾁｪｯｸ
	for (auto i = 0; i < useTypeList1.size(); ++i)
	{
		for (auto j = 0; j < useTypeList2.size(); ++j)
		{
			if (!(useTypeList1[i] == o1->GetType() 
				&& useTypeList2[j] == o1->GetType()))
			{
				continue;
			}
			return colTable[static_cast<int>(o1->GetType())]
				[static_cast<int>(o2->GetType())]->HitCheck(o1, o2);
		}
	}
	return false;	// 何もなかった
}

