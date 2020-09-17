//------------------------------------------------------
// @brief	¼Ý¸ÞÙÄÝ‚ðŽg‚¤Žž‚ÌŠî”Õ
// 2020 9/13 Ryosuke Iida
//------------------------------------------------------

#pragma once

template <typename _T>
class Singleton 
{
protected:
	Singleton() {}			// ºÝ½Ä×¸À
	virtual ~Singleton() {}	// ÃÞ½Ä×¸À

	Singleton(const Singleton& r) {}
	Singleton& operator=(const Singleton& r) {}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};
};