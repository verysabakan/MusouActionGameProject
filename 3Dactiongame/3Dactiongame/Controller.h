//------------------------------------------------------
// @brief	���ް�ނ���۰װ����̑���A����
//				���ް�ނ͈�l�p�A���۰װ�ŕ����l
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <array>

#define KEY_STATE_BUFFER 256	// ���̏�Ԃ�ۑ�����ꏊ�̍ő�i�[��
#define PAD_STATE_BUFFER 28		// �߯�ނ̏�Ԃ�ۑ�����ꏊ�̍ő�i�[��

// ���͐M��
enum INPUT_STATE
{
	INPUT_STATE_NOW,	// ����
	INPUT_STATE_OLD,	// �O�ڰ�
	INPUT_STATE_TRG,	// �������u��
	INPUT_STATE_UP,		// �������u��
	INPUT_STATE_MAX
};

class Controller
{
public:
	Controller();	// �ݽ�׸�
	~Controller();	// �޽�׸�

	void Update(void);	// �X�V
	void Draw(void);	// �`��:�����p

	const bool& GetInputState(int const input,INPUT_STATE const inputState) const;	// ���͂��󂯎������Ԃɂ��邩�𔻒f���Ԃ�

private:
	// ���A�߯�ޏ��i�[�p
	bool key[INPUT_STATE_MAX][KEY_STATE_BUFFER];
	bool pad[INPUT_STATE_MAX][KEY_STATE_BUFFER];
};
