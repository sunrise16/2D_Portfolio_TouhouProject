#pragma once
#include "gameNode.h"

#define PI 3.14159f

// 플레이어 이동 상태 열거문
enum STATE_PLAYER
{
	PLAYER_FRONT = 0,
	PLAYER_LEFT = 1,
	PLAYER_RIGHT = 2
};

// 적 이동 상태 열거문
enum STATE_ENEMY
{
	ENEMY_FRONT = 0,
	ENEMY_LEFT = 1,
	ENEMY_RIGHT = 2
};

// 적 패턴 상태 열거문
enum STATE_PATTERN
{
	PATTERN_OFF = 0,
	PATTERN_1 = 1,
	PATTERN_2 = 2,
	PATTERN_3 = 3,
	PATTERN_4 = 4,
	PATTERN_5
};

// 플레이어 클래스
class tagPlayer
{
private:
	// 객체 관련
	RECT playerRect;		// 플레이어 개체
	
	// 변수 관련
	float x, y;				// 플레이어의 중점 좌표

public:
	// GET, SET 함수
	RECT getPlayerRect()
	{
		return playerRect;
	}
	void setPlayerRect(RECT _playerRect)
	{
		playerRect = _playerRect;
	}
	float getX()
	{
		return x;
	}
	void setX(float _x)
	{
		x = _x;
	}
	float getY()
	{
		return y;
	}
	void setY(float _y)
	{
		y = _y;
	}

	// 생성자, 소멸자
	tagPlayer() : x(0.0f), y(0.0f) {}
	tagPlayer(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	~tagPlayer() {}
};

// 탄막 클래스
class tagBullet
{
private:
	// 객체 관련
	RECT bulletRect;		// 탄막 개체

	// 변수 관련
	float x, y;				// 탄막의 중점 좌표
	float speed;			// 탄막의 속도
	float angle;			// 탄막의 각도
	float radius;			// 탄막의 반지름
	float gravity;			// 탄막의 중력
	bool shot;				// 탄막 발사 여부 판정
	int speedDelay;			// 속도 변화 시 딜레이
	int rotateDelay;		// 각도 변화 시 딜레이
	bool graze;				// 탄막 그레이즈
	bool reflect;			// 탄막 반사
	bool reflect_X;			// 탄막 반사 (X축)
	bool reflect_Y;			// 탄막 반사 (Y축)
	bool speedDown;			// 속도 감소 조건
	bool guidance;			// 조준탄 변화 조건

public:
	// GET, SET 함수
	RECT getBulletRect()
	{
		return bulletRect;
	}
	void setBulletRect(RECT _bulletRect)
	{
		bulletRect = _bulletRect;
	}
	float getX()
	{
		return x;
	}
	void setX(float _x)
	{
		x = _x;
	}
	float getY()
	{
		return y;
	}
	void setY(float _y)
	{
		y = _y;
	}
	float getSpeed()
	{
		return speed;
	}
	void setSpeed(float _speed)
	{
		speed = _speed;
	}
	float getAngle()
	{
		return angle;
	}
	void setAngle(float _angle)
	{
		angle = _angle;
	}
	float getRadius()
	{
		return radius;
	}
	void setRadius(float _radius)
	{
		radius = _radius;
	}
	float getGravity()
	{
		return gravity;
	}
	void setGravity(float _gravity)
	{
		gravity = _gravity;
	}
	bool getShot()
	{
		return shot;
	}
	void setShot(bool _shot)
	{
		shot = _shot;
	}
	int getSpeedDelay()
	{
		return speedDelay;
	}
	void setSpeedDelay(float _speedDelay)
	{
		speedDelay = _speedDelay;
	}
	int getRotateDelay()
	{
		return rotateDelay;
	}
	void setRotateDelay(float _rotateDelay)
	{
		rotateDelay = _rotateDelay;
	}
	bool getGraze()
	{
		return graze;
	}
	void setGraze(bool _graze)
	{
		graze = _graze;
	}
	bool getReflect()
	{
		return reflect;
	}
	void setReflect(bool _reflect)
	{
		reflect = _reflect;
	}
	bool getReflect_X()
	{
		return reflect_X;
	}
	void setReflect_X(bool _reflect_X)
	{
		reflect_X = _reflect_X;
	}
	bool getReflect_Y()
	{
		return reflect_Y;
	}
	void setReflect_Y(bool _reflect_Y)
	{
		reflect_Y = _reflect_Y;
	}
	bool getSpeedDown()
	{
		return speedDown;
	}
	void setSpeedDown(bool _speedDown)
	{
		speedDown = _speedDown;
	}
	bool getGuidance()
	{
		return guidance;
	}
	void setGuidance(bool _guidance)
	{
		guidance = _guidance;
	}

