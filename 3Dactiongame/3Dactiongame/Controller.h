//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
//				ｷｰﾎﾞｰﾄﾞは一人用、ｺﾝﾄﾛｰﾗｰで複数人
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

#define KEY_STATE_BUFFER 256	// ｷｰの状態を保存する場所の最大格納数
#define PAD_STATE_BUFFER 28		// ﾊﾟｯﾄﾞの状態を保存する場所の最大格納数

// ｷｰの入力状態
enum KEY_SIGNAL
{
	KEY_SIGNAL_NOW,	// 現在
	KEY_SIGNAL_OLD,	// 前ﾌﾚｰﾑ
	KEY_SIGNAL_UP,	// 離した瞬間
	KEY_SIGNAL_TRG,	// 押した瞬間
	KEY_SIGNAL_MAX
};

using KEY_FLAG = std::array<char, KEY_STATE_BUFFER>;
using PAD_FLAG = std::array<int, PAD_STATE_BUFFER>;

class Controller
{
public:
	Controller();	// ｺﾝｽﾄﾗｸﾀ
	~Controller();	// ﾃﾞｽﾄﾗｸﾀ

	void Update(void);	// 更新
	void Draw(void);	// 描画:ﾁｪｯｸ用

	// 入力状態を返す関数
	const bool SignalNow() const;
	const bool SignalUp() const;
	const bool SignalTrg() const;

	// ｷｰの状態を取得する関数
	//const KEY_FLAG GetInputKey() const;
	// ﾊﾟｯﾄﾞの状態を取得する関数
	//const KEY_FLAG GetInputKey() const;

private:
	// ｷｰ情報保存用
	KEY_FLAG key[KEY_SIGNAL_MAX];
	
	// ﾊﾟｯﾄﾞ情報保存用
	KEY_FLAG pad[KEY_SIGNAL_MAX];
};
