//------------------------------------------------------
// @brief	3D���W�E�޸�ق�\���\����
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

	VECTOR ConvertVec()const;	// DxLib�Ŏg����VECTOR�^�ɂ��ĕԂ�

	float Magnitude()const;	// �޸�ق̑傫����Ԃ�
	void Normalize();		// ���K��(�傫�����P��)���܂�
	Vector3 Normalized()const;	// ���K���޸�ق�Ԃ��܂�

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

Vector3 ConvertVec3(const VECTOR& v);	// VECTOR�^��Vector3�^�ɂ��ĕԂ�
Vector3 Vec3TransformCoord(const Vector3& v, const MATRIX& m);	// �w�肳�ꂽ�s���3D�x�N�g����ϊ����A���ʂ�w = 1�Ɏˉe
Vector3 Vec3TransformNormal(const Vector3& v, const MATRIX& m);	// 3D�޸�ق��w�肳�ꂽ�s��Ŗ@���ɕϊ�


float Dot(const Vector3& va, const Vector3& vb);			// ���ς�Ԃ�
Vector3 Cross(const Vector3& va, const Vector3& vb);		// �O�ς�Ԃ�
//float operator*(const Vector3& va, const Vector3& vb);	// ���ω��Z�q
//Vector3 operator%(const Vector3& va, const Vector3& vb);	// �O�ω��Z�q

//typedef Vector3 Position3;
