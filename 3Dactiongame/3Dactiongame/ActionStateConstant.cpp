//------------------------------------------------------
// @brief	·¬×‚Ìs“®ó‘Ô
// 2020 9/8 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ActionStateConstant.h"

//------------------------------------------------------
// @brief	ObjectType‚Ìæ“ª‚Ì—v‘f‚ğ•Ô‚·
//------------------------------------------------------
ACTION_STATE begin(ACTION_STATE)
{
	return ACTION_STATE::ACTION_STATE_DEAD;
}

//------------------------------------------------------
// @brief	ObjectType‚Ì––’[‚ğ•Ô‚·
//------------------------------------------------------
ACTION_STATE end(ACTION_STATE)
{
	return ACTION_STATE::ACTION_STATE_NUM;
}

//------------------------------------------------------
// @brief	©•ª©g‚ğ•Ô‚·
//------------------------------------------------------
ACTION_STATE operator*(ACTION_STATE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	ObjectType‚Ì++‚ÌŒvZ
//------------------------------------------------------
ACTION_STATE operator++(ACTION_STATE& id)
{
	// underlying_type‚ÅÃŞÌ«ÙÄ‚ÌŠî’êŒ^int‚ğæ“¾‚µ‰ÁZ‚·‚é
	return id = ACTION_STATE(std::underlying_type<ACTION_STATE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	ObjectType‚É‘Î‚·‚é‘«‚µZ
//------------------------------------------------------
ACTION_STATE operator+(ACTION_STATE& id, int k)
{
	return static_cast<ACTION_STATE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	ObjectType‚É‘Î‚·‚éˆø‚«Z
//------------------------------------------------------
ACTION_STATE operator-(ACTION_STATE& id, int k)
{
	return static_cast<ACTION_STATE>(static_cast<int> (id) - k);
}