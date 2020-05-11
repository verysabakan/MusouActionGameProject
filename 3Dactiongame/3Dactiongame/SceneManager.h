//------------------------------------------------------
// @brief	��݂̊Ǘ�
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class SceneManager 
	: public ISceneSwitcher, BaseProcessing
{
public:
	SceneManager();
	~SceneManager();

	// ���ްײ��
	virtual void Initialize() override;	//������
	virtual void Finalize() override;	//�I������
	virtual void Update() override;		//�X�V
	virtual void Draw() override;		//�`��

	void SwitchScene(eScene nextScene) override;

private:
	BaseScene* scene;	// ��݊Ǘ��ϐ�
	eScene nextScene;	// ���̼�݊Ǘ��ϐ�
};

