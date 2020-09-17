//------------------------------------------------------
// @brief	¼°İŠÔ‚ÌÃŞ°ÀŠÇ—
// 2020 6/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"
#include "Singleton.h"

// ’è‹`
#define lpSceneDateManager SceneDateManager::Instance()

class SceneDateManager
	:public Singleton<SceneDateManager>
{
private:
	STAGE_TYPE stageType;	// ‚Ç‚Ì½Ã°¼Ş‚©

public:
	void SetStageType(const STAGE_TYPE& type);	// ‘I‚ñ‚¾½Ã°¼Ş‚ğ¾¯Ä
	const STAGE_TYPE GetStageType() const;	// Ši”[‚µ‚½½Ã°¼ŞÀ²Ìß‚ğæ“¾

private:
	SceneDateManager();				// ºİ½Ä×¸À
	friend Singleton<SceneDateManager>;	// ÌÚİÄŞ¸×½
	~SceneDateManager();	// ÃŞ½Ä×¸À

};
