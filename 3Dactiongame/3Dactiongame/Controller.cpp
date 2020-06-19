//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
// 2020 5/16 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

bool up = false;
bool trg = false;

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Controller::Controller()
{
	// ﾊﾟｯﾄﾞ対応ﾎﾞﾀﾝの初期化
	SetPadInput(PAD_INPUT_UP, PAD_INPUT_DOWN, PAD_INPUT_LEFT, PAD_INPUT_RIGHT,
		PAD_INPUT_B, PAD_INPUT_A, PAD_INPUT_C, PAD_INPUT_X);

	// 変数初期化
	input = 0;
	inputOld = 0;
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
void Controller::Update()
{
	// 前回入力
	inputOld = input;

	// 今回の入力
	input = GetJoypadInputState(DX_INPUT_PAD1);

	// ｷｰﾎﾞｰﾄﾞの割り当て
	char keyInput[keyBuffer];
	GetHitKeyStateAll(keyInput);
	if (keyInput[KEY_INPUT_UP]) input |= padInput[PAD_UP];
	if (keyInput[KEY_INPUT_DOWN]) input |= padInput[PAD_DOWN];
	if (keyInput[KEY_INPUT_LEFT]) input |= padInput[PAD_LEFT];
	if (keyInput[KEY_INPUT_RIGHT]) input |= padInput[PAD_RIGHT];
	if (keyInput[KEY_INPUT_Z]) input |= padInput[PAD_1];
	if (keyInput[KEY_INPUT_X]) input |= padInput[PAD_2];
	if (keyInput[KEY_INPUT_C]) input |= padInput[PAD_3];
	if (keyInput[KEY_INPUT_V]) input |= padInput[PAD_4];
}

//------------------------------------------------------
// @brief	描画:ﾁｪｯｸ用
//------------------------------------------------------
void Controller::Render()
{
	// 長押し
	if (IsPushUP(INPUT_HOLD))
	{
		DrawString(0, 16, "ﾎｰﾙﾄﾞです", 0xffffff);
		DrawFormatString(0, 32, 0xffffff, "%d", padInput[PAD_UP]);
	}

	// 押した瞬間
	if (IsPushUP(INPUT_TRG))
	{
		trg = !trg;
	}
	if (trg) 
	{
		DrawString(0, 48, "ﾄﾘｶﾞｰです", 0xffffff);
		DrawFormatString(0, 64, 0xffffff, "%d", padInput[PAD_UP]);
	}

	// 離した瞬間
	if (IsPushUP(INPUT_UP))
	{
		up = !up;
	}
	if (up)
	{
		DrawString(0, 80, "ｱｯﾌﾟです", 0xffffff);
		DrawFormatString(0, 96, 0xffffff, "%d", padInput[PAD_UP]);
	}

	// どれを押しているか
	for (auto i = 0; i < PAD_BUTTON_NUM; i++)
	{
		if (input & padInput[i])
		{
			DrawFormatString(0, 112 + 16 * i, 0xffffff, "%d:ﾎｰﾙﾄﾞです", i);
		}
	}
	
}

//------------------------------------------------------
// @brief	ﾊﾟｯﾄﾞ対応ﾎﾞﾀﾝの登録
// @param	対応するﾎﾞﾀﾝの値
//------------------------------------------------------
void Controller::SetPadInput(int up, int down, int left, int right, 
								int a, int b, int c, int d)
{
	// 対応するﾎﾞﾀﾝを割り振り
	padInput[PAD_UP] = up;
	padInput[PAD_DOWN] = down;
	padInput[PAD_LEFT] = left;
	padInput[PAD_RIGHT] = right;
	padInput[PAD_1] = a;
	padInput[PAD_2] = b;
	padInput[PAD_3] = c;
	padInput[PAD_4] = d;
}

//------------------------------------------------------
// @brief	上ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushUP(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_UP])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_UP])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_UP])
	{
		return true;
	}
	
	return false;
}

//------------------------------------------------------
// @brief	下ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushDOWN(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_DOWN])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_DOWN])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_DOWN])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	左ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushLEFT(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_LEFT])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_LEFT])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_LEFT])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	右ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushRIGHT(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_RIGHT])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_RIGHT])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_RIGHT])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	1ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushA(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_1])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_1])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_1])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	2ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushB(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_2])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_2])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_2])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	3ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushC(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_3])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_3])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_3])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	4ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushD(const INPUT_STATE inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_HOLD && input & padInput[PAD_4])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_4])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_4])
	{
		return true;
	}

	return false;
}