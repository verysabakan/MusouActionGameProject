//------------------------------------------------------
// @brief	���ޯ�ނ̎��������s����
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#ifdef _DEBUG
#include <Windows.h>
#include "_Debug.h"

_Debug::_Debug()
{
	// �ݿ�ٳ���޳���J��
	AllocConsole();

	// ������̏o�͂Ɠ���
	freopen_s(&_debugFp, "CONOUT$", "w", stdout);
	freopen_s(&_debugFp, "CONIN$", "r", stdin);
	TRASE("���ޯ�ފJ�n\n");
}

_Debug::~_Debug()
{
	// Alloc��������Free
	FreeConsole();
}

#endif	// _DEBUG