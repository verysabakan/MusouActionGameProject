//------------------------------------------------------
// @brief	3D���W�E�޸�ق�\���\����
// 2020 5/25 Ryosuke Iida
//------------------------------------------------------

#include "Vector3.h"

//------------------------------------------------------
// @brief	DxLib�Ŏg����VECTOR�^�ɂ��ĕԂ�
//------------------------------------------------------
VECTOR Vector3::ConvertVec()
{
	return VGet(x, y, z);
}

//------------------------------------------------------
// @brief	�޸�ق̑傫����Ԃ�
//------------------------------------------------------
float Vector3::Magnitude()const 
{
	return sqrt(x*x + y * y + z * z);
}

//------------------------------------------------------
// @brief	���K��(�傫�����P��)����
//------------------------------------------------------
void Vector3::Normalize() 
{
	float mag = Magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

//------------------------------------------------------
// @brief	���K���޸�ق�Ԃ�
//------------------------------------------------------
Vector3 Vector3::Normalized() 
{
	float mag = Magnitude();
	return Vector3(x / mag, y / mag, z / mag);
}

void Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

void Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void Vector3::operator*=(const Vector3& v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

void Vector3::operator/=(const Vector3& v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
}

Vector3 Vector3::operator+(const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator*(const float& scale)const
{
	return Vector3(x * scale, y * scale, z * scale);
}

Vector3 Vector3::operator*(const MATRIX& matrix)const
{
	Vector3 ret;

	ret.x = matrix.m[0][0] * x + matrix.m[1][0] * y + matrix.m[2][0] * z + matrix.m[3][0];
	ret.y = matrix.m[0][1] * x + matrix.m[1][1] * y + matrix.m[2][1] * z + matrix.m[3][1];
	ret.z = matrix.m[0][2] * x + matrix.m[1][2] * y + matrix.m[2][2] * z + matrix.m[3][2];

	return ret;
}

Vector3 Vector3::operator*(const Vector3& vector3)const
{
	return Vector3(x * vector3.x, y * vector3.y, z * vector3.z);
}

//------------------------------------------------------
// @brief	DxLib�Ŏg����VECTOR�^�ɂ��ĕԂ�
// @return	VECTOR�^�ɕϊ���������
//------------------------------------------------------
Vector3 ConvertVec3(const VECTOR& v)
{
	return Vector3(v.x, v.y, v.z);
}

//------------------------------------------------------
// @brief	���W���S�̉�]��̍��W��Ԃ�
// @param	center	��]���S�_
// @param	angle	��]�p�x
// @param	pos		���̍��W
// @return	�ϊ���̍��W
//------------------------------------------------------
Vector3 RotateVec(const Vector3& center, const Vector3& angle, Vector3 pos)
{
	Vector3 ret;

	// ���S�����_�ɕ��s�ړ�����
	pos -= center;

	// ���_���S�ɉ�]����
	auto x = MGetRotX(angle.x);
	auto y = MGetRotY(angle.y);
	auto z = MGetRotZ(angle.z);

	auto xyz = MMult(z, y);
	xyz = MMult(xyz, x);
	ret = pos * xyz;

	// ���S�����̍��W�֖߂�
	ret += center;

	return ret;
}

//------------------------------------------------------
// @brief	���ς�Ԃ�
//------------------------------------------------------
float Dot(const Vector3& va, const Vector3& vb)
{
	return va.x*vb.x + va.y*vb.y + va.z * vb.z;
}

//------------------------------------------------------
// @brief	�O�ς�Ԃ�
//------------------------------------------------------
Vector3 Cross(const Vector3& va, const Vector3& vb)
{
	return Vector3(va.y * vb.z - va.z * vb.y, va.z * vb.x - va.x * vb.z, va.x * vb.y - va.y * vb.x);
}

////------------------------------------------------------
//// ���ω��Z�q
////------------------------------------------------------
//float operator*(const Vector3& va, const Vector3& vb) 
//{
//	return Dot(va, vb);
//}
//
////------------------------------------------------------
//// �O�ω��Z�q
////------------------------------------------------------
//Vector3 operator%(const Vector3& va, const Vector3& vb) 
//{
//	return Cross(va, vb);
//}