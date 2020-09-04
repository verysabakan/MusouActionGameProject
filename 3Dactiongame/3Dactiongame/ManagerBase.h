//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄを格納するためのﾘｽﾄ
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ManagerTypeConstant.h"

class ManagerBase
{
public:
	ManagerBase();	// ｺﾝｽﾄﾗｸﾀ
	virtual ~ManagerBase();	// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() {}	// 初期化
	virtual void Finalize() {}		// 終了処理
	virtual void Update() {}		// 更新
	virtual void Render() {}		// 描画

	virtual bool GetManagerType(MANAGER_TYPE type) = 0;	// ｵﾌﾞｼﾞｪｸﾄのﾀｲﾌﾟ取得関数
};

