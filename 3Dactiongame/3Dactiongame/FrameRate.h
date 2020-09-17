//------------------------------------------------------
// @brief	ﾌﾚｰﾑﾚｰﾄの管理
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <Windows.h>
#include "Singleton.h"

// 定義
#define lpFrameRate FrameRate::Instance()

class FrameRate
	:public Singleton<FrameRate>
{
private:
	double fps;			// 秒間のﾌﾚｰﾑ更新数
	double frameTime;	// 経過時間

	int stepNum;

	LARGE_INTEGER qpf;
	LARGE_INTEGER qpcStart;
	LARGE_INTEGER qpcEnd;

	//LONGLONG oldUpdateTime;	// 前回の更新時間

	// 60FPSに固定する場合の1ﾌﾚｰﾑにかけられる時間
	const double FRAME_TIME = 1.0 / 60.0;	// 1ﾌﾚｰﾑの最大時間
	const int FRAME_NUM = 8;				// 一度に処理する最大ﾌﾚｰﾑ数

public:
	void Update();	// 更新
	void Render();	// 描画

	float GetStepTime();	// 1ﾌﾚｰﾑにかかった時間を取得
	int GetStepNum();		// 状態推移処理を行う回数を算出

private:
	FrameRate();	// ｺﾝｽﾄﾗｸﾀ
	friend Singleton<FrameRate>;	// ﾌﾚﾝﾄﾞｸﾗｽ
	~FrameRate();	// ﾃﾞｽﾄﾗｸﾀ

};

