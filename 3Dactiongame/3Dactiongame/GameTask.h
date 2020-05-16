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
	GameTask();
	~GameTask();
	
	int Initialize(void);	// 初期化
	void Finalize(void);	// 終了処理
	void Update(void);		// 更新
	void Draw(void);		// 更新

private:
	std::unique_ptr<SceneManager> sceneManager;
	std::unique_ptr<Controller> controll;
};

