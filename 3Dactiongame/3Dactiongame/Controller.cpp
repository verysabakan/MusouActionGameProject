//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
// 2020 5/16 Ryosuke Iida
//------------------------------------------------------

#include <DxLib.h>
#include "Controller.h"

#include "_Debug.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
Controller::Controller()
{
	// �߯�ޑΉ����݂̏�����
	SetPadInput(PAD_INPUT_UP, PAD_INPUT_DOWN, PAD_INPUT_LEFT, PAD_INPUT_RIGHT,
		PAD_INPUT_B, PAD_INPUT_A, PAD_INPUT_C, PAD_INPUT_X, defDeadZone);

	// �ϐ�������
	input = 0;
	inputOld = 0;
	leftLever = {};
	rightLever = {};
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
	inputOld = input;								// �O�����
	input = GetJoypadInputState(DX_INPUT_PAD1);		// ����̓���
	GetJoypadAnalogInput(&leftLever.x, &leftLever.y, DX_INPUT_PAD1);	// ����̍���ް����
	GetJoypadAnalogInputRight(&rightLever.x, &rightLever.y, DX_INPUT_PAD1);	// ����E��ް����

	// ���ް�ނ̊��蓖��(�����p)
	char keyInput[keyBuffer];
	GetHitKeyStateAll(keyInput);
	if (keyInput[KEY_INPUT_UP]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_UP)];
	if (keyInput[KEY_INPUT_DOWN]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)];
	if (keyInput[KEY_INPUT_LEFT]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)];
	if (keyInput[KEY_INPUT_RIGHT]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)];
	if (keyInput[KEY_INPUT_Z]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_1)];
	if (keyInput[KEY_INPUT_X]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_2)];
	if (keyInput[KEY_INPUT_C]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_3)];
	if (keyInput[KEY_INPUT_V]) input |= padInput[ConvertNum(PAD_BUTTON::PAD_4)];

	if (keyInput[KEY_INPUT_W]) rightLever.y = -1000;
	if (keyInput[KEY_INPUT_A]) rightLever.x = -1000;
	if (keyInput[KEY_INPUT_S]) rightLever.y = 1000;
	if (keyInput[KEY_INPUT_D]) rightLever.x = 1000;
}

//------------------------------------------------------
// @brief	�`��:�����p
//------------------------------------------------------
void Controller::Render()
{
	// ���ޯ�ނ̎������`��
#ifdef _DEBUG
	DebugDrawStart;
	// �ǂ�������Ă��邩
	for (auto i = begin(PAD_BUTTON()); i < end(PAD_BUTTON()); ++i)
	{
		if (input & padInput[ConvertNum(i)])
		{
			DFS(0, 16 + 16 * ConvertNum(i), 0xffffff, "%d:ΰ��ނł�", ConvertNum(i));
		}
	}
	// ���E��ް
	DFS(0, 144, 0xffffff, "%f", leftLever.x / tiltMax);
	DFS(0, 160, 0xffffff, "%f", leftLever.y / tiltMax);
	DFS(0, 176, 0xffffff, "%f", rightLever.x / tiltMax);
	DFS(0, 192, 0xffffff, "%f", rightLever.y / tiltMax);
	DebugDrawEnd;
#endif // _DEBUG
}

//------------------------------------------------------
// @brief	�߯�ޑΉ����݂̓o�^
// @param	�Ή��������݂̒l
//------------------------------------------------------
void Controller::SetPadInput(int up, int down, int left, int right, 
								int a, int b, int c, int d, double deadZone)
{
	// �Ή��������݂�����U��
	padInput[ConvertNum(PAD_BUTTON::PAD_UP)] = up;
	padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)] = down;
	padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)] = left;
	padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)] = right;
	padInput[ConvertNum(PAD_BUTTON::PAD_1)] = a;
	padInput[ConvertNum(PAD_BUTTON::PAD_2)] = b;
	padInput[ConvertNum(PAD_BUTTON::PAD_3)] = c;
	padInput[ConvertNum(PAD_BUTTON::PAD_4)] = d;
	deadZone;
	// �ޯ�޿ް�
	SetJoypadDeadZone(DX_INPUT_PAD1, deadZone);
}

//------------------------------------------------------
// @brief	�����݂̏�Ԃ�Ԃ�
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushUP(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD 
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_UP)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG 
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_UP)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP 
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_UP)])
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
const bool &Controller::IsPushDOWN(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_DOWN)])
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
const bool &Controller::IsPushLEFT(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_LEFT)])
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
const bool &Controller::IsPushRIGHT(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_RIGHT)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	1���݂̏�Ԃ�Ԃ�(xbox:B)
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushA(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_1)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_1)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_1)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	2���݂̏�Ԃ�Ԃ�(xbox:A)
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushB(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_2)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_2)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_2)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	3���݂̏�Ԃ�Ԃ�(xbox:X)
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushC(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_3)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_3)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_3)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	4���݂̏�Ԃ�Ԃ�(xbox:Y)
// @param	inputState	���݂̓���
// @return	������Ă����true
//------------------------------------------------------
const bool &Controller::IsPushD(const INPUT_STATE& inputState) const
{
	// ΰ��ށA�ضް�A���߂̏�Ԃ�Ԃ�
	if (inputState == INPUT_STATE::INPUT_HOLD
		&& input & padInput[ConvertNum(PAD_BUTTON::PAD_4)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_TRG
		&& input & ~inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_4)])
	{
		return true;
	}
	else if (inputState == INPUT_STATE::INPUT_UP
		&& ~input & inputOld & padInput[ConvertNum(PAD_BUTTON::PAD_4)])
	{
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	��ް�̉������̌X��(xbox:����ް)
// @param	t(Tilt)	���݂̌X�������邽�߂̓��ꕨ
// @return	������Ă����true
//------------------------------------------------------
const bool& Controller::IsLeftTiltX(float& t) const
{
	// ���͂������t�ɒl������true��Ԃ�
	if (leftLever.x != 0)
	{
		t = (float)leftLever.x / tiltMax;
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	��ް�̏c�����̌X��(xbox:����ް)
// @param	t(Tilt)	���݂̌X�������邽�߂̓��ꕨ
// @return	������Ă����true
//------------------------------------------------------
const bool& Controller::IsLeftTiltY(float& t) const
{
	// ���͂������t�ɒl������true��Ԃ�
	if (leftLever.y != 0)
	{
		t = (float)leftLever.y / tiltMax;
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	��ް�̉������̌X��(xbox:�E��ް)
// @param	t(Tilt)	���݂̌X�������邽�߂̓��ꕨ
// @return	������Ă����true
//------------------------------------------------------
const bool& Controller::IsRightTiltX(float& t) const
{
	// ���͂������t�ɒl������true��Ԃ�
	if (rightLever.x != 0)
	{
		t = (float)rightLever.x / tiltMax;
		return true;
	}

	return false;
}

//------------------------------------------------------
// @brief	��ް�̏c�����̌X��(xbox:�E��ް)
// @param	t(Tilt)	���݂̌X�������邽�߂̓��ꕨ
// @return	������Ă����true
//------------------------------------------------------
const bool& Controller::IsRightTiltY(float& t) const
{
	// ���͂������t�ɒl������true��Ԃ�
	if (rightLever.y != 0)
	{
		t = (float)rightLever.y / tiltMax;
		return true;
	}

	return false;
}