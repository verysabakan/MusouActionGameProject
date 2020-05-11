//------------------------------------------------------
// @brief	基本的な処理の基底
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 基本処理ｸﾗｽ
class BaseProcessing {
public:
	virtual ~BaseProcessing() {}	// ﾃﾞｽﾄﾗｸﾀ
	virtual void Initialize() {}	//初期化:実装しなくてもいい
	virtual void Finalize() {}		//終了処理:実装しなくてもいい
	virtual void Update() = 0;		//更新:必ず実装
	virtual void Draw() = 0;		//描画:必ず実装
};