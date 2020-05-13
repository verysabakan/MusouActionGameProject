//------------------------------------------------------
// @brief	ﾀｲﾄﾙ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class TitleScene
	: public BaseScene
{
public:
	TitleScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	~TitleScene();							// ﾃﾞｽﾄﾗｸﾀ

	// ｵｰﾊﾞｰﾗｲﾄﾞ
	//virtual void Initialize(void) override;	//初期化
	//virtual void Finalize(void) override;	//終了処理
	virtual void Update(void) override;		//更新
	virtual void Draw(void) override;		//描画
};

