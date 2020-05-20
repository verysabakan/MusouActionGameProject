//------------------------------------------------------
// @brief	���ى��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "TitleScene.h"
#include "TitleConstant.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
TitleScene::TitleScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
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
// @brief	������
//------------------------------------------------------
void TitleScene::Initialize()
{
	// ��ׯ̨��̓o�^
	titleImage[TITLE_PARTS_EW] = LoadGraph("Image/Title/EW.png");
	titleImage[TITLE_PARTS_EXTREME] = LoadGraph("Image/Title/EXTREME.png");
	titleImage[TITLE_PARTS_WARRIORS] = LoadGraph("Image/Title/WARRIORS.png");
	titleImage[TITLE_PARTS_MARK] = LoadGraph("Image/Title/MARK.png");
	bgImage = LoadGraph("Image/Title/BACKGROUND.png");
	pabImage = LoadGraph("Image/Title/START.png");
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void TitleScene::Finalize()
{
	// �ǂݍ��񂾉摜�̍폜
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
// @brief	�X�V
//------------------------------------------------------
void TitleScene::Update(const Controller& controll)
{
	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (CheckHitKey(KEY_INPUT_P) == 1)
	{
		// Ӱ�ޑI����ʂɐ؂�ւ�
		sceneSwitcher->SwitchScene(eScene_ModeSel);
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void TitleScene::Render()
{
	// �摜�̕`��
	DrawGraph(0, 0, bgImage, true);
	DrawGraph(MARK_POS_X, MARK_POS_Y, titleImage[TITLE_PARTS_MARK], true);
	DrawGraph(EW_POS_X, EW_POS_Y, titleImage[TITLE_PARTS_EW], true);
	DrawGraph(EXTREME_POS_X, EXTREME_POS_Y, titleImage[TITLE_PARTS_EXTREME], true);
	DrawGraph(WARRIORS_POS_X, WARRIORS_POS_Y, titleImage[TITLE_PARTS_WARRIORS], true);
	DrawGraph(START_POS_X, START_POS_Y, pabImage, true);

	DrawString(0, 0, "���ى��", 0xffffff);
}