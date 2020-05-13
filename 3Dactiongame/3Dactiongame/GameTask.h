//------------------------------------------------------
// @brief	ｹﾞｰﾑ自体の初期化、ﾌﾛｰ、終了
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class SceneManager;

class GameTask
{
public:
	GameTask();
	~GameTask();
	
	int Initialize(void);	// 初期化
	void Finalize(void);	// 終了処理
	void Update(void);		// 更新
	void Draw(void);		// 更新

private:
	SceneManager* sceneManager;
};

