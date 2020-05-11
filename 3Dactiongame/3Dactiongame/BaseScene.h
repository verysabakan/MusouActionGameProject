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
	virtual void Initialize() override {}	//������
	virtual void Finalize() override {}		//�I������
	virtual void Update() override {}		//�X�V
	virtual void Draw() override {}			//�`��

protected:
	ISceneSwitcher* sceneSwitcher;	// ��݂̐؂�ւ���`����
};

