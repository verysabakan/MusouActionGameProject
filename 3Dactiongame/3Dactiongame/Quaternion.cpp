//------------------------------------------------------
// @brief	����Ƶ݂�\���\����
// 2020 5/28 Ryosuke Iida
//------------------------------------------------------

#include "Quaternion.h"

Quaternion Quaternion::operator*(const Quaternion& q)const
{
	Quaternion ret;
	double d1, d2, d3, d4;

	// t
	d1 = t * q.t;
	d2 = -x * q.x;
	d3 = -y * q.y;
	d4 = -z * q.z;
	ret.t = d1 + d2 + d3 + d4;

	// x
	d1 = t * q.x;
	d2 = x * q.t;
	d3 = y * q.z;
	d4 = -z * q.y;
	ret.x = d1 + d2 + d3 + d4;

	// y
	d1 = t * q.y;
	d2 = -x * q.z;
	d3 = y * q.t;
	d4 = z * q.x;
	ret.y = d1 + d2 + d3 + d4;

	// z
	d1 = t * q.z;
	d2 = x * q.y;
	d3 = -y * q.x;
	d4 = z * q.t;
	ret.z = d1 + d2 + d3 + d4;

	return ret;
}

//------------------------------------------------------
// @brief	��]�̸���Ƶ�
// @param	radian	׼ޱ݊p�x
// @param	Axis	��
// @return	��]��̸���Ƶ�
//------------------------------------------------------
Quaternion CreateRotationQuaternion(const double& radian, Vector3 axis)
{
	Quaternion ret;
	double norm, ccc, sss;

	norm = Dot(axis, axis);
	if (norm <= 0) return ret;

	norm = 1.0 / sqrt(norm);
	axis.x *= (float)norm;
	axis.y *= (float)norm;
	axis.z *= (float)norm;

	ccc = cos(0.5 * radian);
	sss = sin(0.5 * radian);

	ret.t = ccc;
	ret.x = sss * axis.x;
	ret.y = sss * axis.y;
	ret.z = sss * axis.z;

	return ret;
}

//------------------------------------------------------
// @brief	�ʒu���縫��Ƶ݂��쐬
// @param	pos	���݈ʒu
// @return	�쐬��������Ƶ�
//------------------------------------------------------
Quaternion CreateXYZToQuaternion(const Vector3& pos)
{
	Quaternion ret;

	ret.t = 0.0;
	ret.x = pos.x;
	ret.y = pos.x;
	ret.z = pos.x;
	
	return ret;
}

//------------------------------------------------------
// @brief	����Ƶ݂����]�s���
// @param	pos	���݈ʒu
// @return	�ϊ���̸���Ƶ�
//------------------------------------------------------
MATRIX QuaternionToMatrix(const Quaternion& q)
{
	MATRIX ret = MGetIdent();	// �P�ʍs��

	//X��
	ret.m[0][0] = (float)(1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z);
	ret.m[0][1] = (float)(2.0f * q.x * q.y + 2.0f * q.t * q.z);
	ret.m[0][2] = (float)(2.0f * q.x * q.z - 2.0f * q.t * q.y);

	//Y��
	ret.m[1][0] = (float)(2.0f * q.x * q.y - 2.0f * q.t * q.z);
	ret.m[1][1] = (float)(1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z);
	ret.m[1][2] = (float)(2.0f * q.y * q.z + 2.0f * q.t * q.x);

	//Z��
	ret.m[2][0] = (float)(2.0f * q.x * q.z + 2.0f * q.t * q.y);
	ret.m[2][1] = (float)(2.0f * q.y * q.z - 2.0f * q.t * q.x);
	ret.m[2][2] = (float)(1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y);

	return ret;
}