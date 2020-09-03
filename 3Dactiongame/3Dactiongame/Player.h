//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを操る
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <vector>
#include "ModelBase.h"

class Player
	:public ModelBase
{
public:
	Player(int mID , std::vector<int>& aID);	// ｺﾝｽﾄﾗｸﾀ
	~Player();									// ﾃﾞｽﾄﾗｸﾀ
	virtual void Initialize();	// 初期化
	virtual void Finalize();	// 終了処理
	virtual void Update();		// 更新
	virtual void Render();		// 描画

	virtual ObjectType GetType() final;		// ｵﾌﾞｼﾞｪｸﾄの種類を取得

private:
	void Behavior();		// 動作
	void Animation();		// ｱﾆﾒｰｼｮﾝ
};