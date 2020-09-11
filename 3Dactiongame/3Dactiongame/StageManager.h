//------------------------------------------------------
// @brief	½Ã°¼Ş‚ÌŠÇ—
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ManagerBase.h"

class StageManager
	:public ManagerBase
{
public:
	StageManager(const STAGE_TYPE& sT);		// ºİ½Ä×¸À
	~StageManager();	// ÃŞ½Ä×¸À

	virtual void Initialize() override;	// ‰Šú‰»
	virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update() override;		// XV
	virtual void Render() override;		// •`‰æ

};

