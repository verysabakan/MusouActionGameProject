//------------------------------------------------------
// @brief	��ڲ԰�ƽð�ނ̓����蔻��
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �������ߐ錾
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
	HitCheckCharAndStage(Player* p, Stage* s);	// �ݽ�׸�
	virtual ~HitCheckCharAndStage();	// �޽�׸�
	
	void HitTerrain();	// �n�`�̓����蔻��

};

