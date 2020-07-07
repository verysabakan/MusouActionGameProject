//------------------------------------------------------
// @brief	ﾀｲﾄﾙ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "TitleScene.h"
#include "TitleConstant.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
TitleScene::TitleScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// 生成時の初期化
	Initialize();
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
TitleScene::~TitleScene()
{
	// 異常終了のﾁｪｯｸ
	for (auto i = 0; i < TITLE_PARTS_MAX; i++)
	{
		assert(titleImage[i] == NULL);
	}
	assert(bgImage == NULL);
	assert(pabImage == NULL);
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void TitleScene::Initialize()
{
	// ｸﾞﾗｯﾌｨｸの登録
	titleImage[TITLE_PARTS_EW] = LoadGraph("Image/Title/EW.png");
	titleImage[TITLE_PARTS_EXTREME] = LoadGraph("Image/Title/EXTREME.png");
	titleImage[TITLE_PARTS_WARRIORS] = LoadGraph("Image/Title/WARRIORS.png");
	titleImage[TITLE_PARTS_MARK] = LoadGraph("Image/Title/MARK.png");
	bgImage = LoadGraph("Image/Title/BACKGROUND.png");
	pabImage = LoadGraph("Image/Title/START.png");
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void TitleScene::Finalize()
{
	// 読み込んだ画像の削除
	for (auto i = 0; i < TITLE_PARTS_MAX; i++)
	{
		DeleteGraph(titleImage[i]);
		titleImage[i] = NULL;
	}
	DeleteGraph(bgImage);
	bgImage = NULL;
	DeleteGraph(pabImage);
	pabImage = NULL;
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void TitleScene::Update()
{
	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (lpController.IsPushC(INPUT_TRG))
	{
		// ﾓｰﾄﾞ選択画面に切り替え
		sceneSwitcher->SwitchScene(eScene_ModeSel);
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void TitleScene::Render()
{
	// 画像の描画
	DrawGraph(0, 0, bgImage, true);
	DrawGraph(MARK_POS_X, MARK_POS_Y, titleImage[TITLE_PARTS_MARK], true);
	DrawGraph(EW_POS_X, EW_POS_Y, titleImage[TITLE_PARTS_EW], true);
	DrawGraph(EXTREME_POS_X, EXTREME_POS_Y, titleImage[TITLE_PARTS_EXTREME], true);
	DrawGraph(WARRIORS_POS_X, WARRIORS_POS_Y, titleImage[TITLE_PARTS_WARRIORS], true);
	DrawGraph(START_POS_X, START_POS_Y, pabImage, true);

	DrawString(0, 0, "ﾀｲﾄﾙ画面", 0xffffff);
}