//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄを格納するためのﾘｽﾄ(文字じゃないよ)
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <list>
#include <memory>
#include "ObjectBase.h"

using OBJECT_PTR = std::shared_ptr<ObjectBase>;			// 個々のｵﾌﾞｼﾞｪｸﾄﾎﾟｲﾝﾀ
using OBJECT_LIST = std::list<OBJECT_PTR>;				// 個々のｵﾌﾞｼﾞｪｸﾄﾎﾟｲﾝﾀのﾘｽﾄ
using OBJECT_LIST_PTR = std::shared_ptr<OBJECT_LIST>;	// OBJECT_PTR_LIST最初のｱﾄﾞﾚｽ
using OBJECT_WEAK_LIST = std::weak_ptr<OBJECT_LIST>;	// 弱参照、除くためﾎﾟｲﾝﾀ

using OBJECT_LIST_ITERATOR = OBJECT_LIST::iterator;		// OBJECT_LISTのｲﾃﾚｰﾀ

class ObjectList
{
protected:
	OBJECT_LIST_PTR objList;	// 格納用のﾘｽﾄのﾎﾟｲﾝﾀ

protected:
	void AddList(OBJECT_WEAK_LIST w, OBJECT_PTR o);	// ﾘｽﾄに追加

public:
	ObjectList();				// ｺﾝｽﾄﾗｸﾀ
	virtual ~ObjectList();		// ﾃﾞｽﾄﾗｸﾀ

};

