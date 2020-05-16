//------------------------------------------------------
// @brief	ｷｬﾗｸﾀｰ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class CharSelScene
	: public BaseScene
{
public:
	CharSelScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	~CharSelScene();						// ﾃﾞｽﾄﾗｸﾀ

	// ｵｰﾊﾞｰﾗｲﾄﾞ
	//virtual void Initialize(void) override;	// 初期化
	//virtual void Finalize(void) override;	// 終了処理
	virtual void Update(const Controller& controll) override;		// 更新
	virtual void Draw(void) override;		// 描画
};

