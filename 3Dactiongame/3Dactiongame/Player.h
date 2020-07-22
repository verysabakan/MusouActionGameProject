//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを操る
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <vector>
#include "ModelBase.h"

class Player
	:private ModelBase
{
public:
	Player(int mID , std::vector<int>& aID);
	~Player();
	void Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update(const Vector3& cameraDir);		// 更新
	void Render();		// 描画

	virtual ObjectType GetType() final;		// ｵﾌﾞｼﾞｪｸﾄの種類を取得

private:
	void Behavior(const Vector3& cameraDir);		// 動作
	void Animation();		// 移動
};