//------------------------------------------------------
// @brief	���ى��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class TitleScene
	: public BaseScene
{
public:
	TitleScene(ISceneSwitcher* switcher);
	~TitleScene();

	// ���ްײ��
	//virtual void Initialize() override;	//������
	//virtual void Finalize() override;	//�I������
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��
};

