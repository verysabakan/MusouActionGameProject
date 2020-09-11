//------------------------------------------------------
// @brief	ﾏﾈｰｼﾞｬｰを格納するためのﾘｽﾄ
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>

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
	// 生成
	mgrList = std::make_shared<MANAGER_LIST>();
	AddList(mgrList, std::make_shared<PlayerManager>());
	AddList(mgrList, std::make_shared<StageManager>(sT));

	fCollision = std::make_unique<FlexibleCollision>();

	//------------------------------------------------------
	// とりあえずのやつ
	TorimaInitialize();
	//------------------------------------------------------
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
GeneralManager::~GeneralManager()
{
	// 異常終了のﾁｪｯｸ
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		assert((*i) == NULL);
	}
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
	fCollision->Initialize();
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
		i->reset();
	}
	fCollision->Finalize();

	// ﾘｿｰｽの開放
	fCollision.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GeneralManager::Update()
{
	// 各更新
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Update();	}

	// 全ての更新が終わった後の処理
	for (auto m1 = mgrList->begin(); m1 != mgrList->end(); m1++)
	{
		for (auto m2 = mgrList->begin(); m2 != mgrList->end(); m2++)
		{
			for (auto i = (*m1)->GetObjectList()->begin(); i != (*m1)->GetObjectList()->end(); i++)
			{
				for (auto j = (*m2)->GetObjectList()->begin(); j != (*m2)->GetObjectList()->end(); j++)
				{
					//fCollision->HitCheck((*i), (*j));
					//------------------------------------------------------
					// とりあえずのやつ
					if ((*i)->GetType() == OBJECT_TYPE::OBJECT_TYPE_PLAYER &&
						(*j)->GetType() == OBJECT_TYPE::OBJECT_TYPE_TERRAIN)
					{
						HitCheckStageAndPlayer((*i), (*j));
						TorimaUpdate((*i));
					}
					//------------------------------------------------------
				}
			}
		}
	}
	int f = 0;
	/*
	for (auto m1 = mgrList->begin(); m1 != mgrList->end(); m1++)
	{
		for (auto m2 = mgrList->begin(); m2 != mgrList->end(); m2++)
		{
			for (auto i = (*m1)->GetObjectList()->begin(); i != (*m1)->GetObjectList()->end(); i++)
			{
				for (auto j = (*m2)->GetObjectList()->begin(); j != (*m2)->GetObjectList()->end(); j++)
				{
					//fCollision->HitCheck((*i), (*j));
					//------------------------------------------------------
					// とりあえずのやつ
					if ((*i)->GetType() == OBJECT_TYPE::OBJECT_TYPE_PLAYER &&
						(*j)->GetType() == OBJECT_TYPE::OBJECT_TYPE_TERRAIN)
					{
						HitCheckStageAndPlayer((*i), (*j));
						TorimaUpdate((*i));
					}
					//------------------------------------------------------
				}
			}
		}
	}
	*/
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