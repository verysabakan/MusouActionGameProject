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
	//virtual void Initialize(void) override;	//������
	//virtual void Finalize(void) override;	//�I������
	virtual void Update(void) override;		//�X�V
	virtual void Draw(void) override;		//�`��
};

