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

class HitCheckCharAndStage
{
private:
	ModelBase* modelBase;
	StageModelBase* stageModelBase;

public:
	HitCheckCharAndStage(Player* p, Stage* s);	// �ݽ�׸�
	virtual ~HitCheckCharAndStage();	// �޽�׸�
	
	void HitTerrain();	// �n�`�̓����蔻��

};

