#pragma once
#include "gameNode.h"

#define PI 3.14159f

// �÷��̾� �̵� ���� ���Ź�
enum STATE_PLAYER
{
	PLAYER_FRONT = 0,
	PLAYER_LEFT = 1,
	PLAYER_RIGHT = 2
};

// �� �̵� ���� ���Ź�
enum STATE_ENEMY
{
	ENEMY_FRONT = 0,
	ENEMY_LEFT = 1,
	ENEMY_RIGHT = 2
};

// �� ���� ���� ���Ź�
enum STATE_PATTERN
{
	PATTERN_OFF = 0,
	PATTERN_1 = 1,
	PATTERN_2 = 2,
	PATTERN_3 = 3,
	PATTERN_4 = 4,
	PATTERN_5
};

// �÷��̾� Ŭ����
class tagPlayer
{
private:
	// ��ü ����
	RECT playerRect;		// �÷��̾� ��ü
	
	// ���� ����
	float x, y;				// �÷��̾��� ���� ��ǥ

public:
	// GET, SET �Լ�
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

	// ������, �Ҹ���
	tagPlayer() : x(0.0f), y(0.0f) {}
	tagPlayer(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	~tagPlayer() {}
};

// ź�� Ŭ����
class tagBullet
{
private:
	// ��ü ����
	RECT bulletRect;		// ź�� ��ü

	// ���� ����
	float x, y;				// ź���� ���� ��ǥ
	float speed;			// ź���� �ӵ�
	float angle;			// ź���� ����
	float radius;			// ź���� ������
	float gravity;			// ź���� �߷�
	bool shot;				// ź�� �߻� ���� ����
	int speedDelay;			// �ӵ� ��ȭ �� ������
	int rotateDelay;		// ���� ��ȭ �� ������
	bool graze;				// ź�� �׷�����
	bool reflect;			// ź�� �ݻ�
	bool reflect_X;			// ź�� �ݻ� (X��)
	bool reflect_Y;			// ź�� �ݻ� (Y��)
	bool speedDown;			// �ӵ� ���� ����
	bool guidance;			// ����ź ��ȭ ����

public:
	// GET, SET �Լ�
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

	// ������, �Ҹ���
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

// ����Ʈ Ŭ����
class tagEffect
{
private:
	// ��ü ����
	RECT effectRect;		// ����Ʈ ��ü

	// ���� ����
	float x, y;				// ����Ʈ�� ���� ��ǥ
	float radius;			// ����Ʈ�� ������
	int frameIndex;			// ����Ʈ�� ������ �̹��� �ε���
	int frameCount;			// ����Ʈ�� ������ ���� ī��Ʈ(�ӵ� ����)
	bool shot;				// ����Ʈ ��� ���� ����
	bool eraseEffect;		// ����Ʈ ���� ����
	
public:
	// GET, SET �Լ�
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

	// ������, �Ҹ���
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

// ���ΰ��� Ŭ����
class mainGame : public gameNode
{
private:
	// �̹��� ���� (��� �� �ý���)
	image* _bgTitle;												// �̹��� - Ÿ��Ʋ
	image* _bgBackgroundInformation;								// �̹��� - ��� (����ĭ)
	image* _bgGameStart;											// �̹��� - ���� ����
	image* _bgGameRestart;											// �̹��� - ���� �����
	image* _bgGameOver;												// �̹��� - ���� ����
	image* _bgGameWin;												// �̹��� - ���� �¸�
	image* _bgInformation;											// �̹��� - ���� �� ����

	// �̹��� ���� (�÷��̾�)
	image* _bgPlayer;												// �̹��� - �÷��̾�
	image* _bgPlayerHitPoint;										// �̹��� - �÷��̾� ��ź��

	// �̹��� ���� (ĳ����)
	image* _bgCharacter;											// �̹��� - ĳ����
	image* _bgCharacterHP;											// �̹��� - ĳ���� HP
	image* _bgHitEffect;											// �̹��� - ��ź ����Ʈ

	// �̹��� ���� (ź��)
	image* _bgPlayerBullet;											// �̹��� - �÷��̾� ź��
	image* _bgEnemyBullet;											// �̹��� - ��ǻ�� ź��
	image* _bgBulletEffect;											// �̹��� - ź�� ����Ʈ
	// PNG ����� ��� �ּ� ���ֱ�
	// Image* _bullet;
	// ULONG_PTR gdiplusToken;

