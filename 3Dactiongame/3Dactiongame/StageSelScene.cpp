//------------------------------------------------------
// @brief	�ð�ޑI�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "SceneManager.h"
#include "StageSelScene.h"

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
	// �����Ȃ�
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
void StageSelScene::Update(const Controller& controll)
{
	
	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (controll.IsPushC(INPUT_TRG))
	{
		// �ްщ�ʂɐ؂�ւ�
		sceneSwitcher->SwitchScene(eScene_Game);
		sceneDateManager->SetStageType(STAGE_SAMPLE);
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void StageSelScene::Render()
{
	DrawString(0,0,"�ð�ޑI�����",0xffffff);
}