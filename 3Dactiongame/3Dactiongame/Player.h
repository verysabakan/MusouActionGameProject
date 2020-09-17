//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ğ‘€‚é
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectBase.h"

class Player
	:public ObjectBase
{
public:
	Player(int mID , std::vector<int>& aID);	// ºİ½Ä×¸À
	~Player();									// ÃŞ½Ä×¸À
	virtual void Initialize() override;	// ‰Šú‰»
	virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update() override;		// XV
	virtual void Render() override;		// •`‰æ

	virtual OBJECT_TYPE GetType() override;		// µÌŞ¼Şª¸Ä‚Ìí—Ş‚ğæ“¾

private:
	void Behavior();		// “®ì
	void Animation();		// ±ÆÒ°¼®İ

	Vector3 otamesi;
};