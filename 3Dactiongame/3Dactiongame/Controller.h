//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
//				ｷｰﾎﾞｰﾄﾞは一人用、ｺﾝﾄﾛｰﾗｰで複数人
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

#define KEY_STATE_BUFFER 256	// ｷｰの状態を保存する場所の最大格納数
#define PAD_STATE_BUFFER 28		// ﾊﾟｯﾄﾞの状態を保存する場所の最大格納数

// 入力信号
enum INPUT_STATE
{
	INPUT_STATE_NOW,	// 現在
	INPUT_STATE_OLD,	// 前ﾌﾚｰﾑ
	INPUT_STATE_TRG,	// 押した瞬間
	INPUT_STATE_UP,		// 離した瞬間
	INPUT_STATE_MAX
};

class Controller
{
public:
	Controller();	// ｺﾝｽﾄﾗｸﾀ
	~Controller();	// ﾃﾞｽﾄﾗｸﾀ

	void Update(void);	// 更新
	void Draw(void);	// 描画:ﾁｪｯｸ用

	const bool& GetInputState(int const input,INPUT_STATE const inputState) const;	// 入力が受け取った状態にあるかを判断し返す

private:
	// ｷｰ、ﾊﾟｯﾄﾞ情報格納用
	bool key[INPUT_STATE_MAX][KEY_STATE_BUFFER];
	bool pad[INPUT_STATE_MAX][KEY_STATE_BUFFER];
};
