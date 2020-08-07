//------------------------------------------------------
// @brief	Ӱ�ޑI�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "ModeSelScene.h"
#include "Controller.h"

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
void ModeSelScene::Update()
{
	// ��ʂɉf��ʒu�ɂR�c���f�����ړ�
	MV1SetPosition(modelHandle, VGet(320.0f, -300.0f, 600.0f));
	MV1DrawModel(modelHandle);

	// ���ޯ�ޗp��ݐ؂�ւ���:C
	if (CheckHitKey(KEY_INPUT_P))
	{
		sceneSwitcher->SwitchScene(eScene_CharSel);	// ��׸���I����ʂɐ؂�ւ�
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void ModeSelScene::Render()
{
	DrawString(0, 0, "Ӱ�ޑI�����", 0xffffff);
}
