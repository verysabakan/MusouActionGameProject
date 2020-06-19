//------------------------------------------------------
// @brief	�����蔻��
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>

// �������ߐ錾
class Player;
class Stage;
class HitCheckCharAndStage;

class Collider
{
private:
	Player* player;
	Stage* stage;
	std::unique_ptr<HitCheckCharAndStage> hcPlayerAndStage;

public:
	Collider(Player* p, Stage* s);		// �ݽ�׸�
	~Collider();	// �޽�׸�

	void Initialize();	// ������
	void Finalize();	// �I������
	void Update();		// �X�V
	// void Render();	// �`��

};

