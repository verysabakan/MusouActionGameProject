//------------------------------------------------------
// @brief	¹Ş°Ñ‰æ–Ê
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
	GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT);	// ºİ½Ä×¸À
	~GameScene();							// ÃŞ½Ä×¸À

	// µ°ÊŞ°×²ÄŞ
	virtual void Initialize() override;	// ‰Šú‰»
	virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update() override;		// XV
	virtual void Render() override;		// •`‰æ
};

