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
	
	// ｵﾌﾞｼﾞｪｸﾄ生成
	objList = std::make_shared<OBJECT_LIST>();
	AddList(objList, std::make_shared<Player>(playerModel, playerAnim));

	camera = std::make_unique<Camera>(GetPlayer());
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
	// 各終了処、ﾘｿｰｽの開放
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
	SetPlayerMoveDir(camera->GetCameraDir());
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
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

//------------------------------------------------------
// @brief	ObjectBaseの取得
//			このままだと一人プレイしかできないので
//			複数人でできるようにする
//------------------------------------------------------
ModelBase* PlayerManager::GetPlayer()
{
	return dynamic_cast<ModelBase*>(objList->begin()->get());
}

//------------------------------------------------------
// @brief	各ｶﾒﾗからのﾌﾟﾚｲﾔｰの動く方向の受け渡し処理
//------------------------------------------------------
void PlayerManager::SetPlayerMoveDir(const Vector3& cameraDir)
{
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->SetMoveDir(cameraDir);
	}
}

//------------------------------------------------------
// @brief	ﾀｲﾌﾟの取得(どのﾀｲﾌﾟか確かめる)
//------------------------------------------------------
bool PlayerManager::GetManagerType(MANAGER_TYPE type)
{
	return (type == MANAGER_TYPE::PLAYER_MANAGER);
}