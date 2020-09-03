//------------------------------------------------------
// @brief	��ڲ԰�̊Ǘ�
// 2020 6/18 Ryosuke Iida
//------------------------------------------------------

#pragma once

#include <memory>
#include "Vector3.h"
#include "ObjectList.h"
#include "ManagerBase.h"

// �������ߐ錾
class Player;
class Camera;
class ModelBase;

class PlayerManager
	:private ObjectList,
	public ManagerBase
{
private:
	std::unique_ptr<Camera> camera;
	
public:
	PlayerManager();	// �ݽ�׸�
	~PlayerManager();				// �޽�׸�

	virtual void Initialize() override;	// ������
	virtual void Finalize() override;	// �I������
	virtual void Update() override;		// �X�V
	virtual void Render() override;		// �`��

	ModelBase* GetPlayer();	// ModelBase�̎擾

	virtual bool GetManagerType(MANAGER_TYPE type) final;	// ���߂̎擾(�ǂ����߂��m���߂�)
private:
	void SetPlayerMoveDir(const Vector3& cameraDir);	// �e��ׂ������ڲ԰�̓��������̎󂯓n������

};

