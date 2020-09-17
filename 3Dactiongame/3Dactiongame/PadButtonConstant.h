//------------------------------------------------------
// @brief	ﾊﾟｯﾄﾞに対応したenum
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 入力状態
enum class PAD_BUTTON
{
	PAD_UP,
	PAD_DOWN,
	PAD_LEFT,
	PAD_RIGHT,
	PAD_1,
	PAD_2,
	PAD_3,
	PAD_4,
	PAD_BUTTON_NUM	// 状態の種類数(最大数)
};

PAD_BUTTON begin(PAD_BUTTON);						// PAD_BUTTONの先頭の要素を返す
PAD_BUTTON end(PAD_BUTTON);							// PAD_BUTTONの末端を返す
PAD_BUTTON operator*(PAD_BUTTON& button);			// 自分自身を返す
PAD_BUTTON operator++(PAD_BUTTON& button);			// PAD_BUTTONの++の計算
PAD_BUTTON operator+(PAD_BUTTON& button, int k);	// PAD_BUTTONに対する足し算
PAD_BUTTON operator-(PAD_BUTTON& button, int k);	// PAD_BUTTONに対する引き算

int ConvertNum(const PAD_BUTTON& button);	// PAD_BUTTONをintに変換して返す