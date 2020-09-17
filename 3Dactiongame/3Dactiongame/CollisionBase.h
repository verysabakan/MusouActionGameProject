//------------------------------------------------------
// @brief	˝čťč
// 2020 7/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ObjectTypeConstant.h"
#include "ObjectBase.h"

// ĚßŰÄŔ˛Ěßéž

class CollisionBase
{
public:
	CollisionBase();			// şÝ˝Ä×¸Ŕ
	virtual ~CollisionBase();	// źzĂŢ˝Ä×¸Ŕ

	virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) = 0;	// e˝čťč:K¸Ŕ
};

