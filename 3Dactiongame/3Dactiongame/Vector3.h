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

	VECTOR ConvertVec()const;	// DxLibで使えるVECTOR型にして返す

	float Magnitude()const;	// ﾍﾞｸﾄﾙの大きさを返す
	void Normalize();		// 正規化(大きさを１に)します
	Vector3 Normalized()const;	// 正規化ﾍﾞｸﾄﾙを返します

	void operator+=(const Vector3& v);
	void operator-=(const Vector3& v);
	void operator*=(const Vector3& v);
	void operator/=(const Vector3& v);
	Vector3 operator+(const Vector3& v)const;
	Vector3 operator-(const Vector3& v)const;
	Vector3 operator-()const;
	Vector3 operator*(const float& scale)const;
	Vector3 operator*(const Vector3& vector3)const;
};

Vector3 ConvertVec3(const VECTOR& v);	// VECTOR型をVector3型にして返す
Vector3 Vec3TransformCoord(const Vector3& v, const MATRIX& m);	// 指定された行列で3Dベクトルを変換し、結果をw = 1に射影
Vector3 Vec3TransformNormal(const Vector3& v, const MATRIX& m);	// 3Dﾍﾞｸﾄﾙを指定された行列で法線に変換


float Dot(const Vector3& va, const Vector3& vb);			// 内積を返す
Vector3 Cross(const Vector3& va, const Vector3& vb);		// 外積を返す
//float operator*(const Vector3& va, const Vector3& vb);	// 内積演算子
//Vector3 operator%(const Vector3& va, const Vector3& vb);	// 外積演算子

//typedef Vector3 Position3;
