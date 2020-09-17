//------------------------------------------------------
// @brief	���ى��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "TitleScene.h"
#include "TitleConstant.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
TitleScene::TitleScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// �������̏�����
	Initialize();
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
TitleScene::~TitleScene()
{
	// �ُ�I��������
	for (auto i = 0; i < TITLE_PARTS_MAX; i++)
	{
		assert(titleImage[i] == NULL);
	}
	assert(bgImage == NULL);
	assert(pabImage == NULL);
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
void TitleScene::Update()
{
	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (lpController->IsPushD(INPUT_STATE::INPUT_TRG))
	{
		//------------------------------------------------------
		// �Ƃ肠�����̂��
		// �I�񂾽ð�ނ�ۑ�
		lpSceneDateManager->SetStageType(STAGE_SAMPLE);
		sceneSwitcher->SwitchScene(eScene_Game);
		//------------------------------------------------------

		// Ӱ�ޑI����ʂɐ؂�ւ�
		//sceneSwitcher->SwitchScene(eScene_ModeSel);
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void TitleScene::Render()
{
	// �摜�̕`��
	DrawGraph(0, 0, bgImage, true);
	DrawGraph(TitleCon::MARK_POS_X, TitleCon::MARK_POS_Y, titleImage[TITLE_PARTS_MARK], true);
	DrawGraph(TitleCon::EW_POS_X, TitleCon::EW_POS_Y, titleImage[TITLE_PARTS_EW], true);
	DrawGraph(TitleCon::EXTREME_POS_X, TitleCon::EXTREME_POS_Y, titleImage[TITLE_PARTS_EXTREME], true);
	DrawGraph(TitleCon::WARRIORS_POS_X, TitleCon::WARRIORS_POS_Y, titleImage[TITLE_PARTS_WARRIORS], true);
	DrawGraph(TitleCon::START_POS_X, TitleCon::START_POS_Y, pabImage, true);

	DS(0, 0, "���ى��", 0xffffff);
}