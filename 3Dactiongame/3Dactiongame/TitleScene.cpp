//------------------------------------------------------
// @brief	¿≤ƒŸâÊñ 
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "TitleScene.h"
#include "TitleConstant.h"

//------------------------------------------------------
// @brief	∫›Ωƒ◊∏¿
//------------------------------------------------------
TitleScene::TitleScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// èàóùÇ»Çµ
}

//------------------------------------------------------
// @brief	√ﬁΩƒ◊∏¿
//------------------------------------------------------
TitleScene::~TitleScene()
{
	for (auto i = 0; i < TITLE_PARTS_MAX; i++)
	{
		assert(titleImage[i] == NULL);
		assert(bgImage == NULL);
		assert(pabImage == NULL);
	}
}

//------------------------------------------------------
// @brief	èâä˙âª
//------------------------------------------------------
void TitleScene::Initialize()
{
	// ∏ﬁ◊ØÃ®∏ÇÃìoò^
	titleImage[TITLE_PARTS_EW] = LoadGraph("Image/Title/EW.png");
	titleImage[TITLE_PARTS_EXTREME] = LoadGraph("Image/Title/EXTREME.png");
	titleImage[TITLE_PARTS_WARRIORS] = LoadGraph("Image/Title/WARRIORS.png");
	titleImage[TITLE_PARTS_MARK] = LoadGraph("Image/Title/MARK.png");
	bgImage = LoadGraph("Image/Title/BACKGROUND.png");
	pabImage = LoadGraph("Image/Title/START.png");
}

//------------------------------------------------------
// @brief	èIóπèàóù
//------------------------------------------------------
void TitleScene::Finalize()
{
	// ì«Ç›çûÇÒÇæâÊëúÇÃçÌèú
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
// @brief	çXêV
//------------------------------------------------------
void TitleScene::Update(const Controller& controll)
{
	// √ﬁ ﬁØ∏ﬁópº∞›êÿÇËë÷Ç¶∑∞:Q
	if (CheckHitKey(KEY_INPUT_P) == 1)
	{
		// ”∞ƒﬁëIëâÊñ Ç…êÿÇËë÷Ç¶
		sceneSwitcher->SwitchScene(eScene_ModeSel);
	}
}

//------------------------------------------------------
// @brief	ï`âÊ
//------------------------------------------------------
void TitleScene::Render()
{
	// âÊëúÇÃï`âÊ
	DrawGraph(0, 0, bgImage, true);
	DrawGraph(MARK_POS_X, MARK_POS_Y, titleImage[TITLE_PARTS_MARK], true);
	DrawGraph(EW_POS_X, EW_POS_Y, titleImage[TITLE_PARTS_EW], true);
	DrawGraph(EXTREME_POS_X, EXTREME_POS_Y, titleImage[TITLE_PARTS_EXTREME], true);
	DrawGraph(WARRIORS_POS_X, WARRIORS_POS_Y, titleImage[TITLE_PARTS_WARRIORS], true);
	DrawGraph(START_POS_X, START_POS_Y, pabImage, true);

	DrawString(0, 0, "¿≤ƒŸâÊñ ", 0xffffff);
}