//------------------------------------------------------
// @brief	(ｷｬﾗ)ﾓﾃﾞﾙのための基底
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <DxLib.h>
#include <vector>
#include "Vector3.h"
#include "ObjectTypeConstant.h"
#include "ActionStateConstant.h"

class ObjectBase
{
protected:
	ACTION_STATE actionState;		// 現在のﾌﾟﾚｲﾔｰの状態
	ACTION_STATE oldActionState;	// 前のﾌﾟﾚｲﾔｰの状態

	int modelHandle;			// ﾓﾃﾞﾙﾃﾞｰﾀ用
	int collisionModelHandle;	// ｺﾘｼﾞｮﾝ用ﾓﾃﾞﾙのﾊﾝﾄﾞﾙ
	int skyModelHandle;			// 空ﾓﾃﾞﾙのﾊﾝﾄﾞﾙ
	std::vector<int> animHandle;	// ｱﾆﾒｰｼｮﾝﾃﾞｰﾀ用
	Vector3 target;		// 向いている方向
	Vector3 pos;		// XYZ軸方向
	Vector3 rol;		// 回転
	Vector3 scl;		// 大きさ
	Vector3 hitpos;		// 判定球の中心
	float hitR;			// 判定球の半径
	Vector3 moveDir;	// 移動方向
	// ｱﾆﾒｰｼｮﾝ
	int attachiIndex;	// ｱﾆﾒ番号登録
	float totalTime;	// 再生総時間
	float playTime;		// 再生箇所
	Vector3 moveSpeed;	// 移動速度
	
	//------------------------------------------
	// とりあえずのやつ↓
	//------------------------------------------
	bool moveFlag = false;
	bool jumpFlag = false;
	float gravity;

public:
	ObjectBase();			// ｺﾝｽﾄﾗｸﾀ
	virtual ~ObjectBase();			// ﾃﾞｽﾄﾗｸﾀ

	virtual void Initialize() {}	// 初期化
	virtual void Finalize() {}		// 終了処理
	virtual void Update() {}		// 更新
	virtual void Render() {}		// 描画

	int GetCollisionModelHandle() { return collisionModelHandle; }	// 当たり判定用ﾓﾃﾞﾙﾊﾝﾄﾞﾙの取得
	Vector3 GetPosition() { return pos; }	// 位置を取得
	Vector3 GetRotation() { return rol; }	// 回転を取得
	Vector3 GetTarget() { return target; }	// 目標を取得
	Vector3 GetHitSpherePositon() { return hitpos; }		// 当たった球の位置の取得
	float GetHitRadiusPositon() { return hitR; }			// 半径の取得
	std::vector<int> GetAnimHandle() { return animHandle; }	// ｱﾆﾒｰｼｮﾝﾊﾝﾄﾞﾙの取得
	ACTION_STATE GetAnimState() { return actionState; }			// 現在のｱﾆﾒｰｼｮﾝの取得
	Vector3 GetFramePosition(int n);						// ﾌﾚｰﾑの座標の取得
	void SetAnimID(int mH, ACTION_STATE no);		// ｱﾆﾒｰｼｮﾝIDのｾｯﾄ

	virtual OBJECT_TYPE GetType() = 0;	// ｵﾌﾞｼﾞｪｸﾄの種類を取得:必ず実装
	//------------------------------------------
	// とりあえずのやつ↓
	//------------------------------------------
	//virtual OBJECT_TYPE GetType() override {}				// ｵﾌﾞｼﾞｪｸﾄの種類を取得

	bool JumpState()		// ｼﾞｬﾝﾌﾟ中
	{
		if (actionState == ACTION_STATE::ACTION_STATE_JUMP)
		{
			true;
		}
		return false;
	}

	float RiseY()
	{
		return moveSpeed.y;
	}

	bool MoveFlag()
	{
		return moveFlag;
	}

	void SetPosY(const float& y)
	{
		pos.y = y;
	}

	void SetMoveSpeedY(const float& y)
	{
		moveSpeed.y = y;
	}

	void SetGravity(const float& g)
	{
		gravity = g;
	}

	bool JumpFlag()
	{
		return jumpFlag;
	}

	Vector3 GetMoveSpeed()
	{
		return moveSpeed;
	}

	void SetPos(const Vector3& p)
	{
		pos = p;
	}

	void SetMoveDir(const Vector3& cameraDir)
	{
		moveDir = cameraDir;
	}
};