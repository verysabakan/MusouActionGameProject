//------------------------------------------------------
// @brief	任意のｵﾌﾞｼﾞｪｸﾄ同士の当たり判定を行う
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "CollisionBase.h"

class FlexibleCollision
	:private CollisionBase
{
private:
	//CollisionBase* colTable[static_cast<int>(ObjectType::OBJECTTYPE_NUM)][static_cast<int>(ObjectType::OBJECTTYPE_NUM)];

	//EnumArray<int, IndexEnum> intArray(0);
	
	std::shared_ptr<CollisionBase> colTable[static_cast<int>(ObjectType::OBJECTTYPE_NUM)][static_cast<int>(ObjectType::OBJECTTYPE_NUM)];
	
public:
	FlexibleCollision();	// ｺﾝｽﾄﾗｸﾀ
	~FlexibleCollision();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();		// 初期化
	void Finalize();		// 終了処理
	// void Update();			// 更新
	// void Render();	// 描画

	virtual bool HitCheck(const ObjectType& o1, const ObjectType& o2) override;

};

