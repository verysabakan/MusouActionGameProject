//------------------------------------------------------
// @brief	��ڲ԰���B����
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

class ModelBase;

class Camera
{
private:
	const float standardEye = 100.0f;

	ModelBase* model;//�J�����I�u�W�F�N�g�̃|�C���^�̕ۑ��p
	Vector3 cameraPos;//�J�����ʒu
	Vector3 targetPos;//�����_
	Vector3 cameraUpVec;//�J�����̏����
	float yaw;
	float fov;//����p
	float clipNear;//��O�N���b�v
	float clipFar;//���N���b�v
	Vector3 camRol;//�J�����̉�]
	float camLength;
	int deg;
	float camDir;
	float size;
	int speed;
	int camcnt;

public:
	Camera(ModelBase* m);		// �ݽ�׸�
	~Camera();		// �޽�׸�

	void Initialize();		// ������
	void Finalize();		// �I������
	void Update();			// �X�V
};
