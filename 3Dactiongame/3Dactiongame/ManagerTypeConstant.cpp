//------------------------------------------------------
// @brief	ﾏﾈｰｼﾞｬｰの種類
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ManagerTypeConstant.h"

//------------------------------------------------------
// @brief	MANAGER_TYPEの先頭の要素を返す
//------------------------------------------------------
MANAGER_TYPE begin(MANAGER_TYPE)
{
	return MANAGER_TYPE::PLAYER_MANAGER;
}

//------------------------------------------------------
// @brief	MANAGER_TYPEの末端を返す
//------------------------------------------------------
MANAGER_TYPE end(MANAGER_TYPE)
{
	return MANAGER_TYPE::MANAGER_TYPE_NUM;
}

//------------------------------------------------------
// @brief	自分自身を返す
//------------------------------------------------------
MANAGER_TYPE operator*(MANAGER_TYPE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	MANAGER_TYPEの++の計算
//------------------------------------------------------
MANAGER_TYPE operator++(MANAGER_TYPE& id)
{
	// underlying_typeでﾃﾞﾌｫﾙﾄの基底型intを取得し加算する
	return id = MANAGER_TYPE(std::underlying_type<MANAGER_TYPE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	MANAGER_TYPEに対する足し算
//------------------------------------------------------
MANAGER_TYPE operator+(MANAGER_TYPE& id, int k)
{
	return static_cast<MANAGER_TYPE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	MANAGER_TYPEに対する引き算
//------------------------------------------------------
MANAGER_TYPE operator-(MANAGER_TYPE& id, int k)
{
	return static_cast<MANAGER_TYPE>(static_cast<int> (id) - k);
}