//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚Æ½Ã°¼Ş‚Ì“–‚½‚è”»’è
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ÌßÛÄÀ²ÌßéŒ¾
class Player;
class Stage;
class ModelBase;
class StageModelBase;
class MakeForm;

class HitCheckCharAndStage
{
private:
	ModelBase* model;
	StageModelBase* stage;
	MakeForm* makeForm;
	
public:
	HitCheckCharAndStage(Player* p, Stage* s);	// ºİ½Ä×¸À
	virtual ~HitCheckCharAndStage();	// ÃŞ½Ä×¸À
	
	void HitTerrain();	// ’nŒ`‚Ì“–‚½‚è”»’è

};

