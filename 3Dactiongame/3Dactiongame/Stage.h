//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/3 Ryosuke Iida
//------------------------------------------------------
#pragma once

#include "LoadStage.h"
#include "ObjectBase.h"

class Stage
	: public ObjectBase
{
public:
	Stage(const STAGE_TYPE& sT);	// �ݽ�׸�
	~Stage();	// �޽�׸�

	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

	virtual OBJECT_TYPE GetType() override;		// ��޼ު�Ă̎�ނ��擾
};

