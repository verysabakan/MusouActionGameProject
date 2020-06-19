//------------------------------------------------------
// @brief	(½Ã°¼Ş)ÓÃŞÙ‚Ì‚½‚ß‚ÌŠî’ê
// 2020 6/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

class StageModelBase
{
protected:
	int modelHandle;			// ÓÃŞÙ‚ÌÊİÄŞÙ
	int collisionModelHandle;	// ºØ¼Ş®İ—pÓÃŞÙ‚ÌÊİÄŞÙ
	int skyModelHandle;			// ‹óÓÃŞÙ‚ÌÊİÄŞÙ

public:
	StageModelBase();	// ºİ½Ä×¸À
	~StageModelBase();	// ÃŞ½Ä×¸À

	int GetCollisionModelHandle() { return collisionModelHandle; }	// “–‚½‚è”»’è—pÓÃŞÙÊİÄŞÙ‚Ìæ“¾
};

