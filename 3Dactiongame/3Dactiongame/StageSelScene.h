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
	StageSelScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~StageSelScene();							// �޽�׸�

	// ���ްײ��
	//virtual void Initialize(void) override;	//������
	//virtual void Finalize(void) override;	//�I������
	virtual void Update(void) override;		//�X�V
	virtual void Draw(void) override;		//�`��
};

