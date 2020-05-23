//------------------------------------------------------
// @brief	�ڰ�ڰĂ̊Ǘ�
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <Windows.h>

class FrameRate
{
public:
	FrameRate();	// �ݽ�׸�
	~FrameRate();	// �޽�׸�

	void Update();	// �X�V
	void Render();	// �`��

private:
	double fps;	// �b�Ԃ��ڰэX�V��
	double frameTime;	// �o�ߎ���

	LARGE_INTEGER qpf;
	LARGE_INTEGER qpcStart;
	LARGE_INTEGER qpcEnd;

	//60FPS�ɌŒ肷��ꍇ��1�t���[���ɂ������鎞��
	const double FRAME_TIME = 1.0 / 60.0;
};

