//------------------------------------------------------
// @brief	��{�I�ȏ����̊��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ��{�����׽
class BaseProcessing {
public:
	virtual ~BaseProcessing() {}	// �޽�׸�
	virtual void Initialize() {}	//������:�������Ȃ��Ă�����
	virtual void Finalize() {}		//�I������:�������Ȃ��Ă�����
	virtual void Update() = 0;		//�X�V:�K������
	virtual void Draw() = 0;		//�`��:�K������
};