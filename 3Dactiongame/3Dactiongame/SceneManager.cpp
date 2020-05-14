//------------------------------------------------------
// @brief	��݂̊Ǘ�
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "TitleScene.h"
#include "ModeSelScene.h"
#include "CharSelScene.h"
#include "StageSelScene.h"
#include "GameScene.h"
#include "SceneManager.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
SceneManager::SceneManager()
	: nextScene(eScene_None)
{
	// �ŏ��̼�݂̐����A������
	scene = (BaseScene*) new TitleScene(this);
	scene->Initialize();
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
SceneManager::~SceneManager()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void SceneManager::Initialize(void)
{
	// �׽�ʂ̏�����
	scene->Initialize();
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void SceneManager::Finalize(void)
{
	// �׽�ʂ̏I������
	scene->Finalize();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void SceneManager::Update(void)
{
	// ���̼�݂�nextScene�ɾ�Ă���Ă�����
	if (nextScene != eScene_None) 
	{
		// ���݂̼�݂̏I���������s��
		scene->Finalize();	
		delete scene;

		// ��݂��Ƃ̏���
		if (nextScene == eScene_Title) 
		{
			scene = (BaseScene*) new TitleScene(this);
		}
		else if (nextScene == eScene_ModeSel)
		{
			scene = (BaseScene*) new ModeSelScene(this);
		}
		else if (nextScene == eScene_CharSel)
		{
			scene = (BaseScene*) new CharSelScene(this);
		}
		else if (nextScene == eScene_StageSel)
		{
			scene = (BaseScene*) new StageSelScene(this);
		}
		else if (nextScene == eScene_Game)
		{
			scene = (BaseScene*) new GameScene(this);
		}

		// ��݂̏�����
		scene->Initialize();
	}

	// ��݂̍X�V
	scene->Update();
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void SceneManager::Draw(void)
{
	scene->Draw();
}

//------------------------------------------------------
// @brief	nextScene�ɼ�݂�ύX����
//------------------------------------------------------
void SceneManager::SwitchScene(eScene nextScene)
{
	this->nextScene = nextScene;
}