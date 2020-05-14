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
	/*
	// 何も入力されてない状態
	for (int i = 0; i < key->max_size; i++) {
		for (int j = 0; i < KEY_SIGNAL_MAX; i++) {
			key[j][i] = false;
		}
	}
	*/
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
Controller::~Controller()
{
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void Controller::Update(void)
{
	// 前ﾌﾚｰﾑの入力状態
	key[KEY_SIGNAL_OLD] = key[KEY_SIGNAL_NOW];
	key[KEY_SIGNAL_OLD] = key[KEY_SIGNAL_NOW];

	// 現在のﾌﾚｰﾑの入力状態
	GetHitKeyStateAll(key[KEY_SIGNAL_NOW].data());
	auto pad1 = GetJoypadInputState(DX_INPUT_PAD1);	// 1P
	//auto pad2 = GetJoypadInputState(DX_INPUT_PAD1);	// 2P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);	// 3P

	for (int i = 0; i < 28; i++) {
		pad[KEY_SIGNAL_NOW][i] = pad1;
	}

	/*
	// 押された瞬間、離された瞬間
	for (int i = 0; i < key->max_size; i++) {
		key[KEY_SIGNAL_TRG][i] = key[KEY_SIGNAL_NOW][i] & ~key[KEY_SIGNAL_OLD][i];
		key[KEY_SIGNAL_UP][i] = ~key[KEY_SIGNAL_NOW][i] & key[KEY_SIGNAL_OLD][i];
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
		if (key[KEY_SIGNAL_NOW][i] == 1)
		{
			DrawFormatString(0, 16, 0xffffff, "現在押しているｷｰ:%d", i);
			
			if (key[KEY_SIGNAL_NOW][KEY_INPUT_G] == 1) 
			{
				DrawString(0, 32, "指定したｷｰを押した", 0xffffff);
			}
		}
	}

	// どのﾎﾞﾀﾝが押されているか
	for (int i = 0; i < 28; i++) {
		if (pad[KEY_SIGNAL_NOW][i]) {
			DrawFormatString(0, 48, 0xffffff, "現在押しているﾎﾞﾀﾝ:%d", i);
		}
	}

	DrawFormatString(0, 48, 0xffffff, "現在押しているﾎﾞﾀﾝ:%d", KEY_INPUT_K);
}

//------------------------------------------------------
// @brief	
//------------------------------------------------------
/*
const KEY_FLAG Controller::GetInputKey() const
{
	
}*/