//------------------------------------------------------
// @brief	“–‚½‚è”»’è
// 2020 7/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ObjectTypeConstant.h"
#include "ObjectBase.h"

// ÌßÛÄÀ²ÌßéŒ¾

class CollisionBase
{
public:
	CollisionBase();			// ºİ½Ä×¸À
	virtual ~CollisionBase();	// ƒˆ‰¼‘zÃŞ½Ä×¸À

	virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) = 0;	// Še“–‚½‚è”»’èˆ—:•K‚¸À‘•
};

