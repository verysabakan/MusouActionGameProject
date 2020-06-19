//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ÌŠÇ—
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"

// ÌßÛÄÀ²ÌßéŒ¾
class Player;
class Controller;
class Camera;

class PlayerManager
{
private:
	std::unique_ptr<Player> player;

public:
	PlayerManager();	// ºİ½Ä×¸À
	~PlayerManager();	// ÃŞ½Ä×¸À

	void Initialize();	// ‰Šú‰»
	void Finalize();	// I—¹ˆ—
	void Update(const Controller& controll, const Vector3& cameraDir);		// XV
	void Render();	// •`‰æ

	Player* GetPlayer();	// ÌßÚ²Ô°‚ğæ“¾
};

