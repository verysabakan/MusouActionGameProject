//------------------------------------------------------
// @brief	��݂̊Ǘ�
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <memory>
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
	scene = std::make_shared<TitleScene>(this);
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
void SceneManager::Initialize()
{
	// �׽�ʂ̏�����
	scene->Initialize();
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void SceneManager::Finalize()
{
	// �׽�ʂ̏I������
	scene->Finalize();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void SceneManager::Update(const Controller& controll)
{
	// ���̼�݂�nextScene�ɾ�Ă���Ă�����
	if (nextScene != eScene_None) 
	{

		// ���݂̼�݂̏I���������s��
		scene->Finalize();
		// ؿ���̊J��
		scene.reset();

		// ��݂��Ƃ̏���
		if (nextScene == eScene_Title)
		{
			scene = std::make_shared<TitleScene>(this);
		}
		else if (nextScene == eScene_ModeSel)
		{
			scene = std::make_shared<ModeSelScene>(this);
		}
		else if (nextScene == eScene_CharSel)
		{
			scene = std::make_shared<CharSelScene>(this);
		}
		else if (nextScene == eScene_StageSel)
		{
			scene = std::make_shared<StageSelScene>(this);
		}
		else if (nextScene == eScene_Game)
		{
			scene = std::make_shared<GameScene>(this, GetStageType());
		}

		// ���̼�݂ɍs���Ȃ�
		nextScene = eScene_None;

		// ��݂̏�����
		scene->Initialize();
	}

	// ��݂̍X�V
	scene->Update(controll);
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void SceneManager::Render()
{
	scene->Render();
}

//------------------------------------------------------
// @brief	nextScene�ɼ�݂�ύX����
//------------------------------------------------------
void SceneManager::SwitchScene(eScene nextScene)
{
	this->nextScene = nextScene;
}
