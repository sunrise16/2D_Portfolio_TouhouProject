#pragma once
#include "singletonBase.h"

// random = ������ �����ϴ� Ŭ����
class random : public singletonBase <random>
{
public:
	// ���� �Ŵ��� �ʱ�ȭ
	HRESULT init();

	// ���� �Ŵ��� ����
	void release();

	// ���� ������ (�Լ� �����ε� ���)
	int Range(int num);
	int Range(int min, int max);
	float Range(float num);
	float Range(float min, float max);

	random() {}
	~random() {}
};

