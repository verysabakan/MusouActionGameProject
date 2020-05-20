//------------------------------------------------------
// @brief	ｷｬﾗｸﾀｰ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "CharSelScene.h"
//#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
CharSelScene::CharSelScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
CharSelScene::~CharSelScene()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void CharSelScene::Update(const Controller& controll)
{
	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (CheckHitKey(KEY_INPUT_I) == 1) {
		// ｽﾃｰｼﾞ選択画面に切り替え
		sceneSwitcher->SwitchScene(eScene_StageSel);
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void CharSelScene::Render()
{
	DrawString(0, 0, "ｷｬﾗｸﾀｰ選択画面", 0xffffff);
}