//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄを格納するためのﾘｽﾄ
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <list>
#include <memory>
#include "ManagerBase.h"

using MANAGER_PTR = std::shared_ptr<ManagerBase>;			// 個々のｵﾌﾞｼﾞｪｸﾄﾎﾟｲﾝﾀ
using MANAGER_LIST = std::list<MANAGER_PTR>;				// 個々のｵﾌﾞｼﾞｪｸﾄﾎﾟｲﾝﾀのﾘｽﾄ
using MANAGER_LIST_PTR = std::shared_ptr<MANAGER_LIST>;		// MANAGER_PTR_LIST最初のｱﾄﾞﾚｽ
using MANAGER_WEAK_LIST = std::weak_ptr<MANAGER_LIST>;				// 弱参照、除くためﾎﾟｲﾝﾀ

using MANAGER_LIST_ITERATOR = MANAGER_LIST::iterator;		// OBJECT_LISTのｲﾃﾚｰﾀ

class GMList
{
protected:
	MANAGER_LIST_PTR mgrList;

protected:
	void AddList(MANAGER_WEAK_LIST w, MANAGER_PTR o);	// ﾘｽﾄに追加

public:
	GMList();			// ｺﾝｽﾄﾗｸﾀ
	virtual ~GMList();	// ﾃﾞｽﾄﾗｸﾀ

};



