//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを操る
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectBase.h"

class Player
	:public ObjectBase
{
public:
	Player(int mID , std::vector<int>& aID);	// ｺﾝｽﾄﾗｸﾀ
	~Player();									// ﾃﾞｽﾄﾗｸﾀ
	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

	virtual OBJECT_TYPE GetType() override;		// ｵﾌﾞｼﾞｪｸﾄの種類を取得

private:
	void Behavior();		// 動作
	void Animation();		// ｱﾆﾒｰｼｮﾝ

	Vector3 otamesi;
};