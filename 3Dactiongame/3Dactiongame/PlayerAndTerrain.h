//------------------------------------------------------
// @brief	��ڲ԰�ƒn�`�̓����蔻��
// 2020 7/22 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "CollisionBase.h"

// PlayerAndTerrainConstant
namespace PATCon
{
	const int STAGE_OBJECT_MAX_NUM = 512;			// �ð���ް��Ɋ܂߂���ő��޼ު�Đ��A512
	const int CHARA_MAX_HITCOLL = 2048;				// ��������ؼޮ���غ�݂̍ő吔�A2048
	const float CHARA_ENUM_DEFAULT_SIZE = 200.0f;	// ���͂���غ�݌��o�Ɏg�p���鋅�̏������ށA
	const int CHARA_HIT_TRYNUM = 16;				// �ǉ����o���ő厎�s�񐔁A16
	const float CHARA_HIT_SLIDE_DISTANCE = 5.0f;	// ��x�̕ǉ����o�������Žײ�ނ����鋗���A5.0f
	const float CHARA_HIT_FLOOR_Y_ADJUST_JUMP = -1.0f;	// �ެ��߂��Ă���ۂ̓����蔻��̍��W�̕␳�l
	const float CHARA_HIT_FLOOR_Y_ADJUST_WALK = -40.0f;	// ���n���Ă���ۂ̓����蔻��̍��W�̕␳�l
}

class PlayerAndTerrain
	:public CollisionBase
{
private:
	

public:
    PlayerAndTerrain();				// �ݽ�׸�
    virtual ~PlayerAndTerrain();	// �޽�׸�

    virtual bool HitCheck(const std::shared_ptr<ObjectBase>& o1, const std::shared_ptr<ObjectBase>& o2) override;  // ��ڲ԰�ƒn�`�̔��菈��

};

