//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

bool checkDayo = false;

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Controller::Controller()
{
	// -----ｷｰ、ﾊﾟｯﾄﾞ入力状態の初期化----- //
	for (int i = 0; i < INPUT_SIGNAL_MAX; i++) {
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
		key[INPUT_SIGNAL_NOW][i] = false;
		key[INPUT_SIGNAL_UP][i] = false;
		key[INPUT_SIGNAL_TRG][i] = false;
	}

	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		// 全部押していない事にする
		pad[INPUT_SIGNAL_NOW][i] = false;
		pad[INPUT_SIGNAL_UP][i] = false;
		pad[INPUT_SIGNAL_TRG][i] = false;
	}

	// -----現在のﾌﾚｰﾑの全ての入力状態の取得----- //
	char keyBuffer[KEY_STATE_BUFFER];
	GetHitKeyStateAll(keyBuffer);
	auto pad1 = GetJoypadInputState(DX_INPUT_PAD1);		// 1P
	//auto pad2 = GetJoypadInputState(DX_INPUT_PAD1);		// 2P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);		// 3P

	// -----ｷｰのの入力状態の格納----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		if (keyBuffer[i] == 1)
		{
			key[INPUT_SIGNAL_NOW][i] = true;
		}
	}

	/*
	// ﾊﾟｯﾄﾞの入力状態の格納
	for (int i = 0; i < PAD_STATE_BUFFER; i++) {
		if (pad1 & ) {

		}
	}
	*/

	// -----押された瞬間、離された瞬間、現ﾌﾚｰﾑの入力保存----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		key[INPUT_SIGNAL_UP][i] = ~key[INPUT_SIGNAL_NOW][i] & key[INPUT_SIGNAL_OLD][i]; 
		key[INPUT_SIGNAL_TRG][i] = key[INPUT_SIGNAL_NOW][i] & ~key[INPUT_SIGNAL_OLD][i];
		key[INPUT_SIGNAL_OLD][i] = key[INPUT_SIGNAL_NOW][i];
	}

	/*
	for (int i = 0; i < PAD_STATE_BUFFER; i++)
	{
		pad[INPUT_SIGNAL_UP][i] = pad[INPUT_SIGNAL_NOW][i] & ~pad[INPUT_SIGNAL_OLD][i];
		pad[INPUT_SIGNAL_TRG][i] = ~pad[INPUT_SIGNAL_NOW][i] & pad[INPUT_SIGNAL_OLD][i];
		pad[INPUT_SIGNAL_OLD][i] = pad[INPUT_SIGNAL_NOW][i];
	}
	*/
}

//------------------------------------------------------
// @brief	描画:ﾁｪｯｸ用
//------------------------------------------------------
void Controller::Draw(void)
{
	// どのｷｰが押されているか
	for (int i = 0; i < 256; i++)
	{
		if (key[INPUT_SIGNAL_NOW][i] == 1)
		{
			DrawFormatString(0, 16, 0xffffff, "現在押しているｷｰ:%d", i);
		}

		if ((key[INPUT_SIGNAL_TRG][i] == 1)&&(checkDayo == false))
		{
			checkDayo = true;
		}
		else if ((key[INPUT_SIGNAL_TRG][i] == 1) && (checkDayo == true))
		{
			checkDayo = false;
		}
	}

	if (checkDayo == true)
	{
		DrawString(0, 32, "指定したｷｰを押した", 0xffffff);
	}

	// どのﾎﾞﾀﾝが押されているか
	for (int i = 0; i < PAD_STATE_BUFFER; i++) {
		if (pad[INPUT_SIGNAL_NOW][i]) {
			DrawFormatString(0, 48, 0xffffff, "現在押しているﾎﾞﾀﾝ:%d", i);
		}
	}
}

/*
//------------------------------------------------------
// @brief	ｷｰが受け取った状態であるか確認する
//------------------------------------------------------
const KEY_FLAG& Controller::GetInputKey(INPUT_SIGNAL requiredSignal) const
{
	return key[INPUT_SIGNAL_NOW][5];
}

//------------------------------------------------------
// @brief	ﾊﾟｯﾄﾞが受け取った状態であるか確認する
//------------------------------------------------------
const PAD_FLAG Controller::GetInputButton(INPUT_SIGNAL requiredSignal) const
{

}
*/