//------------------------------------------------------
// @brief	ﾊﾟｯﾄﾞに対応したenum
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#include <type_traits>
#include "PadButtonConstant.h"

//------------------------------------------------------
// @brief	PAD_BUTTONの先頭の要素を返す
//------------------------------------------------------
PAD_BUTTON begin(PAD_BUTTON)
{
	return PAD_BUTTON::PAD_UP;
}

//------------------------------------------------------
// @brief	PAD_BUTTONの末端を返す
//------------------------------------------------------
PAD_BUTTON end(PAD_BUTTON)
{
	return PAD_BUTTON::PAD_BUTTON_NUM;
}

//------------------------------------------------------
// @brief	自分自身を返す
//------------------------------------------------------
PAD_BUTTON operator*(PAD_BUTTON& button)
{
	return button;
}

//------------------------------------------------------
// @brief	PAD_BUTTONの++の計算
//------------------------------------------------------
PAD_BUTTON operator++(PAD_BUTTON& button)
{
	// underlying_typeでﾃﾞﾌｫﾙﾄの基底型intを取得し加算する
	return button = PAD_BUTTON(std::underlying_type<PAD_BUTTON>::type(button) + 1);
}

//------------------------------------------------------
// @brief	PAD_BUTTONに対する足し算
//------------------------------------------------------
PAD_BUTTON operator+(PAD_BUTTON& button, int k)
{
	return static_cast<PAD_BUTTON>(static_cast<int> (button) + k);
}

//------------------------------------------------------
// @brief	PAD_BUTTONに対する引き算
//------------------------------------------------------
PAD_BUTTON operator-(PAD_BUTTON& button, int k)
{
	return static_cast<PAD_BUTTON>(static_cast<int> (button) - k);
}

//------------------------------------------------------
// @brief	PAD_BUTTONをintに変換して返す
//------------------------------------------------------
int ConvertNum(const PAD_BUTTON& button)
{
	return static_cast<int>(button);
}