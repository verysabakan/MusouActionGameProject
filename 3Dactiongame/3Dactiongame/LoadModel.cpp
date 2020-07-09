//------------------------------------------------------
// @brief	���قɊ֌W������̂̓ǂݍ���
// 2020 5/23 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <memory>
#include <string>
#include <stdexcept>
#include "LoadModel.h"

//------------------------------------------------------
// @brief	��ڲ԰�����ق�ǂݍ���
// @param	modelID �ǂݍ������ق��i�[
// @param	animID �ǂݍ��񂾱�Ұ��݂��i�[
//------------------------------------------------------
void LoadPlayerModelData(int& modelID, std::vector<int>& animID)
{
	// ���ق̓ǂݍ���
	modelID = MV1LoadModel("Model/Player/Warrior.mv1");

	// std::vector<int> playerAnim;
	auto i = 0;

	std::string dirPath = "Model/Player/Animation/";
	std::string extension = "mv1";

	HANDLE hFind;
	WIN32_FIND_DATA fd;
	std::string searchName = dirPath + "*." + extension;

	hFind = FindFirstFile(searchName.c_str(), &fd);

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
			fileName.insert(0, dirPath);

			animID.push_back(MV1LoadModel(fileName.c_str()));
			i++;
		}
	} while (FindNextFile(hFind, &fd));

	//����
	FindClose(hFind);
}