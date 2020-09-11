//------------------------------------------------------
// @brief	�ްщ��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "GameScene.h"
#include "Controller.h"
#include "GeneralManager.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher, const STAGE_TYPE& sT)
	: BaseScene(switcher)
{
	// ����
	generalManager = std::make_unique<GeneralManager>(sT);
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
GameScene::~GameScene()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Initialize()
{
	// �e����������
	generalManager->Initialize();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Finalize()
{
	// �e�I������
	generalManager->Finalize();

	// ؿ���̊J��
	generalManager.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameScene::Update()
{
	// �e�X�V����
	generalManager->Update();
	
	// ���ޯ�ޗp��ݐ؂�ւ���:Q
	if (lpController.IsPushD(INPUT_TRG))
	{
		sceneSwitcher->SwitchScene(eScene_Title);	// ���ى�ʂɐ؂�ւ�
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameScene::Render()
{
	// �e�`�揈��
	generalManager->Render();
}
