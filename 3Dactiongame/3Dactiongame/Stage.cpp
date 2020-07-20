//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#include <string>
#include <memory>
#include <DxLib.h>
#include "Stage.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Stage::Stage(const STAGE_TYPE& sT)
{
	std::unique_ptr<LoadStage> loadStage;

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
	// �����Ȃ�
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