//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "PlayerManager.h"
#include "Player.h"
#include "LoadModel.h"
#include "Camera.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
PlayerManager::PlayerManager()
{
	// -------------------------------------------
	// この読み込み方法は後で変更する
	// -------------------------------------------
	int playerModel;
	std::vector<int> playerAnim;
	// 必要なﾃﾞｰﾀの読み込み
	LoadPlayerModelData(playerModel, playerAnim);
	
	// ｵﾌﾞｼﾞｪｸﾄ構築
	objList = std::make_shared<OBJECT_LIST>();
	AddList(objList, std::make_shared<Player>(playerModel, playerAnim));

	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		camera = std::make_unique<Camera>((*i));
	}
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
PlayerManager::~PlayerManager()
{

}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void PlayerManager::Initialize()
{
	// 各初期化処理
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Initialize();
	}
	camera->Initialize();
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void PlayerManager::Finalize()
{
	// 各終了処理、ﾘｿｰｽの開放
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Finalize();
		(*i).reset();
	}
	camera->Finalize();
	camera.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void PlayerManager::Update()
{
	// 各更新処理
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->SetMoveDir(camera->GetCameraDir());
		(*i)->Update();
	}
	camera->Update();
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void PlayerManager::Render()
{
	// 各描画処理
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Render();
	}
	camera->Renderer();
}
