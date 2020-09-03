//------------------------------------------------------
// @brief	�ްщ��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"
#include "StageType.h"

class GeneralManager;

class GameScene
	: public BaseScene
{
private:
	std::unique_ptr<GeneralManager> generalManager;

public:
	GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT);	// �ݽ�׸�
	~GameScene();							// �޽�׸�

	// ���ްײ��
	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��
};

