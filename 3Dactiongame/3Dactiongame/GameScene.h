//------------------------------------------------------
// @brief	¹Ş°Ñ‰æ–Ê
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "BaseScene.h"

// ÌßÛÄÀ²ÌßéŒ¾
class Camera;

class GameScene
	: public BaseScene
{
public:
	GameScene(ISceneSwitcher* switcher);	// ºİ½Ä×¸À
	~GameScene();							// ÃŞ½Ä×¸À

	// µ°ÊŞ°×²ÄŞ
	//virtual void Initialize() override;	// ‰Šú‰»
	//virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update(const Controller& controll) override;		// XV
	virtual void Render() override;		// •`‰æ

private:
	std::unique_ptr<Camera> camera;
};

