//------------------------------------------------------
// @brief	ﾓｰﾄﾞ選択画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "ModeSelScene.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
ModeSelScene::ModeSelScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// 処理なし
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
ModeSelScene::~ModeSelScene()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	初期化
//------------------------------------------------------
void ModeSelScene::Initialize()
{
	modelHandle = MV1LoadModel("Model/Fukuoka_Prop.fbx");
}

//------------------------------------------------------
// @brief	終了処理
//------------------------------------------------------
void ModeSelScene::Finalize()
{
	MV1DeleteModel(modelHandle);
	modelHandle = NULL;
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void ModeSelScene::Update()
{
	// 画面に映る位置に３Ｄモデルを移動
	MV1SetPosition(modelHandle, VGet(320.0f, -300.0f, 600.0f));
	MV1DrawModel(modelHandle);

	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:C
	if (lpController.IsPushC(INPUT_TRG)) 
	{
		sceneSwitcher->SwitchScene(eScene_CharSel);	// ｷｬﾗｸﾀｰ選択画面に切り替え
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void ModeSelScene::Render()
{
	DrawString(0, 0, "ﾓｰﾄﾞ選択画面", 0xffffff);
}
