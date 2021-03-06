//------------------------------------------------------
// @brief	ｼｰﾝの管理
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class SceneManager 
	: public ISceneSwitcher
	, private SceneProcess
{
private:
	std::shared_ptr<BaseScene> scene;	// ｼｰﾝ管理用変数
	eScene nextScene;					// 次のｼｰﾝ管理用変数

public:
	SceneManager();		// ｺﾝｽﾄﾗｸﾀ
	~SceneManager();	// ﾃﾞｽﾄﾗｸﾀ

	// ｵｰﾊﾞｰﾗｲﾄﾞ
	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

	void SwitchScene(eScene nextScene) override;	// 指定したｼｰﾝに変更
};

