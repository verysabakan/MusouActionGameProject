//------------------------------------------------------
// @brief	Ӱ�ޑI�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "ModeSelScene.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
ModeSelScene::ModeSelScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
ModeSelScene::~ModeSelScene()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void ModeSelScene::Initialize()
{
	modelHandle = MV1LoadModel("Model/Fukuoka_Prop.fbx");
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void ModeSelScene::Finalize()
{
	MV1DeleteModel(modelHandle);
	modelHandle = NULL;
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void ModeSelScene::Update(const Controller& controll)
{
	// ��ʂɉf��ʒu�ɂR�c���f�����ړ�
	MV1SetPosition(modelHandle, VGet(320.0f, -300.0f, 600.0f));
	MV1DrawModel(modelHandle);

	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (CheckHitKey(KEY_INPUT_O) == 1) {
		// ��׸���I����ʂɐ؂�ւ�
		sceneSwitcher->SwitchScene(eScene_CharSel);
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void ModeSelScene::Render()
{
	DrawString(0, 0, "Ӱ�ޑI�����", 0xffffff);
}
