#include <assert.h>
#include <vector>
#include <cmath>
#include <DxLib.h>
#include "ModelBase.h"
#include "Player.h"

//------------------------------------------------------
// @brief	ºÝ½Ä×¸À
//------------------------------------------------------
Player::Player(int mID , std::vector<int>& aID)
	: ModelBase()
{
	modelID = MV1DuplicateModel(mID);
	for (int i = 0; i < aID.size(); i++) {
		animID.push_back(aID[i]);
	}
}

//------------------------------------------------------
// @brief	ÃÞ½Ä×¸À
//------------------------------------------------------
Player::~Player()
{
	// ˆÙíI—¹‚ÌÁª¯¸
	assert(modelID == NULL);
}

//------------------------------------------------------
// @brief	‰Šú‰»
//------------------------------------------------------
void Player::Initialize()
{
	pos = Vector3();
	rol = Vector3();
	scl = Vector3(0.5f, 0.5f, 0.5f);
	dir = 0.0f;
	// ±ÆÒ°¼®Ý¾¯Ä±¯Ìß
	attachiIndex = -1;
	//for (int i = 0; i < animID.size(); i++) {
		attachiIndex = MV1AttachAnim(modelID, 0, animID[7], true);
	//}
	// ±ÆÒ°¼®Ý‚ÌÄ°ÀÙŽžŠÔ‚ðŒv‘ª
	totalTime = MV1GetAttachAnimTotalTime(modelID, attachiIndex);
	playTime = 0;
	newKey = 0;
	oldKey = 0;
	trgKey = 0;
	SetAnimID(modelID, 0);
	// À°¹Þ¯Ä‚ÌŒvŽZ
	target = ConvertVec3(VTransform(VGet(300.0f, pos.y, pos.z), MGetRotY(rol.y)));
	//uŠg‘åk¬vu‰ñ“]vuˆÚ“®v‚ÌÝ’è
	MV1SetScale(modelID, scl.ConvertVec());//‡AŠg‘åk¬
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z));//‰ñ“]
	// MV1SetRotationXYZ(model, rol);//‰ñ“]
	MV1SetPosition(modelID, pos.ConvertVec());//ˆÚ“®
}

//------------------------------------------------------
// @brief	I—¹ˆ—
//------------------------------------------------------
void Player::Finalize()
{
	// ÓÃÞÙ‚Ìíœ
	MV1DeleteModel(modelID);
	modelID = NULL;
}

//------------------------------------------------------
// @brief	XV
//------------------------------------------------------
void Player::Update()
{
	newKey = 0;
	//¶‰Eù‰ñ
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		dir += 0.8f;
		newKey = 1;
		//ModelAnimTime(ACT_RUN);
	}


	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		dir -= 0.8f;
		newKey = 1;
	}
	rol.y = (DX_PI_F / 180)*dir;// ×¼Þ±Ý‚É•ÏŠ·
	//----Œü‚¢‚Ä‚¢‚é•ûŒü‚É‘OŒãˆÚ“®
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos.x += cosf(rol.y)*3.0f;
		pos.z -= sinf(rol.y)*3.0f;
		newKey = 1;
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos.x -= cosf(rol.y)*3.0f;
		newKey = 1;
		pos.z += sinf(rol.y)*3.0f;
	}

	// À°¹Þ¯Ä‚ÌŒvŽZ
	target = ConvertVec3(VTransform(VGet(300.0f, 0.0f, 0.0f), MGetRotY(rol.y)));
	//uŠg‘åk¬vu‰ñ“]vuˆÚ“®v‚ÌÝ’è
	MV1SetScale(modelID, scl.ConvertVec());// ‡AŠg‘åk¬2
	MV1SetRotationXYZ(modelID, VGet(rol.x, rol.y - (DX_PI_F / 180) * 90, rol.z)); //‰ñ“]
	// MV1SetRotationXYZ(model, rol);// ‰ñ“]
	MV1SetPosition(modelID, pos.ConvertVec());// ˆÚ“®

	// ±ÆÒ°¼®Ý‚ÌØ‚è‘Ö‚¦
	if ((newKey == 1) && oldKey == 0)
	{
		SetAnimID(modelID, 7);

	}
	if ((newKey == 0) && oldKey == 1)
	{
		// ’âŽ~(0”Ô)Ó°¼®Ý‚ð¾¯Ä
		// •à‚­(7”Ô)Ó°¼®Ý‚ð¾¯Ä
		SetAnimID(modelID, 0);
	}
	oldKey = newKey;// ŽŸ‚ÌÙ°Ìß‚Ìˆ×‚Ì€”õ
	playTime += 0.5f;
	if (playTime >= totalTime)
	{
		playTime = 0.0f;
	}

	// model‚É±ÆÒ°¼®Ý‚ð¾¯Ä
	MV1SetAttachAnimTime(modelID, attachiIndex, playTime);
}

//------------------------------------------------------
// @brief	•`‰æ
//------------------------------------------------------
void Player::Render()
{
	// •`‰æ
	MV1DrawModel(modelID);
}