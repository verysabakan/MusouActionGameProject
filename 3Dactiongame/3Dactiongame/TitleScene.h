//------------------------------------------------------
// @brief	���ى��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

// ���ق̕��i
enum TITLE_PARTS
{
	TITLE_PARTS_EW,
	TITLE_PARTS_EXTREME,
	TITLE_PARTS_WARRIORS,
	TITLE_PARTS_MARK,
	TITLE_PARTS_MAX
};

class TitleScene
	: public BaseScene
{
public:
	TitleScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~TitleScene();							// �޽�׸�

	// -----���ްײ��----- //
	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

private:

	// �ϐ��̒�`
	int titleImage[TITLE_PARTS_MAX];	// ���ى摜:�߰���
	int bgImage;						// BACKGROUND:�w�i�摜
	int pabImage;						// PRESS ANY BUTTON:�������݉摜
};

