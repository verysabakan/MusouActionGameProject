//------------------------------------------------------
// @brief	��݂̊��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "SceneProcess.h"
#include "ISceneSwitcher.h"

class BaseScene
	: public SceneProcess
{
public:
	BaseScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	virtual ~BaseScene();					// �޽�׸�

	// -----���ްײ��----- //
	virtual void Initialize(void) override {}		// ������
	virtual void Finalize(void) override {}			// �I������
	virtual void Update(const Controller& controll) override {}			// �X�V
	virtual void Draw(void) override {}				// �`��

protected:
	ISceneSwitcher* sceneSwitcher;	// ��݂̐؂�ւ���`����
};

