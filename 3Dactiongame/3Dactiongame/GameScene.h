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
	GameScene(ISceneSwitcher* switcher);
	~GameScene();

	// µ°ÊŞ°×²ÄŞ
	//virtual void Initialize() override;	//‰Šú‰»
	//virtual void Finalize() override;	//I—¹ˆ—
	virtual void Update() override;		//XV
	virtual void Draw() override;		//•`‰æ
};

