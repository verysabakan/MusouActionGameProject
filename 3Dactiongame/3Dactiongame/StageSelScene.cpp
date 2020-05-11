//------------------------------------------------------
// @brief	ｽﾃｰｼﾞ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include "StageSelScene.h"
#include <DxLib.h>

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
StageSelScene::StageSelScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
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
	if (CheckHitKey(KEY_INPUT_Q) != 0) {
		// ｹﾞｰﾑ画面に切り替え
		sceneSwitcher->SwitchScene(eScene_Game);
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void StageSelScene::Draw()
{
	DrawString(0,0,"ｽﾃｰｼﾞ選択画面",0xffffff);
}