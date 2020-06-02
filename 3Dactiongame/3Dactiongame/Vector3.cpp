//------------------------------------------------------
// @brief	3D座標・ﾍﾞｸﾄﾙを表す構造体
// 2020 5/25 Ryosuke Iida
//------------------------------------------------------

#include "Vector3.h"

//------------------------------------------------------
// @brief	DxLibで使えるVECTOR型にして返す
//------------------------------------------------------
VECTOR Vector3::ConvertVec()const
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
// @brief	DxLibで使えるVECTOR型にして返す
// @return	VECTOR型に変換したもの
//------------------------------------------------------
Vector3 ConvertVec3(const VECTOR& v)
{
	return Vector3(v.x, v.y, v.z);
}

//------------------------------------------------------
// @brief	指定された行列で3Dベクトルを変換し、結果をw = 1に射影
//				平行移動成分を考慮
// @param	v 法線に変換したいﾍﾞｸﾄﾙ
// @param	m 変換するための行列
// @return	VECTOR型に変換したもの
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
// @brief	3Dﾍﾞｸﾄﾙを指定された行列で法線に変換
//				平行移動成分を無視
// @param	v 法線に変換したいﾍﾞｸﾄﾙ
// @param	m 変換するための行列
// @return	VECTOR型に変換したもの
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
// @brief	内積を返す
//------------------------------------------------------
float Dot(const Vector3& va, const Vector3& vb)
{
	return va.x*vb.x + va.y*vb.y + va.z * vb.z;
}

//------------------------------------------------------
// @brief	外積を返す
//------------------------------------------------------
Vector3 Cross(const Vector3& va, const Vector3& vb)
{
	return Vector3(va.y * vb.z - va.z * vb.y, va.z * vb.x - va.x * vb.z, va.x * vb.y - va.y * vb.x);
}

////------------------------------------------------------
//// 内積演算子
////------------------------------------------------------
//float operator*(const Vector3& va, const Vector3& vb) 
//{
//	return Dot(va, vb);
//}
//
////------------------------------------------------------
//// 外積演算子
////------------------------------------------------------
//Vector3 operator%(const Vector3& va, const Vector3& vb) 
//{
//	return Cross(va, vb);
//}