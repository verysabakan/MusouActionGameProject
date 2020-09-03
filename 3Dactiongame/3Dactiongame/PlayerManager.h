//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"
#include "ObjectList.h"
#include "ManagerBase.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Player;
class Camera;
class ModelBase;

class PlayerManager
	:private ObjectList,
	public ManagerBase
{
private:
	std::unique_ptr<Camera> camera;
	
public:
	PlayerManager();	// ｺﾝｽﾄﾗｸﾀ
	~PlayerManager();				// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

	ModelBase* GetPlayer();	// ModelBaseの取得

	virtual bool GetManagerType(MANAGER_TYPE type) final;	// ﾀｲﾌﾟの取得(どのﾀｲﾌﾟか確かめる)
private:
	void SetPlayerMoveDir(const Vector3& cameraDir);	// 各ｶﾒﾗからのﾌﾟﾚｲﾔｰの動く方向の受け渡し処理

};

