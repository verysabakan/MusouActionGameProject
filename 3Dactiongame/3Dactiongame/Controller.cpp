//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
// 2020 5/16 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

bool up = false;
bool trg = false;

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Controller::Controller()
{
	// �߯�ޑΉ����݂̏�����
	SetPadInput(PAD_INPUT_UP, PAD_INPUT_DOWN, PAD_INPUT_LEFT, PAD_INPUT_RIGHT,
		PAD_INPUT_B, PAD_INPUT_A, PAD_INPUT_C, PAD_INPUT_X);

	// �ϐ�������
	input = 0;
	inputOld = 0;
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
void Controller::Update()
{
	// �O�����
	inputOld = input;

	// ����̓���
	input = GetJoypadInputState(DX_INPUT_PAD1);

	// ���ް�ނ̊��蓖��
	char keyInput[keyBuffer];
	GetHitKeyStateAll(keyInput);
	if (keyInput[KEY_INPUT_UP]) input |= padInput[PAD_UP];
	if (keyInput[KEY_INPUT_DOWN]) input |= padInput[PAD_DOWN];
	if (keyInput[KEY_INPUT_LEFT]) input |= padInput[PAD_LEFT];
	if (keyInput[KEY_INPUT_RIGHT]) input |= padInput[PAD_RIGHT];
	if (keyInput[KEY_INPUT_Z]) input |= padInput[PAD_1];
	if (keyInput[KEY_INPUT_X]) input |= padInput[PAD_2];
	if (keyInput[KEY_INPUT_C]) input |= padInput[PAD_3];
	if (keyInput[KEY_INPUT_V]) input |= padInput[PAD_4];
}

//------------------------------------------------------
// @brief	�`��:�����p
//------------------------------------------------------
void Controller::Render()
{
	// ������
	if (IsPushUP(INPUT_HOLD))
	{
		DrawString(0, 16, "ΰ��ނł�", 0xffffff);
		DrawFormatString(0, 32, 0xffffff, "%d", padInput[PAD_UP]);
	}

	// �������u��
	if (IsPushUP(INPUT_TRG))
	{
		trg = !trg;
	}
	if (trg) 
	{
		DrawString(0, 48, "�ضް�ł�", 0xffffff);
		DrawFormatString(0, 64, 0xffffff, "%d", padInput[PAD_UP]);
	}

	// �������u��
	if (IsPushUP(INPUT_UP))
	{
		up = !up;
	}
	if (up)
	{
		DrawString(0, 80, "���߂ł�", 0xffffff);
		DrawFormatString(0, 96, 0xffffff, "%d", padInput[PAD_UP]);
	}

	// �ǂ�������Ă��邩
	for (auto i = 0; i < PAD_BUTTON_NUM; i++)
	{
		if (input & padInput[i])
		{
			DrawFormatString(0, 112 + 16 * i, 0xffffff, "%d:ΰ��ނł�", i);
		}
	}
	
}

//------------------------------------------------------
// @brief	�߯�ޑΉ����݂̓o�^
// @param	�Ή��������݂̒l
//------------------------------------------------------
void Controller::SetPadInput(int up, int down, int left, int right, 
								int a, int b, int c, int d)
{
	// �Ή��������݂�����U��
	padInput[PAD_UP] = up;
	padInput[PAD_DOWN] = down;
	padInput[PAD_LEFT] = left;
	padInput[PAD_RIGHT] = right;
	padInput[PAD_1] = a;
	padInput[PAD_2] = b;
	padInput[PAD_3] = c;
	padInput[PAD_4] = d;
}

//------------------------------------------------------
// @brief	�����݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushUP(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_UP])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_UP])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_UP])
	{
		return true;
	}
	
	return false;
}

//------------------------------------------------------
// @brief	�����݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushDOWN(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_DOWN])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_DOWN])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_DOWN])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	�����݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushLEFT(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_LEFT])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_LEFT])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_LEFT])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	�E���݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushRIGHT(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_RIGHT])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_RIGHT])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_RIGHT])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	1���݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushA(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_1])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_1])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_1])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	2���݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushB(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_2])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_2])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_2])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	3���݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushC(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_3])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_3])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_3])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	4���݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushD(const INPUT_STATE inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_HOLD && input & padInput[PAD_4])
	{
		return true;
	}
	else if (inputState == INPUT_TRG && input & ~inputOld & padInput[PAD_4])
	{
		return true;
	}
	else if (inputState == INPUT_UP && ~input & inputOld & padInput[PAD_4])
	{
		return true;
	}

	return false;
}