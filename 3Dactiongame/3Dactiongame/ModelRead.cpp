//------------------------------------------------------
// @brief	ﾓﾃﾞﾙに関係するものの読み込み
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <memory>
#include <vector>
#include "ModelRead.h"

//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰのﾓﾃﾞﾙを読み込む
//------------------------------------------------------
void ReadPlayerModelData(int& modelID, std::vector<int>& animID)
{
	// ｵﾌﾞｼﾞｪｸﾄ生成
	// auto playerModel = MV1LoadModel("Model/Otameshi/Heracules/Model_Heracules_Green.mv1");
	modelID = MV1LoadModel("Model/Otameshi/Heracules/Model_Heracules_Green.mv1");

	// std::vector<int> playerAnim;
	auto i = 0;

	std::string dirName = "Model/Otameshi/Heracules/Animation/";
	std::string extension = "mv1";

	HANDLE hFind;
	WIN32_FIND_DATA fd;
	std::string search_name = dirName + "\\*." + extension;

	hFind = FindFirstFile(search_name.c_str(), &fd);

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
			fileName.insert(0, dirName);

			animID.push_back(MV1LoadModel(fileName.c_str()));
			i++;
		}
	} while (FindNextFile(hFind, &fd));

	//閉じる
	FindClose(hFind);
}