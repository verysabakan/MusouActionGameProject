//------------------------------------------------------
// @brief	��ڲ԰�̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"

// �������ߐ錾
class Player;
class Controller;
class Camera;

class PlayerManager
{
private:
	std::unique_ptr<Player> player;

public:
	PlayerManager();	// �ݽ�׸�
	~PlayerManager();	// �޽�׸�

	void Initialize();	// ������
	void Finalize();	// �I������
	void Update(const Controller& controll, const Vector3& cameraDir);		// �X�V
	void Render();	// �`��

	Player* GetPlayer();	// ��ڲ԰���擾
};

