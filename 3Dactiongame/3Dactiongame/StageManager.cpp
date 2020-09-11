//------------------------------------------------------
// @brief	ｽﾃｰｼﾞの管理
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#include "Stage.h"
#include "StageManager.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
StageManager::StageManager(const STAGE_TYPE& sT)
{
	// ｵﾌﾞｼﾞｪｸﾄを構築
	objList = std::make_shared<OBJECT_LIST>();
	AddList(objList, std::make_shared<Stage>(sT));
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
StageManager::~StageManager()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void StageManager::Initialize()
{
	// 各初期化処理
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Initialize();
	}
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void StageManager::Finalize()
{
	// 各終了処理、ﾘｿｰｽの開放
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Finalize();
		(*i).reset();
	}
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void StageManager::Update()
{
	// 各更新処理
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Update();
	}
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void StageManager::Render()
{
	// 各描画処理
	for (auto i = objList->begin(); i != objList->end(); i++)
	{
		(*i)->Render();
	}
}
