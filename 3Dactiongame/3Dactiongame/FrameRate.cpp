//------------------------------------------------------
// @brief	ﾌﾚｰﾑﾚｰﾄの管理
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "FrameRate.h"

#include "_Debug.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
FrameRate::FrameRate()
{
	// 初期化
	QueryPerformanceCounter(&qpcEnd);	// 現在の時間
	QueryPerformanceFrequency(&qpf);	// 周波数
	QueryPerformanceCounter(&qpcStart);	// 計測開始時間の初期化

	fps = 0;
	frameTime = FRAME_TIME;
	stepNum = 1;
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
	QueryPerformanceCounter(&qpcEnd);	// 現在の時間
	
	// (現在の時間 - 前ﾌﾚｰﾑの時間) / 周波数 = 経過時間(秒単位)
	frameTime = static_cast<double>(qpcEnd.QuadPart - qpcStart.QuadPart) / static_cast<double>(qpf.QuadPart);
	stepNum = frameTime / FRAME_TIME;

	// 状態推移処理を行う回数が０回の場合は１回にする
	if (stepNum == 0)
	{
		stepNum = 1;
	}
	else
	{
		// ０回ではない場合は状態推移で進める時間を状態推移を行う回数で割る
		frameTime /= stepNum;

		// もし状態推移を行う回数が最大値を超えていたら最大値に抑える
		if (stepNum > FRAME_NUM)
		{
			stepNum = FRAME_NUM;
		}
	}

	if (static_cast<double>(qpcEnd.QuadPart - qpcEnd.QuadPart) / static_cast<double>(qpf.QuadPart) > 1.0f)
	{
		fps = (double)1 / frameTime;		// ﾌﾚｰﾑﾚｰﾄ
	}

	QueryPerformanceFrequency(&qpf);	// 周波数
	QueryPerformanceCounter(&qpcStart);	// 計測開始時間の初期化
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void FrameRate::Render()
{
	DebugDrawStart;
	DFS(200, 0, 0xffffff, "FPS:%d", (int)fps);
	DFS(200, 16, 0xffffff, "StepNum:%f", frameTime);
	DFS(200, 32, 0xffffff, "StepNum:%d", stepNum);
	DebugDrawEnd;
}

//------------------------------------------------------
// @brief	1ﾌﾚｰﾑにかかった時間を取得
//------------------------------------------------------
float FrameRate::GetStepTime()
{
	return (float)frameTime;
}

//------------------------------------------------------
// @brief	状態推移処理を行う回数を算出
//------------------------------------------------------
int FrameRate::GetStepNum()
{
	return stepNum;
}