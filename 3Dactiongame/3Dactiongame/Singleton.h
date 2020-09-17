//------------------------------------------------------
// @brief	�ݸ���݂��g�����̊��
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

template <typename _T>
class Singleton 
{
protected:
	Singleton() {}			// �ݽ�׸�
	virtual ~Singleton() {}	// �޽�׸�

	Singleton(const Singleton& r) {}
	Singleton& operator=(const Singleton& r) {}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};
};