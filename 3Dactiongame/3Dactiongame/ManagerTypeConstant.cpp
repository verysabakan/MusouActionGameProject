//------------------------------------------------------
// @brief	ÏÈ°¼Ş¬°‚Ìí—Ş
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "ManagerTypeConstant.h"

//------------------------------------------------------
// @brief	MANAGER_TYPE‚Ìæ“ª‚Ì—v‘f‚ğ•Ô‚·
//------------------------------------------------------
MANAGER_TYPE begin(MANAGER_TYPE)
{
	return MANAGER_TYPE::PLAYER_MANAGER;
}

//------------------------------------------------------
// @brief	MANAGER_TYPE‚Ì––’[‚ğ•Ô‚·
//------------------------------------------------------
MANAGER_TYPE end(MANAGER_TYPE)
{
	return MANAGER_TYPE::MANAGER_TYPE_NUM;
}

//------------------------------------------------------
// @brief	©•ª©g‚ğ•Ô‚·
//------------------------------------------------------
MANAGER_TYPE operator*(MANAGER_TYPE& id)
{
	return id;
}

//------------------------------------------------------
// @brief	MANAGER_TYPE‚Ì++‚ÌŒvZ
//------------------------------------------------------
MANAGER_TYPE operator++(MANAGER_TYPE& id)
{
	// underlying_type‚ÅÃŞÌ«ÙÄ‚ÌŠî’êŒ^int‚ğæ“¾‚µ‰ÁZ‚·‚é
	return id = MANAGER_TYPE(std::underlying_type<MANAGER_TYPE>::type(id) + 1);
}

//------------------------------------------------------
// @brief	MANAGER_TYPE‚É‘Î‚·‚é‘«‚µZ
//------------------------------------------------------
MANAGER_TYPE operator+(MANAGER_TYPE& id, int k)
{
	return static_cast<MANAGER_TYPE>(static_cast<int> (id) + k);
}

//------------------------------------------------------
// @brief	MANAGER_TYPE‚É‘Î‚·‚éˆø‚«Z
//------------------------------------------------------
MANAGER_TYPE operator-(MANAGER_TYPE& id, int k)
{
	return static_cast<MANAGER_TYPE>(static_cast<int> (id) - k);
}