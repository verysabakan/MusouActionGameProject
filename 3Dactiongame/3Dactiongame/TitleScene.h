//------------------------------------------------------
// @brief	���ى��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "BaseScene.h"

class TitleScene
	: public BaseScene
{
public:
	TitleScene(ISceneSwitcher* switcher);	// �ݽ�׸�
	~TitleScene();							// �޽�׸�

	// ���ްײ��
	virtual void Initialize(void) override;	// ������
	virtual void Finalize(void) override;	// �I������
	virtual void Update(void) override;		// �X�V
	virtual void Draw(void) override;		// �`��

private:
	// ���ق̕��i
	enum TITLE_PARTS
	{
		TITLE_PARTS_EW,
		TITLE_PARTS_EXTREME,
		TITLE_PARTS_WARRIORS,
		TITLE_PARTS_MARK,
		TITLE_PARTS_MAX
	};

	// �ϐ��̒�`
	int titleImage[TITLE_PARTS_MAX];	// ���ى摜:�߰���
	int bgImage;						// BACKGROUND:�w�i�摜
	int pabImage;						// PRESS ANY BUTTON:�������݉摜
};

