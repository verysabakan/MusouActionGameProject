//------------------------------------------------------
// @brief	˝čťč
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ObjectTypeConstant.h"

// ĚßŰÄŔ˛Ěßéž

class CollisionBase
{
public:
	CollisionBase();			// şÝ˝Ä×¸Ŕ
	virtual ~CollisionBase();	// źzĂŢ˝Ä×¸Ŕ

	virtual bool HitCheck(const ObjectType& o1, const ObjectType& o2) = 0;	// e˝čťč:K¸Ŕ
};

