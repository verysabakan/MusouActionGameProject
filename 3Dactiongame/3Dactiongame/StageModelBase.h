//------------------------------------------------------
// @brief	(ｽﾃｰｼﾞ)ﾓﾃﾞﾙのための基底
// 2020 6/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

class StageModelBase
{
protected:
	int modelHandle;			// ﾓﾃﾞﾙのﾊﾝﾄﾞﾙ
	int collisionModelHandle;	// ｺﾘｼﾞｮﾝ用ﾓﾃﾞﾙのﾊﾝﾄﾞﾙ
	int skyModelHandle;			// 空ﾓﾃﾞﾙのﾊﾝﾄﾞﾙ

public:
	StageModelBase();	// ｺﾝｽﾄﾗｸﾀ
	~StageModelBase();	// ﾃﾞｽﾄﾗｸﾀ

	int GetCollisionModelHandle() { return collisionModelHandle; }	// 当たり判定用ﾓﾃﾞﾙﾊﾝﾄﾞﾙの取得
};

