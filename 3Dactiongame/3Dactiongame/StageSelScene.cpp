//------------------------------------------------------
// @brief	ｽﾃｰｼﾞ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "SceneManager.h"
#include "StageSelScene.h"

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
	// 処理なし
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
void StageSelScene::Update(const Controller& controll)
{
	
	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (controll.IsPushC(INPUT_TRG))
	{
		// ｹﾞｰﾑ画面に切り替え
		sceneSwitcher->SwitchScene(eScene_Game);
		sceneDateManager->SetStageType(STAGE_SAMPLE);
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void StageSelScene::Render()
{
	DrawString(0,0,"ｽﾃｰｼﾞ選択画面",0xffffff);
}