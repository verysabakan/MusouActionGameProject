//------------------------------------------------------
// @brief	�ްю��̂̏������A�۰�A�I��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �������ߐ錾
class SceneManager;

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
	SceneManager* sceneManager;
};

