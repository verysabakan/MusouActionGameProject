//------------------------------------------------------
// @brief	ﾀｲﾄﾙ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include "TitleScene.h"
#include <DxLib.h>

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
TitleScene::TitleScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
TitleScene::~TitleScene()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void TitleScene::Initialize(void)
{
	// ｸﾞﾗｯﾌｨｸの登録
	titleImage[TITLE_PARTS_EW] = LoadGraph("Image/Title/EW.png");
	titleImage[TITLE_PARTS_EXTREME] = LoadGraph("Image/Title/EXTREME.png");
	titleImage[TITLE_PARTS_WARRIORS] = LoadGraph("Image/Title/WARRIORS.png");
	titleImage[TITLE_PARTS_MARK] = LoadGraph("Image/Title/MARK.png");
	bgImage = LoadGraph("Image/Title/BACKGROUND.png");
	pabImage = LoadGraph("Image/Title/STRAT.png");
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void TitleScene::Finalize(void)
{
	// 読み込んだ画像の削除
	for (auto i = 0; i < TITLE_PARTS_MAX; i++)
	{
		DeleteGraph(titleImage[i]);
	}
	DeleteGraph(bgImage);
	DeleteGraph(pabImage);
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void TitleScene::Update(void)
{
	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (CheckHitKey(KEY_INPUT_Q) != 0) {
		// ﾓｰﾄﾞ選択画面に切り替え
		sceneSwitcher->SwitchScene(eScene_ModeSel);
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void TitleScene::Draw(void)
{
	// 画像の描画
	DrawGraph(0, 0, bgImage, true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_MARK], true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_EW], true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_EXTREME], true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_WARRIORS], true);
	DrawGraph(0, 0, pabImage, true);

	DrawString(0, 0, "ﾀｲﾄﾙ画面", 0xffffff);
}