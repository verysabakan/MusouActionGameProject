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
	SceneManager();		// �ݽ�׸�
	~SceneManager();	// �޽�׸�

	// ���ްײ��
	virtual void Initialize(void) override;	//������
	virtual void Finalize(void) override;	//�I������
	virtual void Update(void) override;		//�X�V
	virtual void Draw(void) override;		//�`��

	void SwitchScene(eScene nextScene) override;

private:
	BaseScene* scene;	// ��݊Ǘ��ϐ�
	eScene nextScene;	// ���̼�݊Ǘ��ϐ�
};

