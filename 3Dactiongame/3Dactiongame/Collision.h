//------------------------------------------------------
// @brief	�����蔻��
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>

// �������ߐ錾

class Collision
{
private:

public:
	Collision();		// �ݽ�׸�
	~Collision();	// �޽�׸�

	void Initialize();	// ������
	void Finalize();	// �I������
	void Update();		// �X�V
	// void Render();	// �`��

};

