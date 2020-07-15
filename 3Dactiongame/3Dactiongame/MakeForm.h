//------------------------------------------------------
// @brief	“–‚½‚è”»’è‚ğs‚¤Œ`‚ğŒ`¬‚·‚é
// 2020 7/14 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "Vector3.h"

class MakeForm
{
private:


public:
	MakeForm();			// ºİ½Ä×¸À
	~MakeForm();		// ÃŞ½Ä×¸À

	void GetHitCapsulePos(const VECTOR* Position, VECTOR* CapsulePosition1, VECTOR* CapsulePosition2);
};

