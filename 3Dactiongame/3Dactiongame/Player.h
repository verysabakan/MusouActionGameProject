

#pragma once

// ÌßÛÄÀ²ÌßéŒ¾

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
	void Initialize();	// ‰Šú‰»ˆ—
	void Finalize();	// I—¹ˆ—
	void Update();		// XV
	void Render();		// •`‰æ
};