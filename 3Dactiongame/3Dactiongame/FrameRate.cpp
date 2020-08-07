//------------------------------------------------------
// @brief	�ڰ�ڰĂ̊Ǘ�
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "FrameRate.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
FrameRate::FrameRate()
{
	// �����Ȃ�
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
	frameTime = static_cast<double>(qpcEnd.QuadPart - qpcStart.QuadPart)
					/ static_cast<double>(qpf.QuadPart);
	double i = static_cast<double>(qpcEnd.QuadPart - oldUpdateTime) / static_cast<double>(qpf.QuadPart);
	if (static_cast<double>(qpcEnd.QuadPart - oldUpdateTime) / static_cast<double>(qpf.QuadPart) > 1.0f)
	{
		fps = (double)1 / frameTime;				// �ڰ�ڰ�
		oldUpdateTime = qpcEnd.QuadPart;	// �X�V���Ԃ��X�V
	}

	QueryPerformanceFrequency(&qpf);	// ���g��
	QueryPerformanceCounter(&qpcStart);	// �v���J�n���Ԃ̏�����
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void FrameRate::Render()
{
	DrawFormatString(200, 0, 0xffffff, "FPS:%d", (int)fps);
}
