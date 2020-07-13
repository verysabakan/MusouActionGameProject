//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰとｽﾃｰｼﾞの当たり判定
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class Player;
class Stage;
class ModelBase;
class StageModelBase;

class HitCheckCharAndStage
{
private:
	ModelBase* model;
	StageModelBase* stage;

public:
	HitCheckCharAndStage(Player* p, Stage* s);	// ｺﾝｽﾄﾗｸﾀ
	virtual ~HitCheckCharAndStage();	// ﾃﾞｽﾄﾗｸﾀ
	
	void HitTerrain();	// 地形の当たり判定

};

