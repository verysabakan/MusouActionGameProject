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
StageSelScene::StageSelScene(SceneManager* sManager)
	: BaseScene(sManager)
{
	// 処理なし
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
	if (lpController->IsPushD(INPUT_STATE::INPUT_TRG))
	{
		lpSceneDateManager->SetStageType(STAGE_SAMPLE);	// 選んだｽﾃｰｼﾞを保存
		sceneSwitcher->SwitchScene(eScene_Game);		// ｹﾞｰﾑ画面に切り替え
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void StageSelScene::Render()
{
	DS(0,0,"ｽﾃｰｼﾞ選択画面",0xffffff);
}