

#pragma once

// �������ߐ錾

class Player 
	:public ModelBase
{
private:
	int newKey;
	int oldKey;
	int trgKey;
public:
	Player(int mID , std::vector<int>& aID);
	~Player();
	void Initialize();	// ����������
	void Finalize();	// �I������
	void Update();		// �X�V
	void Render();		// �`��
};