//------------------------------------------------------
// @brief	��ڲ԰�𑀂�
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <vector>
#include "ModelBase.h"

class Player
	:private ModelBase
{
public:
	Player(int mID , std::vector<int>& aID);
	~Player();
	void Initialize();	// ������
	void Finalize();	// �I������
	void Update(const Vector3& cameraDir);		// �X�V
	void Render();		// �`��

	virtual ObjectType GetType() final;		// ��޼ު�Ă̎�ނ��擾

private:
	void Behavior(const Vector3& cameraDir);		// ����
	void Animation();		// �ړ�
};