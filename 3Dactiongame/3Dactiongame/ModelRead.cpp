//------------------------------------------------------
// @brief	���قɊ֌W������̂̓ǂݍ���
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <memory>
#include <vector>
#include "ModelRead.h"

//------------------------------------------------------
// @brief	��ڲ԰�����ق�ǂݍ���
//------------------------------------------------------
void ReadPlayerModelData(int& modelID, std::vector<int>& animID)
{
	// ��޼ު�Đ���
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

	// �������s
	if (hFind == INVALID_HANDLE_VALUE)
	{
		throw std::runtime_error("̧�ق�������܂���");
	}

	//���̃t�@�C�����������ǂݍ��ݑ�����
	do
	{
		//�f�B���N�g���Ȃ疳��
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {}
		else
		{
			std::string fileName = fd.cFileName;
			fileName.insert(0, dirName);

			animID.push_back(MV1LoadModel(fileName.c_str()));
			i++;
		}
	} while (FindNextFile(hFind, &fd));

	//����
	FindClose(hFind);
}