//------------------------------------------------------
// @brief	ﾘｽﾄに加える
// 2020 7/30 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include <list>

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class ObjectTypeBase;

using OBJECT_PTR = std::shared_ptr<ObjectTypeBase>;		// 個々のｵﾌﾞｼﾞｪｸﾄのﾎﾟｲﾝﾀ
using OBJECT_LIST = std::list<OBJECT_PTR>;				// 個々のｵﾌﾞｼﾞｪｸﾄのﾎﾟｲﾝﾀのﾘｽﾄ
using OBJECT_LIST_PTR = std::shared_ptr<OBJECT_LIST>;	// OBJECT_PTR_List最初のｱﾄﾞﾚｽ
using WEAK_LIST = std::weak_ptr<OBJECT_LIST>;			// 弱参照、除くためﾎﾟｲﾝﾀ

using OBJECT_LIST_ITERATOR = OBJECT_LIST::iterator;		// OBJECT_LISTのｲﾃﾚｰﾀ

// ｲﾝｽﾀﾝｽ化したｵﾌﾞｼﾞｪｸﾄをﾘｽﾄに加える
struct AddList
{
	// ｲﾝｽﾀﾝｽ化したらﾘｽﾄに格納
	OBJECT_LIST_ITERATOR operator()(const WEAK_LIST& weakList, const OBJECT_PTR& objPtr)
	{
		weakList.lock()->push_back(objPtr);	// ﾘｽﾄの末尾にOBJECT_PTRを追加
		OBJECT_LIST_ITERATOR itr = weakList.lock()->end();	// 末尾
		itr--;		// 末尾から前にﾏｲﾅｽ(endでは末尾の次になるため)
		return itr;	// 型推論のため
	}
};