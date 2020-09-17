//------------------------------------------------------
// @brief	ﾃﾞﾊﾞｯｸﾞの時だけ実行する
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 逆にﾘﾘｰｽだけ表示される
// #ifndef _DEBUG
// #endif// _DEBUG

#ifdef _DEBUG
#include <DxLib.h>
#include <memory>
#include "Singleton.h"

// ﾃﾞﾊﾞｯｸ用定義
// ﾘﾘｰｽの時は表示しないので#elseと#endifの間にも書くこと
#define TRASE(fmt, ...) printf(fmt, __VA_ARGS__)	// 引数が複数の時にも対応((...)可変引数､引数が1個に限定されない)
#define DS(x, y, string, color) DrawString(x, y, string, color)
#define DFS(x, y, color, tchar, ...) DrawFormatString(x, y, color, tchar, __VA_ARGS__);

// ﾃﾞﾊﾞｯｸﾞ時の描画に使う
// (最前面に出したい2Dのものにはとりま使っとけばおけ)
#define DebugDrawStart (SetUseZBufferFlag(TRUE),SetWriteZBufferFlag(TRUE),SetUseLighting(FALSE))
#define DebugDrawEnd (SetUseZBufferFlag(FALSE),SetWriteZBufferFlag(FALSE),SetUseLighting(TRUE))

class _Debug
	:public Singleton<_Debug>
{
private:
	_Debug();					// ｺﾝｽﾄﾗｸﾀ
	friend Singleton<_Debug>;	// ﾌﾚﾝﾄﾞｸﾗｽ
	~_Debug();					// ﾃﾞｽﾄﾗｸﾀ

	FILE* _debugFp = nullptr;
};


#else
// ﾘﾘｰｽの時は表示しない
#define TRASE(fmt, ...)
#define DS(x, y, string, color)
#define DFS(x, y, color, tchar, ...)

#define DebugDrawStart
#define DebugDrawEnd
#endif	// _DEBUG

// DebugMngは常に出ており､ﾌﾟﾛｸﾞﾗﾑ終了時に消える
// ｺﾝｿｰﾙｳｨﾝﾄﾞｳに表示される情報はﾌﾟﾛｸﾞﾗﾑが通った後になる
// 経路ﾁｪｯｸや履歴の確認用