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
//StageSelScene::StageSelScene(ISceneSwitcher* switcher, 
//	SceneDateManager* dateManager)
//	: BaseScene(switcher)
//{
//	// �����Ȃ�
//}

StageSelScene::StageSelScene(SceneManager* sManager)
	: BaseScene((ISceneSwitcher*)sManager)
{
	sceneDateManager = (SceneDateManager*)sManager;
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
	if (lpController.IsPushD(INPUT_TRG))
	{
		sceneDateManager->SetStageType(STAGE_SAMPLE);	// �I�񂾽ð�ނ�ۑ�
		sceneSwitcher->SwitchScene(eScene_Game);		// �ްщ�ʂɐ؂�ւ�
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void StageSelScene::Render()
{
	DrawString(0,0,"�ð�ޑI�����",0xffffff);
}