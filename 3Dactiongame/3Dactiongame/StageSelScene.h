//------------------------------------------------------
// @brief	�ð�ޑI�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class StageSelScene
	: public BaseScene
{
public:
	StageSelScene(ISceneSwitcher* switcher);
	~StageSelScene();

	// ���ްײ��
	//virtual void Initialize() override;	//������
	//virtual void Finalize() override;	//�I������
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��
};

