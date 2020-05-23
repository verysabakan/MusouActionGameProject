//------------------------------------------------------
// @brief	ﾌﾚｰﾑﾚｰﾄの管理
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <Windows.h>

class FrameRate
{
public:
	FrameRate();	// ｺﾝｽﾄﾗｸﾀ
	~FrameRate();	// ﾃﾞｽﾄﾗｸﾀ

	void Update();	// 更新
	void Render();	// 描画

private:
	double fps;	// 秒間のﾌﾚｰﾑ更新数
	double frameTime;	// 経過時間

	LARGE_INTEGER qpf;
	LARGE_INTEGER qpcStart;
	LARGE_INTEGER qpcEnd;

	//60FPSに固定する場合の1フレームにかけられる時間
	const double FRAME_TIME = 1.0 / 60.0;
};

