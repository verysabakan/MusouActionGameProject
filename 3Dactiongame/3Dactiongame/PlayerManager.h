//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "Vector3.h"
#include "ManagerBase.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Camera;

class PlayerManager
	:public ManagerBase
{
private:
	std::unique_ptr<Camera> camera;
	
public:
	PlayerManager();	// ｺﾝｽﾄﾗｸﾀ
	~PlayerManager();	// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

};

