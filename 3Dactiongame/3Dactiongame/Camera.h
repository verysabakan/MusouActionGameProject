//------------------------------------------------------
// @brief	��ڲ԰���B����
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

class ModelBase;

namespace {
	const float standardEye = 100.0f;	// ���Ă���ʒu���グ��
	const float clipNear = 0.1f;		// ��O�د��
	const float clipFar = 5000.0f;		// ���د��
	const float deg1Rad = (DX_PI_F / 180.0f);	// 1�x
}

class Camera
{
private:
	ModelBase* model;		// ��׵�޼ު�Ă��߲���̕ۑ��p
	Vector3 cameraPos;		// ��׈ʒu
	Vector3 targetPos;		// �����_
	Vector3 cameraUpVec;	// ��ׂ̏����
	Vector3 cameraRol;		// ��ׂ̉�]
	Vector3 cameraDir;
	float fov;				// ����p
	float camLength;
	int deg;
	float size;
	float rotateSpeed;		// ��]���x
	int camcnt;

public:
	Camera(ModelBase* m);	// �ݽ�׸�
	~Camera();				// �޽�׸�

	void Initialize();		// ������
	void Finalize();		// �I������
	void Update();			// �X�V

	Vector3 GetCameraDir();	// ��ׂ������Ă��������Ԃ�
};
