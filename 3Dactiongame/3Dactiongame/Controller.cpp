//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
// 2020 5/16 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

#include "_Debug.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
Controller::Controller()
{
	// ﾊﾟｯﾄﾞ対応ﾎﾞﾀﾝの初期化
	SetPadInput(PAD_INPUT_UP, PAD_INPUT_DOWN, PAD_INPUT_LEFT, PAD_INPUT_RIGHT,
		PAD_INPUT_B, PAD_INPUT_A, PAD_INPUT_C, PAD_INPUT_X, defDeadZone);

	// 変数初期化
	input = 0;
	inputOld = 0;
	leftLever = {};
	rightLever = {};
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
	inputOld = input;								// 前回入力
	input = GetJoypadInputState(DX_INPUT_PAD1);		// 今回の入力
	GetJoypadAnalogInput(&leftLever.x, &leftLever.y, DX_INPUT_PAD1);	// 今回の左ﾚﾊﾞｰ入力
	GetJoypadAnalogInputRight(&rightLever.x, &rightLever.y, DX_INPUT_PAD1);	// 今回右ﾚﾊﾞｰ入力

	// ｷｰﾎﾞｰﾄﾞの割り当て(ﾁｪｯｸ用)
	char keyInput[keyBuffer];
	GetHitKeyStateAll(keyInput);
	if (keyInput[KEY_INPUT_UP]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_UP)];
	if (keyInput[KEY_INPUT_DOWN]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)];
	if (keyInput[KEY_INPUT_LEFT]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)];
	if (keyInput[KEY_INPUT_RIGHT]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)];
	if (keyInput[KEY_INPUT_Z]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_1)];
	if (keyInput[KEY_INPUT_X]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_2)];
	if (keyInput[KEY_INPUT_C]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_3)];
	if (keyInput[KEY_INPUT_V]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_4)];

	if (keyInput[KEY_INPUT_W]) rightLever.y = -1000;
	if (keyInput[KEY_INPUT_A]) rightLever.x = -1000;
	if (keyInput[KEY_INPUT_S]) rightLever.y = 1000;
	if (keyInput[KEY_INPUT_D]) rightLever.x = 1000;
}

//------------------------------------------------------
// @brief	描画:ﾁｪｯｸ用
//------------------------------------------------------
void Controller::Render()
{
	DebugDrawStart;
	// どれを押しているか
	for (auto i = begin(PAD_BUTTON()); i < end(PAD_BUTTON()); ++i)
	{
		if (input & padInput[ConvertNum(i)])
		{
			DFS(0, 16 + 16 * ConvertNum(i), 0xffffff, "%d:ﾎｰﾙﾄﾞです", ConvertNum(i));
		}
	}
	// 左右ﾚﾊﾞｰ
	DFS(0, 144, 0xffffff, "%f", leftLever.x / tiltMax);
	DFS(0, 160, 0xffffff, "%f", leftLever.y / tiltMax);
	DFS(0, 176, 0xffffff, "%f", rightLever.x / tiltMax);
	DFS(0, 192, 0xffffff, "%f", rightLever.y / tiltMax);
	DebugDrawEnd;
}

//------------------------------------------------------
// @brief	ﾊﾟｯﾄﾞ対応ﾎﾞﾀﾝの登録
// @param	対応するﾎﾞﾀﾝの値
//------------------------------------------------------
void Controller::SetPadInput(int up, int down, int left, int right, 
								int a, int b, int c, int d, double deadZone)
{
	// 対応するﾎﾞﾀﾝを割り振り
	padInput[ConvertNum(PAD_BUTTON::PAD_UP)] = up;
	padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)] = down;
	padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)] = left;
	padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)] = right;
	padInput[ConvertNum(PAD_BUTTON::PAD_1)] = a;
	padInput[ConvertNum(PAD_BUTTON::PAD_2)] = b;
	padInput[ConvertNum(PAD_BUTTON::PAD_3)] = c;
	padInput[ConvertNum(PAD_BUTTON::PAD_4)] = d;
	deadZone;
	// ﾃﾞｯﾄﾞｿﾞｰﾝ
	SetJoypadDeadZone(DX_INPUT_PAD1, deadZone);
}

//------------------------------------------------------
// @brief	上ﾎﾞﾀﾝの状態を返す
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushUP(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD 
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_UP)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG 
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_UP)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP 
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_UP)])
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
const bool &Controller::IsPushDOWN(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)])
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
const bool &Controller::IsPushLEFT(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)])
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
const bool &Controller::IsPushRIGHT(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	1ﾎﾞﾀﾝの状態を返す(xbox:B)
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushA(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_1)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_1)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_1)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	2ﾎﾞﾀﾝの状態を返す(xbox:A)
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushB(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_2)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_2)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_2)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	3ﾎﾞﾀﾝの状態を返す(xbox:X)
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushC(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_3)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_3)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_3)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	4ﾎﾞﾀﾝの状態を返す(xbox:Y)
// @param	inputState	現在の入力
// @return	押されていればtrue
//------------------------------------------------------
const bool &Controller::IsPushD(const INPUT_STATE& inputState) const
{
	// ﾎｰﾙﾄﾞ、ﾄﾘｶﾞｰ、ｱｯﾌﾟの状態を返す
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_4)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_4)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_4)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	ﾚﾊﾞｰの横方向の傾き(xbox:左ﾚﾊﾞｰ)
// @param	t(Tilt)	現在の傾きを入れるための入れ物
// @return	押されていればtrue
//------------------------------------------------------
const bool& Controller::IsLeftTiltX(float& t) const
{
	// 入力があればtに値を入れてtrueを返す
	if (leftLever.x != 0)
	{
		t = (float)leftLever.x / tiltMax;
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	ﾚﾊﾞｰの縦方向の傾き(xbox:左ﾚﾊﾞｰ)
// @param	t(Tilt)	現在の傾きを入れるための入れ物
// @return	押されていればtrue
//------------------------------------------------------
const bool& Controller::IsLeftTiltY(float& t) const
{
	// 入力があればtに値を入れてtrueを返す
	if (leftLever.y != 0)
	{
		t = (float)leftLever.y / tiltMax;
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	ﾚﾊﾞｰの横方向の傾き(xbox:右ﾚﾊﾞｰ)
// @param	t(Tilt)	現在の傾きを入れるための入れ物
// @return	押されていればtrue
//------------------------------------------------------
const bool& Controller::IsRightTiltX(float& t) const
{
	// 入力があればtに値を入れてtrueを返す
	if (rightLever.x != 0)
	{
		t = (float)rightLever.x / tiltMax;
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	ﾚﾊﾞｰの縦方向の傾き(xbox:右ﾚﾊﾞｰ)
// @param	t(Tilt)	現在の傾きを入れるための入れ物
// @return	押されていればtrue
//------------------------------------------------------
const bool& Controller::IsRightTiltY(float& t) const
{
	// 入力があればtに値を入れてtrueを返す
	if (rightLever.y != 0)
	{
		t = (float)rightLever.y / tiltMax;
		return true;
	}

	return false;
}