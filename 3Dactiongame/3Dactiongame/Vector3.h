//------------------------------------------------------
// @brief	3D座標・ﾍﾞｸﾄﾙを表す構造体
// 2020 5/25 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <cmath>
#include <DxLib.h>

struct Vector3
{
	Vector3() :x(0), y(0), z(0) {}
	Vector3(float inx, float iny, float inz) :x(inx), y(iny), z(inz) {}
	float x, y, z;

	VECTOR ConvertVec();	// DxLibで使えるVECTOR型にして返す

	float Magnitude()const;	// ﾍﾞｸﾄﾙの大きさを返す
	void Normalize();		// 正規化(大きさを１に)します
	Vector3 Normalized();	// 正規化ﾍﾞｸﾄﾙを返します

	void operator+=(const Vector3& v);
	void operator-=(const Vector3& v);
	void operator*=(const Vector3& v);
	void operator/=(const Vector3& v);
	Vector3 operator+(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3 operator-();
	Vector3 operator*(const float& scale)const;
	Vector3 operator*(const MATRIX& matrix)const;
	Vector3 operator*(const Vector3& vector3)const;
};

Vector3 ConvertVec3(const VECTOR& v);	// VECTOR型をVector3型にして返す
Vector3 RotateVec(const Vector3& center, const Vector3& angle, Vector3 pos);	// 座標中心の回転後の座標を返す

float Dot(const Vector3& va, const Vector3& vb);			// 内積を返す
Vector3 Cross(const Vector3& va, const Vector3& vb);		// 外積を返す
//float operator*(const Vector3& va, const Vector3& vb);	// 内積演算子
//Vector3 operator%(const Vector3& va, const Vector3& vb);	// 外積演算子

//typedef Vector3 Position3;
