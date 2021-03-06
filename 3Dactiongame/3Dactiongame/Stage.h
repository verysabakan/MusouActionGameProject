//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの管理
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "LoadStage.h"
#include "ObjectBase.h"

class Stage
	: public ObjectBase
{
public:
	Stage(const STAGE_TYPE& sT);	// ｺﾝｽﾄﾗｸﾀ
	~Stage();	// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

	virtual OBJECT_TYPE GetType() override;		// ｵﾌﾞｼﾞｪｸﾄの種類を取得
};

