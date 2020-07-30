//------------------------------------------------------
// @brief	任意のｵﾌﾞｼﾞｪｸﾄ同士の当たり判定を行う
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

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

	colTable[static_cast<int>(ObjectType::OBJECTTYPE_PLAYER)][static_cast<int>(ObjectType::OBJECTTYPE_TERRAIN)]
		= std::make_shared<PlayerAndTerrain>();	// ﾌﾟﾚｲﾔｰと地形の当たり判定
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

}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void FlexibleCollision::Finalize()
{
	auto i = begin();
	/*
	for (ObjectType i = begin(i); i < end(i); ++i) 
	{
		for (ObjectType j = begin(j); j < end(j); ++j) 
		{
			
			//colTable[i][j].reset();
		}
	}*/
}

//------------------------------------------------------
// @brief	当たり判定
//------------------------------------------------------
bool FlexibleCollision::HitCheck(const ObjectType& o1, const ObjectType& o2)
{
	//return colTable[o1.GetType()][o2.GetType()]->HitCheck(o1, o2);
	return false;
}