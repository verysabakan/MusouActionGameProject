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
	ModeSelScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~ModeSelScene();						// �޽�׸�

	// ���ްײ��
	//virtual void Initialize(void) override;	// ������
	//virtual void Finalize(void) override;	// �I������
	virtual void Update(const Controller& controll) override;		// �X�V
	virtual void Draw(void) override;		// �`��
};

