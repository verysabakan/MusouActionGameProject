//------------------------------------------------------
// @brief	�C�ӂ̵�޼ު�ē��m�̓����蔻����s��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#include "FlexibleCollision.h"
#include "PlayerAndTerrain.h"

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

	colTable[static_cast<int>(ObjectType::OBJECTTYPE_PLAYER)][static_cast<int>(ObjectType::OBJECTTYPE_TERRAIN)]
		= std::make_unique<PlayerAndTerrain>();	// ��ڲ԰�ƒn�`�̓����蔻��
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
	/*
	for (ObjectType i = begin(i); i < end(i); ++i) 
	{
		for (ObjectType j = begin(j); j < end(j); ++j) 
		{
			
			//colTable[i][j].reset();
		}
	}
	*/
}

//------------------------------------------------------
// @brief	�����蔻��
//------------------------------------------------------
bool FlexibleCollision::HitCheck(const ObjectType& o1, const ObjectType& o2)
{
	//return colTable[o1.GetType()][o2.GetType()]->HitCheck(o1, o2);
	return false;
}