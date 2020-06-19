//------------------------------------------------------
// @brief	�ð�ނ̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>


// �������ߐ錾
class Stage;

class StageManager
{
private:
	std::unique_ptr<Stage> stage;

public:
	StageManager(const STAGE_TYPE& sT);		// �ݽ�׸�
	~StageManager();	// �޽�׸�

	void Initialize();	// ������
	void Finalize();	// �I������
	void Update();		// �X�V
	void Render();	// �`��

	Stage* GetStage();	// �ð�ނ��擾
};

