//------------------------------------------------------
// @brief	ﾓｰﾄﾞ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class ModeSelScene
	: public BaseScene
{
public:
	ModeSelScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	~ModeSelScene();						// ﾃﾞｽﾄﾗｸﾀ

	// ｵｰﾊﾞｰﾗｲﾄﾞ
	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

private:
	int modelHandle;
};