	// ��ü ���� (�÷��̾�)
	tagPlayer _player;												// �÷��̾� ��ü
	tagPlayer _playerHitPoint;										// �÷��̾� ��ź��
	tagPlayer _playerGraze;											// �÷��̾� �׷����� �ڽ�
	tagPlayer _playerBomb;											// �÷��̾� ��
	tagPlayer _playerHit;											// �÷��̾� ��ź �� ź�Ұ� �ڽ�
	tagPlayer _playerHitEffect;										// �÷��̾� ��ź �� ����Ʈ ��� �ڽ�

	// ��ü ���� (��)
	tagPlayer _enemy;												// �� ��ü

	// ��ü ���� (�÷��̾� ź��)
	vector<tagBullet> _bullet_player1;								// �÷��̾� ���� ź��
	vector<tagEffect> _bullet_player1_effect;						// �÷��̾� ���� ź�� ����Ʈ

	// ��ü ���� (�� ź��)
	vector<tagBullet> _bullet_enemyPatternNormal1_1;				// ��ǻ�� ź�� ���� - ���� 1 ź�� 1
	vector<tagBullet> _bullet_enemyPatternNormal1_2;				// ��ǻ�� ź�� ���� - ���� 1 ź�� 2
	vector<tagEffect> _bullet_enemyPatternNormal1_1_effect;			// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 ����Ʈ
	vector<tagEffect> _bullet_enemyPatternNormal1_2_effect;			// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 ����Ʈ
	
	vector<tagBullet> _bullet_enemyPatternNormal2_1;				// ��ǻ�� ź�� ���� - ���� 2 ź�� 1
	vector<tagBullet> _bullet_enemyPatternNormal2_2;				// ��ǻ�� ź�� ���� - ���� 2 ź�� 2
	vector<tagEffect> _bullet_enemyPatternNormal2_1_effect;			// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 ����Ʈ
	vector<tagEffect> _bullet_enemyPatternNormal2_2_effect;			// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 ����Ʈ

	vector<tagBullet> _bullet_enemyPatternNormal3_1;				// ��ǻ�� ź�� ���� - ���� 3 ź�� 1
	vector<tagBullet> _bullet_enemyPatternNormal3_2;				// ��ǻ�� ź�� ���� - ���� 3 ź�� 2
	vector<tagEffect> _bullet_enemyPatternNormal3_1_effect;			// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 ����Ʈ
	vector<tagEffect> _bullet_enemyPatternNormal3_2_effect;			// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 ����Ʈ

	vector<tagBullet> _bullet_enemyPatternNormal4_1;				// ��ǻ�� ź�� ���� - ���� 4 ź�� 1
	vector<tagBullet> _bullet_enemyPatternNormal4_2;				// ��ǻ�� ź�� ���� - ���� 4 ź�� 2
	vector<tagEffect> _bullet_enemyPatternNormal4_1_effect;			// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 ����Ʈ
	vector<tagEffect> _bullet_enemyPatternNormal4_2_effect;			// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 ����Ʈ

	vector<tagBullet> _bullet_enemyPatternNormal5;					// ��ǻ�� ź�� ���� - ���� 5 ź�� 
	vector<tagEffect> _bullet_enemyPatternNormal5_effect;			// ��ǻ�� ź�� ���� - ���� 5 ź�� ����Ʈ

	// ���� ���� (�÷��̾�)
	bool playerAttack;												// �÷��̾� ����
	int playerAttackDelay;											// �÷��̾� ���� ������
	int playerExtend;												// �÷��̾� �ܱ�
	bool playerExtendDown;											// ��ź �� �÷��̾� �ܱ� ����
	int playerBombStack;											// �÷��̾� �� ����
	bool playerBombUse;												// �÷��̾� �� ���
	int playerBombDelay;											// �÷��̾� �� ������
	bool playerHit;													// �÷��̾� ��ź ����
	bool playerHitDelay;											// �÷��̾� ��ź �� ���� �ð� ������
	int playerInvincibleDelay;										// �÷��̾� ���� �ð� ī��Ʈ
	bool playerInvincible;											// �÷��̾� ���� ����
	int playerInvincibleIndex;										// �÷��̾� ���� ���� �� ������ �̹��� �ε���
	int playerInvincibleCount;										// �÷��̾� ���� ���� �� ������ ���� ī��Ʈ
	int enemyHP;													// �� ü��

