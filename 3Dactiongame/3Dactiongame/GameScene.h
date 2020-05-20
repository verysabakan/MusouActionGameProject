//------------------------------------------------------
// @brief	ｹﾞｰﾑ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "BaseScene.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Camera;

class GameScene
	: public BaseScene
{
public:
	GameScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	~GameScene();							// ﾃﾞｽﾄﾗｸﾀ

	// ｵｰﾊﾞｰﾗｲﾄﾞ
	//virtual void Initialize() override;	// 初期化
	//virtual void Finalize() override;	// 終了処理
	virtual void Update(const Controller& controll) override;		// 更新
	virtual void Render() override;		// 描画

private:
	std::unique_ptr<Camera> camera;
};

