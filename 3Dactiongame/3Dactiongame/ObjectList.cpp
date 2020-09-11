//------------------------------------------------------
// @brief	ｷｬﾗｸﾀｰを格納するためのﾘｽﾄ(文字じゃないよ)
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#include "ObjectList.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
ObjectList::ObjectList()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
ObjectList::~ObjectList()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾘｽﾄに要素を追加
// @param	w 要素を追加するﾘｽﾄ
// @param	o 追加する要素
//------------------------------------------------------
void ObjectList::AddList(OBJECT_WEAK_LIST w, OBJECT_PTR o)
{
	auto kk = o;
	w.lock()->push_back(o);
}