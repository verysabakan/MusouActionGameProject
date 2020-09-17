//------------------------------------------------------
// @brief	��݊Ԃ��ް��Ǘ�
// 2020 6/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"
#include "Singleton.h"

// ��`
#define lpSceneDateManager SceneDateManager::Instance()

class SceneDateManager
	:public Singleton<SceneDateManager>
{
private:
	STAGE_TYPE stageType;	// �ǂ̽ð�ނ�

public:
	void SetStageType(const STAGE_TYPE& type);	// �I�񂾽ð�ނ��
	const STAGE_TYPE GetStageType() const;	// �i�[�����ð�����߂��擾

private:
	SceneDateManager();				// �ݽ�׸�
	friend Singleton<SceneDateManager>;	// ����޸׽
	~SceneDateManager();	// �޽�׸�

};
