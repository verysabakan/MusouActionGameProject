//------------------------------------------------------
// @brief	��݊Ԃ��ް��Ǘ�
// 2020 6/17 Ryosuke Iida
//------------------------------------------------------

#include "SceneDateManager.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
SceneDateManager::SceneDateManager()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
SceneDateManager::~SceneDateManager()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�I�񂾽ð�ނ��
//------------------------------------------------------
void SceneDateManager::SetStageType(const STAGE_TYPE& type)
{
	stageType = type;
}

//------------------------------------------------------
// @brief	�i�[�����ð�����߂��擾
//------------------------------------------------------
const STAGE_TYPE SceneDateManager::GetStageType() const
{
	return stageType;
}