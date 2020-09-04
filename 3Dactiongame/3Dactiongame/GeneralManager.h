//------------------------------------------------------
// @brief	�Ȱ�ެ����i�[���邽�߂�ؽ�
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ManagerBase.h"
#include "GMList.h"
#include "StageType.h"

// �������ߐ錾
class PlayerManager;
class StageManager;
class FlexibleCollision;

class GeneralManager
	:private GMList,
	public ManagerBase
{
public:
	GeneralManager(const STAGE_TYPE& sT);	// �ݽ�׸�
	~GeneralManager();	// �޽�׸�

	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��
};

