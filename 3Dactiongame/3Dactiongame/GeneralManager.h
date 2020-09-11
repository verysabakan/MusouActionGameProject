//------------------------------------------------------
// @brief	ÏÈ°¼Ş¬°‚ğŠi”[‚·‚é‚½‚ß‚ÌØ½Ä
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"
#include "GMList.h"

// ÌßÛÄÀ²ÌßéŒ¾
class FlexibleCollision;

class GeneralManager
	:private GMList
{
private:
	std::unique_ptr<FlexibleCollision> fCollision;

public:
	GeneralManager(const STAGE_TYPE& sT);	// ºİ½Ä×¸À
	~GeneralManager();	// ÃŞ½Ä×¸À

	void Initialize();	// ‰Šú‰»
	void Finalize();	// I—¹ˆ—
	void Update();		// XV
	void Render();		// •`‰æ

};

