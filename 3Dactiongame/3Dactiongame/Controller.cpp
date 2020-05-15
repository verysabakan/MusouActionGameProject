//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

bool checkDayo = false;

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Controller::Controller()
{
	// -----���A�߯�ޓ��͏�Ԃ̏�����----- //
	for (int i = 0; i < INPUT_SIGNAL_MAX; i++) {
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
		key[INPUT_SIGNAL_NOW][i] = false;
		key[INPUT_SIGNAL_UP][i] = false;
		key[INPUT_SIGNAL_TRG][i] = false;
	}

	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		// �S�������Ă��Ȃ����ɂ���
		pad[INPUT_SIGNAL_NOW][i] = false;
		pad[INPUT_SIGNAL_UP][i] = false;
		pad[INPUT_SIGNAL_TRG][i] = false;
	}

	// -----���݂��ڰт̑S�Ă̓��͏�Ԃ̎擾----- //
	char keyBuffer[KEY_STATE_BUFFER];
	GetHitKeyStateAll(keyBuffer);
	auto pad1 = GetJoypadInputState(DX_INPUT_PAD1);		// 1P
	//auto pad2 = GetJoypadInputState(DX_INPUT_PAD1);		// 2P
	//auto pad3 = GetJoypadInputState(DX_INPUT_PAD1);		// 3P

	// -----���̂̓��͏�Ԃ̊i�[----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		if (keyBuffer[i] == 1)
		{
			key[INPUT_SIGNAL_NOW][i] = true;
		}
	}

	/*
	// �߯�ނ̓��͏�Ԃ̊i�[
	for (int i = 0; i < PAD_STATE_BUFFER; i++) {
		if (pad1 & ) {

		}
	}
	*/

	// -----�����ꂽ�u�ԁA�����ꂽ�u�ԁA���ڰт̓��͕ۑ�----- //
	for (int i = 0; i < KEY_STATE_BUFFER; i++)
	{
		key[INPUT_SIGNAL_UP][i] = ~key[INPUT_SIGNAL_NOW][i] & key[INPUT_SIGNAL_OLD][i]; 
		key[INPUT_SIGNAL_TRG][i] = key[INPUT_SIGNAL_NOW][i] & ~key[INPUT_SIGNAL_OLD][i];
		key[INPUT_SIGNAL_OLD][i] = key[INPUT_SIGNAL_NOW][i];
	}

	/*
	for (int i = 0; i < PAD_STATE_BUFFER; i++)
	{
		pad[INPUT_SIGNAL_UP][i] = pad[INPUT_SIGNAL_NOW][i] & ~pad[INPUT_SIGNAL_OLD][i];
		pad[INPUT_SIGNAL_TRG][i] = ~pad[INPUT_SIGNAL_NOW][i] & pad[INPUT_SIGNAL_OLD][i];
		pad[INPUT_SIGNAL_OLD][i] = pad[INPUT_SIGNAL_NOW][i];
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
		if (key[INPUT_SIGNAL_NOW][i] == 1)
		{
			DrawFormatString(0, 16, 0xffffff, "���݉����Ă��鷰:%d", i);
		}

		if ((key[INPUT_SIGNAL_TRG][i] == 1)&&(checkDayo == false))
		{
			checkDayo = true;
		}
		else if ((key[INPUT_SIGNAL_TRG][i] == 1) && (checkDayo == true))
		{
			checkDayo = false;
		}
	}

	if (checkDayo == true)
	{
		DrawString(0, 32, "�w�肵������������", 0xffffff);
	}

	// �ǂ����݂�������Ă��邩
	for (int i = 0; i < PAD_STATE_BUFFER; i++) {
		if (pad[INPUT_SIGNAL_NOW][i]) {
			DrawFormatString(0, 48, 0xffffff, "���݉����Ă�������:%d", i);
		}
	}
}

/*
//------------------------------------------------------
// @brief	�����󂯎������Ԃł��邩�m�F����
//------------------------------------------------------
const KEY_FLAG& Controller::GetInputKey(INPUT_SIGNAL requiredSignal) const
{
	return key[INPUT_SIGNAL_NOW][5];
}

//------------------------------------------------------
// @brief	�߯�ނ��󂯎������Ԃł��邩�m�F����
//------------------------------------------------------
const PAD_FLAG Controller::GetInputButton(INPUT_SIGNAL requiredSignal) const
{

}
*/