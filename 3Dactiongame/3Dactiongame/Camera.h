//------------------------------------------------------
// @brief	��ڲ԰���B����
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#pragma once
#include "Quaternion.h"

// �������ߐ錾
class ModelBase;
class Player;

namespace {
	const float standardEye = 100.0f;	// ���Ă���ʒu���グ��
	const float clipNear = 0.1f;		// ��O�د��
	const float clipFar = 5000.0f;		// ���د��
	const float deg1Rad = (DX_PI_F / 180.0f);	// 1�x
}

class Camera
{
private:
	ModelBase* model;			// ��ڲ԰��޼ު�Ă��߲���̕ۑ��p
	float horizontal;			// ��
	float vertical;				// �c
	Vector3 cameraPos;			// ��׈ʒu
	float camLength;			// ���S����̋���
	Vector3 targetLookAtPos;	// �����_
	Vector3 cameraDir;			// ��ׂ������Ă������
	Vector3 cameraUpVec;		// ��ׂ̏����

public:
	Camera(Player* p);	// �ݽ�׸�
	~Camera();			// �޽�׸�

	void Initialize();		// ������
	void Finalize();		// �I������
	void Update();			// �X�V
	void Renderer();		// �`��

	Vector3 GetCameraDir();	// ��ׂ������Ă��������Ԃ�
private:
	void Move();	// ��ׂ̈ړ���]
};
