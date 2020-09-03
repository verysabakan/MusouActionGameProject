//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "LoadStage.h"
#include "StageModelBase.h"

// �������ߐ錾
class StageModelBase;

class Stage
	: public StageModelBase
{
public:
	Stage(const STAGE_TYPE& sT);	// �ݽ�׸�
	~Stage();	// �޽�׸�

	void Initialize();	// ������
	void Finalize();	// �I������
	void Update();		// �X�V
	void Render();		// �`��

};

