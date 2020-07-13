//------------------------------------------------------
// @brief	(·¬×)ÓÃŞÙ‚Ì‚½‚ß‚ÌŠî’ê
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include "ModelBase.h"

//------------------------------------------------------
// @brief	ºİ½Ä×¸À
//------------------------------------------------------
ModelBase::ModelBase()
{
	// ˆ—‚È‚µ
}

//------------------------------------------------------
// @brief	ÃŞ½Ä×¸À
//------------------------------------------------------
ModelBase::~ModelBase()
{
	// ˆ—‚È‚µ
}

//------------------------------------------------------
// @brief	±ÆÒ°¼®İID‚Ì¾¯Ä
//------------------------------------------------------
void ModelBase::SetAnimID(int mH, int no)
{
	MV1DetachAnim(mH, attachiIndex);
	attachiIndex = MV1AttachAnim(modelHandle, 0, animHandle[no], TRUE);
	totalTime = MV1GetAttachAnimTotalTime(modelHandle, attachiIndex);	// ±ÆÒ°¼®İ‚ÌÄ°ÀÙŠÔ‚ğŒv‘ª
	playTime = 0.0f;
}

//------------------------------------------------------
// @brief	ÌÚ°Ñ‚ÌÀ•W‚Ìæ“¾
//------------------------------------------------------
Vector3 ModelBase::GetFramePosition(int n)
{
	// æ“¾‚µ‚½VECTOR‚ğVector3‚Æ‚µ‚Ä•Ô‚·
	auto vec = MV1GetFramePosition(modelHandle, n);
	auto vec3 = Vector3(vec.x, vec.y, vec.z);
	return vec3;
}