	// 생성자, 소멸자
	tagBullet() : x(0.0f), y(0.0f), speed(0.0f), angle(0.0f), radius(0.0f), gravity(0.0f), shot(FALSE), speedDelay(0), rotateDelay(0), graze(FALSE), reflect(FALSE), 
		reflect_X(FALSE), reflect_Y(FALSE), speedDown(FALSE), guidance(FALSE) {}
	tagBullet(float _x, float _y, float _speed, float _angle, float _radius, float _gravity, bool _shot,
		int _speedDelay = 0, int _rotateDelay = 0, bool _graze = FALSE, bool _reflect = FALSE,
		bool _reflect_X = FALSE, bool _reflect_Y = FALSE, bool _speedDown = FALSE, bool _guidance = FALSE)
	{
		x = _x;
		y = _y;
		speed = _speed;
		angle = _angle;
		radius = _radius;
		gravity = _gravity;
		shot = _shot;
		speedDelay = _speedDelay;
		rotateDelay = _rotateDelay;
		graze = _graze;
		reflect = _reflect;
		reflect_X = _reflect_X;
		reflect_Y = _reflect_Y;
		speedDown = _speedDown;
		guidance = _guidance;
	}
	~tagBullet() {}
};

// 이펙트 클래스
class tagEffect
{
private:
	// 객체 관련
	RECT effectRect;		// 이펙트 개체

	// 변수 관련
	float x, y;				// 이펙트의 중점 좌표
	float radius;			// 이펙트의 반지름
	int frameIndex;			// 이펙트의 프레임 이미지 인덱스
	int frameCount;			// 이펙트의 프레임 돌릴 카운트(속도 조절)
	bool shot;				// 이펙트 출력 여부 판정
	bool eraseEffect;		// 이펙트 제거 조건
	
public:
	// GET, SET 함수
	RECT getEffectRect()
	{
		return effectRect;
	}
	void setEffectRect(RECT _effectRect)
	{
		effectRect = _effectRect;
	}
	float getX()
	{
		return x;
	}
	void setX(float _x)
	{
		x = _x;
	}
	float getY()
	{
		return y;
	}
	void setY(float _y)
	{
		y = _y;
	}
	float getRadius()
	{
		return radius;
	}
	void setRadius(float _radius)
	{
		radius = _radius;
	}
	int getFrameIndex()
	{
		return frameIndex;
	}
	void setFrameIndex(int _frameIndex)
	{
		frameIndex = _frameIndex;
	}
	int getFrameCount()
	{
		return frameCount;
	}
	void setFrameCount(int _frameCount)
	{
		frameCount = _frameCount;
	}
	bool getShot()
	{
		return shot;
	}
	void setShot(bool _shot)
	{
		shot = _shot;
	}
	bool getEraseEffect()
	{
		return eraseEffect;
	}
	void setEraseEffect(bool _eraseEffect)
	{
		eraseEffect = _eraseEffect;
	}

	// 생성자, 소멸자
	tagEffect() : x(0.0f), y(0.0f), radius(0.0f), frameIndex(0), frameCount(0), shot(FALSE), eraseEffect(FALSE) {}
	tagEffect(float _x = 0.0f, float _y = 0.0f, float _radius = 0.0f, int _frameIndex = 0, int _frameCount = 0, bool _shot = FALSE, bool _eraseEffect = FALSE)
	{
		x = _x;
		y = _y;
		radius = _radius;
		frameIndex = _frameIndex;
		frameCount = _frameCount;
		shot = _shot;
		eraseEffect = _eraseEffect;
	}
	~tagEffect() {}
};

// 메인게임 클래스
class mainGame : public gameNode
{
private:
	// 이미지 관련 (배경 및 시스템)
	image* _bgTitle;												// 이미지 - 타이틀
	image* _bgBackgroundInformation;								// 이미지 - 배경 (정보칸)
	image* _bgGameStart;											// 이미지 - 게임 시작
	image* _bgGameRestart;											// 이미지 - 게임 재시작
	image* _bgGameOver;												// 이미지 - 게임 오버
	image* _bgGameWin;												// 이미지 - 게임 승리
	image* _bgInformation;											// 이미지 - 게임 내 정보

