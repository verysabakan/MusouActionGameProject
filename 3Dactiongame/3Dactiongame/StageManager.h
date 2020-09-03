//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "ManagerBase.h"


// �������ߐ錾
class Stage;

class StageManager
	:public ManagerBase
{
private:
	std::unique_ptr<Stage> stage;

public:
	StageManager(const STAGE_TYPE& sT);		// �ݽ�׸�
	~StageManager();	// �޽�׸�

	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

	Stage* GetStage();	// �ð�ނ��擾

	bool GetManagerType(MANAGER_TYPE type);	// ���߂̎擾(�ǂ����߂��m���߂�)
};

