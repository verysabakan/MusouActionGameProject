//------------------------------------------------------
// @brief	ｽﾃｰｼﾞ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "SceneManager.h"
#include "StageSelScene.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
//StageSelScene::StageSelScene(ISceneSwitcher* switcher, 
//	SceneDateManager* dateManager)
//	: BaseScene(switcher)
//{
//	// 処理なし
//}

StageSelScene::StageSelScene(SceneManager* sManager)
	: BaseScene((ISceneSwitcher*)sManager)
{
	sceneDateManager = (SceneDateManager*)sManager;
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
StageSelScene::~StageSelScene()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void StageSelScene::Update()
{
	
	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (lpController.IsPushC(INPUT_TRG))
	{
		sceneDateManager->SetStageType(STAGE_SAMPLE);	// 選んだｽﾃｰｼﾞを保存
		sceneSwitcher->SwitchScene(eScene_Game);		// ｹﾞｰﾑ画面に切り替え
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void StageSelScene::Render()
{
	DrawString(0,0,"ｽﾃｰｼﾞ選択画面",0xffffff);
}