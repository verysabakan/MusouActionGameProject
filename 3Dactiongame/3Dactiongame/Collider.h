//------------------------------------------------------
// @brief	“–‚½‚è”»’è
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>

// ÌßÛÄÀ²ÌßéŒ¾
class Player;
class Stage;
class HitCheckCharAndStage;

class Collider
{
private:
	Player* player;
	Stage* stage;
	std::unique_ptr<HitCheckCharAndStage> hcPlayerAndStage;

public:
	Collider(Player* p, Stage* s);		// ºİ½Ä×¸À
	~Collider();	// ÃŞ½Ä×¸À

	void Initialize();	// ‰Šú‰»
	void Finalize();	// I—¹ˆ—
	void Update();		// XV
	// void Render();	// •`‰æ

};