	// 이미지 관련 (플레이어)
	image* _bgPlayer;												// 이미지 - 플레이어
	image* _bgPlayerHitPoint;										// 이미지 - 플레이어 피탄점

	// 이미지 관련 (캐릭터)
	image* _bgCharacter;											// 이미지 - 캐릭터
	image* _bgCharacterHP;											// 이미지 - 캐릭터 HP
	image* _bgHitEffect;											// 이미지 - 피탄 이펙트

	// 이미지 관련 (탄막)
	image* _bgPlayerBullet;											// 이미지 - 플레이어 탄막
	image* _bgEnemyBullet;											// 이미지 - 컴퓨터 탄막
	image* _bgBulletEffect;											// 이미지 - 탄막 이펙트
	// PNG 사용할 경우 주석 없애기
	// Image* _bullet;
	// ULONG_PTR gdiplusToken;

	// 객체 관련 (플레이어)
	tagPlayer _player;												// 플레이어 객체
	tagPlayer _playerHitPoint;										// 플레이어 피탄점
	tagPlayer _playerGraze;											// 플레이어 그레이즈 박스
	tagPlayer _playerBomb;											// 플레이어 봄
	tagPlayer _playerHit;											// 플레이어 피탄 시 탄소거 박스
	tagPlayer _playerHitEffect;										// 플레이어 피탄 시 이펙트 출력 박스

	// 객체 관련 (적)
	tagPlayer _enemy;												// 적 객체

	// 객체 관련 (플레이어 탄막)
	vector<tagBullet> _bullet_player1;								// 플레이어 공격 탄막
	vector<tagEffect> _bullet_player1_effect;						// 플레이어 공격 탄막 이펙트

	// 객체 관련 (적 탄막)
	vector<tagBullet> _bullet_enemyPatternNormal1_1;				// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1
	vector<tagBullet> _bullet_enemyPatternNormal1_2;				// 컴퓨터 탄막 패턴 - 패턴 1 탄막 2
	vector<tagEffect> _bullet_enemyPatternNormal1_1_effect;			// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 이펙트
	vector<tagEffect> _bullet_enemyPatternNormal1_2_effect;			// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 이펙트
	
	vector<tagBullet> _bullet_enemyPatternNormal2_1;				// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1
	vector<tagBullet> _bullet_enemyPatternNormal2_2;				// 컴퓨터 탄막 패턴 - 패턴 2 탄막 2
	vector<tagEffect> _bullet_enemyPatternNormal2_1_effect;			// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 이펙트
	vector<tagEffect> _bullet_enemyPatternNormal2_2_effect;			// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 이펙트

	vector<tagBullet> _bullet_enemyPatternNormal3_1;				// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1
	vector<tagBullet> _bullet_enemyPatternNormal3_2;				// 컴퓨터 탄막 패턴 - 패턴 3 탄막 2
	vector<tagEffect> _bullet_enemyPatternNormal3_1_effect;			// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 이펙트
	vector<tagEffect> _bullet_enemyPatternNormal3_2_effect;			// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 이펙트

	vector<tagBullet> _bullet_enemyPatternNormal4_1;				// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1
	vector<tagBullet> _bullet_enemyPatternNormal4_2;				// 컴퓨터 탄막 패턴 - 패턴 4 탄막 2
	vector<tagEffect> _bullet_enemyPatternNormal4_1_effect;			// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 이펙트
	vector<tagEffect> _bullet_enemyPatternNormal4_2_effect;			// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 이펙트

	vector<tagBullet> _bullet_enemyPatternNormal5;					// 컴퓨터 탄막 패턴 - 패턴 5 탄막 
	vector<tagEffect> _bullet_enemyPatternNormal5_effect;			// 컴퓨터 탄막 패턴 - 패턴 5 탄막 이펙트

