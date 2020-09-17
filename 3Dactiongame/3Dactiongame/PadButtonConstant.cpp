//------------------------------------------------------
// @brief	Êß¯ÄŞ‚É‘Î‰‚µ‚½enum
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "PadButtonConstant.h"

//------------------------------------------------------
// @brief	PAD_BUTTON‚Ìæ“ª‚Ì—v‘f‚ğ•Ô‚·
//------------------------------------------------------
PAD_BUTTON begin(PAD_BUTTON)
{
	return PAD_BUTTON::PAD_UP;
}

//------------------------------------------------------
// @brief	PAD_BUTTON‚Ì––’[‚ğ•Ô‚·
//------------------------------------------------------
PAD_BUTTON end(PAD_BUTTON)
{
	return PAD_BUTTON::PAD_BUTTON_NUM;
}

//------------------------------------------------------
// @brief	©•ª©g‚ğ•Ô‚·
//------------------------------------------------------
PAD_BUTTON operator*(PAD_BUTTON& button)
{
	return button;
}

//------------------------------------------------------
// @brief	PAD_BUTTON‚Ì++‚ÌŒvZ
//------------------------------------------------------
PAD_BUTTON operator++(PAD_BUTTON& button)
{
	// underlying_type‚ÅÃŞÌ«ÙÄ‚ÌŠî’êŒ^int‚ğæ“¾‚µ‰ÁZ‚·‚é
	return button = PAD_BUTTON(std::underlying_type<PAD_BUTTON>::type(button) + 1);
}

//------------------------------------------------------
// @brief	PAD_BUTTON‚É‘Î‚·‚é‘«‚µZ
//------------------------------------------------------
PAD_BUTTON operator+(PAD_BUTTON& button, int k)
{
	return static_cast<PAD_BUTTON>(static_cast<int> (button) + k);
}

//------------------------------------------------------
// @brief	PAD_BUTTON‚É‘Î‚·‚éˆø‚«Z
//------------------------------------------------------
PAD_BUTTON operator-(PAD_BUTTON& button, int k)
{
	return static_cast<PAD_BUTTON>(static_cast<int> (button) - k);
}

//------------------------------------------------------
// @brief	PAD_BUTTON‚ğint‚É•ÏŠ·‚µ‚Ä•Ô‚·
//------------------------------------------------------
int ConvertNum(const PAD_BUTTON& button)
{
	return static_cast<int>(button);
}