//------------------------------------------------------
// @brief	�Ȱ�ެ����i�[���邽�߂�ؽ�
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
// @brief	�ݽ�׸�
//------------------------------------------------------
GeneralManager::GeneralManager(const STAGE_TYPE& sT)
{
	// ��޼ު�Ă��\�z�A�i�[
	mgrList = std::make_shared<MANAGER_LIST>();
	AddList(mgrList, std::make_shared<PlayerManager>());
	AddList(mgrList, std::make_shared<StageManager>(sT));
	//AddList(mgrList, std::make_shared<FlexibleCollision>());

	//------------------------------------------------------
	// �Ƃ肠�����̂��
	TorimaInitialize();

	//------------------------------------------------------

	/*
	if (!playerMnager) playerMnager = std::make_unique<PlayerManager>();
	if (!stageManager) stageManager = std::make_unique<StageManager>(sT);

	// player��nullptr�łȂ��ꍇ
	if (playerMnager->GetPlayer() != nullptr)
	{
		fCollision = std::make_unique<FlexibleCollision>();

	}
	*/
	//AddList(mgrList, std::make_shared<Player>(playerModel, playerAnim));
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
GeneralManager::~GeneralManager()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void GeneralManager::Initialize()
{
	// �e������
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Initialize();
	}
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void GeneralManager::Finalize()
{
	// �e�I������
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Finalize();
	}
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GeneralManager::Update()
{
	MANAGER_LIST temporaryList(mgrList->size());	// �ꎞ�I��ؽ�
	auto pMgr = std::remove_copy_if(mgrList->begin(), mgrList->end(), temporaryList.begin(),
		[](MANAGER_PTR& mgr) {return !(mgr->GetManagerType(MANAGER_TYPE::PLAYER_MANAGER));});
	auto sMgr = std::remove_copy_if(mgrList->begin(), mgrList->end(), temporaryList.begin(),
		[](MANAGER_PTR& mgr) {return !(mgr->GetManagerType(MANAGER_TYPE::TERRAIN_MANAGER));});

	std::for_each(temporaryList.begin(), pMgr, [&](auto& preyType)
	{
		PlayerManager pM = preyType
	});

	//------------------------------------------------------
	// �Ƃ肠�����̂��
	HitCheckStageAndPlayer(playerMnager->GetPlayer(), stageManager->GetStage());

	TorimaUpdate(playerMnager->GetPlayer());
	//------------------------------------------------------

	// �e�X�V
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Update();
	}
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GeneralManager::Render()
{
	// �e�`��
	for (auto i = mgrList->begin(); i != mgrList->end(); i++)
	{
		(*i)->Render();
	}

	//------------------------------------------------------
	// �Ƃ肠�����̂��
	Draw();
	DrawString(0, 0, "�ްщ��", 0xffffff);
	//------------------------------------------------------
}