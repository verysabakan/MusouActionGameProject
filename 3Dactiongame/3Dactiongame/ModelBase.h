//------------------------------------------------------
// @brief	(ｷｬﾗ)ﾓﾃﾞﾙのための基底
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <DxLib.h>
#include <vector>
#include "Vector3.h"

class ModelBase
{
protected:
	// 現在のｱﾆﾒｰｼｮﾝの状態、M:移動
	enum ANIM_STATE
	{
		ANIM_DEAD,
		ANIM_DOWN,
		ANIM_DAMAGE,
		ANIM_STUN,
		ANIM_JUMP,
		ANIM_SKILL1,
		ANIM_SKILL2,
		ANIM_SKILL3,
		ANIM_ATTACK1,
		ANIM_ATTACK2,
		ANIM_BROCK,
		ANIM_WALK,
		ANIM_RUN,
		ANIM_STANCE
	};

	ANIM_STATE animState;		// 現在のﾌﾟﾚｲﾔｰの状態
	ANIM_STATE oldAnimState;	// 前のﾌﾟﾚｲﾔｰの状態

	int modelHandle;				// ﾓﾃﾞﾙﾃﾞｰﾀ用
	std::vector<int> animHandle;	// ｱﾆﾒｰｼｮﾝﾃﾞｰﾀ用
	Vector3 target;		// 向いている方向
	Vector3 pos;		// XYZ軸方向
	Vector3 rol;		// 回転
	Vector3 scl;		// 大きさ
	Vector3 hitpos;		// 判定球の中心
	float hitR;			// 判定球の半径
	// ｱﾆﾒｰｼｮﾝ
	int attachiIndex;	// ｱﾆﾒ番号登録
	float totalTime;	// 再生総時間
	float playTime;		// 再生箇所
	Vector3 moveSpeed;	// 移動速度

	void SetAnimID(int mH, int no);		// ｱﾆﾒｰｼｮﾝIDのｾｯﾄ
	
public:
	ModelBase();			// ｺﾝｽﾄﾗｸﾀ
	~ModelBase();			// ﾃﾞｽﾄﾗｸﾀ

	Vector3 GetPosition() { return pos; }	// 位置を取得
	Vector3 GetRotation() { return rol; }	// 回転を取得
	Vector3 GetTarget() { return target; }	// 目標を取得
	Vector3 GetHitSpherePositon() { return hitpos; }	// 当たった球の位置の取得
	float GetHitRadiusPositon() { return hitR; }		// 半径の取得
	std::vector<int> GetAnimHandle() { return animHandle; }	// ｱﾆﾒｰｼｮﾝﾊﾝﾄﾞﾙの取得
	ANIM_STATE GetAnimState() { return animState; }			// 現在の状態の取得
	

	Vector3 GetFramePosition(int n);					// ﾌﾚｰﾑの座標の取得

	//------------------------------------------
	// とりあえずのやつ↓
	//------------------------------------------
	bool JumpState()		// ｼﾞｬﾝﾌﾟ中
	{
		if (animState = ANIM_JUMP)
		{
			true;
		}
		return false;
	}

	float RiseY()
	{
		return moveSpeed.y;
	}

	void SetPosY(const float& y)
	{
		pos.y = y;
	}
};