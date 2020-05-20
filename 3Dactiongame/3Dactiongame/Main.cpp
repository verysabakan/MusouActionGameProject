//------------------------------------------------------
// @brief	Ҳݏ���
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "GameTask.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �ްѸ׽�̐�
	std::unique_ptr<GameTask> gameTask;
	gameTask = std::make_unique<GameTask>();

	// �����������s���Ă���ΏI��
	if (gameTask->Initialize() == -1) 
	{
		gameTask.release();	// ��؊J��
		return -1;			// �װ�I��
	}

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		gameTask->Update();
		gameTask->Render();
	}

	gameTask->Finalize();
	gameTask.release();

	return 0;	// ����I��
}