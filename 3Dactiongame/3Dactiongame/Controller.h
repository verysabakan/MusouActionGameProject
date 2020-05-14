//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
//				���ް�ނ͈�l�p�A���۰װ�ŕ����l
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

#define KEY_STATE_BUFFER 256	// ���̏�Ԃ�ۑ�����ꏊ�̍ő�i�[��
#define PAD_STATE_BUFFER 28		// �߯�ނ̏�Ԃ�ۑ�����ꏊ�̍ő�i�[��

// ���̓��͏��
enum KEY_SIGNAL
{
	KEY_SIGNAL_NOW,	// ����
	KEY_SIGNAL_OLD,	// �O�ڰ�
	KEY_SIGNAL_UP,	// �������u��
	KEY_SIGNAL_TRG,	// �������u��
	KEY_SIGNAL_MAX
};

using KEY_FLAG = std::array<char, KEY_STATE_BUFFER>;
using PAD_FLAG = std::array<int, PAD_STATE_BUFFER>;

class Controller
{
public:
	Controller();	// �ݽ�׸�
	~Controller();	// �޽�׸�

	void Update(void);	// �X�V
	void Draw(void);	// �`��:�����p

	// ���͏�Ԃ�Ԃ��֐�
	const bool SignalNow() const;
	const bool SignalUp() const;
	const bool SignalTrg() const;

	// ���̏�Ԃ��擾����֐�
	//const KEY_FLAG GetInputKey() const;
	// �߯�ނ̏�Ԃ��擾����֐�
	//const KEY_FLAG GetInputKey() const;

private:
	// �����ۑ��p
	KEY_FLAG key[KEY_SIGNAL_MAX];
	
	// �߯�ޏ��ۑ��p
	KEY_FLAG pad[KEY_SIGNAL_MAX];
};
