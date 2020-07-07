//------------------------------------------------------
// @brief	ÌßÚ²Ô°‚ğ‘€‚é
// 2020 5/19 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <vector>
#include "ModelBase.h"

class Player
	:private ModelBase
{
public:
	Player(int mID , std::vector<int>& aID);
	~Player();
	void Initialize();	// ‰Šú‰»
	void Finalize();	// I—¹ˆ—
	void Update(const Vector3& cameraDir);		// XV
	void Render();		// •`‰æ

private:
	void Behavior(const Vector3& cameraDir);		// “®ì
	void Animation();		// ˆÚ“®
};