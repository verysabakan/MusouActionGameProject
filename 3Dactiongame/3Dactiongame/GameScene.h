//------------------------------------------------------
// @brief	�ްщ��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "BaseScene.h"
#include "StageType.h"

// �������ߐ錾
class PlayerManager;
class StageManager;
class Camera;
class Collider;

class GameScene
	: public BaseScene
{
private:
	std::unique_ptr<PlayerManager> playerMnager;
	std::unique_ptr<StageManager> stageManager;
	std::unique_ptr<Camera> camera;
	std::unique_ptr<Collider> collider;

public:
	GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT);	// �ݽ�׸�
	~GameScene();							// �޽�׸�

	// ���ްײ��
	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��
};

