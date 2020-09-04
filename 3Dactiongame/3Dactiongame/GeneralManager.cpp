//------------------------------------------------------
// @brief	ﾏﾈｰｼﾞｬｰを格納するためのﾘｽﾄ
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#include <vector>
#include <array>

#include "GeneralManager.h"
#include "LoadModel.h"
#include "PlayerManager.h"
#include "StageManager.h"
#include "FlexibleCollision.h"

#include "toriaezu.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
GeneralManager::GeneralManager(const STAGE_TYPE& sT)
{
	// ｵﾌﾞｼﾞｪｸﾄを構築、格納
	mgrList = std::make_shared<MANAGER_LIST>();
	AddList(mgrList, std::make_shared<PlayerManager>());
	AddList(mgrList, std::make_shared<StageManager>(sT));
	//AddList(mgrList, std::make_shared<FlexibleCollision>());

	//------------------------------------------------------
	// とりあえずのやつ
	TorimaInitialize();

	//------------------------------------------------------

	/*
	if (!playerMnager) playerMnager = std::make_unique<PlayerManager>();
	if (!stageManager) stageManager = std::make_unique<StageManager>(sT);

	// playerがnullptrでない場合
	if (playerMnager->GetPlayer() != nullptr)
	{
		fCollision = std::make_unique<FlexibleCollision>();

	}
	*/
	//AddList(mgrList, std::make_shared<Player>(playerModel, playerAnim));
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
GeneralManager::~GeneralManager()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void GeneralManager::Initialize()
{
	// 各初期化
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Initialize();
	}
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void GeneralManager::Finalize()
{
	// 各終了処理
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Finalize();
	}
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GeneralManager::Update()
{
	MANAGER_LIST temporaryList(mgrList->size());	// 一時的なﾘｽﾄ
	auto pMgr = std::remove_copy_if(mgrList->begin(), mgrList->end(), temporaryList.begin(),
		[](MANAGER_PTR& mgr) {return !(mgr->GetManagerType(MANAGER_TYPE::PLAYER_MANAGER));});
	auto sMgr = std::remove_copy_if(mgrList->begin(), mgrList->end(), temporaryList.begin(),
		[](MANAGER_PTR& mgr) {return !(mgr->GetManagerType(MANAGER_TYPE::TERRAIN_MANAGER));});

	std::for_each(temporaryList.begin(), pMgr, [&](auto& preyType)
	{
		PlayerManager pM = preyType
	});

	//------------------------------------------------------
	// とりあえずのやつ
	HitCheckStageAndPlayer(playerMnager->GetPlayer(), stageManager->GetStage());

	TorimaUpdate(playerMnager->GetPlayer());
	//------------------------------------------------------

	// 各更新
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Update();
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void GeneralManager::Render()
{
	// 各描画
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Render();
	}

	//------------------------------------------------------
	// とりあえずのやつ
	Draw();
	DrawString(0, 0, "ｹﾞｰﾑ画面", 0xffffff);
	//------------------------------------------------------
}