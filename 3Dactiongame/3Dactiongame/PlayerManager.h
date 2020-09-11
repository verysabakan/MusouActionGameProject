//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ÌŠÇ—
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "Vector3.h"
#include "ManagerBase.h"

// ÌßÛÄÀ²ÌßéŒ¾
class Camera;

class PlayerManager
	:public ManagerBase
{
private:
	std::unique_ptr<Camera> camera;
	
public:
	PlayerManager();	// ºİ½Ä×¸À
	~PlayerManager();	// ÃŞ½Ä×¸À

	virtual void Initialize() override;	// ‰Šú‰»
	virtual void Finalize() override;	// I—¹ˆ—
	virtual void Update() override;		// XV
	virtual void Render() override;		// •`‰æ

};

