//------------------------------------------------------
// @brief	(�ð��)���ق̂��߂̊��
// 2020 6/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

class StageModelBase
{
protected:
	int modelHandle;			// ���ق������
	int collisionModelHandle;	// �ؼޮݗp���ق������
	int skyModelHandle;			// �����ق������

public:
	StageModelBase();	// �ݽ�׸�
	~StageModelBase();	// �޽�׸�

	int GetCollisionModelHandle() { return collisionModelHandle; }	// �����蔻��p��������ق̎擾
};

