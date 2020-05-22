//------------------------------------------------------
// @brief	Ҳݏ���
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "GameTask.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// �ް�����̐���
	std::unique_ptr<GameTask> gameTask;
	gameTask = std::make_unique<GameTask>();

	// �����������s���Ă���ΏI��
	if (gameTask->Initialize() == -1) 
	{
		gameTask.reset();	// ��؊J��
		return -1;			// �װ�I��
	}

	// �����߷���������邩����޳��������܂�ٰ��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		gameTask->Update();
		gameTask->Render();
	}

	gameTask->Finalize();
	gameTask.reset();

	return 0;	// ����I��
}