//------------------------------------------------------
// @brief	�ްщ��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "BaseScene.h"

// �������ߐ錾
class Camera;

class GameScene
	: public BaseScene
{
public:
	GameScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~GameScene();							// �޽�׸�

	// ���ްײ��
	//virtual void Initialize() override;	// ������
	//virtual void Finalize() override;	// �I������
	virtual void Update(const Controller& controll) override;		// �X�V
	virtual void Render() override;		// �`��

private:
	std::unique_ptr<Camera> camera;
};