	// 변수 관련 (플레이어)
	bool playerAttack;												// 플레이어 공격
	int playerAttackDelay;											// 플레이어 공격 딜레이
	int playerExtend;												// 플레이어 잔기
	bool playerExtendDown;											// 피탄 시 플레이어 잔기 제거
	int playerBombStack;											// 플레이어 봄 갯수
	bool playerBombUse;												// 플레이어 봄 사용
	int playerBombDelay;											// 플레이어 봄 딜레이
	bool playerHit;													// 플레이어 피탄 판정
	bool playerHitDelay;											// 플레이어 피탄 시 무적 시간 딜레이
	int playerInvincibleDelay;										// 플레이어 무적 시간 카운트
	bool playerInvincible;											// 플레이어 무적 상태
	int playerInvincibleIndex;										// 플레이어 무적 상태 시 프레임 이미지 인덱스
	int playerInvincibleCount;										// 플레이어 무적 상태 시 프레임 돌릴 카운트
	int enemyHP;													// 적 체력

	// 변수 관련 (이미지)
	int playerHitPoint_alphaNum;									// 플레이어 피탄점 알파 블렌딩 - 내가 변경시킬 알파값
	int playerHitPoint_alphaCount;									// 플레이어 피탄점 알파 블렌딩 - 페이드 인, 아웃 시 속도 조절용
	int playerBomb_alphaNum;										// 플레이어 봄 알파 블렌딩 - 내가 변경시킬 알파값
	int playerBomb_alphaCount;										// 플레이어 봄 알파 블렌딩 - 페이드 인, 아웃 시 속도 조절용
	int player_front_frameIndex;									// 플레이어 (정면) - 프레임 이미지 인덱스
	int player_front_frameCount;									// 플레이어 (정면) - 프레임 돌릴 카운트 (속도 조절)
	int player_left_frameIndex;										// 플레이어 (좌측 이동) - 프레임 이미지 인덱스
	int player_left_frameCount;										// 플레이어 (좌측 이동) - 프레임 돌릴 카운트 (속도 조절)
	int player_right_frameIndex;									// 플레이어 (우측 이동) - 프레임 이미지 인덱스
	int player_right_frameCount;									// 플레이어 (우측 이동) - 프레임 돌릴 카운트 (속도 조절)
	int enemy_front_frameIndex;										// 적 (정면) - 프레임 이미지 인덱스
	int enemy_front_frameCount;										// 적 (정면) - 프레임 돌릴 카운트 (속도 조절)
	int playerHit_frameIndex;
	int playerHit_frameCount;
	bool player_leftMove;											// 플레이어 왼쪽 이동 이미지 표현
	bool player_rightMove;											// 플레이어 오른쪽 이동 이미지 표현
	int _loopX, _loopY;												// 루프시킬 변수들

	// 변수 관련 (시스템)
	STATE_PLAYER _playerState;										// 플레이어의 움직임 상태
	STATE_ENEMY _enemyState;										// 적의 움직임 상태
	int scorePoint;													// 점수 포인트
	int scorePoint_Num1;											// 점수 포인트 - 1의 자리
	int scorePoint_Num2;											// 점수 포인트 - 10의 자리
	int scorePoint_Num3;											// 점수 포인트 - 100의 자리
	int scorePoint_Num4;											// 점수 포인트 - 1000의 자리
	int scorePoint_Num5;											// 점수 포인트 - 10000의 자리
	int scorePoint_Num6;											// 점수 포인트 - 100000의 자리
	int scorePoint_Num7;											// 점수 포인트 - 1000000의 자리
	int scorePoint_Num8;											// 점수 포인트 - 10000000의 자리
	int scorePoint_Num9;											// 점수 포인트 - 100000000의 자리
	int scorePoint_Num10;											// 점수 포인트 - 1000000000의 자리
	int grazePoint;													// 그레이즈 포인트
	int grazePoint_Num1;											// 그레이즈 포인트 - 1의 자리
	int grazePoint_Num2;											// 그레이즈 포인트 - 10의 자리
	int grazePoint_Num3;											// 그레이즈 포인트 - 100의 자리
	int grazePoint_Num4;											// 그레이즈 포인트 - 1000의 자리
	int grazePoint_Num5;											// 그레이즈 포인트 - 10000의 자리
	int patternDelay;												// 패턴 교체 딜레이
	bool gameStart;													// 게임 시작
	bool gameOver;													// 게임 오버
	bool gameWin;													// 게임 승리

	// 변수 관련 (적 탄막)
	int enemyPattern;												// 컴퓨터 현재 탄막 패턴
	bool enemyPatternChange;										// 컴퓨터 탄막 패턴 전환
	int enemyPatternChangeDelay;									// 컴퓨터 탄막 패턴 전환 딜레이

