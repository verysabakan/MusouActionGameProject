//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類の基底ｸﾗｽ
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectTypeConstant.h"

class ObjectTypeBace
{
public:
	ObjectTypeBace();				// ｺﾝｽﾄﾗｸﾀ
	virtual ~ObjectTypeBace();		// ﾃﾞｽﾄﾗｸﾀ

	virtual ObjectType GetType() = 0;	// ｵﾌﾞｼﾞｪｸﾄの種類を取得:必ず実装
};

