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
	// ���Ӱ�ނ̾��
	ChangeWindowMode(TRUE);				// TRUE:����޳�AFALSE:�ٽ�ذ�
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, COLLAR_BIT_NUM);		// ��ذ݂̻��ށA�ޯĐ�
	if (DxLib_Init() == -1){return -1;}	// DxLib�̏����������A�װ���N������I��
	SetDrawScreen(DX_SCREEN_BACK);		// �w�ʂɕ`��
	SetBackgroundColor(BACKGROUND_COLOR, BACKGROUND_COLOR, BACKGROUND_COLOR);	// �w�i�F
	//SetUseZBuffer3D(FALSE);			// z�ޯ̧��L���ɂ��邩(3D�̂�)
	//SetWriteZBuffer3D(FALSE);			// z�ޯ̧�ւ̏������݂�L���ɂ��邩(3D�̂�)
	SetUseZBufferFlag(FALSE);			// z�ޯ̧��L���ɂ��邩
	SetWriteZBufferFlag(FALSE);			// z�ޯ̧�ւ̏������݂�L���ɂ��邩
	SetUseLighting(TRUE);				// ײèݸތv�Z�������g�p���邩

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

	// DxLib�̌�n��
	DxLib_End();	
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameTask::Update()
{
	lpController->Update();	// ���۰װ�̍X�V
	sceneManager->Update();	// ��ݕʂ̍X�V
	lpFrameRate->Update();	// �ڰьv���Œ�
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameTask::Render()
{
	ClearDrawScreen();		// ��ʂ�������

	sceneManager->Render();	// ��ݕʂ̕`��
	lpController->Render();	// ���۰װ�̕`��:��������
	lpFrameRate->Render();	// ���݂��ڰ�ڰĂ̕`��

	ScreenFlip();			// ����ʂ̓��e��\�ʂɔ��f������
}