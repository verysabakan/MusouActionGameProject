//------------------------------------------------------
// @brief	��݂̊Ǘ�
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class SceneManager 
	: public ISceneSwitcher
	, private SceneProcess
{
private:
	std::shared_ptr<BaseScene> scene;	// ��݊Ǘ��p�ϐ�
	eScene nextScene;					// ���̼�݊Ǘ��p�ϐ�

public:
	SceneManager();		// �ݽ�׸�
	~SceneManager();	// �޽�׸�

	// ���ްײ��
	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

	void SwitchScene(eScene nextScene) override;	// �w�肵����݂ɕύX
};

