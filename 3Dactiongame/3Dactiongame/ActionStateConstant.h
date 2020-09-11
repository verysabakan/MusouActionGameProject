//------------------------------------------------------
// @brief	ｷｬﾗの行動状態
// 2020 9/8 Ryosuke Iida
//------------------------------------------------------

#pragma once

// 当たり判定を取るｵﾌﾞｼﾞｪｸﾄの種類
enum class ACTION_STATE
{
	ACTION_STATE_DEAD,		// 
	ACTION_STATE_DOWN,		// 
	ACTION_STATE_DAMAGE,	// 
	ACTION_STATE_STUN,		// 
	ACTION_STATE_JUMP,		// 
	ACTION_STATE_SKILL1,	// 
	ACTION_STATE_SKILL2,	// 
	ACTION_STATE_SKILL3,	// 
	ACTION_STATE_ATTACK1,	// 
	ACTION_STATE_ATTACK2,	// 
	ACTION_STATE_BROCK,		// 
	ACTION_STATE_WALK,		// 
	ACTION_STATE_RUN,		// 
	ACTION_STATE_STANCE,	// 

	ACTION_STATE_NUM		// ｷｬﾗの行動の状態数(最大値)
};

ACTION_STATE begin(ACTION_STATE);					// ACTION_STATEの先頭の要素を返す
ACTION_STATE end(ACTION_STATE);						// ACTION_STATEの末端を返す
ACTION_STATE operator*(ACTION_STATE& type);			// 自分自身を返す
ACTION_STATE operator++(ACTION_STATE& type);		// ACTION_STATEの++の計算
ACTION_STATE operator+(ACTION_STATE& type, int k);	// ACTION_STATEに対する足し算
ACTION_STATE operator-(ACTION_STATE& type, int k);	// ACTION_STATEに対する引き算
