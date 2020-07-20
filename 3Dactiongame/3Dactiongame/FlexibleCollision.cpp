//------------------------------------------------------
// @brief	�C�ӂ̵�޼ު�ē��m�̓����蔻����s��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#include "FlexibleCollision.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
FlexibleCollision::FlexibleCollision()
{
	/*
	colTable[SHAPE_CIRCLE][SHAPE_CIRCLE] = new CircleAndCircle();
	colTable[SHAPE_CIRCLE][SHAPE_RECT] = new CircleAndRect();
	colTable[SHAPE_RECT][SHAPE_CIRCLE] = new CircleAndRect();
	colTable[SHAPE_RECT][SHAPE_RECT] = new RectAndRect();
	*/
	
	colTable[ObjectType::OBJECTTYPE_PLAYER][ObjectType::OBJECTTYPE_PLAYER] = std::make_unique<CollisionBase>();
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
FlexibleCollision::~FlexibleCollision()
{
	// �����Ȃ�
}
//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void FlexibleCollision::Initialize()
{

}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void FlexibleCollision::Finalize()
{

}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void FlexibleCollision::Update()
{

}

//------------------------------------------------------
// @brief	�����蔻��
//------------------------------------------------------
bool FlexibleCollision::HitCheck(const ObjectType& o1, const ObjectType& o2)
{
	return true;
}