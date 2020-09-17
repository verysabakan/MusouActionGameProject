//------------------------------------------------------
// @brief	��ڲ԰�𑀂�
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "ObjectBase.h"

class Player
	:public ObjectBase
{
public:
	Player(int mID , std::vector<int>& aID);	// �ݽ�׸�
	~Player();									// �޽�׸�
	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

	virtual OBJECT_TYPE GetType() override;		// ��޼ު�Ă̎�ނ��擾

private:
	void Behavior();		// ����
	void Animation();		// ��Ұ���

	Vector3 otamesi;
};