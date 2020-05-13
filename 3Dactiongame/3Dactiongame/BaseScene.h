//------------------------------------------------------
// @brief	ｼｰﾝの基底
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseProcessing.h"
#include "ISceneSwitcher.h"

class BaseScene
	: public BaseProcessing
{
public:
	BaseScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	virtual ~BaseScene();					// ﾃﾞｽﾄﾗｸﾀ

	// ｵｰﾊﾞｰﾗｲﾄﾞ
	virtual void Initialize(void) override {}	//初期化
	virtual void Finalize(void) override {}		//終了処理
	virtual void Update(void) override {}		//更新
	virtual void Draw(void) override {}			//描画

protected:
	ISceneSwitcher* sceneSwitcher;	// ｼｰﾝの切り替えを伝える
};

