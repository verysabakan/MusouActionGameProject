//------------------------------------------------------
// @brief	�ڰ�ڰĂ̊Ǘ�
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "FrameRate.h"

#include "_Debug.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
FrameRate::FrameRate()
{
	// ������
	QueryPerformanceCounter(&qpcEnd);	// ���݂̎���
	QueryPerformanceFrequency(&qpf);	// ���g��
	QueryPerformanceCounter(&qpcStart);	// �v���J�n���Ԃ̏�����

	fps = 0;
	frameTime = FRAME_TIME;
	stepNum = 1;
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
FrameRate::~FrameRate()
{
	// �����Ȃ�

}

//------------------------------------------------------
// @brief	�X�V:�I����
//------------------------------------------------------
void FrameRate::Update()
{
	QueryPerformanceCounter(&qpcEnd);	// ���݂̎���
	
	// (���݂̎��� - �O�ڰт̎���) / ���g�� = �o�ߎ���(�b�P��)
	frameTime = static_cast<double>(qpcEnd.QuadPart - qpcStart.QuadPart) / static_cast<double>(qpf.QuadPart);
	stepNum = frameTime / FRAME_TIME;

	// ��Ԑ��ڏ������s���񐔂��O��̏ꍇ�͂P��ɂ���
	if (stepNum == 0)
	{
		stepNum = 1;
	}
	else
	{
		// �O��ł͂Ȃ��ꍇ�͏�Ԑ��ڂŐi�߂鎞�Ԃ���Ԑ��ڂ��s���񐔂Ŋ���
		frameTime /= stepNum;

		// ������Ԑ��ڂ��s���񐔂��ő�l�𒴂��Ă�����ő�l�ɗ}����
		if (stepNum > FRAME_NUM)
		{
			stepNum = FRAME_NUM;
		}
	}

	if (static_cast<double>(qpcEnd.QuadPart - qpcEnd.QuadPart) / static_cast<double>(qpf.QuadPart) > 1.0f)
	{
		fps = (double)1 / frameTime;		// �ڰ�ڰ�
	}

	QueryPerformanceFrequency(&qpf);	// ���g��
	QueryPerformanceCounter(&qpcStart);	// �v���J�n���Ԃ̏�����
}

//------------------------------------------------------
// @brief	�`��
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
// @brief	1�ڰтɂ����������Ԃ��擾
//------------------------------------------------------
float FrameRate::GetStepTime()
{
	return (float)frameTime;
}

//------------------------------------------------------
// @brief	��Ԑ��ڏ������s���񐔂��Z�o
//------------------------------------------------------
int FrameRate::GetStepNum()
{
	return stepNum;
}