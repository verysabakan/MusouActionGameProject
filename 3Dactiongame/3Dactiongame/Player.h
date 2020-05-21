

#pragma once

class Player 
	:public ModelBase
{
private:
	int newKey;
	int oldKey;
	int trgKey;
public:
	Player(int ID);
	~Player();
	void Initialize();	// ‰Šú‰»ˆ—
	void Finalize();	// I—¹ˆ—
	void Update();		// XV
	void Render();		// •`‰æ
};