//------------------------------------------------------
// @brief	¼°İ‚ÌŠî’ê
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseProcessing.h"
#include "ISceneSwitcher.h"

class BaseScene
	: public BaseProcessing
{
public:
	BaseScene(ISceneSwitcher* switcher);	// ºİ½Ä×¸À
	virtual ~BaseScene();					// ÃŞ½Ä×¸À

	// µ°ÊŞ°×²ÄŞ
	virtual void Initialize(void) override {}		// ‰Šú‰»
	virtual void Finalize(void) override {}			// I—¹ˆ—
	virtual void Update(void) override {}			// XV
	virtual void Draw(void) override {}				// •`‰æ

protected:
	ISceneSwitcher* sceneSwitcher;	// ¼°İ‚ÌØ‚è‘Ö‚¦‚ğ“`‚¦‚é
};

