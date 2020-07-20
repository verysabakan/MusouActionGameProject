//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "Stage.h"
#include "StageManager.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
StageManager::StageManager(const STAGE_TYPE& sT)
{
	// ��޼ު�Ă��\�z
	stage = std::make_unique<Stage>(sT);
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
StageManager::~StageManager()
{
	
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Initialize()
{
	// �e����������
	stage->Initialize();
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Finalize()
{
	// �e�I������
	stage->Finalize();

	// ؿ���̉��
	stage.reset();
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Update()
{
	// �e�X�V����
	stage->Update();
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void StageManager::Render()
{
	// �e�`�揈��
	stage->Render();
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
Stage* StageManager::GetStage()
{
	return stage.get();
}