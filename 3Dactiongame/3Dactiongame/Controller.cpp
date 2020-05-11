//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include "Controller.h"
#include <DxLib.h>

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
void Controller::Update()
{
	// 前ﾌﾚｰﾑの入力状態
	key[KEY_SIGNAL_OLD] = key[KEY_SIGNAL_NOW];
	key[KEY_SIGNAL_OLD] = key[KEY_SIGNAL_NOW];

	// 現在のﾌﾚｰﾑの入力状態
	GetHitKeyStateAll(key[KEY_SIGNAL_NOW].data());
	//pad[KEY_SIGNAL_NOW].data = GetJoypadInputState(DX_INPUT_PAD1);

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
void Controller::Draw()
{
	// どのｷｰが押されているか
	for (int i = 0; i < 256; i++) 
	{
		if (key[KEY_SIGNAL_NOW][i] == true)
		{
			DrawFormatString(0, 16, 0xffffff, "現在押されているｷｰ:%d", i);
		}
	}
}

//------------------------------------------------------
// @brief	
//------------------------------------------------------
/*
const KEY_FLAG Controller::GetInputKey() const
{
	
}*/