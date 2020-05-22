//------------------------------------------------------
// @brief	ｹﾞｰﾑ画面
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "ModelBase.h"
#include "Player.h"
#include "Camera.h"
#include "GameScene.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	ｺﾝｽﾄﾗｸﾀ
//------------------------------------------------------
GameScene::GameScene(ISceneSwitcher* switcher)
	: BaseScene(switcher)
{
	// ｵﾌﾞｼﾞｪｸﾄ生成
	auto playerModel = MV1LoadModel("Model/Otameshi/Heracules/Model_Heracules_Green.mv1");

	// -----------------------------------------
	std::vector<int> playerAnim;
	auto i = 0;

	std::string dir_name = "Model/Otameshi/heracules/Animation";
	std::string extension = "mv1";

	HANDLE hFind;
	WIN32_FIND_DATA win32fd;
	std::string search_name = dir_name + "\\*." + extension;

	hFind = FindFirstFile(search_name.c_str(), &win32fd);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		throw std::runtime_error("file not found");
	}

	//次のファイルがある限り読み込み続ける
	do
	{
		//ディレクトリなら無視
		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {}
		else
		{
			std::string fileName = win32fd.cFileName;
			fileName.insert(0, "Model/Otameshi/Heracules/Animation/");

			playerAnim.push_back(MV1LoadModel(fileName.c_str()));
			i++;
		}
	} while (FindNextFile(hFind, &win32fd));

	//閉じる
	FindClose(hFind);
	// -----------------------------------------

	stage = MV1LoadModel("Model/Otameshi/room/droidroom.x");

	player = std::make_unique<Player>(playerModel ,playerAnim);

	// playerがnullptrでない場合
	if (player != nullptr)
	{
		camera = std::make_unique<Camera>(player.get());
	}
}

//------------------------------------------------------
// @brief	ﾃﾞｽﾄﾗｸﾀ
//------------------------------------------------------
GameScene::~GameScene()
{
	// 処理なし
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Initialize()
{
	// 各初期化処理
	player->Initialize();
	camera->Initialize();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Finalize()
{
	// 各終了処理
	player->Finalize();

	// ﾘｿｰｽの開放
	player.reset();
	camera.reset();
}

//------------------------------------------------------
// @brief	更新
//------------------------------------------------------
void GameScene::Update(const Controller& controll)
{
	// 各更新処理
	player->Update();
	camera->Update();

	// ﾃﾞﾊﾞｯｸﾞ用ｼｰﾝ切り替えｷｰ:Q
	if (CheckHitKey(KEY_INPUT_Y) == 1) {
		// ﾀｲﾄﾙ画面に切り替え
		sceneSwitcher->SwitchScene(eScene_Title);
	}
}

//------------------------------------------------------
// @brief	描画
//------------------------------------------------------
void GameScene::Render()
{
	//x座標
	DrawLine3D(VGet(-500.0f, 0.0f, 0.0f), VGet(+500.0f, 0.0f, 0.0f), 0xff0000);
	//ｙ座標
	DrawLine3D(VGet(0.0f, -500.0f, 0.0f), VGet(0.0f, 500.0f, 0.0f), 0x00ff00);
	//ｚ座標
	DrawLine3D(VGet(0.0f, 0.0f, -500.0f), VGet(0.0f, 0.0f, 500.0f), 0x0000ff);

	for (int x = 0; x < 11; x++)
	{
		DrawLine3D(VGet(-500.0f + 100.0f*x, 0.0f, -500.0f), VGet(-500.0f + 100.0f*x, 0.0f, 500.0f), 0x0000ff);
	}
	for (int z = 0; z < 11; z++)
	{
		DrawLine3D(VGet(-500.0f, 0.0f, -500.0f + 100.0f*z), VGet(500.0f, 0.0f, -500.0f + 100.0f*z), 0xff0000);
	}

	// モデルの座標をセット
	auto Spos = VGet(0.0f, 200.0f, 0.0f);
	auto Sscale = VGet(0.5f, 0.5f, 0.5f);
	auto Srol = VGet(0.0f, 0.0f, 0.0f);
	MV1SetPosition(stage, Spos);
	MV1SetRotationXYZ(stage, Srol);
	MV1SetScale(stage, Sscale );
	MV1DrawModel(stage);

	// 各更新処理
	player->Render();
	DrawString(0, 0, "ｹﾞｰﾑ画面", 0xffffff);
}