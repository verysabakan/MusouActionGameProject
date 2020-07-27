//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類
enum class ObjectType
{
	OBJECTTYPE_PLAYER,			// ﾌﾟﾚｲﾔｰ
	OBJECTTYPE_ENEMY,			// ｴﾈﾐｰ
	OBJECTTYPE_SHOT,			// 弾
	OBJECTTYPE_WEAPON,			// 武器
	OBJECTTYPE_OBSTACLE,		// 障害物
	OBJECTTYPE_TERRAIN,			// 地形

	NONE,						// 何もない
	OBJECTTYPE_NUM				// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類数(最大値)
};

ObjectType begin(ObjectType);					// ObjectTypeの先頭の要素を返す
ObjectType end(ObjectType);						// ObjectTypeの末端を返す
//ObjectType operator*(ObjectType& type);			// 自分自身を返す
ObjectType operator++(ObjectType& type);		// ObjectTypeの++の計算
ObjectType operator+(ObjectType& type, int k);	// ObjectTypeに対する足し算
ObjectType operator-(ObjectType& type, int k);	// ObjectTypeに対する引き算
