//------------------------------------------------------
// @brief	ｼｰﾝの基本的な処理の基底
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ｼｰﾝの基本処理ｸﾗｽ
class SceneProcess {
public:
	virtual ~SceneProcess() {}			// ﾃﾞｽﾄﾗｸﾀ
	virtual void Initialize() {}		// 初期化:実装しなくてもいい
	virtual void Finalize() {}			// 終了処理:実装しなくてもいい
	virtual void Update() = 0;			// 更新:必ず実装
	virtual void Render() = 0;			// 描画:必ず実装
};