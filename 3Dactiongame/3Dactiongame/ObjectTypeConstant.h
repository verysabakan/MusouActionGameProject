//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類の定数
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

	OBJECTTYPE_NUM				// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類数
};
