//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Controller::Controller()
{
	// -----ｷｰ、ﾊﾟｯﾄﾞ入力状態の初期化----- //
	for (int i = 0; i < INPUT_STATE_MAX; i++) {
		// ｷｰﾎﾞｰﾄﾞ
		for (int j = 0; j < KEY_STATE_BUFFER; j++) 
		{
			key[i][j] = false;
		}

		// ﾊﾟｯﾄﾞ
		for (int j = 0; j < PAD_STATE_BUFFER; j++) 
		{
			pad[i][j] = false;
		}
	}
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Controller::~Controller()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Controller::Update(void)
{
	// -----入力状態初期化----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		// 全部押していない事にする
		key[INPUT_STATE_NOW][i] = false;
		key[INPUT_STATE_UP][i] = false;
		key[INPUT_STATE_TRG][i] = false;
	}

	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		// 全部押していない事にする
		pad[INPUT_STATE_NOW][i] = false;
		pad[INPUT_STATE_UP][i] = false;
		pad[INPUT_STATE_TRG][i] = false;
	}

	// -----現在のﾌﾚｰﾑの全ての入力状態の取得----- //
	char keyBuffer[KEY_STATE_BUFFER];
	GetHitKeyStateAll(keyBuffer);
	auto pad1 = GetJoypadInputState(DX_INPUT_PAD1);		// 1P
	//auto pad2 = GetJoypadInputState(DX_INPUT_PAD1);		// 2P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);		// 3P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);		// 4P

	// -----ｷｰのの入力状態の格納----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		if (keyBuffer[i] == 1)
		{
			key[INPUT_STATE_NOW][i] = true;
		}
	}

	// ﾊﾟｯﾄﾞの入力状態の格納
	for (int i = 0; i < PAD_STATE_BUFFER; i++) {
		if (pad1 & (1 << i)) {
			pad[INPUT_STATE_NOW][i] = true;
		}
	}

	// -----押された瞬間、離された瞬間、現ﾌﾚｰﾑの入力保存----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		key[INPUT_STATE_UP][i] = ~key[INPUT_STATE_NOW][i] & key[INPUT_STATE_OLD][i]; 
		key[INPUT_STATE_TRG][i] = key[INPUT_STATE_NOW][i] & ~key[INPUT_STATE_OLD][i];
		key[INPUT_STATE_OLD][i] = key[INPUT_STATE_NOW][i];
	}

	for (int i = 0; i < PAD_STATE_BUFFER; i++)
	{
		pad[INPUT_STATE_UP][i] = pad[INPUT_STATE_NOW][i] & ~pad[INPUT_STATE_OLD][i];
		pad[INPUT_STATE_TRG][i] = ~pad[INPUT_STATE_NOW][i] & pad[INPUT_STATE_OLD][i];
		pad[INPUT_STATE_OLD][i] = pad[INPUT_STATE_NOW][i];
	}
}

//------------------------------------------------------
// @brief	描画:ﾁｪｯｸ用
//------------------------------------------------------
void Controller::Draw(void)
{
	// どのｷｰが押されているか
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		if (key[INPUT_STATE_NOW][i] == 1)
		{
			DrawFormatString(0, 16, 0xffffff, "現在押しているｷｰ:%d", i);
		}
	}

	// どのﾎﾞﾀﾝが押されているか
	for (int i = 0; i < PAD_STATE_BUFFER; i++)
	{
		if (pad[INPUT_STATE_NOW][i]) {
			DrawFormatString(0, 32, 0xffffff, "現在押しているﾎﾞﾀﾝ:%d", i);
		}
	}
}

//------------------------------------------------------
// @brief	入力が受け取った状態にあるかを判断し返す
//------------------------------------------------------
const bool& Controller::GetInputState(int const input, INPUT_STATE const inputState) const
{
	bool ret = false;

	// ｷｰ、ﾊﾟｯﾄﾞの入力が受け取った状態か
	if ((key[inputState][input] == true)
	||	(pad[inputState][input] == true))
	{
		ret = true;
	}

	return ret;
}