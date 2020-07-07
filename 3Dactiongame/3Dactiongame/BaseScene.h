//------------------------------------------------------
// @brief	��݂̊��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "SceneProcess.h"
#include "ISceneSwitcher.h"
#include "SceneDateManager.h"

class BaseScene
	: public SceneProcess
{
public:
	BaseScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	virtual ~BaseScene();					// �޽�׸�

	// -----���ްײ��----- //
	virtual void Initialize() override {}		// ������
	virtual void Finalize() override {}			// �I������
	virtual void Update() override {}			// �X�V
	virtual void Render() override {}				// �`��

protected:
	ISceneSwitcher* sceneSwitcher;			// ��݂̐؂�ւ���`����
	SceneDateManager* sceneDateManager;		// ��݊Ԃ��ް��̎󂯓n��

};

