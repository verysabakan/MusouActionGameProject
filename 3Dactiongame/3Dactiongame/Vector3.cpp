//------------------------------------------------------
// @brief	3D���W�E�޸�ق�\���\����
// 2020 5/25 Ryosuke Iida
//------------------------------------------------------

#include "Vector3.h"

//------------------------------------------------------
// @brief	DxLib�Ŏg����VECTOR�^�ɂ��ĕԂ�
//------------------------------------------------------
VECTOR Vector3::ConvertVec()const
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
Vector3 Vector3::Normalized()const
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

Vector3 Vector3::operator+(const Vector3& v)const
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v)const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator-()const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator*(const float& scale)const
{
	return Vector3(x * scale, y * scale, z * scale);
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
// @brief	�w�肳�ꂽ�s���3D�x�N�g����ϊ����A���ʂ�w = 1�Ɏˉe
//				���s�ړ��������l��
// @param	v �@���ɕϊ��������޸��
// @param	m �ϊ����邽�߂̍s��
// @return	VECTOR�^�ɕϊ���������
//------------------------------------------------------
Vector3 Vec3TransformCoord(const Vector3& v, const MATRIX& m)
{
	Vector3 ret;
	float w;

	w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + m.m[3][3];
	if (w) w = 1.f / w;
	ret.x = (v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0]) * w;
	ret.y = (v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1]) * w;
	ret.z = (v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2]) * w;

	return ret;
}

//------------------------------------------------------
// @brief	3D�޸�ق��w�肳�ꂽ�s��Ŗ@���ɕϊ�
//				���s�ړ������𖳎�
// @param	v �@���ɕϊ��������޸��
// @param	m �ϊ����邽�߂̍s��
// @return	VECTOR�^�ɕϊ���������
//------------------------------------------------------
Vector3 Vec3TransformNormal(const Vector3& v, const MATRIX& m)
{
	Vector3 ret;

	ret.x = (v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0]);
	ret.y = (v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1]);
	ret.z = (v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2]);

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