//------------------------------------------------------
// @brief	µÌŞ¼Şª¸Ä‚ğŠi”[‚·‚é‚½‚ß‚ÌØ½Ä
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ManagerTypeConstant.h"

class ManagerBase
{
public:
	ManagerBase();	// ºİ½Ä×¸À
	virtual ~ManagerBase();	// ÃŞ½Ä×¸À

	virtual void Initialize() {}	// ‰Šú‰»
	virtual void Finalize() {}		// I—¹ˆ—
	virtual void Update() {}		// XV
	virtual void Render() {}		// •`‰æ

	virtual bool GetManagerType(MANAGER_TYPE type) = 0;	// µÌŞ¼Şª¸Ä‚ÌÀ²Ìßæ“¾ŠÖ”
};

