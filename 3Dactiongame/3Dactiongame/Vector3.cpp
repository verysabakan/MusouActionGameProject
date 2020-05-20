//------------------------------------------------------
// @brief	3D座標・ﾍﾞｸﾄﾙを表す構造体
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#include <cmath>
#include <DxLib.h>
#include "Vector3.h"

//------------------------------------------------------
// @brief	DxLibで使えるVECTOR型にして返す
//------------------------------------------------------
VECTOR Vector3::ConvertVec()
{
	return VGet(x, y, z);
}

//------------------------------------------------------
// @brief	ﾍﾞｸﾄﾙの大きさを返す
//------------------------------------------------------
float Vector3::Magnitude()const 
{
	return sqrt(x*x + y * y + z * z);
}

//------------------------------------------------------
// @brief	正規化(大きさを１に)する
//------------------------------------------------------
void Vector3::Normalize() 
{
	float mag = Magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

//------------------------------------------------------
// @brief	正規化ﾍﾞｸﾄﾙを返す
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

Vector3 Vector3::operator*(float scale)const
{
	return Vector3(x * scale, y * scale, z * scale);
}

Vector3 Vector3::operator-() 
{
	return Vector3(-x, -y, -z);
}

//------------------------------------------------------
// @brief	DxLibで使えるVECTOR型にして返す
//				別に型を用意しなくてはならない
//------------------------------------------------------
Vector3 ConvertVec3(const VECTOR& v)
{
	return Vector3(v.x, v.y, v.z);
}

Vector3 operator+(const Vector3& va, const Vector3 vb) 
{
	return Vector3(va.x + vb.x, va.y + vb.y, va.z + vb.z);
}

Vector3 operator-(const Vector3& va, const Vector3 vb) 
{
	return Vector3(va.x - vb.x, va.y - vb.y, va.z - vb.z);
}

