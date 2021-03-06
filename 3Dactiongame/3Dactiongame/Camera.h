//------------------------------------------------------
// @brief	ﾌﾟﾚｲﾔｰを撮るｶﾒﾗ
// 2020 5/18 Ryosuke Iida
//------------------------------------------------------

#pragma once
#include <memory>
#include "Quaternion.h"

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class ObjectBase;
class Player;

// CameraConstant
namespace CamCon
{
	const float standardEye = 100.0f;	// 見ている位置を上げる
	const float clipNear = 0.1f;		// 手前ｸﾘｯﾌﾟ
	const float clipFar = 5000.0f;		// 奥ｸﾘｯﾌﾟ
	const float deg1Rad = (DX_PI_F / 180.0f);	// 1度
}

class Camera
{
private:
	std::shared_ptr<ObjectBase> player;// ﾌﾟﾚｲﾔｰｵﾌﾞｼﾞｪｸﾄのﾎﾟｲﾝﾀの保存用
	float horizontal;			// 横
	float vertical;				// 縦
	Vector3 cameraPos;			// ｶﾒﾗ位置
	float camLength;			// 中心からの距離
	Vector3 targetLookAtPos;	// 注視点
	Vector3 cameraDir;			// ｶﾒﾗが向いている方向
	Vector3 cameraUpVec;		// ｶﾒﾗの上方向

public:
	Camera(const std::shared_ptr<ObjectBase>& p);	// ｺﾝｽﾄﾗｸﾀ
	~Camera();			// ﾃﾞｽﾄﾗｸﾀ

	void Initialize();		// 初期化
	void Finalize();		// 終了処理
	void Update();			// 更新
	void Renderer();		// 描画

	Vector3 GetCameraDir();	// ｶﾒﾗが向いている方向を返す
private:
	void Move();	// ｶﾒﾗの移動回転
};
