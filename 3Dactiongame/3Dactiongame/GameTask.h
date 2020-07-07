//------------------------------------------------------
// @brief	�ްю��̂̏������A�۰�A�I��
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
//#include <mutex>

// �������ߐ錾
class SceneManager;
class FrameRate;

class GameTask
{
public:
	GameTask();			// �ݽ�׸�
	~GameTask();		// �޽�׸�
	
	int Initialize();	// ������
	void Finalize();	// �I������
	void Update();		// �X�V
	void Render();		// �X�V

private:
	std::unique_ptr<SceneManager> sceneManager;
	std::unique_ptr<FrameRate> frameRate;
};

