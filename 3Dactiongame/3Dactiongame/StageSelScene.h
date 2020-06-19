//------------------------------------------------------
// @brief	ｽﾃｰｼﾞ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class SceneManager;

class StageSelScene
	: public BaseScene
{
public:
	//StageSelScene(ISceneSwitcher* switcher,SceneDateManager* dateManager);	// ｺﾝｽﾄﾗｸﾀ
	StageSelScene(SceneManager* sManager);
	~StageSelScene();					// ﾃﾞｽﾄﾗｸﾀ

	// -----ｵｰﾊﾞｰﾗｲﾄﾞ----- //
	//virtual void Initialize() override;	// 初期化
	//virtual void Finalize() override;	// 終了処理
	virtual void Update(const Controller& controll) override;		// 更新
	virtual void Render() override;		// 描画
};

