//------------------------------------------------------
// @brief	��ڲ԰���B����
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include <cmath>
#include <assert.h>
#include "Camera.h"
#include "ObjectBase.h"
#include "Controller.h"
#include "FrameRate.h"

#include "_Debug.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Camera::Camera(const std::shared_ptr<ObjectBase>& p)
{
	player = p;
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Camera::~Camera()
{
	// �ُ�I��������
	assert(player == NULL);
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
void Camera::Initialize()
{
	camLength = -230.0f;		// ���S����̏�������
	auto pPos = player->GetPosition();
	cameraPos = { pPos.x, pPos.y, pPos.z + camLength };	// ��ׂ̏����ʒu
	targetLookAtPos = {};				// �����_
	cameraDir = {};						// ����
	cameraUpVec = { 0, 1.0f, 0.0f };	// ��ׂ̏����
	SetCameraNearFar(CamCon::clipNear, CamCon::clipFar);	// ��ׂ̕`��͈�
	horizontal = 0;
	vertical = 0;
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void Camera::Finalize()
{
	// ؿ���̊J��
	player.reset();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Camera::Update()
{
	// ��ב���
	// �ݒ�ŕύX�ł���悤�ɂ���
	if (CheckHitKey(KEY_INPUT_F)) camLength += 5;
	if (CheckHitKey(KEY_INPUT_G)) camLength -= 5;
	// �è���ɂ����̂ɕς���
	auto x = 0.0f;
	auto y = 0.0f;
	if (lpController->IsRightTiltX(x)) horizontal -= CamCon::deg1Rad * 1.5f * x;
	if (lpController->IsRightTiltY(y)) vertical -= CamCon::deg1Rad * 1.5 * y;
	

	Move();

	/*
	float roll = 0;		// roll��]
	float pitch = 0;	// pitch��]
	float yaw = 0;		// yaw��]

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
	// ���ޯ�ނ̎������`��
#ifdef _DEBUG
	DebugDrawStart;
	DFS(200, 48, 0xffffff, "%f,%f,%f", cameraPos.x, cameraPos.y, cameraPos.z);
	DFS(200, 64, 0xffffff, "%f,%f,%f", targetLookAtPos.x, targetLookAtPos.y, targetLookAtPos.z);
	DFS(200, 80, 0xffffff, "%f,%f", vertical, horizontal);
	DebugDrawEnd;
#endif // _DEBUG
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
	auto pc = player;
	if (pc == NULL)
	{
		return;
	}

	auto StepTime = lpFrameRate->GetStepTime();	// ���ڎ���
	Vector3 origPosition = cameraPos;	// �h�炵�𖳎������ʒu
	Vector3 origLookAtPosition = targetLookAtPos;	// �h�炵�𖳎��������ޯĈʒu
	Vector3 shakePosition = { 0.0f, 0.0f, 0.0f };	// �h�炵���Ƃ��̈ʒu
	bool shake = false;	// �h�炷���ǂ���
	float shakeAngle = 0;	// �h�炷�p�x
	float shakeTimeCounter = 0;	// �h�玞�Ԃ̶����
	float shakeTime = 1.0f;	// �h�炷����
	float shakeWidth = 5.0f;	// �h�炷��
	float shakeAngleSpeed = 0.5f;	// �h�炷����
	Vector3 TestPosition = {};

	// ���������̊p�x�ύX
	if (horizontal < -DX_PI_F)
	{
		horizontal += DX_TWO_PI_F;
	}
	if (horizontal > DX_PI_F)
	{
		horizontal -= DX_TWO_PI_F;
	}

	// ���������̊p�x�ύX
	if (vertical < -DX_PI_F / 2.0f + 0.6f)
	{
		vertical = -DX_PI_F / 2.0f + 0.6f;
	}
	if (vertical > DX_PI_F / 2.0f - 0.6f)
	{
		vertical = DX_PI_F / 2.0f - 0.6f;
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
	targetLookAtPos.y += 70.0f;

	// �ڕW���W�̎Z�o
	Vector3 targetPosition;
	targetPosition.x = 0.0f;
	targetPosition.z = cos(vertical) * camLength;
	targetPosition.y = sin(vertical) * camLength;
	targetPosition.x = -sin(horizontal) * targetPosition.z;
	targetPosition.z = cos(horizontal) * targetPosition.z;

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
	cameraDir = frontDirection;

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