//------------------------------------------------------
// @brief	µÌŞ¼Şª¸Ä‚Ìí—Ş
// 2020 7/27 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ObjectTypeConstant.h"

//------------------------------------------------------
// @brief	ObjectType‚Ìæ“ª‚Ì—v‘f‚ğ•Ô‚·
//------------------------------------------------------
ObjectType begin(ObjectType)
{
	return ObjectType::OBJECTTYPE_PLAYER;
}

//------------------------------------------------------
// @brief	ObjectType‚Ì––’[‚ğ•Ô‚·
//------------------------------------------------------
ObjectType end(ObjectType)
{
	return ObjectType::OBJECTTYPE_NUM;
}

/*
//------------------------------------------------------
// @brief	©•ª©g‚ğ•Ô‚·
//------------------------------------------------------
ObjectType operator*(ObjectType& id)
{
	return id;
}
*/

//------------------------------------------------------
// @brief	ObjectType‚Ì++‚ÌŒvZ
//------------------------------------------------------
ObjectType operator++(ObjectType& id)
{
	// underlying_type‚ÅÃŞÌ«ÙÄ‚ÌŠî’êŒ^int‚ğæ“¾‚µ‰ÁZ‚·‚é
	return id = ObjectType(std::underlying_type<ObjectType>::type(id) + 1);
}

//------------------------------------------------------
// @brief	ObjectType‚É‘Î‚·‚é‘«‚µZ
//------------------------------------------------------
ObjectType operator+(ObjectType& id, int k)
{
	return static_cast<ObjectType>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	ObjectType‚É‘Î‚·‚éˆø‚«Z
//------------------------------------------------------
ObjectType operator-(ObjectType& id, int k)
{
	return static_cast<ObjectType>(static_cast<int> (id) - k);
}
