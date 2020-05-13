//------------------------------------------------------
// @brief	��݂̊��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseProcessing.h"
#include "ISceneSwitcher.h"

class BaseScene
	: public BaseProcessing
{
public:
	BaseScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	virtual ~BaseScene();					// �޽�׸�

	// ���ްײ��
	virtual void Initialize(void) override {}	//������
	virtual void Finalize(void) override {}		//�I������
	virtual void Update(void) override {}		//�X�V
	virtual void Draw(void) override {}			//�`��

protected:
	ISceneSwitcher* sceneSwitcher;	// ��݂̐؂�ւ���`����
};

