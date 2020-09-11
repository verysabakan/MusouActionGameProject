//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#include <string>
#include <assert.h>
#include <memory>
#include <DxLib.h>
#include "Stage.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Stage::Stage(const STAGE_TYPE& sT)
{
	// ����
	std::unique_ptr<LoadStage> loadStage = std::make_unique<LoadStage>();

	// �ð�ނ̐����Ɏg�����ق�ǂݍ���
	loadStage->LoadStageDate(modelHandle, collisionModelHandle, skyModelHandle, sT);

	// �ǂݍ��񂾂�K�v�Ȃ��Ȃ�̂ŉ��
	loadStage.reset();
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Stage::~Stage()
{
	// �ُ�I��������
	assert(modelHandle == NULL);
	assert(collisionModelHandle == NULL);
	assert(skyModelHandle == NULL);
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void Stage::Initialize()
{
	
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void Stage::Finalize()
{

}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Stage::Update()
{

}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void Stage::Render()
{
	// �X�e�[�W�R�c���f����`��
	MV1DrawModel(modelHandle);

	if (collisionModelHandle)
	{
		// ���ޯ�ޗp
		MV1DrawModelDebug(collisionModelHandle, GetColor(0, 255, 0),
			FALSE, 1.0f, TRUE, FALSE);
	}
}

//------------------------------------------------------
// @brief	��޼ު�Ă̎�ނ��擾
//------------------------------------------------------
OBJECT_TYPE Stage::GetType()
{
	return OBJECT_TYPE::OBJECT_TYPE_TERRAIN;
}
