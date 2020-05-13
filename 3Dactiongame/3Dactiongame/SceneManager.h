//------------------------------------------------------
// @brief	¼°İ‚ÌŠÇ—
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class SceneManager 
	: public ISceneSwitcher, BaseProcessing
{
public:
	SceneManager();		// ºİ½Ä×¸À
	~SceneManager();	// ÃŞ½Ä×¸À

	// µ°ÊŞ°×²ÄŞ
	virtual void Initialize(void) override;	//‰Šú‰»
	virtual void Finalize(void) override;	//I—¹ˆ—
	virtual void Update(void) override;		//XV
	virtual void Draw(void) override;		//•`‰æ

	void SwitchScene(eScene nextScene) override;

private:
	BaseScene* scene;	// ¼°İŠÇ—•Ï”
	eScene nextScene;	// Ÿ‚Ì¼°İŠÇ—•Ï”
};

