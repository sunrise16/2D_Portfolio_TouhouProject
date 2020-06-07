#pragma once
#include "singletonBase.h"

// random = 난수를 생성하는 클래스
class random : public singletonBase <random>
{
public:
	// 랜덤 매니저 초기화
	HRESULT init();

	// 랜덤 매니저 해제
	void release();

	// 난수 생성기 (함수 오버로딩 사용)
	int Range(int num);
	int Range(int min, int max);
	float Range(float num);
	float Range(float min, float max);

	random() {}
	~random() {}
};

