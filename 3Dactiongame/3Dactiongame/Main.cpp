//------------------------------------------------------
// @brief	Ҳݏ���
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "GameTask.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �ްѸ׽�̐���
	GameTask* gameTask = new GameTask();

	// �����������s���Ă���ΏI��
	if (gameTask->Initialize() == -1) 
	{
		delete(gameTask);	// ��؊J��
		return -1;			// �װ�I��
	}

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		gameTask->Update();
		gameTask->Draw();
	}

	gameTask->Finalize();
	delete(gameTask);

	return 0;	// ����I��
}