//------------------------------------------------------
// @brief	½Ã°¼Ş‚ÌŠÇ—
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>


// ÌßÛÄÀ²ÌßéŒ¾
class Stage;

class StageManager
{
private:
	std::unique_ptr<Stage> stage;

public:
	StageManager(const STAGE_TYPE& sT);		// ºİ½Ä×¸À
	~StageManager();	// ÃŞ½Ä×¸À

	void Initialize();	// ‰Šú‰»
	void Finalize();	// I—¹ˆ—
	void Update();		// XV
	void Render();	// •`‰æ

	Stage* GetStage();	// ½Ã°¼Ş‚ğæ“¾
};

