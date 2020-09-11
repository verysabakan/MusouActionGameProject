//------------------------------------------------------
// @brief	½Ã°¼Ş‚ÌŠÇ—
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "LoadStage.h"
#include "ObjectBase.h"

class Stage
	: public ObjectBase
{
public:
	Stage(const STAGE_TYPE& sT);	// ºİ½Ä×¸À
	~Stage();	// ÃŞ½Ä×¸À

	virtual void Initialize() override;	// ‰Šú‰»
	virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update() override;		// XV
	virtual void Render() override;		// •`‰æ

	virtual OBJECT_TYPE GetType() override;		// µÌŞ¼Şª¸Ä‚Ìí—Ş‚ğæ“¾
};

