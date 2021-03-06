//------------------------------------------------------
// @brief	ｷｬﾗの行動状態
// 2020 9/8 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ActionStateConstant.h"

//------------------------------------------------------
// @brief	ObjectTypeの先頭の要素を返す
//------------------------------------------------------
ACTION_STATE begin(ACTION_STATE)
{
	return ACTION_STATE::ACTION_STATE_DEAD;
}

//------------------------------------------------------
// @brief	ObjectTypeの末端を返す
//------------------------------------------------------
ACTION_STATE end(ACTION_STATE)
{
	return ACTION_STATE::ACTION_STATE_NUM;
}

//------------------------------------------------------
// @brief	自分自身を返す
//------------------------------------------------------
ACTION_STATE operator*(ACTION_STATE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	ObjectTypeの++の計算
//------------------------------------------------------
ACTION_STATE operator++(ACTION_STATE& id)
{
	// underlying_typeでﾃﾞﾌｫﾙﾄの基底型intを取得し加算する
	return id = ACTION_STATE(std::underlying_type<ACTION_STATE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	ObjectTypeに対する足し算
//------------------------------------------------------
ACTION_STATE operator+(ACTION_STATE& id, int k)
{
	return static_cast<ACTION_STATE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	ObjectTypeに対する引き算
//------------------------------------------------------
ACTION_STATE operator-(ACTION_STATE& id, int k)
{
	return static_cast<ACTION_STATE>(static_cast<int> (id) - k);
}