	// 패턴 1
	int enemyPatternNormal1_attackDelay1_1;							// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 공격 딜레이
	int enemyPatternNormal1_bulletTemp1_1;							// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 출력 제한
	bool enemyPatternNormal1_bulletDelay1_1;						// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 발사 딜레이
	int enemyPatternNormal1_bulletDelayTemp1_1;						// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 발사 딜레이 변수
	int enemyPatternNormal1_attackDelay1_2;							// 컴퓨터 탄막 패턴 - 패턴 1 탄막 2 공격 딜레이
	int enemyPatternNormal1_bulletTemp1_2;							// 컴퓨터 탄막 패턴 - 패턴 1 탄막 2 출력 제한

	// 패턴 2
	int enemyPatternNormal2_attackDelay1_1;							// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 공격 딜레이
	int enemyPatternNormal2_bulletTemp1_1;							// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 출력 제한
	int enemyPatternNormal2_attackDelay1_2;							// 컴퓨터 탄막 패턴 - 패턴 2 탄막 2 공격 딜레이
	int enemyPatternNormal2_bulletTemp1_2;							// 컴퓨터 탄막 패턴 - 패턴 2 탄막 2 출력 제한

	// 패턴 3
	int enemyPatternNormal3_attackDelay1_1;							// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 공격 딜레이
	int enemyPatternNormal3_bulletTemp1_1;							// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 출력 제한
	int enemyPatternNormal3_attackDelay1_2;							// 컴퓨터 탄막 패턴 - 패턴 3 탄막 2 공격 딜레이
	int enemyPatternNormal3_bulletTemp1_2;							// 컴퓨터 탄막 패턴 - 패턴 3 탄막 2 출력 제한

	// 패턴 4
	int enemyPatternNormal4_attackDelay1_1;							// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 공격 딜레이
	int enemyPatternNormal4_bulletTemp1_1;							// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 출력 제한
	int enemyPatternNormal4_attackDelay1_2;							// 컴퓨터 탄막 패턴 - 패턴 4 탄막 2 공격 딜레이
	int enemyPatternNormal4_bulletTemp1_2;							// 컴퓨터 탄막 패턴 - 패턴 4 탄막 2 출력 제한

	// 패턴 5
	int enemyPatternNormal5_attackDelay;							// 컴퓨터 탄막 패턴 - 패턴 5 탄막 공격 딜레이
	int enemyPatternNormal5_bulletTemp;								// 컴퓨터 탄막 패턴 - 패턴 5 탄막 출력 제한
	int enemyPatternNormal5_attackRank;								// 컴퓨터 탄막 패턴 - 패턴 5 탄막 랭크
	int enemyPatternNormal5_attackDelayTemp;						// 컴퓨터 탄막 패턴 - 패턴 5 탄막 공격 딜레이 랜덤값
	int enemyPatternNormal5_speedRand;								// 컴퓨터 탄막 패턴 - 패턴 5 탄막 속도 랜덤값
	int enemyPatternNormal5_randX;									// 컴퓨터 탄막 패턴 - 패턴 5 탄막 출력 X좌표
	int enemyPatternNormal5_randY;									// 컴퓨터 탄막 패턴 - 패턴 5 탄막 출력 Y좌표

