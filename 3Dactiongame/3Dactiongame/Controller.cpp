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
	// -----���A�߯�ޓ��͏�Ԃ̏�����----- //
	for (int i = 0; i < INPUT_STATE_MAX; i++) {
		// ���ް��
		for (int j = 0; j < KEY_STATE_BUFFER; j++) 
		{
			key[i][j] = false;
		}

		// �߯��
		for (int j = 0; j < PAD_STATE_BUFFER; j++) 
		{
			pad[i][j] = false;
		}
	}
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
Controller::~Controller()
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void Controller::Update(void)
{
	// -----���͏�ԏ�����----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		// �S�������Ă��Ȃ����ɂ���
		key[INPUT_STATE_NOW][i] = false;
		key[INPUT_STATE_UP][i] = false;
		key[INPUT_STATE_TRG][i] = false;
	}

	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		// �S�������Ă��Ȃ����ɂ���
		pad[INPUT_STATE_NOW][i] = false;
		pad[INPUT_STATE_UP][i] = false;
		pad[INPUT_STATE_TRG][i] = false;
	}

	// -----���݂��ڰт̑S�Ă̓��͏�Ԃ̎擾----- //
	char keyBuffer[KEY_STATE_BUFFER];
	GetHitKeyStateAll(keyBuffer);
	auto pad1 = GetJoypadInputState(DX_INPUT_PAD1);		// 1P
	//auto pad2 = GetJoypadInputState(DX_INPUT_PAD1);		// 2P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);		// 3P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);		// 4P

	// -----���̂̓��͏�Ԃ̊i�[----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		if (keyBuffer[i] == 1)
		{
			key[INPUT_STATE_NOW][i] = true;
		}
	}

	// �߯�ނ̓��͏�Ԃ̊i�[
	for (int i = 0; i < PAD_STATE_BUFFER; i++) {
		if (pad1 & (1 << i)) {
			pad[INPUT_STATE_NOW][i] = true;
		}
	}

	// -----�����ꂽ�u�ԁA�����ꂽ�u�ԁA���ڰт̓��͕ۑ�----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		key[INPUT_STATE_UP][i] = ~key[INPUT_STATE_NOW][i] & key[INPUT_STATE_OLD][i]; 
		key[INPUT_STATE_TRG][i] = key[INPUT_STATE_NOW][i] & ~key[INPUT_STATE_OLD][i];
		key[INPUT_STATE_OLD][i] = key[INPUT_STATE_NOW][i];
	}

	for (int i = 0; i < PAD_STATE_BUFFER; i++)
	{
		pad[INPUT_STATE_UP][i] = pad[INPUT_STATE_NOW][i] & ~pad[INPUT_STATE_OLD][i];
		pad[INPUT_STATE_TRG][i] = ~pad[INPUT_STATE_NOW][i] & pad[INPUT_STATE_OLD][i];
		pad[INPUT_STATE_OLD][i] = pad[INPUT_STATE_NOW][i];
	}
}

//------------------------------------------------------
// @brief	�`��:�����p
//------------------------------------------------------
void Controller::Draw(void)
{
	// �ǂ̷���������Ă��邩
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		if (key[INPUT_STATE_NOW][i] == 1)
		{
			DrawFormatString(0, 16, 0xffffff, "���݉����Ă��鷰:%d", i);
		}
	}

	// �ǂ����݂�������Ă��邩
	for (int i = 0; i < PAD_STATE_BUFFER; i++)
	{
		if (pad[INPUT_STATE_NOW][i]) {
			DrawFormatString(0, 32, 0xffffff, "���݉����Ă�������:%d", i);
		}
	}
}

//------------------------------------------------------
// @brief	���͂��󂯎������Ԃɂ��邩�𔻒f���Ԃ�
//------------------------------------------------------
const bool& Controller::GetInputState(int const input, INPUT_STATE const inputState) const
{
	bool ret = false;

	// ���A�߯�ނ̓��͂��󂯎������Ԃ�
	if ((key[inputState][input] == true)
	||	(pad[inputState][input] == true))
	{
		ret = true;
	}

	return ret;
}