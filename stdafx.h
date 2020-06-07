#pragma once
#include <SDKDDKVer.h>

// GDI+ 사용
#pragma comment(lib, "Gdiplus.lib")
#include <Ole2.h>
#include <gdiplus.h>
using namespace Gdiplus;

// 거의 사용되지 않는 내용은 Windows 헤더에서 제외
#define WIN32_LEAN_AND_MEAN
// Windows 헤더 파일
#include <Windows.h>
// C 런타임 헤더 파일
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <math.h>
// C++ 런타임 헤더 파일
#include <iostream>
using namespace std;
// 자주 사용하는 STL
#include <string>
#include <vector>
#include <map>

//=============================================================
//	## 직접 만든 헤더 파일을 이곳에 추가 ##
//=============================================================

#include "commonMacroFunction.h"
#include "input.h"
#include "random.h"
#include "imageManager.h"

//=============================================================
//	## 싱글톤 추가 ##
//=============================================================

#define INPUT input::getSingleton()
#define RANDOM random::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()

//=============================================================
//	## DEFINE 문 (윈도우창 초기화)
//=============================================================

#define WINNAME (LPTSTR)(TEXT("이종석_2D슈팅게임_동방프로젝트 모작"))
#define WINSTARTX	500
#define WINSTARTY	100
#define WINSIZEX		1200
#define WINSIZEY		800
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

//=============================================================
//	## 매크로 함수 ## (클래스에서 동적 할당된 부분 해제)
//=============================================================

#define SAFE_DELETE(p)		{if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = NULL;}}

//=============================================================
//	## 전역 변수 ##
//=============================================================

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;