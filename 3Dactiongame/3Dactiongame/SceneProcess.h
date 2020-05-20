//------------------------------------------------------
// @brief	��݂̊�{�I�ȏ����̊��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "Controller.h"

// ��݂̊�{�����׽
class SceneProcess {
public:
	virtual ~SceneProcess() {}			// �޽�׸�
	virtual void Initialize() {}		// ������:�������Ȃ��Ă�����
	virtual void Finalize() {}			// �I������:�������Ȃ��Ă�����
	virtual void Update(const Controller& controll) = 0;			// �X�V:�K������
	virtual void Render() = 0;			// �`��:�K������
};