//------------------------------------------------------
// @brief	ÏÈ°¼Ş¬°‚ğŠi”[‚·‚é‚½‚ß‚ÌØ½Ä
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ManagerBase.h"
#include "GMList.h"
#include "StageType.h"

// ÌßÛÄÀ²ÌßéŒ¾
class PlayerManager;
class StageManager;
class FlexibleCollision;

class GeneralManager
	:private GMList,
	public ManagerBase
{
public:
	GeneralManager(const STAGE_TYPE& sT);	// ºİ½Ä×¸À
	~GeneralManager();	// ÃŞ½Ä×¸À

	virtual void Initialize() override;	// ‰Šú‰»
	virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update() override;		// XV
	virtual void Render() override;		// •`‰æ
};

