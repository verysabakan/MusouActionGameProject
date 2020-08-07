//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ÌŠÇ—
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"
#include "AddList.h"

// ÌßÛÄÀ²ÌßéŒ¾
class Player;
class Camera;
class ModelBase;

class PlayerManager
{
private:
	std::unique_ptr<Player> player;

public:
	PlayerManager(const WEAK_LIST& weakList);	// ºİ½Ä×¸À
	~PlayerManager();	// ÃŞ½Ä×¸À

	void Initialize();	// ‰Šú‰»
	void Finalize();						// I—¹ˆ—
	void Update(const Vector3& cameraDir);	// XV
	void Render();							// •`‰æ

	ModelBase* GetPlayer();	// ÌßÚ²Ô°‚ğæ“¾

};

