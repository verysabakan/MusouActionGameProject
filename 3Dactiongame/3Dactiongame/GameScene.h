//------------------------------------------------------
// @brief	�ްщ��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class GameScene
	: public BaseScene
{
public:
	GameScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~GameScene();							// �޽�׸�

	// ���ްײ��
	//virtual void Initialize() override;	//������
	//virtual void Finalize() override;	//�I������
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��
};

