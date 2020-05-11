//------------------------------------------------------
// @brief	ｼｰﾝの管理
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
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
SceneManager::SceneManager()
	: nextScene(eScene_None)
{
	scene = (BaseScene*) new TitleScene(this);
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
void SceneManager::Update()
{
	// 次のｼｰﾝがnextSceneにｾｯﾄされていたら
	if (nextScene != eScene_None) 
	{
		// 現在のｼｰﾝの終了処理を行う
		scene->Finalize();	
		delete scene;

		// ｼｰﾝごとの処理
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

		// ｼｰﾝの初期化
		scene->Initialize();
	}

	// ｼｰﾝの更新
	scene->Update();
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void SceneManager::Draw()
{
	scene->Draw();
}

//------------------------------------------------------
// @brief	nextSceneにｼｰﾝを変更する
//------------------------------------------------------
void SceneManager::SwitchScene(eScene nextScene)
{
	this->nextScene = nextScene;
}