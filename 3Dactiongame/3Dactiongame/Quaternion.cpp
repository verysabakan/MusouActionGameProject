//------------------------------------------------------
// @brief	ｸｫｰﾀﾆｵﾝを表す構造体
// 2020 5/28 Ryosuke Iida
//------------------------------------------------------

#include "Quaternion.h"

Quaternion Quaternion::operator*(const Quaternion& q)const
{
	Quaternion ret;
	double d1, d2, d3, d4;

	// x
	d1 = x * q.w;
	d2 = y * q.z;
	d3 = -z * q.y;
	d4 = w * q.x;
	ret.x = d1 + d2 + d3 + d4;

	// y
	d1 = -x * q.z;
	d2 = y * q.w;
	d3 = z * q.x;
	d4 = w * q.y;
	ret.y = d1 + d2 + d3 + d4;

	// z
	d1 = x * q.y;
	d2 = -y * q.x;
	d3 = z * q.w;
	d4 = w * q.z;
	ret.z = d1 + d2 + d3 + d4;

	// w
	d1 = -x * q.x;
	d2 = -y * q.y;
	d3 = -z * q.z;
	d4 = w * q.w;
	ret.w = d1 + d2 + d3 + d4;

	return ret;
}

//------------------------------------------------------
// @brief	回転のｸｫｰﾀﾆｵﾝ
// @param	radian	ﾗｼﾞｱﾝ角度
// @param	Axis	軸
// @return	回転後のｸｫｰﾀﾆｵﾝ
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

	ret.x = sss * axis.x;
	ret.y = sss * axis.y;
	ret.z = sss * axis.z;
	ret.w = ccc;

	return ret;
}

//------------------------------------------------------
// @brief	位置からｸｫｰﾀﾆｵﾝを作成
// @param	pos	現在位置
// @return	作成したｸｫｰﾀﾆｵﾝ
//------------------------------------------------------
Quaternion CreateXYZToQuaternion(const Vector3& pos)
{
	Quaternion ret;

	ret.x = pos.x;
	ret.y = pos.y;
	ret.z = pos.z;
	ret.w = 0.0;
	
	return ret;
}

//------------------------------------------------------
// @brief	ｸｫｰﾀﾆｵﾝから回転行列へ
// @param	pos	現在位置
// @return	変換後のｸｫｰﾀﾆｵﾝ
//------------------------------------------------------
MATRIX QuaternionToMatrix(const Quaternion& q)
{
	MATRIX ret = MGetIdent();	// 単位行列

	//X軸
	ret.m[0][0] = (float)(1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z);
	ret.m[0][1] = (float)(2.0f * q.x * q.y + 2.0f * q.w * q.z);
	ret.m[0][2] = (float)(2.0f * q.x * q.z - 2.0f * q.w * q.y);

	//Y軸
	ret.m[1][0] = (float)(2.0f * q.x * q.y - 2.0f * q.w * q.z);
	ret.m[1][1] = (float)(1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z);
	ret.m[1][2] = (float)(2.0f * q.y * q.z + 2.0f * q.w * q.x);

	//Z軸
	ret.m[2][0] = (float)(2.0f * q.x * q.z + 2.0f * q.w * q.y);
	ret.m[2][1] = (float)(2.0f * q.y * q.z - 2.0f * q.w * q.x);
	ret.m[2][2] = (float)(1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y);

	return ret;
}