

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
	void Initialize();	// 初期化処理
	void Finalize();	// 終了処理
	void Update();		// 更新
	void Render();		// 描画
};