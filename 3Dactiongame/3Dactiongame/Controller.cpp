//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

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
	auto pad1 = GetJoypadInputState(DX_INPUT_PAD1);	// 1P
	//auto pad2 = GetJoypadInputState(DX_INPUT_PAD1);	// 2P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);	// 3P

	for (int i = 0; i < 28; i++) {
		pad[KEY_SIGNAL_NOW][i] = pad1;
	}

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
		if (key[KEY_SIGNAL_NOW][i] == 1)
		{
			DrawFormatString(0, 16, 0xffffff, "���݉����Ă��鷰:%d", i);
			
			if (key[KEY_SIGNAL_NOW][KEY_INPUT_G] == 1) 
			{
				DrawString(0, 32, "�w�肵������������", 0xffffff);
			}
		}
	}

	// �ǂ����݂�������Ă��邩
	for (int i = 0; i < 28; i++) {
		if (pad[KEY_SIGNAL_NOW][i]) {
			DrawFormatString(0, 48, 0xffffff, "���݉����Ă�������:%d", i);
		}
	}

	DrawFormatString(0, 48, 0xffffff, "���݉����Ă�������:%d", KEY_INPUT_K);
}

//------------------------------------------------------
// @brief	
//------------------------------------------------------
/*
const KEY_FLAG Controller::GetInputKey() const
{
	
}*/