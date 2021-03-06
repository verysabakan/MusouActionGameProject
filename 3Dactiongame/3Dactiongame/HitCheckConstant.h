//------------------------------------------------------
// @brief	当たり判定に使う定数
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ｺﾘｼﾞｮﾝの種類
enum class StageCollType
{
	STAGECOLLTYPE_WALL,			// 壁
	STAGECOLLTYPE_FLOOR,		// 床
	STAGECOLLTYPE_CEILING,		// 天井

	STAGECOLLTYPE_NUM			// ｺﾘｼﾞｮﾝの種類数
};
