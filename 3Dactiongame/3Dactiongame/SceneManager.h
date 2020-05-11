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
	SceneManager();
	~SceneManager();

	// µ°ÊŞ°×²ÄŞ
	virtual void Initialize() override;	//‰Šú‰»
	virtual void Finalize() override;	//I—¹ˆ—
	virtual void Update() override;		//XV
	virtual void Draw() override;		//•`‰æ

	void SwitchScene(eScene nextScene) override;

private:
	BaseScene* scene;	// ¼°İŠÇ—•Ï”
	eScene nextScene;	// Ÿ‚Ì¼°İŠÇ—•Ï”
};

