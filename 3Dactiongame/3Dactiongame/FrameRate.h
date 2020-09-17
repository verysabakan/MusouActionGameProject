//------------------------------------------------------
// @brief	�ڰ�ڰĂ̊Ǘ�
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <Windows.h>
#include "Singleton.h"

// ��`
#define lpFrameRate FrameRate::Instance()

class FrameRate
	:public Singleton<FrameRate>
{
private:
	double fps;			// �b�Ԃ��ڰэX�V��
	double frameTime;	// �o�ߎ���

	int stepNum;

	LARGE_INTEGER qpf;
	LARGE_INTEGER qpcStart;
	LARGE_INTEGER qpcEnd;

	//LONGLONG oldUpdateTime;	// �O��̍X�V����

	// 60FPS�ɌŒ肷��ꍇ��1�ڰтɂ������鎞��
	const double FRAME_TIME = 1.0 / 60.0;	// 1�ڰт̍ő厞��
	const int FRAME_NUM = 8;				// ��x�ɏ�������ő��ڰѐ�

public:
	void Update();	// �X�V
	void Render();	// �`��

	float GetStepTime();	// 1�ڰтɂ����������Ԃ��擾
	int GetStepNum();		// ��Ԑ��ڏ������s���񐔂��Z�o

private:
	FrameRate();	// �ݽ�׸�
	friend Singleton<FrameRate>;	// ����޸׽
	~FrameRate();	// �޽�׸�

};

