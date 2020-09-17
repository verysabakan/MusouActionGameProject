//------------------------------------------------------
// @brief	�ð�ޑI�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "SceneManager.h"
#include "StageSelScene.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
StageSelScene::StageSelScene(SceneManager* sManager)
	: BaseScene(sManager)
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
StageSelScene::~StageSelScene()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void StageSelScene::Update()
{
	
	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (lpController->IsPushD(INPUT_STATE::INPUT_TRG))
	{
		lpSceneDateManager->SetStageType(STAGE_SAMPLE);	// �I�񂾽ð�ނ�ۑ�
		sceneSwitcher->SwitchScene(eScene_Game);		// �ްщ�ʂɐ؂�ւ�
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void StageSelScene::Render()
{
	DS(0,0,"�ð�ޑI�����",0xffffff);
}