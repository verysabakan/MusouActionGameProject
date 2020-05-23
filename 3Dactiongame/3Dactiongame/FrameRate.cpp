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
	// ���݂̎���
	QueryPerformanceCounter(&qpcEnd);

	// (���݂̎��� - �O�ڰт̎���) / ���g�� = �o�ߎ���(�b�P��)
	frameTime = static_cast<double>(qpcEnd.QuadPart - qpcStart.QuadPart)
					/ static_cast<double>(qpf.QuadPart);

	// �ڰ�ڰ�
	fps = (double)1 / frameTime;

	// ���g��
	QueryPerformanceFrequency(&qpf);

	// �v���J�n���Ԃ̏�����
	QueryPerformanceCounter(&qpcStart);
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void FrameRate::Render()
{
	DrawFormatString(200, 0, 0xffffff, "%.2ffps", fps);
}
