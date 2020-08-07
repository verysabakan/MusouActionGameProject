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
PlayerManager::PlayerManager(const WEAK_LIST& weakList)
{
	// -------------------------------------------
	// この読み込み方法は後で変更する
	// -------------------------------------------
	int playerModel;
	std::vector<int> playerAnim;
	// 必要なﾃﾞｰﾀの読み込み
	LoadPlayerModelData(playerModel, playerAnim);

	// ｵﾌﾞｼﾞｪｸﾄ生成
	player = std::make_unique<Player>(playerModel, playerAnim);
	//OBJECT_PTR ii = std::make_unique<Player>(playerModel, playerAnim);
	//AddList() (weakList, );
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
	player->Initialize();
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void PlayerManager::Finalize()
{
	// 各終了処理
	player->Finalize();

	// ﾘｿｰｽの開放
	player.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void PlayerManager::Update(const Vector3& cameraDir)
{
	// 各更新処理
	player->Update(cameraDir);
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void PlayerManager::Render()
{
	player->Render();
}

//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰの基盤を取得
//------------------------------------------------------
ModelBase* PlayerManager::GetPlayer()
{
	return reinterpret_cast<ModelBase*>(player.get());
}