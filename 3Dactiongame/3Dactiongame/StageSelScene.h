//------------------------------------------------------
// @brief	�ð�ޑI�����
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

// �������ߐ錾
class SceneManager;

class StageSelScene
	: public BaseScene
{
public:	// �ݽ�׸�
	StageSelScene(SceneManager* sManager);
	~StageSelScene();					// �޽�׸�

	// -----���ްײ��----- //
	//virtual void Initialize() override;	// ������
	//virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��
};

