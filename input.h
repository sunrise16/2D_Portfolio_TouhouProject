#pragma once
#include "singletonBase.h"

#define KEYMAX 256

// input = 키 입력을 처리하는 클래스
class input : public singletonBase<input>
{
private:
	bool _keyUp[KEYMAX];
	bool _keyDown[KEYMAX];

public:
	// 입력 매니저 초기화
	HRESULT init();

	// 입력 매니저 해제
	void release();

	// 키가 계속 눌려 있는지 체크
	bool getKey(int key);
	
	// 키가 한번만 눌렸는지 체크 (한번씩만 작동)
	bool getKeyDown(int key);

	// 키가 한번 눌렸다가 띄였는지 체크
	bool getKeyUp(int key);

	// 토글 키인지 체크 (유니티에는 이 기능이 없음)
	bool getToggleKey(int key);

	input() {}
	~input() {}
};

