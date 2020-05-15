//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
//				ｷｰﾎﾞｰﾄﾞは一人用、ｺﾝﾄﾛｰﾗｰで複数人
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

#define KEY_STATE_BUFFER 256	// ｷｰの状態を保存する場所の最大格納数
#define PAD_STATE_BUFFER 28		// ﾊﾟｯﾄﾞの状態を保存する場所の最大格納数

// 入力状態
enum INPUT_SIGNAL
{
	INPUT_SIGNAL_NOW,	// 現在
	INPUT_SIGNAL_OLD,	// 前ﾌﾚｰﾑ
	INPUT_SIGNAL_TRG,	// 押した瞬間
	INPUT_SIGNAL_UP,	// 離した瞬間
	INPUT_SIGNAL_MAX
};

//using KEY_FLAG = std::array<char, KEY_STATE_BUFFER>;
//using PAD_FLAG = std::array<bool, PAD_STATE_BUFFER>;

class Controller
{
public:
	Controller();	// ｺﾝｽﾄﾗｸﾀ
	~Controller();	// ﾃﾞｽﾄﾗｸﾀ

	void Update(void);	// 更新
	void Draw(void);	// 描画:ﾁｪｯｸ用

	// ｷｰ、ﾊﾟｯﾄﾞが受け取った状態であるか確認する
	//const KEY_FLAG& GetInputKey(INPUT_SIGNAL requiredSignal) const;
	//const PAD_FLAG& GetInputButton(INPUT_SIGNAL requiredSignal) const;

private:
	// ｷｰ、ﾊﾟｯﾄﾞ情報保存用
	bool key[INPUT_SIGNAL_MAX][KEY_STATE_BUFFER];
	bool pad[INPUT_SIGNAL_MAX][KEY_STATE_BUFFER];
};
