//------------------------------------------------------
// @brief	µÌÞ¼Þª¸Ä‚ÌŽí—Þ‚ÌŠî’ê¸×½
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectTypeConstant.h"

class ObjectTypeBace
{
	ObjectTypeBace();				// ºÝ½Ä×¸À
	virtual ~ObjectTypeBace();		// ÃÞ½Ä×¸À

	virtual ObjectType GetType() = 0;	
};

