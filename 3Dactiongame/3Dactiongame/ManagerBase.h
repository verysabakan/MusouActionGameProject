//------------------------------------------------------
// @brief	ﾏﾈｰｼﾞｬｰの基底
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

//#include "ManagerTypeConstant.h"
#include "ObjectList.h"

class ManagerBase
	:public ObjectList
{
public:
	ManagerBase();			// ｺﾝｽﾄﾗｸﾀ
	virtual ~ManagerBase();	// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() {}	// 初期化
	virtual void Finalize() {}		// 終了処理
	virtual void Update() {}		// 更新
	virtual void Render() {}		// 描画

	OBJECT_LIST_PTR GetObjectList();	// OBJECT_LIST_PTRの取得
};

