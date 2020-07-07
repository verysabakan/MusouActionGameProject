//------------------------------------------------------
// @brief	ｼｰﾝの基底
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "SceneProcess.h"
#include "ISceneSwitcher.h"
#include "SceneDateManager.h"

class BaseScene
	: public SceneProcess
{
public:
	BaseScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	virtual ~BaseScene();					// ﾃﾞｽﾄﾗｸﾀ

	// -----ｵｰﾊﾞｰﾗｲﾄﾞ----- //
	virtual void Initialize() override {}		// 初期化
	virtual void Finalize() override {}			// 終了処理
	virtual void Update() override {}			// 更新
	virtual void Render() override {}				// 描画

protected:
	ISceneSwitcher* sceneSwitcher;			// ｼｰﾝの切り替えを伝える
	SceneDateManager* sceneDateManager;		// ｼｰﾝ間のﾃﾞｰﾀの受け渡し

};

