//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ğ‘€‚é
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <vector>
#include "ModelBase.h"

class Player
	:public ModelBase
{
public:
	Player(int mID , std::vector<int>& aID);	// ºİ½Ä×¸À
	~Player();									// ÃŞ½Ä×¸À
	virtual void Initialize();	// ‰Šú‰»
	virtual void Finalize();	// I—¹ˆ—
	virtual void Update();		// XV
	virtual void Render();		// •`‰æ

	virtual ObjectType GetType() final;		// µÌŞ¼Şª¸Ä‚Ìí—Ş‚ğæ“¾

private:
	void Behavior();		// “®ì
	void Animation();		// ±ÆÒ°¼®İ
};