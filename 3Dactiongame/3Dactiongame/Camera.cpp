//------------------------------------------------------
// @brief	��ڲ԰���B����
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include "Camera.h"
#include "ModelBase.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Camera::Camera(ModelBase* m)
{
	model = m;
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Camera::~Camera()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void Camera::Initialize()
{
	camLength = 500.0f;		//���S����̋���
	cameraPos = { 0, 0, camLength };	// ��ׂ̏����ʒu
	targetLookAtPos = {};
	cameraDir = {};
	cameraUpVec = { 0, 1.0f, 0.0f };	// ��ׂ̏����
	cameraRol = {};
	quaternion.x = quaternion.y = quaternion.z = 0.0f;
	quaternion.w = 1.0f;
	camcnt = 0;
	deg = 90;
	//camRol = model->GetRotation();
	//camRol.y = (DX_PI_F / 180) * camDir;
	SetCameraNearFar(clipNear, clipFar);	// ��ׂ̕`��͈�
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void Camera::Finalize()
{

}

float roll = 0;		// roll��]
float pitch = 0;	// pitch��]
float yaw = 0;		// yaw��]

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Camera::Update()
{
	// �~�߂邽�߂̂��
	if (CheckHitKey(KEY_INPUT_T))
	{
		auto time = 0;
	}

	cameraDir = (targetLookAtPos - cameraPos).Normalized();	// ��ׂ̌���

	if (CheckHitKey(KEY_INPUT_F))
	{
		camLength += 5;
	}

	if (CheckHitKey(KEY_INPUT_G))
	{
		camLength -= 5;
	}

	if (CheckHitKey(KEY_INPUT_W))
	{
		roll = deg1Rad;
	}

	if (CheckHitKey(KEY_INPUT_S))
	{
		roll = -deg1Rad;
	}

	if (CheckHitKey(KEY_INPUT_A))
	{
		yaw = deg1Rad;
	}

	if (CheckHitKey(KEY_INPUT_D))
	{
		yaw = -deg1Rad;
	}

	Move();

	/*
	MATRIX mat;
	MATRIX matRot;
	MATRIX matTrans;
	CreateIdentityMatrix(&mat);
	CreateIdentityMatrix(&matRot);
	CreateIdentityMatrix(&matTrans);

	quaternion.w = 1.0f;
	quaternion.x = quaternion.y = quaternion.z = 0;

	// �߯�
	auto xAxis = Vector3(mat.m[0][0], mat.m[0][1], mat.m[0][2]);
	quaternion = quaternion * CreateRotationQuaternion(pitch, xAxis);

	// ְ
	auto yAxis = Vector3(mat.m[1][0], mat.m[1][1], mat.m[1][2]);
	quaternion = quaternion * CreateRotationQuaternion(yaw, yAxis);

	// ۰�
	auto zAxis = Vector3(mat.m[2][0], mat.m[2][1], mat.m[2][2]);
	quaternion = quaternion * CreateRotationQuaternion(roll, zAxis);

	matRot = QuaternionToMatrix(quaternion);
	mat = MMult(mat, matRot);         // ��]�~����

	matTrans = MGetTranslate(VGet(0, 0, 0));
	mat = MMult(mat, matTrans);       // �ړ��~��]�~����

	cameraPos = Vec3TransformNormal(cameraPos, mat);
	*/
}

//------------------------------------------------------
// @brief	�`��:ýėp
//------------------------------------------------------
void Camera::Renderer()
{
	//DrawString(200, 16, "���߂ł�", 0xffffff);
	DrawFormatString(200, 16, 0xffffff, "%d,%d", cameraPos.x, cameraPos.y);
	DrawFormatString(200, 16, 0xffffff, "%d,%d", targetLookAtPos.x, targetLookAtPos.y);
}

//------------------------------------------------------
// @brief	��ׂ������Ă��������Ԃ�
//------------------------------------------------------
Vector3 Camera::GetCameraDir()
{
	return cameraDir;
}

//------------------------------------------------------
// @brief	��ׂ̈ړ���]
//------------------------------------------------------
void Camera::Move()
{
	// ��ڲ԰�����݂��Ȃ��ꍇ�͉������Ȃ�
	auto pc = model;
	if (pc == NULL)
	{
		return;
	}

	auto StepTime = 0.01f;	// ���ڎ���
	Vector3 origPosition = cameraPos;	// �h�炵�𖳎������ʒu
	Vector3 origLookAtPosition = targetLookAtPos;	// �h�炵�𖳎��������ޯĈʒu
	Vector3 shakePosition = { 0.0f, 0.0f, 0.0f };	// �h�炵���Ƃ��̈ʒu
	bool shake = false;	// �h�炷���ǂ���
	float shakeAngle = 0;	// �h�炷�p�x
	float shakeTimeCounter = 0;	// �h�玞�Ԃ̶����
	float shakeTime = 1.0f;	// �h�炷����
	float shakeWidth = 5.0f;	// �h�炷��
	float shakeAngleSpeed = 0.5f;	// �h�炷����

									// ���������̊p�x�ύX
	auto HAngle = yaw;
	if (HAngle < -DX_PI_F)
	{
		HAngle += DX_TWO_PI_F;
	}
	if (HAngle > DX_PI_F)
	{
		HAngle -= DX_TWO_PI_F;
	}

	// ���������̊p�x�ύX
	auto VAngle = roll;
	if (VAngle < -DX_PI_F)
	{
		VAngle += DX_TWO_PI_F;
	}
	if (VAngle > DX_PI_F)
	{
		VAngle -= DX_TWO_PI_F;
	}

	/*
	// �J������h�炷�������s�����ǂ����̃t���O�������Ă�����J������h�炷�������s��
	if (shake)
	{
	// sin ���g�p�����h�炵���W�̎Z�o
	shakePosition.y = sin(shakeAngle) * (1.0f - (shakeTimeCounter /
	shakeTime)) * shakeWidth;
	shakePosition.x = 0.0f;
	shakePosition.z = 0.0f;

	// �h�炵�����Ɏg�p���� sin �ɓn���p�x�̕ύX����
	shakeAngle += shakeAngleSpeed * StepTime;

	// �h�炷���Ԃ��o�߂�����h�炵�������I������
	shakeTimeCounter += StepTime;
	if (shakeTimeCounter >= shakeTime)
	{
	shake = false;
	}
	}
	else
	{
	// �h�炳��Ă��Ȃ��ꍇ�͗h�炵�����ɂ����Z���W���O�ɂ���
	shakePosition = { 0.0f, 0.0f, 0.0f };
	}
	*/

	// �ڕW�����_���W�̎Z�o
	targetLookAtPos = pc->GetPosition();
	targetLookAtPos.y += 50.0f;

	// �ڕW���W�̎Z�o
	Vector3 targetPosition;
	targetPosition.x = 0.0f;
	targetPosition.z = cos(VAngle) * camLength;
	targetPosition.y = sin(VAngle) * camLength;
	targetPosition.x = -sin(HAngle) * targetPosition.z;
	targetPosition.z = cos(HAngle) * targetPosition.z;

	// �Z�o�����ʒu�ɒ��S�̈ʒu�����Z
	targetPosition = targetPosition + targetLookAtPos;

	auto MOVE_DIV_NUM = 0.17f;
	// �J�����̗h�炵�����𖳎������J�����̍��W�A�����_���W�����ꂼ��̖ڕW���W�ɋ߂Â���
	auto MoveScale = StepTime / MOVE_DIV_NUM;

	auto TempV = targetPosition - origPosition;
	TempV = TempV * MoveScale;
	origPosition = origPosition + TempV;

	TempV = targetLookAtPos - origLookAtPosition;
	TempV = TempV * MoveScale;
	origLookAtPosition = origLookAtPosition + TempV;

	// �J�����̗h�炵�����𖳎������J�����̍��W�A�����_���W�ɃJ�����̗h�炵�����ɂ��
	// ���Z���W�𑫂������W�����݂̃J�����̍��W�A�����_���W�Ƃ���
	cameraPos = origPosition + shakePosition;

	auto lookAtPosition = origLookAtPosition + shakePosition;

	// �J�����̍��W����J�����̒����_���W�ւ̃x�N�g�����Z�o
	auto direction = (lookAtPosition - cameraPos).Normalized();

	// �J�������猩�ĉE�����̃x�N�g�����Z�o
	auto rightDirection = (Cross(direction, Vector3(0.0f, -1.0f, 0.0f))).Normalized();

	// �J�����̐��ʕ����̂x�����𔲂����x�N�g�����Z�o
	auto frontDirection = (Cross(Vector3(0.0f, -1.0f, 0.0f), rightDirection)).Normalized();

	/*
	// �J�������W���璍���_���W�̊ԂɃR���W�����p�|���S�������݂��邩�`�F�b�N
	if (Stage_HitCheck(g_CamInfo.Position, g_CamInfo.LookAtPosition, COLLISION_SIZE))
	{
	// �R���W�����p�|���S�������݂��Ȃ����W�܂ŃJ�������W�𒍎��_�ɋ߂Â���

	// �����_���W����J�������W�ւ̃x�N�g�����Z�o
	Direction = VNorm(VSub(g_CamInfo.Position, g_CamInfo.LookAtPosition));

	// �|���S���ɓ�����Ȃ��������Z�b�g
	NotHitDistance = 0.0f;

	// �|���S���ɓ����鋗�����Z�b�g
	HitDistance = PLAYER_DISTANCE;
	do
	{
	// �����邩�ǂ����e�X�g���鋗�����Z�o( ������Ȃ������Ɠ����鋗���̒��� )
	TestDistance = NotHitDistance + (HitDistance - NotHitDistance) / 2.0f;

	// �e�X�g�p�̃J�������W���Z�o
	TestPosition =
	VAdd(g_CamInfo.LookAtPosition, VScale(Direction, TestDistance));

	// �V�������W�ŃR���W�����p�|���S���ɓ����邩�e�X�g
	if (Stage_HitCheck(TestPosition, g_CamInfo.LookAtPosition, COLLISION_SIZE))
	{
	// ���������瓖���鋗���� TestDistance �ɕύX����
	HitDistance = TestDistance;
	}
	else
	{
	// ������Ȃ������瓖����Ȃ������� TestDistance �ɕύX����
	NotHitDistance = TestDistance;
	}

	// HitDistance �� NoHitDistance ���\���ɋ߂Â��Ă��Ȃ������烋�[�v
	} while (HitDistance - NotHitDistance > 1.0f);

	// �J�����̍��W���Z�b�g
	g_CamInfo.Position = TestPosition;
	g_CamInfo.OrigPosition = TestPosition;
	}
	*/

	// ���X�i�[�̈ʒu��ύX
	//Set3DSoundListenerPosAndFrontPos_UpVecY(cameraPos.ConvertVec(), targetLookAtPos.ConvertVec());

	SetCameraPositionAndTargetAndUpVec(cameraPos.ConvertVec(), targetLookAtPos.ConvertVec(), cameraUpVec.ConvertVec());
}