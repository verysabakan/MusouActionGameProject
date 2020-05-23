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
	controll = std::make_unique<Controller>();
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
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);		// (��)
	ChangeWindowMode(TRUE);				// TRUE:����޳�AFALSE:�ٽ�ذ�
	SetDrawScreen(DX_SCREEN_BACK);		// �w�ʂɕ`��
	SetBackgroundColor(BACKGROUND_COLOR, BACKGROUND_COLOR, BACKGROUND_COLOR);	// �w�i�F
	SetUseZBuffer3D(TRUE);				// z�o�b�t�@��L���ɂ���
	SetWriteZBuffer3D(TRUE);			//���o�b�t�@�ւ̏������݂�L���ɂ���
	
	// ������
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
	controll.reset();
	frameRate.reset();

	// DxLib�̌�n��
	DxLib_End();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameTask::Update()
{
	// �ڰьv���Œ�
	frameRate->Update();

	// ��ݕʂ̍X�V
	sceneManager->Update(*controll);

	// ���۰װ�̍X�V
	controll->Update();
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameTask::Render()
{
	// ��ʂ�������
	ClearDrawScreen();

	// ��ݕʂ̕`��
	sceneManager->Render();

	// ���۰װ�̕`��:��������
	controll->Render();

	// ���݂��ڰ�ڰĂ̕`��
	frameRate->Render();

	// ����ʂ̓��e��\�ʂɔ��f������
	ScreenFlip();

	
}