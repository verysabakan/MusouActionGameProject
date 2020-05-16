//------------------------------------------------------
// @brief	ｼｰﾝの基本的な処理の基底
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Controller;

// ｼｰﾝの基本処理ｸﾗｽ
class SceneProcess {
public:
	virtual ~SceneProcess() {}			// ﾃﾞｽﾄﾗｸﾀ
	virtual void Initialize(void) {}		// 初期化:実装しなくてもいい
	virtual void Finalize(void) {}			// 終了処理:実装しなくてもいい
	virtual void Update(const Controller& controll) = 0;			// 更新:必ず実装
	virtual void Draw(void) = 0;			// 描画:必ず実装
};