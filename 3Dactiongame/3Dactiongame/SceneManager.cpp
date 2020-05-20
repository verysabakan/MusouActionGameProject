//------------------------------------------------------
// @brief	ｼｰﾝの管理
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
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
SceneManager::SceneManager()
	: nextScene(eScene_None)
{
	// 最初のｼｰﾝの生成、初期化
	scene = std::make_shared<TitleScene>(this);
	scene->Initialize();
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
SceneManager::~SceneManager()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void SceneManager::Initialize()
{
	// ｸﾗｽ別の初期化
	scene->Initialize();
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void SceneManager::Finalize()
{
	// ｸﾗｽ別の終了処理
	scene->Finalize();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void SceneManager::Update(const Controller& controll)
{
	// 次のｼｰﾝがnextSceneにｾｯﾄされていたら
	if (nextScene != eScene_None) 
	{
		// 現在のｼｰﾝの終了処理を行う
		scene->Finalize();

		// ｼｰﾝごとの処理
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
			scene = std::make_shared<GameScene>(this);
		}

		// ｼｰﾝの初期化
		scene->Initialize();
	}

	// ｼｰﾝの更新
	scene->Update(controll);

	//std::shared_ptr<TitleScene>;
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void SceneManager::Render()
{
	scene->Render();
}

//------------------------------------------------------
// @brief	nextSceneにｼｰﾝを変更する
//------------------------------------------------------
void SceneManager::SwitchScene(eScene nextScene)
{
	this->nextScene = nextScene;
}