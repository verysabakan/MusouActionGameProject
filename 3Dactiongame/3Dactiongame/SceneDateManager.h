//------------------------------------------------------
// @brief	��݊Ԃ��ް��Ǘ�
// 2020 6/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"

class SceneDateManager
{
private:
	STAGE_TYPE stageType;	// �ǂ̽ð�ނ�

public:
	SceneDateManager();				// �ݽ�׸�
	virtual ~SceneDateManager();	// �޽�׸�

	void SetStageType(const STAGE_TYPE& type);	// �I�񂾽ð�ނ��
	const STAGE_TYPE GetStageType() const;	// �i�[�����ð�����߂��擾

};
