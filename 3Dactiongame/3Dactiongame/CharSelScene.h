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
	CharSelScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~CharSelScene();						// �޽�׸�

	// ���ްײ��
	//virtual void Initialize(void) override;	//������
	//virtual void Finalize(void) override;	//�I������
	virtual void Update(void) override;		//�X�V
	virtual void Draw(void) override;		//�`��
};

