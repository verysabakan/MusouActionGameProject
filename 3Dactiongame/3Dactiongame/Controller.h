//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
//				ｷｰﾎﾞｰﾄﾞは一人用、ｺﾝﾄﾛｰﾗｰで複数人
// 2020 5/16 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "Singleton.h"
#include "InputStateConstant.h"
#include "PadButtonConstant.h"

// 定義
#define lpController Controller::Instance()

// ｼﾝｸﾞﾙﾄﾝ
/*Controller();	// ｺﾝｽﾄﾗｸﾀ
~Controller();	// ﾃﾞｽﾄﾗｸﾀ
#define lpController Controller::GetInstance()
static Controller &GetInstance(void)
{
	static Controller s_Instance;
	return (s_Instance);
}*/

class Controller
	:public Singleton<Controller>
{
private:
	static const int keyBuffer = 256;
	static constexpr  double defDeadZone = 0.35;
	static constexpr float tiltMax = 1000.0f;

	int padInput[static_cast<int>(PAD_BUTTON::PAD_BUTTON_NUM)];	// ﾊﾟｯﾄﾞ情報格納用
	int input;							// 入力情報
	int inputOld;						// 前回の入力情報

	// 左右ﾚﾊﾞｰ
	struct Pad
	{
		int x;
		int y;
	};
	Pad rightLever;
	Pad leftLever;

public:
	void Update();	// 更新
	void Render();	// 描画:ﾁｪｯｸ用

	void SetPadInput(int up, int down, int left, int right, int a, int b, int c, int d, double deadZone);	// ﾊﾟｯﾄﾞ対応ﾎﾞﾀﾝの登録

	// 入力状態の取得関数
	// ﾎﾞﾀﾝ
	const bool& IsPushUP(const INPUT_STATE& inputState) const;
	const bool& IsPushDOWN(const INPUT_STATE& inputState) const;
	const bool& IsPushLEFT(const INPUT_STATE& inputState) const;
	const bool& IsPushRIGHT(const INPUT_STATE& inputState) const;
	const bool& IsPushA(const INPUT_STATE& inputState) const;
	const bool& IsPushB(const INPUT_STATE& inputState) const;
	const bool& IsPushC(const INPUT_STATE& inputState) const;
	const bool& IsPushD(const INPUT_STATE& inputState) const;
	// ﾚﾊﾞｰ
	const bool& IsLeftTiltX(float& t) const;
	const bool& IsLeftTiltY(float& t) const;
	const bool& IsRightTiltX(float& t) const;
	const bool& IsRightTiltY(float& t) const;

private:
	Controller();	// ｺﾝｽﾄﾗｸﾀ
	friend Singleton<Controller>;	// ﾌﾚﾝﾄﾞｸﾗｽ
	~Controller();	// ﾃﾞｽﾄﾗｸﾀ
};
