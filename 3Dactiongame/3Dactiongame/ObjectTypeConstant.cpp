//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類
// 2020 7/27 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ObjectTypeConstant.h"

//------------------------------------------------------
// @brief	OBJECT_TYPEの先頭の要素を返す
//------------------------------------------------------
OBJECT_TYPE begin(OBJECT_TYPE)
{
	return OBJECT_TYPE::OBJECT_TYPE_PLAYER;
}

//------------------------------------------------------
// @brief	OBJECT_TYPEの末端を返す
//------------------------------------------------------
OBJECT_TYPE end(OBJECT_TYPE)
{
	return OBJECT_TYPE::OBJECT_TYPE_NUM;
}

//------------------------------------------------------
// @brief	自分自身を返す
//------------------------------------------------------
OBJECT_TYPE operator*(OBJECT_TYPE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	OBJECT_TYPEの++の計算
//------------------------------------------------------
OBJECT_TYPE operator++(OBJECT_TYPE& id)
{
	// underlying_typeでﾃﾞﾌｫﾙﾄの基底型intを取得し加算する
	return id = OBJECT_TYPE(std::underlying_type<OBJECT_TYPE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	OBJECT_TYPEに対する足し算
//------------------------------------------------------
OBJECT_TYPE operator+(OBJECT_TYPE& id, int k)
{
	return static_cast<OBJECT_TYPE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	OBJECT_TYPEに対する引き算
//------------------------------------------------------
OBJECT_TYPE operator-(OBJECT_TYPE& id, int k)
{
	return static_cast<OBJECT_TYPE>(static_cast<int> (id) - k);
}
