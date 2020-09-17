//------------------------------------------------------
// @brief	ｹﾞｰﾑ自体の初期化、ﾌﾛｰ、終了
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class SceneManager;

class GameTask
{
private:
	std::unique_ptr<SceneManager> sceneManager;

public:
	GameTask();			// ｺﾝｽﾄﾗｸﾀ
	~GameTask();		// ﾃﾞｽﾄﾗｸﾀ
	
	int Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update();		// 更新
	void Render();		// 更新

};

