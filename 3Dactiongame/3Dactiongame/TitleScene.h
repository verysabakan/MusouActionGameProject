//------------------------------------------------------
// @brief	À²ÄÙ‰æ–Ê
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class TitleScene
	: public BaseScene
{
public:
	TitleScene(ISceneSwitcher* switcher);
	~TitleScene();

	// µ°ÊŞ°×²ÄŞ
	//virtual void Initialize() override;	//‰Šú‰»
	//virtual void Finalize() override;	//I—¹ˆ—
	virtual void Update() override;		//XV
	virtual void Draw() override;		//•`‰æ
};

