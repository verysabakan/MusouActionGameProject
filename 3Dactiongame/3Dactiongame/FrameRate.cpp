//------------------------------------------------------
// @brief	ﾌﾚｰﾑﾚｰﾄの管理
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "FrameRate.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
FrameRate::FrameRate()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
FrameRate::~FrameRate()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	更新:終了時
//------------------------------------------------------
void FrameRate::Update()
{
	// 現在の時間
	QueryPerformanceCounter(&qpcEnd);

	// (現在の時間 - 前ﾌﾚｰﾑの時間) / 周波数 = 経過時間(秒単位)
	frameTime = static_cast<double>(qpcEnd.QuadPart - qpcStart.QuadPart)
					/ static_cast<double>(qpf.QuadPart);

	// ﾌﾚｰﾑﾚｰﾄ
	fps = (double)1 / frameTime;

	// 周波数
	QueryPerformanceFrequency(&qpf);

	// 計測開始時間の初期化
	QueryPerformanceCounter(&qpcStart);
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void FrameRate::Render()
{
	DrawFormatString(200, 0, 0xffffff, "%.2ffps", fps);
}
