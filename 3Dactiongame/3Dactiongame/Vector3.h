//------------------------------------------------------
// @brief	3D���W�E�޸�ق�\���\����
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

struct Vector3
{
	Vector3() :x(0), y(0), z(0) {}
	Vector3(float inx, float iny, float inz) :x(inx), y(iny), z(inz) {}
	float x, y, z;

	VECTOR ConvertVec();	// DxLib�Ŏg����VECTOR�^�ɂ��ĕԂ�

	float Magnitude()const;	// �޸�ق̑傫����Ԃ�
	void Normalize();		// ���K��(�傫�����P��)���܂�
	Vector3 Normalized();	// ���K���޸�ق�Ԃ��܂�

	void operator+=(const Vector3& v);
	void operator-=(const Vector3& v);
	void operator*=(const Vector3& v);
	void operator/=(const Vector3& v);
	Vector3 operator*(float scale)const;
	Vector3 operator-();
};



Vector3 ConvertVec3(const VECTOR& v);	// VECTOR�^��Vector3�^�ɂ��ĕԂ�

Vector3 operator+(const Vector3& va, const Vector3 vb);
Vector3 operator-(const Vector3& va, const Vector3 vb);

// ���ς�Ԃ�
//float Dot(const Vector3& va, const Vector3& vb);
// �O�ς�Ԃ�
//Vector3 Cross(const Vector3& va, const Vector3& vb);
// ���ω��Z�q
//float operator*(const Vector3& va, const Vector3& vb);
// �O�ω��Z�q
//Vector3 operator%(const Vector3& va, const Vector3& vb);

typedef Vector3 Position3;
