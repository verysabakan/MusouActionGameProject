#pragma once

#include <DxLib.h>
#include "Vector3.h"

class ModelBase
{
protected:
	int model;			// ﾓﾃﾞﾙﾃﾞｰﾀ用
	int modelID;
	Vector3 target;		// 向いている方向
	Vector3 pos;		// XYZ軸方向
	Vector3 rol;		// 回転
	Vector3 scl;		// 大きさ
	Vector3 scale;
	Vector3 hitpos;		// 判定球の中心
	float hitR;			// 判定球の半径
	float dir;
	// ｱﾆﾒｰｼｮﾝ
	int attachiIndex;	// アニメ番号登録
	float totalTime;	// 再生総時間
	float playTime;		// 再生箇所
public:

	ModelBase() {}			// ｺﾝｽﾄﾗｸﾀ
	~ModelBase() {}		// ﾃﾞｽﾄﾗｸﾀ

	virtual void Update(void) = 0;	// 更新:必ず実装
	virtual void Render(void) = 0;	// 描画:必ず実装

	Vector3 GetPosition() { return pos; }	// 位置を取得
	Vector3 GetRotation() { return rol; }	// 回転を取得
	Vector3 GetTarget() { return target; }	// 目標を取得
	Vector3 GetHitSpherePositon() { return hitpos; }	// 当たった球の位置の取得
	float GetHitRadiusPositon() { return hitR; }		// の取得
	int GetAmeID() { return modelID; }					// ｱﾆﾒｰｼｮﾝIDの取得
	Vector3 GetFramePosition(int n)						// ﾌﾚｰﾑの座標の取得
	{ 
		// 取得したVECTORをVector3として返す
		auto vec = MV1GetFramePosition(modelID, n);
		auto vec3 = Vector3(vec.x, vec.y, vec.z);
		return vec3;
	}	
	void SetAnimID(int modelID, int no)					// ｱﾆﾒｰｼｮﾝIDのｾｯﾄ
	{
		//歩く(７番)モーションをセット
		MV1DetachAnim(modelID, attachiIndex);//アニメーションのリセット
		attachiIndex = MV1AttachAnim(modelID, no, -1, false);
		//アニメーションのトータル時間を計測
		totalTime = MV1GetAttachAnimTotalTime(modelID, attachiIndex);
		playTime = 0.0f;
	}
};