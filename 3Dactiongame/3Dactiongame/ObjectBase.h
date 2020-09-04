//------------------------------------------------------
// @brief	ｵﾌﾞｼﾞｪｸﾄの種類の基底ｸﾗｽ
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectTypeConstant.h"
#include "Vector3.h"

class ObjectBase
{
protected:
	Vector3 moveDir;	// 移動方向

public:
	ObjectBase();				// ｺﾝｽﾄﾗｸﾀ
	virtual ~ObjectBase();		// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() {}	// 初期化
	virtual void Finalize() {}		// 終了処理
	virtual void Update() {}		// 更新
	virtual void Render() {}		// 描画

	virtual ObjectType GetType() = 0;	// ｵﾌﾞｼﾞｪｸﾄの種類を取得:必ず実装


	// 外部からの変更
	void SetMoveDir(const Vector3& cameraDir);
};

