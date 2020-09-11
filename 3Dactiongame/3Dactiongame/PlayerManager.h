//------------------------------------------------------
// @brief	��ڲ԰�̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include "Vector3.h"
#include "ManagerBase.h"

// �������ߐ錾
class Camera;

class PlayerManager
	:public ManagerBase
{
private:
	std::unique_ptr<Camera> camera;
	
public:
	PlayerManager();	// �ݽ�׸�
	~PlayerManager();	// �޽�׸�

	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

};

