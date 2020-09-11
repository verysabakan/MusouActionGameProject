//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ManagerBase.h"

class StageManager
	:public ManagerBase
{
public:
	StageManager(const STAGE_TYPE& sT);		// �ݽ�׸�
	~StageManager();	// �޽�׸�

	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

};

