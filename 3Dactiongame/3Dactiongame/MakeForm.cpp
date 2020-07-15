//------------------------------------------------------
// @brief	当たり判定を行う形を形成する
// 2020 7/14 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "MakeForm.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
MakeForm::MakeForm()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
MakeForm::~MakeForm()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	当たり判定の情報からｶﾌﾟｾﾙを形成する2座標の取得
// @param	HitInfo	当たり判定情報のアドレス
// @param	HitInfo	当たり判定を行うキャラクターの座標のアドレス
// @param	HitInfo	計算後のカプセルの座標を格納するアドレス
// @return	押されていればtrue
//------------------------------------------------------
void GetHitCapsulePos(const VECTOR* Position, VECTOR* CapsulePosition1, VECTOR* CapsulePosition2)
{
	*CapsulePosition1 = *CapsulePosition2 = VAdd(*Position, VECTOR{ 0.0f, 105.0f, 0.0f });

	CapsulePosition1->y -= 10.0f / 2.0f;
	CapsulePosition2->y += 10.0f / 2.0f;
}