	// ���� ���� (�̹���)
	int playerHitPoint_alphaNum;									// �÷��̾� ��ź�� ���� ���� - ���� �����ų ���İ�
	int playerHitPoint_alphaCount;									// �÷��̾� ��ź�� ���� ���� - ���̵� ��, �ƿ� �� �ӵ� ������
	int playerBomb_alphaNum;										// �÷��̾� �� ���� ���� - ���� �����ų ���İ�
	int playerBomb_alphaCount;										// �÷��̾� �� ���� ���� - ���̵� ��, �ƿ� �� �ӵ� ������
	int player_front_frameIndex;									// �÷��̾� (����) - ������ �̹��� �ε���
	int player_front_frameCount;									// �÷��̾� (����) - ������ ���� ī��Ʈ (�ӵ� ����)
	int player_left_frameIndex;										// �÷��̾� (���� �̵�) - ������ �̹��� �ε���
	int player_left_frameCount;										// �÷��̾� (���� �̵�) - ������ ���� ī��Ʈ (�ӵ� ����)
	int player_right_frameIndex;									// �÷��̾� (���� �̵�) - ������ �̹��� �ε���
	int player_right_frameCount;									// �÷��̾� (���� �̵�) - ������ ���� ī��Ʈ (�ӵ� ����)
	int enemy_front_frameIndex;										// �� (����) - ������ �̹��� �ε���
	int enemy_front_frameCount;										// �� (����) - ������ ���� ī��Ʈ (�ӵ� ����)
	int playerHit_frameIndex;
	int playerHit_frameCount;
	bool player_leftMove;											// �÷��̾� ���� �̵� �̹��� ǥ��
	bool player_rightMove;											// �÷��̾� ������ �̵� �̹��� ǥ��
	int _loopX, _loopY;												// ������ų ������

	// ���� ���� (�ý���)
	STATE_PLAYER _playerState;										// �÷��̾��� ������ ����
	STATE_ENEMY _enemyState;										// ���� ������ ����
	int scorePoint;													// ���� ����Ʈ
	int scorePoint_Num1;											// ���� ����Ʈ - 1�� �ڸ�
	int scorePoint_Num2;											// ���� ����Ʈ - 10�� �ڸ�
	int scorePoint_Num3;											// ���� ����Ʈ - 100�� �ڸ�
	int scorePoint_Num4;											// ���� ����Ʈ - 1000�� �ڸ�
	int scorePoint_Num5;											// ���� ����Ʈ - 10000�� �ڸ�
	int scorePoint_Num6;											// ���� ����Ʈ - 100000�� �ڸ�
	int scorePoint_Num7;											// ���� ����Ʈ - 1000000�� �ڸ�
	int scorePoint_Num8;											// ���� ����Ʈ - 10000000�� �ڸ�
	int scorePoint_Num9;											// ���� ����Ʈ - 100000000�� �ڸ�
	int scorePoint_Num10;											// ���� ����Ʈ - 1000000000�� �ڸ�
	int grazePoint;													// �׷����� ����Ʈ
	int grazePoint_Num1;											// �׷����� ����Ʈ - 1�� �ڸ�
	int grazePoint_Num2;											// �׷����� ����Ʈ - 10�� �ڸ�
	int grazePoint_Num3;											// �׷����� ����Ʈ - 100�� �ڸ�
	int grazePoint_Num4;											// �׷����� ����Ʈ - 1000�� �ڸ�
	int grazePoint_Num5;											// �׷����� ����Ʈ - 10000�� �ڸ�
	int patternDelay;												// ���� ��ü ������
	bool gameStart;													// ���� ����
	bool gameOver;													// ���� ����
	bool gameWin;													// ���� �¸�

	// ���� ���� (�� ź��)
	int enemyPattern;												// ��ǻ�� ���� ź�� ����
	bool enemyPatternChange;										// ��ǻ�� ź�� ���� ��ȯ
	int enemyPatternChangeDelay;									// ��ǻ�� ź�� ���� ��ȯ ������

	// ���� 1
	int enemyPatternNormal1_attackDelay1_1;							// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 ���� ������
	int enemyPatternNormal1_bulletTemp1_1;							// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 ��� ����
	bool enemyPatternNormal1_bulletDelay1_1;						// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 �߻� ������
	int enemyPatternNormal1_bulletDelayTemp1_1;						// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 �߻� ������ ����
	int enemyPatternNormal1_attackDelay1_2;							// ��ǻ�� ź�� ���� - ���� 1 ź�� 2 ���� ������
	int enemyPatternNormal1_bulletTemp1_2;							// ��ǻ�� ź�� ���� - ���� 1 ź�� 2 ��� ����

