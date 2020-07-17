//------------------------------------------------------
// @brief	ｹﾞｰﾑ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "BaseScene.h"
#include "StageType.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class PlayerManager;
class StageManager;
class Camera;
class FlexibleCollision;

class GameScene
	: public BaseScene
{
private:
	std::unique_ptr<PlayerManager> playerMnager;
	std::unique_ptr<StageManager> stageManager;
	std::unique_ptr<Camera> camera;
	std::unique_ptr<FlexibleCollision> fCollision;

public:
	GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT);	// ｺﾝｽﾄﾗｸﾀ
	~GameScene();							// ﾃﾞｽﾄﾗｸﾀ

	// ｵｰﾊﾞｰﾗｲﾄﾞ
	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画
};

