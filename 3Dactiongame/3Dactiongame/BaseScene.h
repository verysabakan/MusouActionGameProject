//------------------------------------------------------
// @brief	ｼｰﾝの基底
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "SceneProcess.h"
#include "ISceneSwitcher.h"
#include "SceneDateManager.h"

#include "_Debug.h"

class BaseScene
	: public SceneProcess
{
protected:
	ISceneSwitcher* sceneSwitcher;			// ｼｰﾝの切り替えを伝える

public:
	BaseScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	virtual ~BaseScene();					// ﾃﾞｽﾄﾗｸﾀ

	// -----ｵｰﾊﾞｰﾗｲﾄﾞ----- //
	virtual void Initialize() override {}		// 初期化
	virtual void Finalize() override {}			// 終了処理
	virtual void Update() override {}			// 更新
	virtual void Render() override {}			// 描画
};

