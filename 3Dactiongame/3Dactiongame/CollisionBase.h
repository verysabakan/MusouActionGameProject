//------------------------------------------------------
// @brief	“–‚½‚è”»’è
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ObjectTypeConstant.h"

// ÌßÛÄÀ²ÌßéŒ¾

class CollisionBase
{
public:
	CollisionBase();			// ºİ½Ä×¸À
	virtual ~CollisionBase();	// ƒˆ‰¼‘zÃŞ½Ä×¸À

	virtual bool HitCheck(const ObjectType& o1, const ObjectType& o2) = 0;	// Še“–‚½‚è”»’èˆ—:•K‚¸À‘•

};

