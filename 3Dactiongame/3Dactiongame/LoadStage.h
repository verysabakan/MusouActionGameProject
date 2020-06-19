//------------------------------------------------------
// @brief	½Ã°¼Ş‚Ì\¬‚É•K—v‚ÈÃŞ°À‚Ì“Ç‚İ‚İ
// 2020 6/4 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"

class LoadStage
{
private:
	// “Ç‚İ‚ŞÓÃŞÙ‚ÌÀ²Ìß
	typedef enum
	{
		LOAD_MODEL,
		LOAD_COLLISION,
		LOAD_SKY
	} LoadType;

public:
	LoadStage();	// ºİ½Ä×¸À
	~LoadStage();	// ÃŞ½Ä×¸À

	bool LoadStageDate(int& mH, int& cH, int& sH, const STAGE_TYPE& sT);			// ½Ã°¼ŞÃŞ°À‚Ì“Ç‚İ‚İ

private:
	const char* ConvertStageKindToPath(const STAGE_TYPE& sT, const LoadType& lT);	// STAGE_KIND‚ğÊß½‚É•ÏŠ·
	
};
