//------------------------------------------------------
// @brief	(ｷｬﾗ)ﾓﾃﾞﾙのための基底
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include "ObjectBase.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
ObjectBase::ObjectBase()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
ObjectBase::~ObjectBase()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ｱﾆﾒｰｼｮﾝIDのｾｯﾄ
//------------------------------------------------------
void ObjectBase::SetAnimID(int mH, ACTION_STATE no)
{
	MV1DetachAnim(mH, attachiIndex);
	attachiIndex = MV1AttachAnim(modelHandle, 0, animHandle[static_cast<int>(no)], TRUE);
	totalTime = MV1GetAttachAnimTotalTime(modelHandle, attachiIndex);	// ｱﾆﾒｰｼｮﾝのﾄｰﾀﾙ時間を計測
	playTime = 0.0f;
}

//------------------------------------------------------
// @brief	ﾌﾚｰﾑの座標の取得
//------------------------------------------------------
Vector3 ObjectBase::GetFramePosition(int n)
{
	// 取得したVECTORをVector3として返す
	auto vec = MV1GetFramePosition(modelHandle, n);
	auto vec3 = Vector3(vec.x, vec.y, vec.z);
	return vec3;
}