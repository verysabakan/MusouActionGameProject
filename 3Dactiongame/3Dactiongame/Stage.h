//------------------------------------------------------
// @brief	½Ã°¼Ş‚ÌŠÇ—
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "LoadStage.h"
#include "StageModelBase.h"

// ÌßÛÄÀ²ÌßéŒ¾
class StageModelBase;

class Stage
	: public StageModelBase
{
public:
	Stage(const STAGE_TYPE& sT);	// ºİ½Ä×¸À
	~Stage();	// ÃŞ½Ä×¸À

	void Initialize();	// ‰Šú‰»
	void Finalize();	// I—¹ˆ—
	void Update();		// XV
	void Render();		// •`‰æ

};

