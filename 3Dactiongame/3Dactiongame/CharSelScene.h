//------------------------------------------------------
// @brief	��׸���I�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class CharSelScene
	: public BaseScene
{
public:
	CharSelScene(ISceneSwitcher* switcher);
	~CharSelScene();

	// ���ްײ��
	//virtual void Initialize() override;	//������
	//virtual void Finalize() override;	//�I������
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��
};

