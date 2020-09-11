//------------------------------------------------------
// @brief	任意のｵﾌﾞｼﾞｪｸﾄ同士の当たり判定を行う
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "CollisionBase.h"

class FlexibleCollision
	:private CollisionBase
{
private:
	// 当たり判定テーブル
	std::unique_ptr<CollisionBase> colTable
		[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_NUM)]
		[static_cast<int>(OBJECT_TYPE::OBJECT_TYPE_NUM)];

	// makeしたものが入っている番号を格納
	std::vector<OBJECT_TYPE> useTypeList1;
	std::vector<OBJECT_TYPE> useTypeList2;

public:
	FlexibleCollision();			// ｺﾝｽﾄﾗｸﾀ
	virtual ~FlexibleCollision();	// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();		// 初期化
	void Finalize();		// 終了処理
	// void Update();		// 更新
	// void Render();		// 描画

	virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) override;

};

