//------------------------------------------------------
// @brief	ﾏﾈｰｼﾞｬｰの種類
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類
enum class MANAGER_TYPE
{
	PLAYER_MANAGER,		// ﾌﾟﾚｲﾔｰ
	ENAMY_MANAGER,		// ｴﾈﾐｰ
	SHOT_MANAGER,		// 弾
	WEAPON_MANAGER,		// 武器
	OBSTACLE_MANAGER,	// 障害物
	TERRAIN_MANAGER,	// 地形

	NONE,				// 何もない
	MANAGER_TYPE_NUM	// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類数(最大値)
};

MANAGER_TYPE begin(MANAGER_TYPE);					// MANAGER_TYPEの先頭の要素を返す
MANAGER_TYPE end(MANAGER_TYPE);						// MANAGER_TYPEの末端を返す
MANAGER_TYPE operator*(MANAGER_TYPE& type);			// 自分自身を返す
MANAGER_TYPE operator++(MANAGER_TYPE& type);		// MANAGER_TYPEの++の計算
MANAGER_TYPE operator+(MANAGER_TYPE& type, int k);	// MANAGER_TYPEに対する足し算
MANAGER_TYPE operator-(MANAGER_TYPE& type, int k);	// MANAGER_TYPEに対する引き算

