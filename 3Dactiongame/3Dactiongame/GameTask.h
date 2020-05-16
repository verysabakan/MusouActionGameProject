//------------------------------------------------------
// @brief	�ްю��̂̏������A�۰�A�I��
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Controller.h"

//#include <mutex>

// �������ߐ錾
class SceneManager;
class Controller;

class GameTask
{
public:
	GameTask();
	~GameTask();
	
	int Initialize(void);	// ������
	void Finalize(void);	// �I������
	void Update(void);		// �X�V
	void Draw(void);		// �X�V

private:
	std::unique_ptr<SceneManager> sceneManager;
	std::unique_ptr<Controller> controll;
};

