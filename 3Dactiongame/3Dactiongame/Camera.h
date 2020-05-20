//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを撮るｶﾒﾗ
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

class ModelBase;

class Camera
{
private:
	const float standardEye = 100.0f;

	ModelBase * model;//カメラオブジェクトのポインタの保存用
	Vector3 cameraPos;//カメラ位置
	Vector3 targetPos;//注視点
	Vector3 cameraUpVec;//カメラの上方向
	float yaw;
	float fov;//視野角
	float clipNear;//手前クリップ
	float clipFar;//奥クリップ
	Vector3 camRol;//カメラの回転
	float camLength;
	int deg;
	float camDir;
	float size;
	int speed;
	int camcnt;

public:
	Camera(ModelBase*);		// ｺﾝｽﾄﾗｸﾀ
	~Camera();		// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();		// 初期化
	void Finalize();		// 終了処理
	void Update();			// 更新
	void Render();			// 描画

};
