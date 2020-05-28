//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを撮るｶﾒﾗ
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#pragma once
#include "Quaternion.h"

class ModelBase;

namespace {
	const float standardEye = 100.0f;	// 見ている位置を上げる
	const float clipNear = 0.1f;		// 手前ｸﾘｯﾌﾟ
	const float clipFar = 5000.0f;		// 奥ｸﾘｯﾌﾟ
	const float deg1Rad = (DX_PI_F / 180.0f);	// 1度
}

class Camera
{
private:
	ModelBase* model;		// ｶﾒﾗｵﾌﾞｼﾞｪｸﾄのﾎﾟｲﾝﾀの保存用
	Vector3 cameraPos;		// ｶﾒﾗ位置
	Vector3 targetPos;		// 注視点
	Vector3 cameraUpVec;	// ｶﾒﾗの上方向
	Vector3 cameraRol;		// ｶﾒﾗの回転
	Vector3 cameraDir;
	Quaternion quaternion;	// ｸｫｰﾀﾆｵﾝ
	float fov;				// 視野角
	float camLength;
	int deg;
	float size;
	int camcnt;

public:
	Camera(ModelBase* m);	// ｺﾝｽﾄﾗｸﾀ
	~Camera();				// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();		// 初期化
	void Finalize();		// 終了処理
	void Update();			// 更新

	Vector3 GetCameraDir();	// ｶﾒﾗが向いている方向を返す
};
