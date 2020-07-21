//------------------------------------------------------
// @brief	�C�ӂ̵�޼ު�ē��m�̓����蔻����s��
// 2020 7/17 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "CollisionBase.h"

class FlexibleCollision
	:private CollisionBase
{
private:
	//CollisionBase* colTable[static_cast<int>(ObjectType::OBJECTTYPE_NUM)][static_cast<int>(ObjectType::OBJECTTYPE_NUM)];

	//EnumArray<int, IndexEnum> intArray(0);
	
	std::unique_ptr<CollisionBase> colTable[static_cast<int>(ObjectType::OBJECTTYPE_NUM)][static_cast<int>(ObjectType::OBJECTTYPE_NUM)];
	constexpr std::initializer_list<ObjectType> all;
public:
	FlexibleCollision();	// �ݽ�׸�
	~FlexibleCollision();	// �޽�׸�

	void Initialize();		// ������
	void Finalize();		// �I������
	void Update();			// �X�V
	// void Render();	// �`��

	virtual bool HitCheck(const ObjectType& o1, const ObjectType& o2) override;

};

