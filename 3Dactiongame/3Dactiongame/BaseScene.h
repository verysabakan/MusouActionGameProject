//------------------------------------------------------
// @brief	¼°İ‚ÌŠî’ê
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "SceneProcess.h"
#include "ISceneSwitcher.h"
#include "SceneDateManager.h"

class BaseScene
	: public SceneProcess
{
protected:
	ISceneSwitcher* sceneSwitcher;			// ¼°İ‚ÌØ‚è‘Ö‚¦‚ğ“`‚¦‚é
	SceneDateManager* sceneDateManager;		// ¼°İŠÔ‚ÌÃŞ°À‚Ìó‚¯“n‚µ

public:
	BaseScene(ISceneSwitcher* switcher);	// ºİ½Ä×¸À
	virtual ~BaseScene();					// ÃŞ½Ä×¸À

	// -----µ°ÊŞ°×²ÄŞ----- //
	virtual void Initialize() override {}		// ‰Šú‰»
	virtual void Finalize() override {}			// I—¹ˆ—
	virtual void Update() override {}			// XV
	virtual void Render() override {}				// •`‰æ

};

