//------------------------------------------------------
// @brief	ｼｰﾝ変更を行うための窓口
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ｼｰﾝ切り替えのための定数
typedef enum {
	eScene_Title,		// ﾀｲﾄﾙ画面
	eScene_ModeSel,		// ﾓｰﾄﾞ選択画面
	eScene_CharSel,		// ｷｬﾗｸﾀｰ選択画面
	eScene_StageSel,	// ｽﾃｰｼﾞ選択画面
	eScene_Game,		// ｹﾞｰﾑ画面

	eScene_None,		// 無し
} eScene;

class ISceneSwitcher
{
public:
	ISceneSwitcher();			// ｺﾝｽﾄﾗｸﾀ
	virtual ~ISceneSwitcher();	// ﾃﾞｽﾄﾗｸﾀ

	virtual void SwitchScene(eScene NextScene) = 0;	// 指定したｼｰﾝに変更
};