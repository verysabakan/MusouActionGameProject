//------------------------------------------------------
// @brief	任意のｵﾌﾞｼﾞｪｸﾄ同士の当たり判定を行う
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

class FlexibleCollision
{
public:
	FlexibleCollision();	// ｺﾝｽﾄﾗｸﾀ
	~FlexibleCollision();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();		// 初期化
	void Finalize();		// 終了処理
	void Update();			// 更新
	// void Render();	// 描画

};