	// ���� 2
	int enemyPatternNormal2_attackDelay1_1;							// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 ���� ������
	int enemyPatternNormal2_bulletTemp1_1;							// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 ��� ����
	int enemyPatternNormal2_attackDelay1_2;							// ��ǻ�� ź�� ���� - ���� 2 ź�� 2 ���� ������
	int enemyPatternNormal2_bulletTemp1_2;							// ��ǻ�� ź�� ���� - ���� 2 ź�� 2 ��� ����

	// ���� 3
	int enemyPatternNormal3_attackDelay1_1;							// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 ���� ������
	int enemyPatternNormal3_bulletTemp1_1;							// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 ��� ����
	int enemyPatternNormal3_attackDelay1_2;							// ��ǻ�� ź�� ���� - ���� 3 ź�� 2 ���� ������
	int enemyPatternNormal3_bulletTemp1_2;							// ��ǻ�� ź�� ���� - ���� 3 ź�� 2 ��� ����

	// ���� 4
	int enemyPatternNormal4_attackDelay1_1;							// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 ���� ������
	int enemyPatternNormal4_bulletTemp1_1;							// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 ��� ����
	int enemyPatternNormal4_attackDelay1_2;							// ��ǻ�� ź�� ���� - ���� 4 ź�� 2 ���� ������
	int enemyPatternNormal4_bulletTemp1_2;							// ��ǻ�� ź�� ���� - ���� 4 ź�� 2 ��� ����

	// ���� 5
	int enemyPatternNormal5_attackDelay;							// ��ǻ�� ź�� ���� - ���� 5 ź�� ���� ������
	int enemyPatternNormal5_bulletTemp;								// ��ǻ�� ź�� ���� - ���� 5 ź�� ��� ����
	int enemyPatternNormal5_attackRank;								// ��ǻ�� ź�� ���� - ���� 5 ź�� ��ũ
	int enemyPatternNormal5_attackDelayTemp;						// ��ǻ�� ź�� ���� - ���� 5 ź�� ���� ������ ������
	int enemyPatternNormal5_speedRand;								// ��ǻ�� ź�� ���� - ���� 5 ź�� �ӵ� ������
	int enemyPatternNormal5_randX;									// ��ǻ�� ź�� ���� - ���� 5 ź�� ��� X��ǥ
	int enemyPatternNormal5_randY;									// ��ǻ�� ź�� ���� - ���� 5 ź�� ��� Y��ǥ

	// ��ǻ�� ����
	int enemyPatternNormal2_enemyMove;								// ��ǻ�� ź�� ���� - ���� 2 ��ǻ�� ����
	int enemyPatternNormal2_enemyMoveDelay;							// ��ǻ�� ź�� ���� - ���� 2 ��ǻ�� ���� ������
	int enemyPatternNormal3_enemyMove;								// ��ǻ�� ź�� ���� - ���� 3 ��ǻ�� ����
	int enemyPatternNormal3_enemyMoveDelay;							// ��ǻ�� ź�� ���� - ���� 3 ��ǻ�� ���� ������

public:
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 �߻� �Լ�
	void bulletFire_enemyPatternNormal1_1();
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 �̵� �Լ�
	void bulletMove_enemyPatternNormal1_1();
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 �׷����� �Լ�
	void graze_enemyPatternNormal1_1();
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 1 ��ź ���� �Լ�
	void hit_enemyPatternNormal1_1();
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 2 �߻� �Լ�
	void bulletFire_enemyPatternNormal1_2();
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 2 �̵� �Լ�
	void bulletMove_enemyPatternNormal1_2();
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 2 �׷����� �Լ�
	void graze_enemyPatternNormal1_2();
	// ��ǻ�� ź�� ���� - ���� 1 ź�� 2 ��ź ���� �Լ�
	void hit_enemyPatternNormal1_2();

	// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 �߻� �Լ�
	void bulletFire_enemyPatternNormal2_1();
	// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 �̵� �Լ�
	void bulletMove_enemyPatternNormal2_1();
	// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 �׷����� �Լ�
	void graze_enemyPatternNormal2_1();
	// ��ǻ�� ź�� ���� - ���� 2 ź�� 1 ��ź ���� �Լ�
	void hit_enemyPatternNormal2_1();
	// ��ǻ�� ź�� ���� - ���� 2 ź�� 2 �߻� �Լ�
	void bulletFire_enemyPatternNormal2_2();
	// ��ǻ�� ź�� ���� - ���� 2 ź�� 2 �̵� �Լ�
	void bulletMove_enemyPatternNormal2_2();
	// ��ǻ�� ź�� ���� - ���� 2 ź�� 2 �׷����� �Լ�
	void graze_enemyPatternNormal2_2();
	// ��ǻ�� ź�� ���� - ���� 2 ź�� 2 ��ź ���� �Լ�
	void hit_enemyPatternNormal2_2();

	// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 �߻� �Լ�
	void bulletFire_enemyPatternNormal3_1();
	// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 �̵� �Լ�
	void bulletMove_enemyPatternNormal3_1();
	// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 �׷����� �Լ�
	void graze_enemyPatternNormal3_1();
	// ��ǻ�� ź�� ���� - ���� 3 ź�� 1 ��ź ���� �Լ�
	void hit_enemyPatternNormal3_1();
	// ��ǻ�� ź�� ���� - ���� 3 ź�� 2 �߻� �Լ�
	void bulletFire_enemyPatternNormal3_2();
	// ��ǻ�� ź�� ���� - ���� 3 ź�� 2 �̵� �Լ�
	void bulletMove_enemyPatternNormal3_2();
	// ��ǻ�� ź�� ���� - ���� 3 ź�� 2 �׷����� �Լ�
	void graze_enemyPatternNormal3_2();
	// ��ǻ�� ź�� ���� - ���� 3 ź�� 2 ��ź ���� �Լ�
	void hit_enemyPatternNormal3_2();

	// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 �߻� �Լ�
	void bulletFire_enemyPatternNormal4_1();
	// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 �̵� �Լ�
	void bulletMove_enemyPatternNormal4_1();
	// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 �׷����� �Լ�
	void graze_enemyPatternNormal4_1();
	// ��ǻ�� ź�� ���� - ���� 4 ź�� 1 ��ź ���� �Լ�
	void hit_enemyPatternNormal4_1();
	// ��ǻ�� ź�� ���� - ���� 4 ź�� 2 �߻� �Լ�
	void bulletFire_enemyPatternNormal4_2();
	// ��ǻ�� ź�� ���� - ���� 4 ź�� 2 �̵� �Լ�
	void bulletMove_enemyPatternNormal4_2();
	// ��ǻ�� ź�� ���� - ���� 4 ź�� 2 �׷����� �Լ�
	void graze_enemyPatternNormal4_2();
	// ��ǻ�� ź�� ���� - ���� 4 ź�� 2 ��ź ���� �Լ�
	void hit_enemyPatternNormal4_2();

	// ��ǻ�� ź�� ���� - ���� 5 ź�� �߻� �Լ�
	void bulletFire_enemyPatternNormal5();
	// ��ǻ�� ź�� ���� - ���� 5 ź�� �̵� �Լ�
	void bulletMove_enemyPatternNormal5();
	// ��ǻ�� ź�� ���� - ���� 5 ź�� �׷����� �Լ�
	void graze_enemyPatternNormal5();
	// ��ǻ�� ź�� ���� - ���� 5 ź�� ��ź ���� �Լ�
	void hit_enemyPatternNormal5();

	// ��ǻ�� ź�� ���� - ���� 2 ��ǻ�� ���� �Լ�
	void comMove_enemyPatternNormal2();
	// ��ǻ�� ź�� ���� - ���� 3 ��ǻ�� ���� �Լ�
	void comMove_enemyPatternNormal3();

	// �̹��� �ִϸ��̼� ��� �Լ�
	void animation();

	// �� �� ������ �Ÿ��� ���ϴ� �Լ�
	float getDistance(float startX, float startY, float endX, float endY);

	// �� �� ������ ������ ���ϴ� �Լ�
	float getAngle(float startX, float startY, float endX, float endY);

	// �ʱ�ȭ�� ���⿡�� ó��
	HRESULT init();

	// ������ ���⿡�� ó��
	void release();

	// ������ ���⿡�� ó��
	void update();

	// ȭ�� ����� ���⿡�� ó��
	void render();

	// ������, �Ҹ���
	mainGame()
	{
		// PNG ����� ��� �ּ� ���ֱ�
		// GDIPLUS �ʱ�ȭ
		// GdiplusStartupInput gdiplusStartInput;
		// GdiplusStartup(&gdiplusToken, &gdiplusStartInput, NULL);
	}
	~mainGame()
	{
		// PNG ����� ��� �ּ� ���ֱ�
		// GDI+ ����
		// GdiplusShutdown(gdiplusToken);
	}
};