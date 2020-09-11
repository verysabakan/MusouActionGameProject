//------------------------------------------------------
// @brief	ÏÈ°¼Ş¬°‚ÌŠî’ê
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

//#include "ManagerTypeConstant.h"
#include "ObjectList.h"

class ManagerBase
	:public ObjectList
{
public:
	ManagerBase();			// ºİ½Ä×¸À
	virtual ~ManagerBase();	// ÃŞ½Ä×¸À

	virtual void Initialize() {}	// ‰Šú‰»
	virtual void Finalize() {}		// I—¹ˆ—
	virtual void Update() {}		// XV
	virtual void Render() {}		// •`‰æ

	OBJECT_LIST_PTR GetObjectList();	// OBJECT_LIST_PTR‚Ìæ“¾
};

