#pragma once
#include "singletonBase.h"

#define KEYMAX 256

// input = Ű �Է��� ó���ϴ� Ŭ����
class input : public singletonBase<input>
{
private:
	bool _keyUp[KEYMAX];
	bool _keyDown[KEYMAX];

public:
	// �Է� �Ŵ��� �ʱ�ȭ
	HRESULT init();

	// �Է� �Ŵ��� ����
	void release();

	// Ű�� ��� ���� �ִ��� üũ
	bool getKey(int key);
	
	// Ű�� �ѹ��� ���ȴ��� üũ (�ѹ����� �۵�)
	bool getKeyDown(int key);

	// Ű�� �ѹ� ���ȴٰ� �翴���� üũ
	bool getKeyUp(int key);

	// ��� Ű���� üũ (����Ƽ���� �� ����� ����)
	bool getToggleKey(int key);

	input() {}
	~input() {}
};

