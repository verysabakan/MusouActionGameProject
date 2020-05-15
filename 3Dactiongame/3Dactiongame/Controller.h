//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
//				���ް�ނ͈�l�p�A���۰װ�ŕ����l
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

#define KEY_STATE_BUFFER 256	// ���̏�Ԃ�ۑ�����ꏊ�̍ő�i�[��
#define PAD_STATE_BUFFER 28		// �߯�ނ̏�Ԃ�ۑ�����ꏊ�̍ő�i�[��

// ���͏��
enum INPUT_SIGNAL
{
	INPUT_SIGNAL_NOW,	// ����
	INPUT_SIGNAL_OLD,	// �O�ڰ�
	INPUT_SIGNAL_TRG,	// �������u��
	INPUT_SIGNAL_UP,	// �������u��
	INPUT_SIGNAL_MAX
};

//using KEY_FLAG = std::array<char, KEY_STATE_BUFFER>;
//using PAD_FLAG = std::array<bool, PAD_STATE_BUFFER>;

class Controller
{
public:
	Controller();	// �ݽ�׸�
	~Controller();	// �޽�׸�

	void Update(void);	// �X�V
	void Draw(void);	// �`��:�����p

	// ���A�߯�ނ��󂯎������Ԃł��邩�m�F����
	//const KEY_FLAG& GetInputKey(INPUT_SIGNAL requiredSignal) const;
	//const PAD_FLAG& GetInputButton(INPUT_SIGNAL requiredSignal) const;

private:
	// ���A�߯�ޏ��ۑ��p
	bool key[INPUT_SIGNAL_MAX][KEY_STATE_BUFFER];
	bool pad[INPUT_SIGNAL_MAX][KEY_STATE_BUFFER];
};
