//------------------------------------------------------
// @brief	¼°İŠÔ‚ÌÃŞ°ÀŠÇ—
// 2020 6/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"

class SceneDateManager
{
private:
	STAGE_TYPE stageType;	// ‚Ç‚Ì½Ã°¼Ş‚©

public:
	SceneDateManager();				// ºİ½Ä×¸À
	virtual ~SceneDateManager();	// ÃŞ½Ä×¸À

	void SetStageType(const STAGE_TYPE& type);	// ‘I‚ñ‚¾½Ã°¼Ş‚ğ¾¯Ä
	const STAGE_TYPE GetStageType() const;	// Ši”[‚µ‚½½Ã°¼ŞÀ²Ìß‚ğæ“¾

};
