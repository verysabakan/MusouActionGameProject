//------------------------------------------------------
// @brief	���ى��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include "TitleScene.h"
#include <DxLib.h>

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
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void TitleScene::Initialize(void)
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
void TitleScene::Finalize(void)
{
	// �ǂݍ��񂾉摜�̍폜
	for (auto i = 0; i < TITLE_PARTS_MAX; i++)
	{
		DeleteGraph(titleImage[i]);
	}
	DeleteGraph(bgImage);
	DeleteGraph(pabImage);
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void TitleScene::Update(void)
{
	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (CheckHitKey(KEY_INPUT_Q) != 0) {
		// Ӱ�ޑI����ʂɐ؂�ւ�
		sceneSwitcher->SwitchScene(eScene_ModeSel);
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void TitleScene::Draw(void)
{
	// �摜�̕`��
	DrawGraph(0, 0, bgImage, true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_MARK], true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_EW], true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_EXTREME], true);
	DrawGraph(0, 0, titleImage[TITLE_PARTS_WARRIORS], true);
	DrawGraph(0, 0, pabImage, true);

	DrawString(0, 0, "���ى��", 0xffffff);
}