//------------------------------------------------------
// @brief	Ӱ�ޑI�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class ModeSelScene
	: public BaseScene
{
public:
	ModeSelScene(ISceneSwitcher* switcher);
	~ModeSelScene();

	// ���ްײ��
	//virtual void Initialize() override;	//������
	//virtual void Finalize() override;	//�I������
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��
};

