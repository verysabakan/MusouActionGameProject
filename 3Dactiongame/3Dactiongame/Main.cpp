//------------------------------------------------------
// @brief	Ҳݏ���
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "GameTask.h"
#include "FrameRate.h"

#include "_Debug.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ���ޯ�޳���޳�ݽ�ݽ
#ifdef _DEBUG
	_Debug::Instance();
#endif	// _DEBUG

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
		for (auto i = 0; i < lpFrameRate->GetStepNum(); i++)
		{
			gameTask->Update();
			gameTask->Render();
		}
	}

	gameTask->Finalize();	// �I������
	gameTask.reset();		// ؿ���̊J��

	return 0;	// ����I��
}