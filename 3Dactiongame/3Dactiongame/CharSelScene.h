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
	//virtual void Initialize() override;	// 初期化
	//virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画
};

