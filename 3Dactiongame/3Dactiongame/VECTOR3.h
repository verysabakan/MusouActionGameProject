//------------------------------------------------------
// @brief	3DÀ•WEÍŞ¸ÄÙ‚ğ•\‚·\‘¢‘Ì
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

struct Vector3 
{
	Vector3() :x(0), y(0), z(0) {}
	Vector3(float inx, float iny, float inz) :x(inx), y(iny), z(inz) {}
	float x, y, z;

	VECTOR ConvertVec();	// DxLib‚Åg‚¦‚éVECTORŒ^‚É‚µ‚Ä•Ô‚·

	float Magnitude()const;	// ÍŞ¸ÄÙ‚Ì‘å‚«‚³‚ğ•Ô‚·
	void Normalize();		// ³‹K‰»(‘å‚«‚³‚ğ‚P‚É)‚µ‚Ü‚·
	Vector3 Normalized();	// ³‹K‰»ÍŞ¸ÄÙ‚ğ•Ô‚µ‚Ü‚·

	void operator+=(const Vector3& v);
	void operator-=(const Vector3& v);
	void operator*=(const Vector3& v);
	void operator/=(const Vector3& v);
	Vector3 operator*(float scale)const;
	Vector3 operator-();
};



Vector3 ConvertVec3(const VECTOR& v);	// VECTORŒ^‚ğVector3Œ^‚É‚µ‚Ä•Ô‚·

Vector3 operator+(const Vector3& va, const Vector3 vb);
Vector3 operator-(const Vector3& va, const Vector3 vb);

// “àÏ‚ğ•Ô‚·
//float Dot(const Vector3& va, const Vector3& vb);
// ŠOÏ‚ğ•Ô‚·
//Vector3 Cross(const Vector3& va, const Vector3& vb);
// “àÏ‰‰Zq
//float operator*(const Vector3& va, const Vector3& vb);
// ŠOÏ‰‰Zq
//Vector3 operator%(const Vector3& va, const Vector3& vb);

typedef Vector3 Position3;