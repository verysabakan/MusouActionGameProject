//------------------------------------------------------
// @brief	ﾀｲﾄﾙ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

// ﾀｲﾄﾙの部品
enum TITLE_PARTS
{
	TITLE_PARTS_EW,
	TITLE_PARTS_EXTREME,
	TITLE_PARTS_WARRIORS,
	TITLE_PARTS_MARK,
	TITLE_PARTS_MAX
};

class TitleScene
	: public BaseScene
{
private:
	// 変数の定義
	int titleImage[TITLE_PARTS_MAX];	// ﾀｲﾄﾙ画像:ﾊﾟｰﾂごと
	int bgImage;						// BACKGROUND:背景画像
	int pabImage;						// PRESS ANY BUTTON:ｽﾀｰﾄﾎﾞﾀﾝ画像

public:
	TitleScene(ISceneSwitcher* switcher);	// ｺﾝｽﾄﾗｸﾀ
	~TitleScene();							// ﾃﾞｽﾄﾗｸﾀ

	// -----ｵｰﾊﾞｰﾗｲﾄﾞ----- //
	virtual void Initialize() override;	// 初期化
	virtual void Finalize() override;	// 終了処理
	virtual void Update() override;		// 更新
	virtual void Render() override;		// 描画

};

