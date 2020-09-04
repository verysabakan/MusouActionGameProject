//------------------------------------------------------
// @brief	ﾏﾈｰｼﾞｬｰを格納するためのﾘｽﾄ
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ManagerBase.h"
#include "GMList.h"
#include "StageType.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class PlayerManager;
class StageManager;
class FlexibleCollision;

class GeneralManager
	:private GMList,
	public ManagerBase
{
public:
	GeneralManager(const STAGE_TYPE& sT);	// ｺﾝｽﾄﾗｸﾀ
	~GeneralManager();	// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画
};

