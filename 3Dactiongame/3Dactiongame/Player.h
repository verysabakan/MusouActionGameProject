//------------------------------------------------------
// @brief	��ڲ԰�𑀂�
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <vector>
#include "ModelBase.h"

// �������ߐ錾
class Controller;

class Player
	:private ModelBase
{
public:
	Player(int mID , std::vector<int>& aID);
	~Player();
	void Initialize();	// ������
	void Finalize();	// �I������
	void Update(const Controller& controll, const Vector3& cameraDir);		// �X�V
	void Render();		// �`��

private:
	void Behavior(const Controller& controll, const Vector3& cameraDir);		// ����
	void Animation();		// �ړ�
};