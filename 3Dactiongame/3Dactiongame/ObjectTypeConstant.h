//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類
enum class OBJECT_TYPE
{
	OBJECT_TYPE_PLAYER,			// ﾌﾟﾚｲﾔｰ
	OBJECT_TYPE_ENEMY,			// ｴﾈﾐｰ
	OBJECT_TYPE_SHOT,			// 弾
	OBJECT_TYPE_WEAPON,			// 武器
	OBJECT_TYPE_OBSTACLE,		// 障害物
	OBJECT_TYPE_TERRAIN,			// 地形

	NONE,						// 何もない
	OBJECT_TYPE_NUM				// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類数(最大値)
};

OBJECT_TYPE begin(OBJECT_TYPE);						// OBJECT_TYPEの先頭の要素を返す
OBJECT_TYPE end(OBJECT_TYPE);						// OBJECT_TYPEの末端を返す
OBJECT_TYPE operator*(OBJECT_TYPE& type);			// 自分自身を返す
OBJECT_TYPE operator++(OBJECT_TYPE& type);			// OBJECT_TYPEの++の計算
OBJECT_TYPE operator+(OBJECT_TYPE& type, int k);	// OBJECT_TYPEに対する足し算
OBJECT_TYPE operator-(OBJECT_TYPE& type, int k);	// OBJECT_TYPEに対する引き算
