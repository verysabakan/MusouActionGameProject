//------------------------------------------------------
// @brief	��ڲ԰�𑀂�
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <vector>
#include "ModelBase.h"

class Player
	:public ModelBase
{
public:
	Player(int mID , std::vector<int>& aID);	// �ݽ�׸�
	~Player();									// �޽�׸�
	virtual void Initialize();	// ������
	virtual void Finalize();	// �I������
	virtual void Update();		// �X�V
	virtual void Render();		// �`��

	virtual ObjectType GetType() final;		// ��޼ު�Ă̎�ނ��擾

private:
	void Behavior();		// ����
	void Animation();		// ��Ұ���
};