	// 컴퓨터 무빙
	int enemyPatternNormal2_enemyMove;								// 컴퓨터 탄막 패턴 - 패턴 2 컴퓨터 무빙
	int enemyPatternNormal2_enemyMoveDelay;							// 컴퓨터 탄막 패턴 - 패턴 2 컴퓨터 무빙 딜레이
	int enemyPatternNormal3_enemyMove;								// 컴퓨터 탄막 패턴 - 패턴 3 컴퓨터 무빙
	int enemyPatternNormal3_enemyMoveDelay;							// 컴퓨터 탄막 패턴 - 패턴 3 컴퓨터 무빙 딜레이

public:
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 발사 함수
	void bulletFire_enemyPatternNormal1_1();
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 이동 함수
	void bulletMove_enemyPatternNormal1_1();
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 그레이즈 함수
	void graze_enemyPatternNormal1_1();
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 1 피탄 판정 함수
	void hit_enemyPatternNormal1_1();
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 2 발사 함수
	void bulletFire_enemyPatternNormal1_2();
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 2 이동 함수
	void bulletMove_enemyPatternNormal1_2();
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 2 그레이즈 함수
	void graze_enemyPatternNormal1_2();
	// 컴퓨터 탄막 패턴 - 패턴 1 탄막 2 피탄 판정 함수
	void hit_enemyPatternNormal1_2();

	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 발사 함수
	void bulletFire_enemyPatternNormal2_1();
	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 이동 함수
	void bulletMove_enemyPatternNormal2_1();
	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 그레이즈 함수
	void graze_enemyPatternNormal2_1();
	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 1 피탄 판정 함수
	void hit_enemyPatternNormal2_1();
	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 2 발사 함수
	void bulletFire_enemyPatternNormal2_2();
	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 2 이동 함수
	void bulletMove_enemyPatternNormal2_2();
	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 2 그레이즈 함수
	void graze_enemyPatternNormal2_2();
	// 컴퓨터 탄막 패턴 - 패턴 2 탄막 2 피탄 판정 함수
	void hit_enemyPatternNormal2_2();

	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 발사 함수
	void bulletFire_enemyPatternNormal3_1();
	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 이동 함수
	void bulletMove_enemyPatternNormal3_1();
	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 그레이즈 함수
	void graze_enemyPatternNormal3_1();
	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 1 피탄 판정 함수
	void hit_enemyPatternNormal3_1();
	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 2 발사 함수
	void bulletFire_enemyPatternNormal3_2();
	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 2 이동 함수
	void bulletMove_enemyPatternNormal3_2();
	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 2 그레이즈 함수
	void graze_enemyPatternNormal3_2();
	// 컴퓨터 탄막 패턴 - 패턴 3 탄막 2 피탄 판정 함수
	void hit_enemyPatternNormal3_2();

	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 발사 함수
	void bulletFire_enemyPatternNormal4_1();
	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 이동 함수
	void bulletMove_enemyPatternNormal4_1();
	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 그레이즈 함수
	void graze_enemyPatternNormal4_1();
	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 1 피탄 판정 함수
	void hit_enemyPatternNormal4_1();
	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 2 발사 함수
	void bulletFire_enemyPatternNormal4_2();
	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 2 이동 함수
	void bulletMove_enemyPatternNormal4_2();
	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 2 그레이즈 함수
	void graze_enemyPatternNormal4_2();
	// 컴퓨터 탄막 패턴 - 패턴 4 탄막 2 피탄 판정 함수
	void hit_enemyPatternNormal4_2();

	// 컴퓨터 탄막 패턴 - 패턴 5 탄막 발사 함수
	void bulletFire_enemyPatternNormal5();
	// 컴퓨터 탄막 패턴 - 패턴 5 탄막 이동 함수
	void bulletMove_enemyPatternNormal5();
	// 컴퓨터 탄막 패턴 - 패턴 5 탄막 그레이즈 함수
	void graze_enemyPatternNormal5();
	// 컴퓨터 탄막 패턴 - 패턴 5 탄막 피탄 판정 함수
	void hit_enemyPatternNormal5();

	// 컴퓨터 탄막 패턴 - 패턴 2 컴퓨터 무빙 함수
	void comMove_enemyPatternNormal2();
	// 컴퓨터 탄막 패턴 - 패턴 3 컴퓨터 무빙 함수
	void comMove_enemyPatternNormal3();

	// 이미지 애니메이션 출력 함수
	void animation();

	// 두 점 사이의 거리를 구하는 함수
	float getDistance(float startX, float startY, float endX, float endY);

	// 두 점 사이의 각도를 구하는 함수
	float getAngle(float startX, float startY, float endX, float endY);

	// 초기화는 여기에서 처리
	HRESULT init();

	// 해제는 여기에서 처리
	void release();

	// 계산식은 여기에서 처리
	void update();

	// 화면 출력은 여기에서 처리
	void render();

	// 생성자, 소멸자
	mainGame()
	{
		// PNG 사용할 경우 주석 없애기
		// GDIPLUS 초기화
		// GdiplusStartupInput gdiplusStartInput;
		// GdiplusStartup(&gdiplusToken, &gdiplusStartInput, NULL);
	}
	~mainGame()
	{
		// PNG 사용할 경우 주석 없애기
		// GDI+ 해제
		// GdiplusShutdown(gdiplusToken);
	}
};