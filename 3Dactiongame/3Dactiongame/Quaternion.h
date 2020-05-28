//------------------------------------------------------
// @brief	����Ƶ݂�\���\����
// 2020 5/28 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <cmath>
#include <DxLib.h>
#include "Vector3.h"

struct Quaternion
{
	Quaternion() :t(0), x(0), y(0), z(0) {}
	Quaternion(double in_t, double in_x, double in_y, double in_z) :t(in_t), x(in_x), y(in_y), z(in_z) {}
	double t, x, y, z;

	Quaternion operator*(const Quaternion& q) const;
};

Quaternion CreateRotationQuaternion(const double& rad, Vector3 axis);	// ��]�̸���Ƶ�
Quaternion CreateXYZToQuaternion(const Vector3& pos);					// �ʒu���縫��Ƶ݂��쐬
MATRIX QuaternionToMatrix(const Quaternion& q);							// ����Ƶ݂����]�s���
