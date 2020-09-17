//------------------------------------------------------
// @brief	ﾃﾞﾊﾞｯｸﾞの時だけ実行する
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#ifdef _DEBUG
#include <Windows.h>
#include "_Debug.h"

_Debug::_Debug()
{
	// ｺﾝｿｰﾙｳｨﾝﾄﾞｳを開く
	AllocConsole();

	// 文字列の出力と入力
	freopen_s(&_debugFp, "CONOUT$", "w", stdout);
	freopen_s(&_debugFp, "CONIN$", "r", stdin);
	TRASE("ﾃﾞﾊﾞｯｸﾞ開始\n");
}

_Debug::~_Debug()
{
	// AllocしたからFree
	FreeConsole();
}

#endif	// _DEBUG