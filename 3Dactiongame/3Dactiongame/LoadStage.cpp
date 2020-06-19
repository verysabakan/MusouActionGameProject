//------------------------------------------------------
// @brief	�ð�ނ̍\���ɕK�v���ް��̓ǂݍ���
// 2020 6/4 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <vector>
#include <string>
#include "LoadStage.h"
#include "DxLib.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
LoadStage::LoadStage()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
LoadStage::~LoadStage()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�ð���ް��̓ǂݍ���
// @param	mH �ð�����ٗp
// @param	cH �ؼޮݗp
// @param	sH ��p
// @param	sT �ð�ނ̎��
// @return	�����������ǂ���
//------------------------------------------------------
bool LoadStage::LoadStageDate(int& mH, int& cH, int& sH, const STAGE_TYPE& sT)
{
	// �߽�������۰�ނ���
	auto path = ConvertStageKindToPath(sT, LOAD_MODEL);
	if (path)
	{
		mH = MV1LoadModel(path);
		cH = MV1LoadModel(ConvertStageKindToPath(sT, LOAD_COLLISION));
		sH = MV1LoadModel(ConvertStageKindToPath(sT, LOAD_SKY));
	}

	// �ǂݍ��ݎ��s
	if (mH == -1)
	{
		// �ُ�I��
		return false;
	}

	// ����I��
	return true;
}

//------------------------------------------------------
// @brief	��ނ��߽�ɕϊ�����
// @param	sk �ð�ނ̎��
// @return	̧�ق��߽
//------------------------------------------------------
const char* LoadStage::ConvertStageKindToPath(const STAGE_TYPE& sT, const LoadType& lT)
{
	// ���̕ӂ�.txt��ǂݍ���

	// SAMPLE�����������ٽð�ނ��߽��
	if (sT == STAGE_SAMPLE)
	{
		auto path = "Model/SampleStage/Stage01.mv1";

		if (lT == LOAD_COLLISION)
		{
			path = "Model/SampleStage/Stage01_c.mv1";
		}
		else if (lT == LOAD_SKY)
		{
			path = "Model/SampleStage/Stage01_sky.mv1";
		}
		
		return path;
	}

	return false;
}