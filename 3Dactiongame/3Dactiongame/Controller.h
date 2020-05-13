//------------------------------------------------------
// @brief	ｷｰﾎﾞｰﾄﾞやｺﾝﾄﾛｰﾗｰからの操作、入力
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

// ｷｰの入力状態
enum KEY_SIGNAL
{
	KEY_SIGNAL_NOW,	// 現在
	KEY_SIGNAL_OLD,	// 前ﾌﾚｰﾑ
	KEY_SIGNAL_TRG,	// 押された瞬間
	KEY_SIGNAL_UP,	// 離された瞬間
	KEY_SIGNAL_MAX
};

using KEY_FLAG = std::array<char, 256>;
using PAD_FLAG = std::array<bool, 28>;

class Controller
{
public:
	Controller();	// ｺﾝｽﾄﾗｸﾀ
	~Controller();	// ﾃﾞｽﾄﾗｸﾀ

	// ｷｰの状態を取得する関数
	//const KEY_FLAG GetInputKey() const;
	// ﾊﾟｯﾄﾞの状態を取得する関数
	//const KEY_FLAG GetInputKey() const;

	void Update();	// 更新
	void Draw();	// 描画:ﾁｪｯｸ用

private:
	// ｷｰ情報保存用
	KEY_FLAG key[KEY_SIGNAL_MAX];

	// ﾊﾟｯﾄﾞ情報保存用
	PAD_FLAG pad[KEY_SIGNAL_MAX];
};
