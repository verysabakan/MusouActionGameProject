//------------------------------------------------------
// @brief	ﾓﾃﾞﾙに関係するものの読み込み
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <memory>
#include <string>
#include <stdexcept>
#include "LoadModel.h"

//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰのﾓﾃﾞﾙを読み込む
// @param	modelID 読み込んだﾓﾃﾞﾙを格納
// @param	animID 読み込んだｱﾆﾒｰｼｮﾝを格納
//------------------------------------------------------
void LoadPlayerModelData(int& modelID, std::vector<int>& animID)
{
	// ﾓﾃﾞﾙの読み込み
	modelID = MV1LoadModel("Model/Player/Warrior.mv1");

	// std::vector<int> playerAnim;
	auto i = 0;

	std::string dirPath = "Model/Player/Animation/";
	std::string extension = "mv1";

	HANDLE hFind;
	WIN32_FIND_DATA fd;
	std::string searchName = dirPath + "*." + extension;

	hFind = FindFirstFile(searchName.c_str(), &fd);

	// 検索失敗
	if (hFind == INVALID_HANDLE_VALUE)
	{
		throw std::runtime_error("ﾌｧｲﾙが見つかりません");
	}

	//次のファイルがある限り読み込み続ける
	do
	{
		//ディレクトリなら無視
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {}
		else
		{
			std::string fileName = fd.cFileName;
			fileName.insert(0, dirPath);

			animID.push_back(MV1LoadModel(fileName.c_str()));
			i++;
		}
	} while (FindNextFile(hFind, &fd));

	//閉じる
	FindClose(hFind);
}