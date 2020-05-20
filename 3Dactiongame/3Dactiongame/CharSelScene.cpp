//------------------------------------------------------
// @brief	��׸���I�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "CharSelScene.h"
//#include "Controller.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
CharSelScene::CharSelScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
CharSelScene::~CharSelScene()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void CharSelScene::Update(const Controller& controll)
{
	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (CheckHitKey(KEY_INPUT_I) == 1) {
		// �ð�ޑI����ʂɐ؂�ւ�
		sceneSwitcher->SwitchScene(eScene_StageSel);
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void CharSelScene::Render()
{
	DrawString(0, 0, "��׸���I�����", 0xffffff);
}