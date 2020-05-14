//------------------------------------------------------
// @brief	��{�I�ȏ����̊��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ��{�����׽
class BaseProcessing {
public:
	virtual ~BaseProcessing() {}			// �޽�׸�
	virtual void Initialize(void) {}		// ������:�������Ȃ��Ă�����
	virtual void Finalize(void) {}			// �I������:�������Ȃ��Ă�����
	virtual void Update(void) = 0;			// �X�V:�K������
	virtual void Draw(void) = 0;			// �`��:�K������
};