//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
//				ｷｰﾎﾞｰﾄﾞは一人用、ｺﾝﾄﾛｰﾗｰで複数人
// 2020 5/16 Ryosuke Iida
//------------------------------------------------------

#pragma once

//#include <array>

// 定義
#define lpController Controller::GetInstance()

// 入力状態
enum INPUT_STATE
{
	INPUT_HOLD,
	INPUT_TRG,
	INPUT_UP
};

class Controller
{
private:
	// ﾊﾟｯﾄﾞ対応ﾎﾞﾀﾝ
	enum
	{
		PAD_UP,
		PAD_DOWN,
		PAD_LEFT,
		PAD_RIGHT,
		PAD_1,
		PAD_2,
		PAD_3,
		PAD_4,
		PAD_BUTTON_NUM,
	};

	static const int keyBuffer = 256;
	static constexpr  double defDeadZone = 0.35;
	static constexpr float tiltMax = 1000.0f;

	int padInput[PAD_BUTTON_NUM];	// ﾊﾟｯﾄﾞ情報格納用
	int input;						// 入力情報
	int inputOld;					// 前回の入力情報

	// 左右ﾚﾊﾞｰ
	struct Pad
	{
		int x;
		int y;
	};
	Pad rightLever;
	Pad leftLever;

public:
	// ｼﾝｸﾞﾙﾄﾝ
	static Controller &GetInstance(void)
	{
		static Controller s_Instance;
		return (s_Instance);
	}

	void Update();	// 更新
	void Render();	// 描画:ﾁｪｯｸ用

	void SetPadInput(int up, int down, int left, int right, int a, int b, int c, int d, double deadZone);	// ﾊﾟｯﾄﾞ対応ﾎﾞﾀﾝの登録

	// 入力状態の取得関数
	// ﾎﾞﾀﾝ
	const bool& IsPushUP(const INPUT_STATE inputState) const;
	const bool& IsPushDOWN(const INPUT_STATE inputState) const;
	const bool& IsPushLEFT(const INPUT_STATE inputState) const;
	const bool& IsPushRIGHT(const INPUT_STATE inputState) const;
	const bool& IsPushA(const INPUT_STATE inputState) const;
	const bool& IsPushB(const INPUT_STATE inputState) const;
	const bool& IsPushC(const INPUT_STATE inputState) const;
	const bool& IsPushD(const INPUT_STATE inputState) const;
	// ﾚﾊﾞｰ
	const bool& IsLeftTiltX(float& t) const;
	const bool& IsLeftTiltY(float& t) const;
	const bool& IsRightTiltX(float& t) const;
	const bool& IsRightTiltY(float& t) const;

private:
	Controller();	// ｺﾝｽﾄﾗｸﾀ
	~Controller();	// ﾃﾞｽﾄﾗｸﾀ

};
