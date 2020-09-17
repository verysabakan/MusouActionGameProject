//------------------------------------------------------
// @brief	�ްю��̂̏������A�۰�A�I��
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>

// �������ߐ錾
class SceneManager;

class GameTask
{
private:
	std::unique_ptr<SceneManager> sceneManager;

public:
	GameTask();			// �ݽ�׸�
	~GameTask();		// �޽�׸�
	
	int Initialize();	// ������
	void Finalize();	// �I������
	void Update();		// �X�V
	void Render();		// �X�V

};

