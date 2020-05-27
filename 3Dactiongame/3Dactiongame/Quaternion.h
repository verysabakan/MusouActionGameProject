//------------------------------------------------------
// @brief	∏´∞¿∆µ›Çï\Ç∑ç\ë¢ëÃ
// 2020 5/28 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <cmath>
#include <DxLib.h>
#include "Vector3.h"

struct Quaternion
{
	Quaternion() :t(0), x(0), y(0), z(0) {}
	Quaternion(double t, double inx, double iny, double inz) :x(inx), y(iny), z(inz) {}
	double t, x, y, z;

	Quaternion operator*(const Quaternion& q)const;
	Quaternion CreateRotationQuaternion(const double& rad, Vector3 axis);
	Quaternion CreateXYZToQuaternion(const Vector3& pos);
	MATRIX QuaternionToMatrix(const Quaternion& q);
};
