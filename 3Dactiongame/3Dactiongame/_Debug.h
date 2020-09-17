//------------------------------------------------------
// @brief	���ޯ�ނ̎��������s����
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �t���ذ������\�������
// #ifndef _DEBUG
// #endif// _DEBUG

#ifdef _DEBUG
#include <DxLib.h>
#include <memory>
#include "Singleton.h"

// ���ޯ��p��`
// �ذ��̎��͕\�����Ȃ��̂�#else��#endif�̊Ԃɂ���������
#define TRASE(fmt, ...) printf(fmt, __VA_ARGS__)	// �����������̎��ɂ��Ή�((...)�ψ����������1�Ɍ��肳��Ȃ�)
#define DS(x, y, string, color) DrawString(x, y, string, color)
#define DFS(x, y, color, tchar, ...) DrawFormatString(x, y, color, tchar, __VA_ARGS__);

// ���ޯ�ގ��̕`��Ɏg��
// (�őO�ʂɏo������2D�̂��̂ɂ͂Ƃ�܎g���Ƃ��΂���)
#define DebugDrawStart (SetUseZBufferFlag(TRUE),SetWriteZBufferFlag(TRUE),SetUseLighting(FALSE))
#define DebugDrawEnd (SetUseZBufferFlag(FALSE),SetWriteZBufferFlag(FALSE),SetUseLighting(TRUE))

class _Debug
	:public Singleton<_Debug>
{
private:
	_Debug();					// �ݽ�׸�
	friend Singleton<_Debug>;	// ����޸׽
	~_Debug();					// �޽�׸�

	FILE* _debugFp = nullptr;
};


#else
// �ذ��̎��͕\�����Ȃ�
#define TRASE(fmt, ...)
#define DS(x, y, string, color)
#define DFS(x, y, color, tchar, ...)

#define DebugDrawStart
#define DebugDrawEnd
#endif	// _DEBUG

// DebugMng�͏�ɏo�Ă�����۸��яI�����ɏ�����
// �ݿ�ٳ���޳�ɕ\������������۸��т��ʂ�����ɂȂ�
// �o�H�����◚���̊m�F�p