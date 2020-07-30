//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類
// 2020 7/27 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ObjectTypeConstant.h"

//------------------------------------------------------
// @brief	ObjectTypeの先頭の要素を返す
//------------------------------------------------------
ObjectType begin(ObjectType)
{
	return ObjectType::OBJECTTYPE_PLAYER;
}

//------------------------------------------------------
// @brief	ObjectTypeの末端を返す
//------------------------------------------------------
ObjectType end(ObjectType)
{
	return ObjectType::OBJECTTYPE_NUM;
}

//------------------------------------------------------
// @brief	自分自身を返す
//------------------------------------------------------
ObjectType operator*(ObjectType& id)
{
	return id;
}

//------------------------------------------------------
// @brief	ObjectTypeの++の計算
//------------------------------------------------------
ObjectType operator++(ObjectType& id)
{
	// underlying_typeでﾃﾞﾌｫﾙﾄの基底型intを取得し加算する
	return id = ObjectType(std::underlying_type<ObjectType>::type(id) + 1);
}

//------------------------------------------------------
// @brief	ObjectTypeに対する足し算
//------------------------------------------------------
ObjectType operator+(ObjectType& id, int k)
{
	return static_cast<ObjectType>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	ObjectTypeに対する引き算
//------------------------------------------------------
ObjectType operator-(ObjectType& id, int k)
{
	return static_cast<ObjectType>(static_cast<int> (id) - k);
}
