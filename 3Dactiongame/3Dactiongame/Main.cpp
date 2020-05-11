//------------------------------------------------------
// @brief	Ҳݏ���
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	SceneManager SceneManager;
	SceneManager.Initialize();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

		SceneManager.Update();  //�X�V
		SceneManager.Draw();    //�`��

	}

	SceneManager.Finalize();

	DxLib_End(); // DX���C�u�����I������
	return 0;
}