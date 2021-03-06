//------------------------------------------------------
// @brief	ｷｬﾗの行動状態
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "InputStateConstant.h"

//------------------------------------------------------
// @brief	INPUT_STATEの先頭の要素を返す
//------------------------------------------------------
INPUT_STATE begin(INPUT_STATE)
{
	return INPUT_STATE::INPUT_HOLD;
}

//------------------------------------------------------
// @brief	INPUT_STATEの末端を返す
//------------------------------------------------------
INPUT_STATE end(INPUT_STATE)
{
	return INPUT_STATE::INPUT_NUM;
}

//------------------------------------------------------
// @brief	自分自身を返す
//------------------------------------------------------
INPUT_STATE operator*(INPUT_STATE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	INPUT_STATEの++の計算
//------------------------------------------------------
INPUT_STATE operator++(INPUT_STATE& id)
{
	// underlying_typeでﾃﾞﾌｫﾙﾄの基底型intを取得し加算する
	return id = INPUT_STATE(std::underlying_type<INPUT_STATE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	INPUT_STATEに対する足し算
//------------------------------------------------------
INPUT_STATE operator+(INPUT_STATE& id, int k)
{
	return static_cast<INPUT_STATE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	INPUT_STATEに対する引き算
//------------------------------------------------------
INPUT_STATE operator-(INPUT_STATE& id, int k)
{
	return static_cast<INPUT_STATE>(static_cast<int> (id) - k);
}