//------------------------------------------------------
// @brief	ｸｫｰﾀﾆｵﾝを表す構造体
// 2020 5/28 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <cmath>
#include <DxLib.h>
#include "Vector3.h"

struct Quaternion
{
	Quaternion() :x(0), y(0), z(0), w(0) {}
	Quaternion(double in_x, double in_y, double in_z, double in_w) :x(in_x), y(in_y), z(in_z), w(in_w) {}
	double x, y, z, w;

	Quaternion operator*(const Quaternion& q) const;
};

Quaternion CreateRotationQuaternion(const double& rad, Vector3 axis);	// 回転のｸｫｰﾀﾆｵﾝ
Quaternion CreateXYZToQuaternion(const Vector3& pos);					// 位置からｸｫｰﾀﾆｵﾝを作成
MATRIX QuaternionToMatrix(const Quaternion& q);							// ｸｫｰﾀﾆｵﾝから回転行列へ
