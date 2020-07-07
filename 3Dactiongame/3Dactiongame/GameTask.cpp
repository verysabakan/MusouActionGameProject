//------------------------------------------------------
// @brief	�ްю��̂̏������A�۰�A�I��
// 2020 5/14 Ryosuke Iida
//------------------------------------------------------

#include <assert.h>
#include <DxLib.h>
#include "GameTask.h"
#include "SceneManager.h"
#include "Controller.h"
#include "MainConstant.h"
#include "FrameRate.h"

//------------------------------------------------------
// @brief	�ݽ�׸�
//------------------------------------------------------
GameTask::GameTask()
{
	// ��޼ު�Đ���
	sceneManager = std::make_unique<SceneManager>();
	frameRate = std::make_unique<FrameRate>();
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
GameTask::~GameTask()
{
	// �����Ȃ�
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
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);		// ��ذ݂̻���
	ChangeWindowMode(TRUE);				// TRUE:����޳�AFALSE:�ٽ�ذ�
	SetDrawScreen(DX_SCREEN_BACK);		// �w�ʂɕ`��
	SetBackgroundColor(BACKGROUND_COLOR, BACKGROUND_COLOR, BACKGROUND_COLOR);	// �w�i�F
	SetUseZBuffer3D(TRUE);				// z�ޯ̧��L���ɂ���
	SetWriteZBuffer3D(TRUE);			// z�ޯ̧�ւ̏������݂�L���ɂ���
	
	// ����������
	sceneManager->Initialize();

	return 0;
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void GameTask::Finalize()
{
	// �e�I������
	sceneManager->Finalize();

	// ؿ���̊J��
	sceneManager.reset();
	frameRate.reset();

	// DxLib�̌�n��
	DxLib_End();	
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameTask::Update()
{
	frameRate->Update();	// �ڰьv���Œ�
	lpController.Update();	// ���۰װ�̍X�V
	sceneManager->Update();	// ��ݕʂ̍X�V
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameTask::Render()
{
	ClearDrawScreen();		// ��ʂ�������
	sceneManager->Render();	// ��ݕʂ̕`��
	lpController.Render();	// ���۰װ�̕`��:��������
	frameRate->Render();	// ���݂��ڰ�ڰĂ̕`��
	ScreenFlip();			// ����ʂ̓��e��\�ʂɔ��f������
}