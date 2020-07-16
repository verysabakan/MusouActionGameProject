//------------------------------------------------------
// @brief	¹Ş°Ñ‰æ–Ê
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "BaseScene.h"
#include "StageType.h"

// ÌßÛÄÀ²ÌßéŒ¾
class PlayerManager;
class StageManager;
class Camera;
class Collision;

class GameScene
	: public BaseScene
{
private:
	std::unique_ptr<PlayerManager> playerMnager;
	std::unique_ptr<StageManager> stageManager;
	std::unique_ptr<Camera> camera;
	std::unique_ptr<Collision> collision;

public:
	GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT);	// ºİ½Ä×¸À
	~GameScene();							// ÃŞ½Ä×¸À

	// µ°ÊŞ°×²ÄŞ
	virtual void Initialize() override;	// ‰Šú‰»
	virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update() override;		// XV
	virtual void Render() override;		// •`‰æ
};

