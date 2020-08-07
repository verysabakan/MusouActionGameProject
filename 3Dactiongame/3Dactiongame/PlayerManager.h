//------------------------------------------------------
// @brief	��ڲ԰�̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"
#include "AddList.h"

// �������ߐ錾
class Player;
class Camera;
class ModelBase;

class PlayerManager
{
private:
	std::unique_ptr<Player> player;

public:
	PlayerManager(const WEAK_LIST& weakList);	// �ݽ�׸�
	~PlayerManager();	// �޽�׸�

	void Initialize();	// ������
	void Finalize();						// �I������
	void Update(const Vector3& cameraDir);	// �X�V
	void Render();							// �`��

	ModelBase* GetPlayer();	// ��ڲ԰���擾

};

