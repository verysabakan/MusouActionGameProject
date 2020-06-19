//------------------------------------------------------
// @brief	�ð�ނ̍\���ɕK�v���ް��̓ǂݍ���
// 2020 6/4 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "StageType.h"

class LoadStage
{
private:
	// �ǂݍ������ق�����
	typedef enum
	{
		LOAD_MODEL,
		LOAD_COLLISION,
		LOAD_SKY
	} LoadType;

public:
	LoadStage();	// �ݽ�׸�
	~LoadStage();	// �޽�׸�

	bool LoadStageDate(int& mH, int& cH, int& sH, const STAGE_TYPE& sT);			// �ð���ް��̓ǂݍ���

private:
	const char* ConvertStageKindToPath(const STAGE_TYPE& sT, const LoadType& lT);	// STAGE_KIND���߽�ɕϊ�
	
};
