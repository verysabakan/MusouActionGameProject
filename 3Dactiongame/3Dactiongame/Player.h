

#pragma once

class Player :public ModelBase
{

private:
	int newKey;
	int oldKey;
	int trgKey;
public:
	Player(int ID);
	~Player();
	void Initialize();	// ����������
	void Finalize();	// �I������
	void Update();		// �X�V
	void Render();		// �`��
};