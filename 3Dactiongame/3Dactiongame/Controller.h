//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
//				���ް�ނ͈�l�p�A���۰װ�ŕ����l
// 2020 5/16 Ryosuke Iida
//------------------------------------------------------

#pragma once

//#include <array>

// ���͏��
enum INPUT_STATE
{
	INPUT_HOLD,
	INPUT_TRG,
	INPUT_UP
};

class Controller
{
private:
	// �߯�ޑΉ�����
	enum
	{
		PAD_UP,
		PAD_DOWN,
		PAD_LEFT,
		PAD_RIGHT,
		PAD_1,
		PAD_2,
		PAD_3,
		PAD_4,
		PAD_BUTTON_NUM,
	};

	static const int keyBuffer = 256;

	int padInput[PAD_BUTTON_NUM];	// �߯�ޏ��i�[�p
	int input;						// ���͏��
	int inputOld;					// �O��̓��͏��

public:
	Controller();	// �ݽ�׸�
	~Controller();	// �޽�׸�

	void Update();	// �X�V
	void Render();	// �`��:�����p

	void SetPadInput(int up, int down, int left, int right, int a, int b, int c, int d);	// �߯�ޑΉ����݂̓o�^
	const bool &IsPushUP(const INPUT_STATE inputState) const;
	const bool &IsPushDOWN(const INPUT_STATE inputState) const;
	const bool &IsPushLEFT(const INPUT_STATE inputState) const;
	const bool &IsPushRIGHT(const INPUT_STATE inputState) const;
	const bool &IsPushA(const INPUT_STATE inputState) const;
	const bool &IsPushB(const INPUT_STATE inputState) const;
	const bool &IsPushC(const INPUT_STATE inputState) const;
	const bool &IsPushD(const INPUT_STATE inputState) const;
};
