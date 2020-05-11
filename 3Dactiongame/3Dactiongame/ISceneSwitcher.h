//------------------------------------------------------
// @brief	��ݕύX���s�����߂̑���
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#pragma once

// ��ݐ؂�ւ��̂��߂̒萔
typedef enum {
	eScene_Title,		//���ى��
	eScene_ModeSel,		//Ӱ�ޑI�����
	eScene_CharSel,		//��׸���I�����
	eScene_StageSel,	//�ð�ޑI�����
	eScene_Game,		//�ްщ��

	eScene_None,		//����
} eScene;

class ISceneSwitcher
{
public:
	ISceneSwitcher();			// �ݽ�׸�
	virtual ~ISceneSwitcher();	// �޽�׸�

	virtual void SwitchScene(eScene NextScene) = 0;	// �w�肵����݂ɕύX
};