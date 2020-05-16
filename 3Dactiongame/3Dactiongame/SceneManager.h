//------------------------------------------------------
// @brief	��݂̊Ǘ�
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class SceneManager 
	: public ISceneSwitcher, SceneProcess
{
public:
	SceneManager();		// �ݽ�׸�
	~SceneManager();	// �޽�׸�

	// ���ްײ��
	virtual void Initialize(void) override;	// ������
	virtual void Finalize(void) override;	// �I������
	virtual void Update(const Controller& controll) override;		// �X�V
	virtual void Draw(void) override;		// �`��

	void SwitchScene(eScene nextScene) override;	// �w�肵����݂ɕύX
private:
	std::shared_ptr<BaseScene> scene;	// ��݊Ǘ��p�ϐ�
	eScene nextScene;					// ���̼�݊Ǘ��p�ϐ�			
};

