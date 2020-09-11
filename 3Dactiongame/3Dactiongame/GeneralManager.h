//------------------------------------------------------
// @brief	�Ȱ�ެ����i�[���邽�߂�ؽ�
// 2020 9/3 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"
#include "GMList.h"

// �������ߐ錾
class FlexibleCollision;

class GeneralManager
	:private GMList
{
private:
	std::unique_ptr<FlexibleCollision> fCollision;

public:
	GeneralManager(const STAGE_TYPE& sT);	// �ݽ�׸�
	~GeneralManager();	// �޽�׸�

	void Initialize();	// ������
	void Finalize();	// �I������
	void Update();		// �X�V
	void Render();		// �`��

};

