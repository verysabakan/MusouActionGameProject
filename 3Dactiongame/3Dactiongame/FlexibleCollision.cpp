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
	// 判定の生成
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
	for (auto i = begin(OBJECT_TYPE()); i < end(OBJECT_TYPE()); ++i)
	{
		for (auto j = begin(OBJECT_TYPE()); j < end(OBJECT_TYPE()); ++j)
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
	for (auto i = begin(OBJECT_TYPE()); i < end(OBJECT_TYPE()); ++i)
	{
		for (auto j = begin(OBJECT_TYPE()); j < end(OBJECT_TYPE()); ++j)
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
	for (auto i = 0; i < useTypeList1.size(); i++)
	{
		for (auto j = 0; j < useTypeList2.size(); j++)
		{
			// listに入って無ければｽｷｯﾌﾟ
			if (!(useTypeList1[i] == o1->GetType() 
				&& useTypeList2[j] == o2->GetType()))
			{
				continue;
			}

			// ﾘｽﾄに入っていれば判定を取る
			return colTable[static_cast<int>(o1->GetType())]
				[static_cast<int>(o2->GetType())]->HitCheck(o1, o2);
		}
	}
	return false;	// 何もなかった(異常終了)
}

