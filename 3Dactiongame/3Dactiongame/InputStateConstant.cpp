//------------------------------------------------------
// @brief	·¬×‚Ìs“®ó‘Ô
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "InputStateConstant.h"

//------------------------------------------------------
// @brief	INPUT_STATE‚Ìæ“ª‚Ì—v‘f‚ğ•Ô‚·
//------------------------------------------------------
INPUT_STATE begin(INPUT_STATE)
{
	return INPUT_STATE::INPUT_HOLD;
}

//------------------------------------------------------
// @brief	INPUT_STATE‚Ì––’[‚ğ•Ô‚·
//------------------------------------------------------
INPUT_STATE end(INPUT_STATE)
{
	return INPUT_STATE::INPUT_NUM;
}

//------------------------------------------------------
// @brief	©•ª©g‚ğ•Ô‚·
//------------------------------------------------------
INPUT_STATE operator*(INPUT_STATE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	INPUT_STATE‚Ì++‚ÌŒvZ
//------------------------------------------------------
INPUT_STATE operator++(INPUT_STATE& id)
{
	// underlying_type‚ÅÃŞÌ«ÙÄ‚ÌŠî’êŒ^int‚ğæ“¾‚µ‰ÁZ‚·‚é
	return id = INPUT_STATE(std::underlying_type<INPUT_STATE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	INPUT_STATE‚É‘Î‚·‚é‘«‚µZ
//------------------------------------------------------
INPUT_STATE operator+(INPUT_STATE& id, int k)
{
	return static_cast<INPUT_STATE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	INPUT_STATE‚É‘Î‚·‚éˆø‚«Z
//------------------------------------------------------
INPUT_STATE operator-(INPUT_STATE& id, int k)
{
	return static_cast<INPUT_STATE>(static_cast<int> (id) - k);
}