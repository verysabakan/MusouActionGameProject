//------------------------------------------------------
// @brief	入力状態
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 入力状態
enum class INPUT_STATE
{
	INPUT_HOLD,	// 長押し
	INPUT_TRG,	// 押した瞬間
	INPUT_UP,	// 話した瞬間

	INPUT_NUM	// 状態の種類数(最大数)
};

INPUT_STATE begin(INPUT_STATE);						// INPUT_STATEの先頭の要素を返す
INPUT_STATE end(INPUT_STATE);						// INPUT_STATEの末端を返す
INPUT_STATE operator*(INPUT_STATE& type);			// 自分自身を返す
INPUT_STATE operator++(INPUT_STATE& type);			// INPUT_STATEの++の計算
INPUT_STATE operator+(INPUT_STATE& type, int k);	// INPUT_STATEに対する足し算
INPUT_STATE operator-(INPUT_STATE& type, int k);	// INPUT_STATEに対する引き算
