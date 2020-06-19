//------------------------------------------------------
// @brief	(ｷｬﾗ)ﾓﾃﾞﾙのための基底
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include "ModelBase.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
ModelBase::ModelBase()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
ModelBase::~ModelBase()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ｱﾆﾒｰｼｮﾝIDのｾｯﾄ
//------------------------------------------------------
void ModelBase::SetAnimID(int mH, int no)
{
	MV1DetachAnim(mH, attachiIndex);
	attachiIndex = MV1AttachAnim(modelHandle, 0, animHandle[no], TRUE);
	// ｱﾆﾒｰｼｮﾝのﾄｰﾀﾙ時間を計測
	totalTime = MV1GetAttachAnimTotalTime(modelHandle, attachiIndex);
	playTime = 0.0f;
}

//------------------------------------------------------
// @brief	ﾌﾚｰﾑの座標の取得
//------------------------------------------------------
Vector3 ModelBase::GetFramePosition(int n)
{
	// 取得したVECTORをVector3として返す
	auto vec = MV1GetFramePosition(modelHandle, n);
	auto vec3 = Vector3(vec.x, vec.y, vec.z);
	return vec3;
}