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
	TitleScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~TitleScene();							// �޽�׸�

	// ���ްײ��
	//virtual void Initialize(void) override;	//������
	//virtual void Finalize(void) override;	//�I������
	virtual void Update(void) override;		//�X�V
	virtual void Draw(void) override;		//�`��
};

