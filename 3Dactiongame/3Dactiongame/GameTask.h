//------------------------------------------------------
// @brief	ｹﾞｰﾑ自体の初期化、ﾌﾛｰ、終了
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Controller.h"

//#include <mutex>

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class SceneManager;
class Controller;

class GameTask
{
public:
	GameTask();			// ｺﾝｽﾄﾗｸﾀ
	~GameTask();		// ﾃﾞｽﾄﾗｸﾀ
	
	int Initialize();	// 初期化
	void Finalize();	// 終了処理
	void Update();		// 更新
	void Render();		// 更新

private:
	std::unique_ptr<SceneManager> sceneManager;
	std::unique_ptr<Controller> controll;
};

