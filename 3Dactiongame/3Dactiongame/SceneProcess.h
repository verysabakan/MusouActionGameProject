//------------------------------------------------------
// @brief	��݂̊�{�I�ȏ����̊��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// �������ߐ錾
class Controller;

// ��݂̊�{�����׽
class SceneProcess {
public:
	virtual ~SceneProcess() {}			// �޽�׸�
	virtual void Initialize(void) {}		// ������:�������Ȃ��Ă�����
	virtual void Finalize(void) {}			// �I������:�������Ȃ��Ă�����
	virtual void Update(const Controller& controll) = 0;			// �X�V:�K������
	virtual void Draw(void) = 0;			// �`��:�K������
};