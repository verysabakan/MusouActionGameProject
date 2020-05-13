//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include "Controller.h"
#include <DxLib.h>

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Controller::Controller()
{
	/*
	// �������͂���ĂȂ����
	for (int i = 0; i < key->max_size; i++) {
		for (int j = 0; i < KEY_SIGNAL_MAX; i++) {
			key[j][i] = false;
		}
	}
	*/
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Controller::~Controller()
{
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Controller::Update(void)
{
	// �O�ڰт̓��͏��
	key[KEY_SIGNAL_OLD] = key[KEY_SIGNAL_NOW];
	key[KEY_SIGNAL_OLD] = key[KEY_SIGNAL_NOW];

	// ���݂��ڰт̓��͏��
	GetHitKeyStateAll(key[KEY_SIGNAL_NOW].data());
	//pad[KEY_SIGNAL_NOW].data = GetJoypadInputState(DX_INPUT_PAD1);

	/*
	// �����ꂽ�u�ԁA�����ꂽ�u��
	for (int i = 0; i < key->max_size; i++) {
		key[KEY_SIGNAL_TRG][i] = key[KEY_SIGNAL_NOW][i] & ~key[KEY_SIGNAL_OLD][i];
		key[KEY_SIGNAL_UP][i] = ~key[KEY_SIGNAL_NOW][i] & key[KEY_SIGNAL_OLD][i];
	}
	*/
}

//------------------------------------------------------
// @brief	�`��:�����p
//------------------------------------------------------
void Controller::Draw(void)
{
	// �ǂ̷���������Ă��邩
	for (int i = 0; i < 256; i++) 
	{
		if (key[KEY_SIGNAL_NOW][i] == true)
		{
			DrawFormatString(0, 16, 0xffffff, "���݉�����Ă��鷰:%d", i);
		}
	}
}

//------------------------------------------------------
// @brief	
//------------------------------------------------------
/*
const KEY_FLAG Controller::GetInputKey() const
{
	
}*/