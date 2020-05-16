//------------------------------------------------------
// @brief	¹Ş°Ñ‰æ–Ê
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class GameScene
	: public BaseScene
{
public:
	GameScene(ISceneSwitcher* switcher);	// ºİ½Ä×¸À
	~GameScene();							// ÃŞ½Ä×¸À

	// µ°ÊŞ°×²ÄŞ
	//virtual void Initialize(void) override;	// ‰Šú‰»
	//virtual void Finalize(void) override;	// I—¹ˆ—
	virtual void Update(const Controller& controll) override;		// XV
	virtual void Draw(void) override;		// •`‰æ
};

