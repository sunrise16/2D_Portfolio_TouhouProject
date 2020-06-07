#include "stdafx.h"
#include "random.h"

HRESULT random::init()
{
	// ���� �õ� �ʱ�ȭ
	srand(GetTickCount64());

	return S_OK;
}

void random::release()
{
}

int random::Range(int num)
{
	return rand() % num;
}

int random::Range(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

float random::Range(float num)
{
	// rand() / RAND_MAX => ���� ���� : 0.0f ~ 1.0f
	return ((float) rand() / (float) RAND_MAX) * num;
}

float random::Range(float min, float max)
{
	float rnd = ((float) rand() / (float) RAND_MAX);
	return (rnd * (max - min)) + min;
}
