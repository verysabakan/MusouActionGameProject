//------------------------------------------------------
// @brief	�ްю��̂̏������A�۰�A�I��
// 2020 5/14 Ryosuke Iida
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
{
	// �����Ȃ�
}

//------------------------------------------------------
// @brief	�޽�׸�
//------------------------------------------------------
GameTask::~GameTask()
{
	// �ُ�I��������
	assert(sceneManager == nullptr);
	assert(controll == nullptr);
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
	SetGraphMode(1200, 720, 32);		// (��)
	ChangeWindowMode(TRUE);				// TRUE:����޳�AFALSE:�ٽ�ذ�
	SetDrawScreen(DX_SCREEN_BACK);		// �w�ʂɕ`��

	SetBackgroundColor(128, 128, 128);
	//z�o�b�t�@��L���ɂ���
	//SetUseZBuffer3D(true);
	//���o�b�t�@�ւ̏������݂�L���ɂ���
	//SetWriteZBuffer3D(true);
	

	// SceneManager�𐶐�
	sceneManager = std::make_unique<SceneManager>();

	// Controller�𐶐�
	controll = std::make_unique<Controller>();

	return 0;
}

//------------------------------------------------------
// @brief	�I������
//------------------------------------------------------
void GameTask::Finalize()
{
	// SceneManager���J��
	sceneManager.release();

	// controller���J��
	controll.release();

	// DxLib�̌�n��
	DxLib_End();
}

//------------------------------------------------------
// @brief	�X�V
//------------------------------------------------------
void GameTask::Update()
{
	// ��ݕʂ̍X�V
	sceneManager->Update((*controll));

	// ���۰װ�̍X�V
	controll->Update();
}

//------------------------------------------------------
// @brief	�`��
//------------------------------------------------------
void GameTask::Draw()
{
	// ��ʂ�������
	ClearDrawScreen();

	// ���۰װ�̕`��:��������
	controll->Draw();

	// ��ݕʂ̕`��
	sceneManager->Draw();

	// ����ʂ̓��e��\�ʂɔ��f������
	ScreenFlip();
}