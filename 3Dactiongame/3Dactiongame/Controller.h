//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

// ���̓��͏��
enum KEY_SIGNAL
{
	KEY_SIGNAL_NOW,	// ����
	KEY_SIGNAL_OLD,	// �O�ڰ�
	KEY_SIGNAL_TRG,	// �����ꂽ�u��
	KEY_SIGNAL_UP,	// �����ꂽ�u��
	KEY_SIGNAL_MAX
};

using KEY_FLAG = std::array<char, 256>;
using PAD_FLAG = std::array<bool, 28>;

class Controller
{
public:
	Controller();
	~Controller();

	// ���̏�Ԃ��擾����֐�
	//const KEY_FLAG GetInputKey() const;
	// �߯�ނ̏�Ԃ��擾����֐�
	//const KEY_FLAG GetInputKey() const;

	void Update();	// �X�V
	void Draw();	// �`��:�����p

private:
	// �����ۑ��p
	KEY_FLAG key[KEY_SIGNAL_MAX];

	// �߯�ޏ��ۑ��p
	PAD_FLAG pad[KEY_SIGNAL_MAX];
};
