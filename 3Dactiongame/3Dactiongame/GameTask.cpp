//------------------------------------------------------
// @brief	�ްю��̂̏������A�۰�A�I��
// 2020 5/7 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "GameTask.h"
#include "SceneManager.h"
#include "Controller.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
GameTask::GameTask()
	: sceneManager(NULL)
	, controller(NULL)
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
GameTask::~GameTask()
{
	// �ُ�I��������
	assert(sceneManager == NULL);
	assert(controller == NULL);
}

//------------------------------------------------------
// @brief	������
//------------------------------------------------------
int GameTask::Initialize()
{
	// DxLib�̏���������
	if (DxLib_Init() == -1) {
		return -1;	// �װ���N������I��
	}

	// ���Ӱ�ނ̾��
	SetGraphMode(640, 480, 16);		// (��)
	ChangeWindowMode(TRUE);			// TRUE:����޳�AFALSE:�ٽ�ذ�

	// SceneManager�𐶐�
	sceneManager = new SceneManager();

	// Controller�𐶐�
	controller = new Controller();

	return 0;
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void GameTask::Finalize()
{
	// SceneManager���폜
	delete(sceneManager);
	sceneManager = NULL;

	// controller���폜
	delete(controller);
	controller = NULL;

	// DxLib�̌�n��
	DxLib_End();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameTask::Update()
{
	// ���۰װ�̍X�V
	controller->Update();

	// ��ݕʂ̍X�V
	sceneManager->Update();
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameTask::Draw()
{
	// ��ʂ�������
	ClearDrawScreen();

	// ���۰װ�̕`��:��������
	controller->Draw();

	// ��ݕʂ̕`��
	sceneManager->Draw();

	// ����ʂ̓��e��\�ʂɔ��f������
	ScreenFlip();
}