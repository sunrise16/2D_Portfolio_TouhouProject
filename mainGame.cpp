#include "stdafx.h"
#include "mainGame.h"

// 초기화 (init)
HRESULT mainGame::init()
{
	// 이곳에서 초기화
	gameNode::init();

	// 백그라운드 이미지
	_bgTitle = IMAGEMANAGER->addImage("Title", "Title.bmp", 1200, 800);
	IMAGEMANAGER->addImage("Background", "Background.bmp", 800, 1600);
	IMAGEMANAGER->addImage("Bomb", "Bomb.bmp", 800, 800);
	_bgBackgroundInformation = IMAGEMANAGER->addImage("BackgroundInformation", "BackgroundInformation.bmp", 400, 800);
	_bgInformation = IMAGEMANAGER->addImage("Information", "Information.bmp", 0, 0, 300, 200, TRUE, RGB(255, 0, 255));

	// 시스템 이미지
	_bgGameStart = IMAGEMANAGER->addImage("GameStart", "GameStart.bmp", 0, 0, 600, 120, TRUE, RGB(255, 0, 255));
	_bgGameRestart = IMAGEMANAGER->addImage("GameRestart", "GameRestart.bmp", 0, 0, 600, 120, TRUE, RGB(255, 0, 255));
	_bgGameOver = IMAGEMANAGER->addImage("GameOver", "GameOver.bmp", 0, 0, 300, 200, TRUE, RGB(255, 0, 255));
	_bgGameWin = IMAGEMANAGER->addImage("GameWin", "GameWin.bmp", 0, 0, 500, 300, TRUE, RGB(255, 0, 255));

	// 플레이어 이미지
	_bgPlayer = IMAGEMANAGER->addImage("PlayerSprite", "PlayerSprite.bmp", 0, 0, 780, 1170, TRUE, RGB(255, 0, 255));
	_bgPlayerHitPoint = IMAGEMANAGER->addImage("Player_HitPoint", "Player_HitPoint.bmp", 0, 0, 20, 20, TRUE, RGB(255, 0, 255));

	// 캐릭터 이미지
	_bgCharacter = IMAGEMANAGER->addImage("CharacterSprite", "CharacterSprite.bmp", 0, 0, 1000, 900, TRUE, RGB(255, 0, 255));
	_bgCharacterHP = IMAGEMANAGER->addImage("PlayerSprite", "PlayerSprite.bmp", 0, 0, 780, 1170, TRUE, RGB(255, 0, 255));
	_bgHitEffect = IMAGEMANAGER->addImage("HitEffect", "HitEffect.bmp", 0, 0, 1400, 200, TRUE, RGB(255, 0, 255));

	// 플레이어 탄막 이미지
	_bgPlayerBullet = IMAGEMANAGER->addImage("PlayerSprite", "PlayerSprite.bmp", 0, 0, 780, 1170, TRUE, RGB(255, 0, 255));

	// 적 탄막 이미지
	_bgEnemyBullet = IMAGEMANAGER->addImage("BulletSprite", "BulletSprite.bmp", 0, 0, 1080, 1080, TRUE, RGB(255, 0, 255));

	// 탄막 이펙트 이미지
	_bgBulletEffect = IMAGEMANAGER->addImage("BulletEffect", "BulletEffect.bmp", 0, 0, 600, 150, TRUE, RGB(255, 0, 255));

	// 플레이어 좌표 초기화
	_player.setX(400);
	_player.setY(700);
	_player.setPlayerRect(RectMakeCenter(400, 700, 48, 66));
	_playerHitPoint.setX(400);
	_playerHitPoint.setY(700);
	_playerHitPoint.setPlayerRect(RectMakeCenter(400, 700, 6, 6));
	_playerGraze.setX(400);
	_playerGraze.setY(700);
	_playerGraze.setPlayerRect(RectMakeCenter(400, 700, 70, 90));
	_playerBomb.setX(400);
	_playerBomb.setY(400);
	_playerBomb.setPlayerRect(RectMakeCenter(_playerBomb.getX(), _playerBomb.getY(), 800, 800));
	_playerHit.setX(400);
	_playerHit.setY(1200);
	_playerHit.setPlayerRect(RectMakeCenter(_playerHit.getX(), _playerHit.getY(), 800, 800));
	_playerHitEffect.setX(400);
	_playerHitEffect.setY(900);
	_playerHitEffect.setPlayerRect(RectMakeCenter(_playerHitEffect.getX(), _playerHitEffect.getY(), 200, 200));

	// 적 좌표 초기화
	_enemy.setX(400);
	_enemy.setY(100);
	_enemy.setPlayerRect(RectMakeCenter(400, 100, 62, 64));

	// 플레이어 변수 초기화
	playerAttack = FALSE;
	playerAttackDelay = 0;
	playerExtend = 8;
	playerExtendDown = FALSE;
	playerBombStack = 3;
	playerBombUse = FALSE;
	playerBombDelay = 0;
	playerHit = FALSE;
	playerHitDelay = FALSE;
	playerInvincible = FALSE;
	playerInvincibleDelay = 0;
	playerInvincibleIndex = 0;
	playerInvincibleCount = 0;
	enemyHP = 7000;

	// 적 탄막 변수 초기화
	enemyPattern = PATTERN_OFF;
	enemyPatternChange = FALSE;
	enemyPatternChangeDelay = 0;
	
	enemyPatternNormal1_attackDelay1_1 = 0;
	enemyPatternNormal1_bulletTemp1_1 = 0;
	enemyPatternNormal1_bulletDelay1_1 = FALSE;
	enemyPatternNormal1_bulletDelayTemp1_1 = 0;
	enemyPatternNormal1_attackDelay1_2 = 0;
	enemyPatternNormal1_bulletTemp1_2 = 0;

	enemyPatternNormal2_attackDelay1_1 = 0;
	enemyPatternNormal2_bulletTemp1_1 = 0;
	enemyPatternNormal2_attackDelay1_2 = 0;
	enemyPatternNormal2_bulletTemp1_2 = 0;

	enemyPatternNormal3_attackDelay1_1 = 0;
	enemyPatternNormal3_bulletTemp1_1 = 0;
	enemyPatternNormal3_attackDelay1_2 = 0;
	enemyPatternNormal3_bulletTemp1_2 = 0;

	enemyPatternNormal4_attackDelay1_1 = 0;
	enemyPatternNormal4_bulletTemp1_1 = 0;
	enemyPatternNormal4_attackDelay1_2 = 0;
	enemyPatternNormal4_bulletTemp1_2 = 0;

	enemyPatternNormal5_attackDelay = 0;
	enemyPatternNormal5_bulletTemp = 0;
	enemyPatternNormal5_attackRank = 0;
	enemyPatternNormal5_attackDelayTemp = 0;
	enemyPatternNormal5_speedRand = 0;
	enemyPatternNormal5_randX = 0;
	enemyPatternNormal5_randY = 0;

	enemyPatternNormal2_enemyMove = 0;
	enemyPatternNormal2_enemyMoveDelay = 0;
	enemyPatternNormal3_enemyMove = 0;
	enemyPatternNormal3_enemyMoveDelay = 0;

	// 이미지 변수 초기화
	playerHitPoint_alphaNum = 0;
	playerHitPoint_alphaCount = 0;
	playerBomb_alphaNum = 0;
	playerBomb_alphaCount = 0;
	player_front_frameIndex = 0;
	player_front_frameCount = 0;
	player_left_frameIndex = 0;
	player_left_frameCount = 0;
	player_right_frameIndex = 0;
	player_right_frameCount = 0;
	enemy_front_frameIndex = 0;
	enemy_front_frameCount = 0;
	playerHit_frameIndex = 0;
	playerHit_frameCount = 0;
	player_leftMove = FALSE;
	player_rightMove = FALSE;
	_loopX = 0;
	_loopY = 0;

	// 시스템 변수 초기화
	_playerState = PLAYER_FRONT;
	_enemyState = ENEMY_FRONT;
	scorePoint = 0;
	grazePoint = 0;
	scorePoint_Num1 = 0;
	scorePoint_Num2 = 0;
	scorePoint_Num3 = 0;
	scorePoint_Num4 = 0;
	scorePoint_Num5 = 0;
	scorePoint_Num6 = 0;
	scorePoint_Num7 = 0;
	scorePoint_Num8 = 0;
	scorePoint_Num9 = 0;
	scorePoint_Num10 = 0;
	grazePoint_Num1 = 0;
	grazePoint_Num2 = 0;
	grazePoint_Num3 = 0;
	grazePoint_Num4 = 0;
	grazePoint_Num5 = 0;

	// 게임 시작, 게임 오버, 게임 승리 변수 초기화
	gameStart = FALSE;
	gameOver = FALSE;
	gameWin = FALSE;

	// init 함수를 종료시키고 나가므로 이 밑에다가 코드를 적지 않을 것
	return S_OK;
}

// 해제 (release)
void mainGame::release()
{
	gameNode::release();
}

// 업데이트 (update)
void mainGame::update()
{
	gameNode::update();

	// 알파 블렌딩 - 페이드 인, 아웃 연출 시에 사용
	/*
	alphaCount++;
	if (alphaCount % 2 == 0)
	{
		alphaNum++;
		if (alphaNum > 255) alphaNum = 255;
	}
	*/

	// 게임 시작
	if (INPUT->getKey(VK_SPACE))
	{
		if (gameStart == FALSE)
		{
			gameStart = TRUE;
			gameOver = FALSE;
			enemyPattern = PATTERN_OFF;
			enemyPatternChange = TRUE;
		}

		// 게임 재시작
		if (gameStart == TRUE && gameOver == TRUE)
		{
			gameOver = FALSE;
			gameWin = FALSE;

			enemyPatternNormal1_attackDelay1_1 = 0;
			enemyPatternNormal1_bulletTemp1_1 = 0;
			enemyPatternNormal1_bulletDelay1_1 = 0;
			enemyPatternNormal1_bulletDelayTemp1_1 = 0;
			enemyPatternNormal1_attackDelay1_2 = 0;
			enemyPatternNormal1_bulletTemp1_2 = 0;

			enemyPatternNormal2_attackDelay1_1 = 0;
			enemyPatternNormal2_bulletTemp1_1 = 0;
			enemyPatternNormal2_attackDelay1_2 = 0;
			enemyPatternNormal2_bulletTemp1_2 = 0;

			enemyPatternNormal3_attackDelay1_1 = 0;
			enemyPatternNormal3_bulletTemp1_1 = 0;
			enemyPatternNormal3_attackDelay1_2 = 0;
			enemyPatternNormal3_bulletTemp1_2 = 0;

			enemyPatternNormal4_attackDelay1_1 = 0;
			enemyPatternNormal4_bulletTemp1_1 = 0;
			enemyPatternNormal4_attackDelay1_2 = 0;
			enemyPatternNormal4_bulletTemp1_2 = 0;

			enemyPatternNormal5_attackDelay = 0;
			enemyPatternNormal5_bulletTemp = 0;
			enemyPatternNormal5_attackRank = 0;
			enemyPatternNormal5_attackDelayTemp = 0;
			enemyPatternNormal5_speedRand = 0;
			enemyPatternNormal5_randX = 0;
			enemyPatternNormal5_randY = 0;

			_player.setX(400);
			_player.setY(700);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));

			_playerHitPoint.setX(400);
			_playerHitPoint.setY(700);
			_playerHitPoint.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 6, 6));

			_playerGraze.setX(400);
			_playerGraze.setY(700);
			_playerGraze.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 70, 90));

			_playerBomb.setX(400);
			_playerBomb.setY(400);
			_playerBomb.setPlayerRect(RectMakeCenter(_playerBomb.getX(), _playerBomb.getY(), 800, 800));

			_playerHit.setX(400);
			_playerHit.setY(1200);
			_playerHit.setPlayerRect(RectMakeCenter(_playerHit.getX(), _playerHit.getY(), 800, 800));

			_playerHitEffect.setX(400);
			_playerHitEffect.setY(900);
			_playerHitEffect.setPlayerRect(RectMakeCenter(_playerHitEffect.getX(), _playerHitEffect.getY(), 200, 200));

			_enemy.setX(400);
			_enemy.setY(100);
			_enemy.setPlayerRect(RectMakeCenter(_enemy.getX(), _enemy.getY(), 62, 64));

			_bullet_player1.clear();
			_bullet_player1_effect.clear();

			switch (enemyPattern)
			{
			case PATTERN_1:
				_bullet_enemyPatternNormal1_1.clear();
				_bullet_enemyPatternNormal1_2.clear();
				_bullet_enemyPatternNormal1_1_effect.clear();
				_bullet_enemyPatternNormal1_2_effect.clear();
				break;
			case PATTERN_2:
				_bullet_enemyPatternNormal2_1.clear();
				_bullet_enemyPatternNormal2_2.clear();
				_bullet_enemyPatternNormal2_1_effect.clear();
				_bullet_enemyPatternNormal2_2_effect.clear();
				break;
			case PATTERN_3:
				_bullet_enemyPatternNormal3_1.clear();
				_bullet_enemyPatternNormal3_2.clear();
				_bullet_enemyPatternNormal3_1_effect.clear();
				_bullet_enemyPatternNormal3_2_effect.clear();
				break;
			case PATTERN_4:
				_bullet_enemyPatternNormal4_1.clear();
				_bullet_enemyPatternNormal4_2.clear();
				_bullet_enemyPatternNormal4_1_effect.clear();
				_bullet_enemyPatternNormal4_2_effect.clear();
				break;
			case PATTERN_5:
				_bullet_enemyPatternNormal5.clear();
				_bullet_enemyPatternNormal5_effect.clear();
				break;
			}

			scorePoint = 0;
			grazePoint = 0;
			playerExtend = 8;
			playerExtendDown = FALSE;
			playerBombStack = 3;
			playerBombUse = FALSE;
			playerHit = FALSE;
			playerInvincible = FALSE;
			playerBombDelay = 0;
			playerBomb_alphaNum = 0;
			playerBomb_alphaCount = 0;
			enemyHP = 7000;
			enemyPattern = PATTERN_OFF;
			enemyPatternChange = TRUE;
		}
	}

	// 게임 중 시스템
	if (gameStart == TRUE && gameOver == FALSE)
	{
		// 백그라운드 이미지 루프
		switch (enemyPattern)
		{
		case PATTERN_1:
			_loopY -= 6;
			break;
		case PATTERN_2:
			_loopY -= 7;
			break;
		case PATTERN_3:
			_loopY -= 8;
			break;
		case PATTERN_4:
			_loopY -= 9;
			break;
		case PATTERN_5:
			_loopY -= 10;
			break;
		}

		// 플레이어 캐릭터 고정
		_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));

		// 플레이어 피탄점 고정
		_playerHitPoint.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 6, 6));

		// 플레이어 그레이즈 박스 고정
		_playerGraze.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 70, 90));

		// 컴퓨터 캐릭터 고정
		_enemy.setPlayerRect(RectMakeCenter(_enemy.getX(), _enemy.getY(), 62, 64));

		// 플레이어 조작
		if (playerHit == FALSE)
		{
			// 왼쪽 이동
			if (INPUT->getKey(VK_LEFT))
			{
				// 화면 밖으로 벗어나지 않도록 처리
				if (_player.getPlayerRect().left > 0)
				{
					// 플레이어 상태 변화
					_playerState = PLAYER_LEFT;
					player_leftMove = TRUE;

					// 저속 이동
					if (INPUT->getKey(VK_LSHIFT))
					{
						_player.setX(_player.getX() - 2);
					}
					// 고속 이동
					else
					{
						_player.setX(_player.getX() - 6);
					}
				}
			}
			if (INPUT->getKeyUp(VK_LEFT))
			{
				_playerState = PLAYER_FRONT;
				player_leftMove = FALSE;
				player_left_frameCount = 0;
				player_left_frameIndex = 0;
			}
			// 오른쪽 이동
			if (INPUT->getKey(VK_RIGHT))
			{
				// 플레이어 상태 변화
				_playerState = PLAYER_RIGHT;
				player_rightMove = TRUE;

				// 화면 밖으로 벗어나지 않도록 처리
				if (_player.getPlayerRect().right < 800)
				{
					// 저속 이동
					if (INPUT->getKey(VK_LSHIFT))
					{
						_player.setX(_player.getX() + 2);
					}
					// 고속 이동
					else
					{
						_player.setX(_player.getX() + 6);
					}
				}
			}
			if (INPUT->getKeyUp(VK_RIGHT))
			{
				_playerState = PLAYER_FRONT;
				player_rightMove = FALSE;
				player_right_frameCount = 0;
				player_right_frameIndex = 0;
			}
			// 위쪽 이동
			if (INPUT->getKey(VK_UP))
			{
				// 플레이어 상태 변화
				_playerState = PLAYER_FRONT;

				// 화면 밖으로 벗어나지 않도록 처리
				if (_player.getPlayerRect().top > 0)
				{
					// 저속 이동
					if (INPUT->getKey(VK_LSHIFT))
					{
						_player.setY(_player.getY() - 2);
					}
					// 고속 이동
					else
					{
						_player.setY(_player.getY() - 6);
					}
				}
			}
			// 아래쪽 이동
			if (INPUT->getKey(VK_DOWN))
			{
				// 플레이어 상태 변화
				_playerState = PLAYER_FRONT;

				// 화면 밖으로 벗어나지 않도록 처리
				if (_player.getPlayerRect().bottom < 800)
				{
					// 저속 이동
					if (INPUT->getKey(VK_LSHIFT))
					{
						_player.setY(_player.getY() + 2);
					}
					// 고속 이동
					else
					{
						_player.setY(_player.getY() + 6);
					}
				}
			}
		}
		// 플레이어 공격
		if (INPUT->getKey(0x5A))
		{
			if (playerHit == FALSE)
			{
				playerAttack = TRUE;
			}
		}
		if (INPUT->getKeyUp(0x5A))
		{
			playerAttack = FALSE;
			playerAttackDelay = 0;
		}
		if (playerAttack == TRUE)
		{
			if (enemyPatternChange == FALSE)
			{
				playerAttackDelay++;

				if (playerAttackDelay >= 3)
				{
					playerAttackDelay = 0;
					for (int i = 0; i < 2; i++)
					{
						_bullet_player1.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
					}

					// 플레이어 탄막 세부 설정
					for (int i = 0; i < _bullet_player1.size(); i++)
					{
						if (_bullet_player1[i].getShot() == TRUE)
						{
							continue;
						}
						else
						{
							if (i % 2 == 0)
							{
								_bullet_player1[i].setX(_player.getX() - 15);
							}
							else
							{
								_bullet_player1[i].setX(_player.getX() + 15);
							}
							_bullet_player1[i].setY(_player.getY());
							_bullet_player1[i].setSpeed(30.0f);
							_bullet_player1[i].setAngle(PI / 2);
							_bullet_player1[i].setRadius(10.5f);
							_bullet_player1[i].setGravity(0.0f);
							_bullet_player1[i].setShot(TRUE);
							_bullet_player1[i].setBulletRect(RectMakeCenter(_bullet_player1[i].getX(), _bullet_player1[i].getY(),
								_bullet_player1[i].getRadius() * 2, _bullet_player1[i].getRadius() * 2));;
						}
					}
				}
			}
		}
		// 플레이어 탄막 이동 처리
		for (int i = 0; i < _bullet_player1.size(); i++)
		{
			// 플레이어 탄막 이동 처리
			if (_bullet_player1[i].getShot() == TRUE)
			{
				_bullet_player1[i].setX(_bullet_player1[i].getX() + (cosf(_bullet_player1[i].getAngle()) * _bullet_player1[i].getSpeed()));
				_bullet_player1[i].setY(_bullet_player1[i].getY() + (-sinf(_bullet_player1[i].getAngle()) * _bullet_player1[i].getSpeed()));

				_bullet_player1[i].setBulletRect(RectMakeCenter(_bullet_player1[i].getX(), _bullet_player1[i].getY(),
					_bullet_player1[i].getRadius() * 2, _bullet_player1[i].getRadius() * 2));
			}

			// 화면 밖으로 벗어났을 경우 탄막 제거
			if ((_bullet_player1[i].getBulletRect().top >= 800 || _bullet_player1[i].getBulletRect().bottom <= -400 ||
				_bullet_player1[i].getBulletRect().right <= 0 || _bullet_player1[i].getBulletRect().left >= 800) &&
				_bullet_player1[i].getShot() == TRUE)
			{
				_bullet_player1[i].setShot(FALSE);
				_bullet_player1.erase(_bullet_player1.begin() + i);
			}
			// 적이 맞았을 시 플레이어 탄막 제거 및 이펙트 생성
			else if (collisionEllipseRectangleCheck(_enemy.getPlayerRect(), _bullet_player1[i].getBulletRect()))
			{
				_bullet_player1[i].setShot(FALSE);
				_bullet_player1_effect.push_back(tagEffect(_bullet_player1[i].getX(), _bullet_player1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
				_bullet_player1.erase(_bullet_player1.begin() + i);
				scorePoint += 10;
				if (enemyPatternChange == FALSE)
				{
					if (enemyPattern == PATTERN_1 || enemyPattern == PATTERN_4)
					{
						enemyHP -= 2;
					}
					else if (enemyPattern == PATTERN_2 || enemyPattern == PATTERN_3)
					{
						enemyHP -= 5;
					}
					else if (enemyPattern == PATTERN_5)
					{
						enemyHP -= 1;
					}
				}
			}
		}
		// 플레이어 이펙트 출력 및 제거
		for (int i = 0; i < _bullet_player1_effect.size(); i++)
		{
			_bullet_player1_effect[i].setEffectRect(RectMakeCenter(_bullet_player1_effect[i].getX(), _bullet_player1_effect[i].getY(),
				_bullet_player1_effect[i].getRadius() * 2, _bullet_player1_effect[i].getRadius() * 2));

			if (_bullet_player1_effect[i].getEraseEffect() == TRUE)
			{
				_bullet_player1_effect.erase(_bullet_player1_effect.begin() + i);
			}
		}
		// 플레이어 봄 사용
		if (INPUT->getKeyDown(0x58))
		{
			if (playerBombStack > 0 && playerBombUse == FALSE && playerHit == FALSE)
			{
				playerBombUse = TRUE;
				playerInvincible = TRUE;
				playerBombStack--;
				playerBomb_alphaCount = 0;
			}
		}
		// 봄을 사용했을 경우 화면 초기화
		if (playerBombUse == TRUE)
		{
			_playerBomb.setX(400);
			_playerBomb.setY(400);
			_playerBomb.setPlayerRect(RectMakeCenter(_playerBomb.getX(), _playerBomb.getY(), 800, 800));

			playerBombDelay++;

			// 컴퓨터 탄막 제거 및 이펙트 생성
			// 패턴 1
			for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal1_1[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal1_1[i].setShot(FALSE);
					_bullet_enemyPatternNormal1_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal1_1[i].getX(), _bullet_enemyPatternNormal1_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal1_1.erase(_bullet_enemyPatternNormal1_1.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal1_2.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal1_2[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal1_2[i].setShot(FALSE);
					_bullet_enemyPatternNormal1_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal1_2[i].getX(), _bullet_enemyPatternNormal1_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal1_2.erase(_bullet_enemyPatternNormal1_2.begin() + i);
				}
			}
			// 패턴 2
			for (int i = 0; i < _bullet_enemyPatternNormal2_1.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal2_1[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal2_1[i].setShot(FALSE);
					_bullet_enemyPatternNormal2_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal2_1[i].getX(), _bullet_enemyPatternNormal2_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal2_1.erase(_bullet_enemyPatternNormal2_1.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal2_2.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal2_2[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal2_2[i].setShot(FALSE);
					_bullet_enemyPatternNormal2_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal2_2[i].getX(), _bullet_enemyPatternNormal2_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal2_2.erase(_bullet_enemyPatternNormal2_2.begin() + i);
				}
			}
			// 패턴 3
			for (int i = 0; i < _bullet_enemyPatternNormal3_1.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal3_1[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal3_1[i].setShot(FALSE);
					_bullet_enemyPatternNormal3_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal3_1[i].getX(), _bullet_enemyPatternNormal3_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal3_1.erase(_bullet_enemyPatternNormal3_1.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal3_2[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal3_2[i].setShot(FALSE);
					_bullet_enemyPatternNormal3_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal3_2[i].getX(), _bullet_enemyPatternNormal3_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal3_2.erase(_bullet_enemyPatternNormal3_2.begin() + i);
				}
			}
			// 패턴 4
			for (int i = 0; i < _bullet_enemyPatternNormal4_1.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal4_1[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal4_1[i].setShot(FALSE);
					_bullet_enemyPatternNormal4_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal4_1[i].getX(), _bullet_enemyPatternNormal4_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal4_1.erase(_bullet_enemyPatternNormal4_1.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal4_2.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal4_2[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal4_2[i].setShot(FALSE);
					_bullet_enemyPatternNormal4_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal4_2[i].getX(), _bullet_enemyPatternNormal4_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal4_2.erase(_bullet_enemyPatternNormal4_2.begin() + i);
				}
			}
			// 패턴 5
			for (int i = 0; i < _bullet_enemyPatternNormal5.size(); i++)
			{
				if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal5[i].getBulletRect(), _playerBomb.getPlayerRect()))
				{
					_bullet_enemyPatternNormal5[i].setShot(FALSE);
					_bullet_enemyPatternNormal5_effect.push_back(tagEffect(_bullet_enemyPatternNormal5[i].getX(), _bullet_enemyPatternNormal5[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
					_bullet_enemyPatternNormal5.erase(_bullet_enemyPatternNormal5.begin() + i);
				}
			}

			// 컴퓨터 탄막 이펙트 출력 및 제거
			// 패턴 1
			for (int i = 0; i < _bullet_enemyPatternNormal1_1_effect.size(); i++)
			{
				_bullet_enemyPatternNormal1_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal1_1_effect[i].getX(), _bullet_enemyPatternNormal1_1_effect[i].getY(),
					_bullet_enemyPatternNormal1_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal1_1_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal1_1_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal1_1_effect.erase(_bullet_enemyPatternNormal1_1_effect.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal1_2_effect.size(); i++)
			{
				_bullet_enemyPatternNormal1_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal1_2_effect[i].getX(), _bullet_enemyPatternNormal1_2_effect[i].getY(),
					_bullet_enemyPatternNormal1_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal1_2_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal1_2_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal1_2_effect.erase(_bullet_enemyPatternNormal1_2_effect.begin() + i);
				}
			}
			// 패턴 2
			for (int i = 0; i < _bullet_enemyPatternNormal2_1_effect.size(); i++)
			{
				_bullet_enemyPatternNormal2_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal2_1_effect[i].getX(), _bullet_enemyPatternNormal2_1_effect[i].getY(),
					_bullet_enemyPatternNormal2_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal2_1_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal2_1_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal2_1_effect.erase(_bullet_enemyPatternNormal2_1_effect.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal2_2_effect.size(); i++)
			{
				_bullet_enemyPatternNormal2_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal2_2_effect[i].getX(), _bullet_enemyPatternNormal2_2_effect[i].getY(),
					_bullet_enemyPatternNormal2_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal2_2_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal2_2_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal2_2_effect.erase(_bullet_enemyPatternNormal2_2_effect.begin() + i);
				}
			}
			// 패턴 3
			for (int i = 0; i < _bullet_enemyPatternNormal3_1_effect.size(); i++)
			{
				_bullet_enemyPatternNormal3_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal3_1_effect[i].getX(), _bullet_enemyPatternNormal3_1_effect[i].getY(),
					_bullet_enemyPatternNormal3_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal3_1_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal3_1_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal3_1_effect.erase(_bullet_enemyPatternNormal3_1_effect.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal3_2_effect.size(); i++)
			{
				_bullet_enemyPatternNormal3_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal3_2_effect[i].getX(), _bullet_enemyPatternNormal3_2_effect[i].getY(),
					_bullet_enemyPatternNormal3_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal3_2_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal3_2_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal3_2_effect.erase(_bullet_enemyPatternNormal3_2_effect.begin() + i);
				}
			}
			// 패턴 4
			for (int i = 0; i < _bullet_enemyPatternNormal4_1_effect.size(); i++)
			{
				_bullet_enemyPatternNormal4_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal4_1_effect[i].getX(), _bullet_enemyPatternNormal4_1_effect[i].getY(),
					_bullet_enemyPatternNormal4_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal4_1_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal4_1_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal4_1_effect.erase(_bullet_enemyPatternNormal4_1_effect.begin() + i);
				}
			}
			for (int i = 0; i < _bullet_enemyPatternNormal4_2_effect.size(); i++)
			{
				_bullet_enemyPatternNormal4_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal4_2_effect[i].getX(), _bullet_enemyPatternNormal4_2_effect[i].getY(),
					_bullet_enemyPatternNormal4_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal4_2_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal4_2_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal4_2_effect.erase(_bullet_enemyPatternNormal4_2_effect.begin() + i);
				}
			}
			// 패턴 5
			for (int i = 0; i < _bullet_enemyPatternNormal5_effect.size(); i++)
			{
				_bullet_enemyPatternNormal5_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal5_effect[i].getX(), _bullet_enemyPatternNormal5_effect[i].getY(),
					_bullet_enemyPatternNormal5_effect[i].getRadius() * 2, _bullet_enemyPatternNormal5_effect[i].getRadius() * 2));

				if (_bullet_enemyPatternNormal5_effect[i].getEraseEffect() == TRUE)
				{
					_bullet_enemyPatternNormal5_effect.erase(_bullet_enemyPatternNormal5_effect.begin() + i);
				}
			}
			
			if (playerBombDelay >= 300)
			{
				playerBombDelay = 0;
				playerBombUse = FALSE;
				playerInvincible = FALSE;
				playerInvincibleIndex = 0;
				playerInvincibleCount = 0;
				playerBomb_alphaCount = 255;
			}
		}
		// 플레이어 피탄
		if (playerExtendDown == TRUE)
		{
			playerExtend--;
			playerBombStack = 3;
			playerExtendDown = FALSE;
		}
		if (playerHit == TRUE)
		{
			_playerState = PLAYER_FRONT;
			playerInvincible = TRUE;
			_playerHit.setY(_playerHit.getY() - 10);
			_playerHit.setPlayerRect(RectMakeCenter(_playerHit.getX(), _playerHit.getY(), 800, 800));

			if (_player.getY() >= 700)
			{
				_player.setY(_player.getY() - 2);
				_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
			}

			// 컴퓨터 탄막 제거 및 이펙트 생성
			// 패턴 1
			if (enemyPattern == PATTERN_1)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal1_1[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal1_1[i].setShot(FALSE);
						_bullet_enemyPatternNormal1_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal1_1[i].getX(), _bullet_enemyPatternNormal1_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal1_1.erase(_bullet_enemyPatternNormal1_1.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal1_2.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal1_2[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal1_2[i].setShot(FALSE);
						_bullet_enemyPatternNormal1_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal1_2[i].getX(), _bullet_enemyPatternNormal1_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal1_2.erase(_bullet_enemyPatternNormal1_2.begin() + i);
					}
				}
			}
			// 패턴 2
			else if (enemyPattern == PATTERN_2)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal2_1.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal2_1[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal2_1[i].setShot(FALSE);
						_bullet_enemyPatternNormal2_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal2_1[i].getX(), _bullet_enemyPatternNormal2_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal2_1.erase(_bullet_enemyPatternNormal2_1.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal2_2.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal2_2[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal2_2[i].setShot(FALSE);
						_bullet_enemyPatternNormal2_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal2_2[i].getX(), _bullet_enemyPatternNormal2_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal2_2.erase(_bullet_enemyPatternNormal2_2.begin() + i);
					}
				}
			}
			// 패턴 3
			else if (enemyPattern == PATTERN_3)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal3_1.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal3_1[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal3_1[i].setShot(FALSE);
						_bullet_enemyPatternNormal3_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal3_1[i].getX(), _bullet_enemyPatternNormal3_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal3_1.erase(_bullet_enemyPatternNormal3_1.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal3_2[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal3_2[i].setShot(FALSE);
						_bullet_enemyPatternNormal3_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal3_2[i].getX(), _bullet_enemyPatternNormal3_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal3_2.erase(_bullet_enemyPatternNormal3_2.begin() + i);
					}
				}
			}
			// 패턴 4
			else if (enemyPattern == PATTERN_4)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal4_1.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal4_1[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal4_1[i].setShot(FALSE);
						_bullet_enemyPatternNormal4_1_effect.push_back(tagEffect(_bullet_enemyPatternNormal4_1[i].getX(), _bullet_enemyPatternNormal4_1[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal4_1.erase(_bullet_enemyPatternNormal4_1.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal4_2.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal4_2[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal4_2[i].setShot(FALSE);
						_bullet_enemyPatternNormal4_2_effect.push_back(tagEffect(_bullet_enemyPatternNormal4_2[i].getX(), _bullet_enemyPatternNormal4_2[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal4_2.erase(_bullet_enemyPatternNormal4_2.begin() + i);
					}
				}
			}
			// 패턴 5
			else if (enemyPattern == PATTERN_5)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal5.size(); i++)
				{
					if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal5[i].getBulletRect(), _playerHit.getPlayerRect()))
					{
						_bullet_enemyPatternNormal5[i].setShot(FALSE);
						_bullet_enemyPatternNormal5_effect.push_back(tagEffect(_bullet_enemyPatternNormal5[i].getX(), _bullet_enemyPatternNormal5[i].getY(), 25.0f, 0, 0, FALSE, FALSE));
						_bullet_enemyPatternNormal5.erase(_bullet_enemyPatternNormal5.begin() + i);
					}
				}
			}

			// 컴퓨터 탄막 이펙트 출력 및 제거
			// 패턴 1
			if (enemyPattern == PATTERN_1)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal1_1_effect.size(); i++)
				{
					_bullet_enemyPatternNormal1_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal1_1_effect[i].getX(), _bullet_enemyPatternNormal1_1_effect[i].getY(),
						_bullet_enemyPatternNormal1_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal1_1_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal1_1_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal1_1_effect.erase(_bullet_enemyPatternNormal1_1_effect.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal1_2_effect.size(); i++)
				{
					_bullet_enemyPatternNormal1_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal1_2_effect[i].getX(), _bullet_enemyPatternNormal1_2_effect[i].getY(),
						_bullet_enemyPatternNormal1_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal1_2_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal1_2_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal1_2_effect.erase(_bullet_enemyPatternNormal1_2_effect.begin() + i);
					}
				}
			}
			// 패턴 2
			else if (enemyPattern == PATTERN_2)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal2_1_effect.size(); i++)
				{
					_bullet_enemyPatternNormal2_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal2_1_effect[i].getX(), _bullet_enemyPatternNormal2_1_effect[i].getY(),
						_bullet_enemyPatternNormal2_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal2_1_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal2_1_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal2_1_effect.erase(_bullet_enemyPatternNormal2_1_effect.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal2_2_effect.size(); i++)
				{
					_bullet_enemyPatternNormal2_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal2_2_effect[i].getX(), _bullet_enemyPatternNormal2_2_effect[i].getY(),
						_bullet_enemyPatternNormal2_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal2_2_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal2_2_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal2_2_effect.erase(_bullet_enemyPatternNormal2_2_effect.begin() + i);
					}
				}
			}
			// 패턴 3
			else if (enemyPattern == PATTERN_3)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal3_1_effect.size(); i++)
				{
					_bullet_enemyPatternNormal3_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal3_1_effect[i].getX(), _bullet_enemyPatternNormal3_1_effect[i].getY(),
						_bullet_enemyPatternNormal3_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal3_1_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal3_1_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal3_1_effect.erase(_bullet_enemyPatternNormal3_1_effect.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal3_2_effect.size(); i++)
				{
					_bullet_enemyPatternNormal3_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal3_2_effect[i].getX(), _bullet_enemyPatternNormal3_2_effect[i].getY(),
						_bullet_enemyPatternNormal3_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal3_2_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal3_2_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal3_2_effect.erase(_bullet_enemyPatternNormal3_2_effect.begin() + i);
					}
				}
			}
			// 패턴 4
			else if (enemyPattern == PATTERN_4)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal4_1_effect.size(); i++)
				{
					_bullet_enemyPatternNormal4_1_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal4_1_effect[i].getX(), _bullet_enemyPatternNormal4_1_effect[i].getY(),
						_bullet_enemyPatternNormal4_1_effect[i].getRadius() * 2, _bullet_enemyPatternNormal4_1_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal4_1_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal4_1_effect.erase(_bullet_enemyPatternNormal4_1_effect.begin() + i);
					}
				}
				for (int i = 0; i < _bullet_enemyPatternNormal4_2_effect.size(); i++)
				{
					_bullet_enemyPatternNormal4_2_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal4_2_effect[i].getX(), _bullet_enemyPatternNormal4_2_effect[i].getY(),
						_bullet_enemyPatternNormal4_2_effect[i].getRadius() * 2, _bullet_enemyPatternNormal4_2_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal4_2_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal4_2_effect.erase(_bullet_enemyPatternNormal4_2_effect.begin() + i);
					}
				}
			}
			// 패턴 5
			else if (enemyPattern == PATTERN_5)
			{
				for (int i = 0; i < _bullet_enemyPatternNormal5_effect.size(); i++)
				{
					_bullet_enemyPatternNormal5_effect[i].setEffectRect(RectMakeCenter(_bullet_enemyPatternNormal5_effect[i].getX(), _bullet_enemyPatternNormal5_effect[i].getY(),
						_bullet_enemyPatternNormal5_effect[i].getRadius() * 2, _bullet_enemyPatternNormal5_effect[i].getRadius() * 2));

					if (_bullet_enemyPatternNormal5_effect[i].getEraseEffect() == TRUE)
					{
						_bullet_enemyPatternNormal5_effect.erase(_bullet_enemyPatternNormal5_effect.begin() + i);
					}
				}
			}
			if (_playerHit.getPlayerRect().bottom <= 0)
			{
				_playerHit.setY(1200);
				playerHit = FALSE;
				playerHitDelay = TRUE;
			}
		}
		if (playerHitDelay == TRUE)
		{
			playerInvincibleDelay++;

			if (playerInvincibleDelay >= 200)
			{
				if (playerBombUse == FALSE)
				{
					playerInvincible = FALSE;
				}
				playerHitDelay = FALSE;
				playerInvincibleDelay = 0;
				playerInvincibleIndex = 0;
				playerInvincibleCount = 0;
				playerHit_frameIndex = 0;
				playerHit_frameCount = 0;
			}
		}

		// 컴퓨터 탄막 패턴 전환
		if (enemyPatternChange == TRUE)
		{
			enemyPatternChangeDelay++;
			if (enemyPatternChangeDelay >= 200)
			{
				if (enemyPattern == PATTERN_OFF)
				{
					enemyPattern = PATTERN_1;
				}
				else if (enemyPattern == PATTERN_1)
				{
					enemyPattern = PATTERN_2;
				}
				else if (enemyPattern == PATTERN_2)
				{
					enemyPattern = PATTERN_3;
				}
				else if (enemyPattern == PATTERN_3)
				{
					enemyPattern = PATTERN_4;
				}
				else if (enemyPattern == PATTERN_4)
				{
					enemyPattern = PATTERN_5;
				}
				enemyPatternChange = FALSE;
				enemyPatternChangeDelay = 0;
			}
		}
		if (enemyPattern == PATTERN_1 && enemyHP <= 5600)
		{
			_bullet_enemyPatternNormal1_1.clear();
			_bullet_enemyPatternNormal1_2.clear();
			_enemy.setX(400);
			enemyPatternChange = TRUE;
		}
		if (enemyPattern == PATTERN_2 && enemyHP <= 4200)
		{
			_bullet_enemyPatternNormal2_1.clear();
			_bullet_enemyPatternNormal2_2.clear();
			_enemy.setX(400);
			enemyPatternChange = TRUE;
		}
		if (enemyPattern == PATTERN_3 && enemyHP <= 2800)
		{
			_bullet_enemyPatternNormal3_1.clear();
			_bullet_enemyPatternNormal3_2.clear();
			_enemy.setX(400);
			enemyPatternChange = TRUE;
		}
		if (enemyPattern == PATTERN_4 && enemyHP <= 1400)
		{
			_bullet_enemyPatternNormal4_1.clear();
			_bullet_enemyPatternNormal4_2.clear();
			_enemy.setX(400);
			enemyPatternChange = TRUE;
		}
		if (enemyPattern == PATTERN_5 && enemyHP <= 0)
		{
			_bullet_enemyPatternNormal5.clear();
			_enemy.setX(400);
			gameOver = TRUE;
			gameWin = TRUE;
		}

		// 컴퓨터 탄막 패턴 - 패턴 1
		if (enemyPattern == PATTERN_1 && enemyPatternChange == FALSE)
		{
			this->bulletFire_enemyPatternNormal1_1();
			this->bulletMove_enemyPatternNormal1_1();
			this->graze_enemyPatternNormal1_1();
			this->hit_enemyPatternNormal1_1();

			this->bulletFire_enemyPatternNormal1_2();
			this->bulletMove_enemyPatternNormal1_2();
			this->graze_enemyPatternNormal1_2();
			this->hit_enemyPatternNormal1_2();
		}
		// 컴퓨터 탄막 패턴 - 패턴 2
		if (enemyPattern == PATTERN_2 && enemyPatternChange == FALSE)
		{
			this->bulletFire_enemyPatternNormal2_1();
			this->bulletMove_enemyPatternNormal2_1();
			this->graze_enemyPatternNormal2_1();
			this->hit_enemyPatternNormal2_1();

			this->bulletFire_enemyPatternNormal2_2();
			this->bulletMove_enemyPatternNormal2_2();
			this->graze_enemyPatternNormal2_2();
			this->hit_enemyPatternNormal2_2();

			this->comMove_enemyPatternNormal2();
		}
		// 컴퓨터 탄막 패턴 - 패턴 3
		if (enemyPattern == PATTERN_3 && enemyPatternChange == FALSE)
		{
			this->bulletFire_enemyPatternNormal3_1();
			this->bulletMove_enemyPatternNormal3_1();
			this->graze_enemyPatternNormal3_1();
			this->hit_enemyPatternNormal3_1();

			this->bulletFire_enemyPatternNormal3_2();
			this->bulletMove_enemyPatternNormal3_2();
			this->graze_enemyPatternNormal3_2();
			this->hit_enemyPatternNormal3_2();

			this->comMove_enemyPatternNormal3();
		}
		// 컴퓨터 탄막 패턴 - 패턴 4
		if (enemyPattern == PATTERN_4 && enemyPatternChange == FALSE)
		{
			this->bulletFire_enemyPatternNormal4_1();
			this->bulletMove_enemyPatternNormal4_1();
			this->graze_enemyPatternNormal4_1();
			this->hit_enemyPatternNormal4_1();

			this->bulletFire_enemyPatternNormal4_2();
			this->bulletMove_enemyPatternNormal4_2();
			this->graze_enemyPatternNormal4_2();
			this->hit_enemyPatternNormal4_2();
		}
		// 컴퓨터 탄막 패턴 - 패턴 5
		if (enemyPattern == PATTERN_5 && enemyPatternChange == FALSE)
		{
			this->bulletFire_enemyPatternNormal5();
			this->bulletMove_enemyPatternNormal5();
			this->graze_enemyPatternNormal5();
			this->hit_enemyPatternNormal5();
		}

		// 점수 체크
		scorePoint_Num1 = scorePoint % 10;
		scorePoint_Num2 = ((scorePoint % 100) - scorePoint_Num1) / 10;
		scorePoint_Num3 = ((scorePoint % 1000) - scorePoint_Num2) / 100;
		scorePoint_Num4 = ((scorePoint % 10000) - scorePoint_Num3) / 1000;
		scorePoint_Num5 = ((scorePoint % 100000) - scorePoint_Num4) / 10000;
		scorePoint_Num6 = ((scorePoint % 1000000) - scorePoint_Num5) / 100000;
		scorePoint_Num7 = ((scorePoint % 10000000) - scorePoint_Num6) / 1000000;
		scorePoint_Num8 = ((scorePoint % 100000000) - scorePoint_Num7) / 10000000;
		scorePoint_Num9 = ((scorePoint % 1000000000) - scorePoint_Num8) / 100000000;
		scorePoint_Num10 = ((scorePoint % 10000000000) - scorePoint_Num9) / 1000000000;

		// 그레이즈 체크
		grazePoint_Num1 = grazePoint % 10;
		grazePoint_Num2 = ((grazePoint % 100) - grazePoint_Num1) / 10;
		grazePoint_Num3 = ((grazePoint % 1000) - grazePoint_Num2) / 100;
		grazePoint_Num4 = ((grazePoint % 10000) - grazePoint_Num3) / 1000;
		grazePoint_Num5 = ((grazePoint % 100000) - grazePoint_Num4) / 10000;

		// 플레이어 잔기가 0이거나 적의 체력이 0이 되었을 때 게임 오버
		if (enemyHP <= 0 || playerExtend < 0)
		{
			gameOver = TRUE;
		}
	}

	// 이미지 애니메이션 출력
	this->animation();
}

// 렌더 (render)
void mainGame::render()
{
	// PNG 사용할 경우 주석 없애기
	// Graphics ScreenG(getMemDC());
	
	// 흰색 빈 비트맵 (이것도 렌더에 두기)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	// 백그라운드 이미지 렌더 (루프 렌더)
	RECT rc2 = RectMake(0, 0, 800, 800);
	IMAGEMANAGER->loopRender("Background", getMemDC(), &rc2, _loopX, _loopY);

	// 플레이어 봄 사용시 이미지 렌더 (루프 렌더)
	RECT rcBomb = RectMake(0, 0, 800, 800);
	IMAGEMANAGER->loopAlphaRender("Bomb", getMemDC(), &rcBomb, _loopX * 5, _loopY * 5, playerBomb_alphaNum);
	if (playerBombUse == TRUE)
	{
		playerBomb_alphaCount++;
		if (playerBomb_alphaCount > 2)
		{
			playerBomb_alphaNum += 50;
			playerBomb_alphaCount = 0;
			if (playerBomb_alphaNum > 255)
			{
				playerBomb_alphaNum = 255;
			}
		}
	}

	// 플레이어 기체 출력
	if (playerHit == FALSE && playerInvincible == FALSE)
	{
		switch (_playerState)
		{
		case PLAYER_FRONT:
			_bgPlayer->frameRender(getMemDC(), _player.getPlayerRect().left, _player.getPlayerRect().top, 4, 788, 48, 66, 8, 1);
			break;
		case PLAYER_LEFT:
			if (player_leftMove == TRUE)
			{
				_bgPlayer->frameRender(getMemDC(), _player.getPlayerRect().left, _player.getPlayerRect().top, 4, 860, 48, 66, 8, 1);
			}
			break;
		case PLAYER_RIGHT:
			if (player_rightMove == TRUE)
			{
				_bgPlayer->frameRender(getMemDC(), _player.getPlayerRect().left, _player.getPlayerRect().top, 4, 932, 48, 66, 8, 1);
			}
			break;
		}
	}

	// 플레이어 피탄점 출력
	if (INPUT->getKey(VK_LSHIFT))
	{
		if (playerHit == FALSE)
		{
			playerHitPoint_alphaCount++;
			if (playerHitPoint_alphaCount % 2 == 0)
			{
				playerHitPoint_alphaNum += 20;
				if (playerHitPoint_alphaNum > 255)
				{
					playerHitPoint_alphaNum = 255;
				}
			}
			_bgPlayerHitPoint->alphaRender(getMemDC(), _player.getX() - 10, _player.getY() - 10, playerHitPoint_alphaNum);
		}
	}
	if (INPUT->getKeyUp(VK_LSHIFT))
	{
		if (playerHit == FALSE)
		{
			playerHitPoint_alphaCount = 0;
			playerHitPoint_alphaNum = 0;
		}
	}

	// 플레이어 탄막 출력
	for (int i = 0; i < _bullet_player1.size(); i++)
	{
		if (_bullet_player1[i].getShot() == TRUE)
		{
			_bgPlayerBullet->render(getMemDC(), _bullet_player1[i].getBulletRect().left, _bullet_player1[i].getBulletRect().top, 196, 998, 21, 21);
		}
	}
	for (int i = 0; i < _bullet_player1_effect.size(); i++)
	{
		if (_bullet_player1_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_player1_effect[i].getEffectRect().left, _bullet_player1_effect[i].getEffectRect().top, 0, 50, 50, 50, 12, 1);
		}
	}

	// 플레이어 피탄 출력
	if (playerHit == TRUE)
	{
		_bgHitEffect->frameRender(getMemDC(), _playerHitEffect.getPlayerRect().left, _playerHitEffect.getPlayerRect().top, 0, 0, 200, 200, 7, 1);
	}

	// 플레이어 무적 상태 출력
	if (playerInvincible == TRUE)
	{
		playerInvincibleCount++;
		if (playerInvincibleCount % 2 == 0)
		{
			playerInvincibleIndex++;
		}

		if (playerInvincibleIndex % 2 == 1)
		{
			switch (_playerState)
			{
			case PLAYER_FRONT:
				_bgPlayer->frameRender(getMemDC(), _player.getPlayerRect().left, _player.getPlayerRect().top, 4, 788, 48, 66, 8, 1);
				break;
			case PLAYER_LEFT:
				if (player_leftMove == TRUE)
				{
					_bgPlayer->frameRender(getMemDC(), _player.getPlayerRect().left, _player.getPlayerRect().top, 4, 860, 48, 66, 8, 1);
				}
				break;
			case PLAYER_RIGHT:
				if (player_rightMove == TRUE)
				{
					_bgPlayer->frameRender(getMemDC(), _player.getPlayerRect().left, _player.getPlayerRect().top, 4, 932, 48, 66, 8, 1);
				}
				break;
			}
		}
	}

	// 적 출력
	switch (_enemyState)
	{
	case ENEMY_FRONT:
		_bgCharacter->frameRender(getMemDC(), _enemy.getPlayerRect().left, _enemy.getPlayerRect().top, 0, 0, 62, 64, 4, 1);
		break;
	case ENEMY_LEFT:
		break;
	case ENEMY_RIGHT:
		break;
	}

	// 적 HP 출력
	_bgCharacterHP->render(getMemDC(), 50, 10, 4, 1101, enemyHP / 10, 14);

	// 적 탄막 패턴 - 패턴 1 탄막 1 출력
	for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
	{
		if (_bullet_enemyPatternNormal1_1[i].getShot() == TRUE)
		{
			// PNG 사용할 경우 주석 없애기
			// _bullet = Image::FromFile(L"BulletSprite.png");
			// ScreenG.DrawImage(_bullet, Rect(_bullet_enemyPatternNormal1_1[i].getX(), _bullet_enemyPatternNormal1_1[i].getY(), 16, 16), 117, 54, 16, 16, UnitPixel);

			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal1_1[i].getBulletRect().left- 8, _bullet_enemyPatternNormal1_1[i].getBulletRect().top - 8,
				170, 108, 32, 32);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal1_1_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal1_1_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal1_1_effect[i].getEffectRect().left, _bullet_enemyPatternNormal1_1_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 1 탄막 2 출력
	for (int i = 0; i < _bullet_enemyPatternNormal1_2.size(); i++)
	{
		if (_bullet_enemyPatternNormal1_2[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal1_2[i].getBulletRect().left - 8, _bullet_enemyPatternNormal1_2[i].getBulletRect().top - 8,
				170, 76, 32, 32);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal1_2_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal1_2_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal1_2_effect[i].getEffectRect().left, _bullet_enemyPatternNormal1_2_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 2 탄막 1 출력
	for (int i = 0; i < _bullet_enemyPatternNormal2_1.size(); i++)
	{
		if (_bullet_enemyPatternNormal2_1[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal2_1[i].getBulletRect().left - 7, _bullet_enemyPatternNormal2_1[i].getBulletRect().top - 7,
				144, 617, 54, 54);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal2_1_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal2_1_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal2_1_effect[i].getEffectRect().left, _bullet_enemyPatternNormal2_1_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 2 탄막 2 출력
	for (int i = 0; i < _bullet_enemyPatternNormal2_2.size(); i++)
	{
		if (_bullet_enemyPatternNormal2_2[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal2_2[i].getBulletRect().left - 8, _bullet_enemyPatternNormal2_2[i].getBulletRect().top - 8,
				170, 76, 32, 32);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal2_2_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal2_2_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal2_2_effect[i].getEffectRect().left, _bullet_enemyPatternNormal2_2_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 3 탄막 1 출력
	for (int i = 0; i < _bullet_enemyPatternNormal3_1.size(); i++)
	{
		if (_bullet_enemyPatternNormal3_1[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal3_1[i].getBulletRect().left - 7, _bullet_enemyPatternNormal3_1[i].getBulletRect().top - 7,
				144, 617, 54, 54);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal3_1_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal3_1_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal3_1_effect[i].getEffectRect().left, _bullet_enemyPatternNormal3_1_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 3 탄막 2 출력
	for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
	{
		if (_bullet_enemyPatternNormal3_2[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal3_2[i].getBulletRect().left - 8, _bullet_enemyPatternNormal3_2[i].getBulletRect().top - 8,
				170, 76, 32, 32);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal3_2_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal3_2_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal3_2_effect[i].getEffectRect().left, _bullet_enemyPatternNormal3_2_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 4 탄막 1 출력
	for (int i = 0; i < _bullet_enemyPatternNormal4_1.size(); i++)
	{
		if (_bullet_enemyPatternNormal4_1[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal4_1[i].getBulletRect().left - 8, _bullet_enemyPatternNormal4_1[i].getBulletRect().top - 8,
				170, 108, 32, 32);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal4_1_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal4_1_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal4_1_effect[i].getEffectRect().left, _bullet_enemyPatternNormal4_1_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 4 탄막 2 출력
	for (int i = 0; i < _bullet_enemyPatternNormal4_2.size(); i++)
	{
		if (_bullet_enemyPatternNormal4_2[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal4_2[i].getBulletRect().left - 8, _bullet_enemyPatternNormal4_2[i].getBulletRect().top - 8,
				170, 76, 32, 32);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal4_2_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal4_2_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal4_2_effect[i].getEffectRect().left, _bullet_enemyPatternNormal4_2_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}
	// 적 탄막 패턴 - 패턴 5 탄막 출력
	for (int i = 0; i < _bullet_enemyPatternNormal5.size(); i++)
	{
		if (_bullet_enemyPatternNormal5[i].getShot() == TRUE)
		{
			_bgEnemyBullet->render(getMemDC(), _bullet_enemyPatternNormal5[i].getBulletRect().left - 8, _bullet_enemyPatternNormal5[i].getBulletRect().top - 8,
				170, 108, 32, 32);
		}
	}
	for (int i = 0; i < _bullet_enemyPatternNormal5_effect.size(); i++)
	{
		if (_bullet_enemyPatternNormal5_effect[i].getEraseEffect() == FALSE)
		{
			_bgBulletEffect->frameRender(getMemDC(), _bullet_enemyPatternNormal5_effect[i].getEffectRect().left, _bullet_enemyPatternNormal5_effect[i].getEffectRect().top, 0, 0, 50, 50, 12, 1);
		}
	}

	// 백그라운드 UI (정보칸) 이미지 렌더
	_bgBackgroundInformation->render(getMemDC(), 800, 0);

	// 개임 내 정보 메세지 이미지 렌더
	_bgInformation->render(getMemDC(), 850, 160, 0, 0, 154, 40);
	_bgInformation->render(getMemDC(), 850, 280, 0, 40, 115, 40);
	_bgInformation->render(getMemDC(), 850, 400, 0, 80, 166, 40);
	_bgInformation->render(getMemDC(), 850, 520, 0, 120, 135, 40);

	// 잔기 및 봄 갯수 이미지 렌더
	for (int i = 0; i < playerExtend; i++)
	{
		_bgInformation->render(getMemDC(), 850 + (27 * i) + 6, 210, 0, 174, 27, 26);
	}
	for (int i = 0; i < playerBombStack; i++)
	{
		_bgInformation->render(getMemDC(), 850 + (27 * i) + 6, 330, 27, 174, 27, 26);
	}

	// 점수 이미지 렌더
	switch (scorePoint_Num1)
	{
	case 0:
		_bgInformation->render(getMemDC(), 1138, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 1138, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 1138, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 1138, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 1138, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 1138, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 1138, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 1138, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 1138, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 1138, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num2)
	{
	case 0:
		_bgInformation->render(getMemDC(), 1106, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 1106, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 1106, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 1106, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 1106, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 1106, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 1106, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 1106, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 1106, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 1106, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num3)
	{
	case 0:
		_bgInformation->render(getMemDC(), 1074, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 1074, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 1074, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 1074, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 1074, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 1074, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 1074, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 1074, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 1074, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 1074, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num4)
	{
	case 0:
		_bgInformation->render(getMemDC(), 1042, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 1042, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 1042, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 1042, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 1042, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 1042, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 1042, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 1042, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 1042, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 1042, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num5)
	{
	case 0:
		_bgInformation->render(getMemDC(), 1010, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 1010, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 1010, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 1010, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 1010, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 1010, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 1010, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 1010, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 1010, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 1010, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num6)
	{
	case 0:
		_bgInformation->render(getMemDC(), 978, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 978, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 978, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 978, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 978, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 978, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 978, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 978, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 978, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 978, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num7)
	{
	case 0:
		_bgInformation->render(getMemDC(), 946, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 946, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 946, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 946, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 946, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 946, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 946, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 946, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 946, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 946, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num8)
	{
	case 0:
		_bgInformation->render(getMemDC(), 914, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 914, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 914, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 914, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 914, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 914, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 914, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 914, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 914, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 914, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num9)
	{
	case 0:
		_bgInformation->render(getMemDC(), 882, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 882, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 882, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 882, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 882, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 882, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 882, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 882, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 882, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 882, 450, 272, 80, 28, 40);
		break;
	}
	switch (scorePoint_Num10)
	{
	case 0:
		_bgInformation->render(getMemDC(), 850, 450, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 850, 450, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 850, 450, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 850, 450, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 850, 450, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 850, 450, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 850, 450, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 850, 450, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 850, 450, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 850, 450, 272, 80, 28, 40);
		break;
	}

	// 그레이즈 이미지 렌더
	switch (grazePoint_Num1)
	{
	case 0:
		_bgInformation->render(getMemDC(), 978, 570, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 978, 570, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 978, 570, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 978, 570, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 978, 570, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 978, 570, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 978, 570, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 978, 570, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 978, 570, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 978, 570, 272, 80, 28, 40);
		break;
	}
	switch (grazePoint_Num2)
	{
	case 0:
		_bgInformation->render(getMemDC(), 946, 570, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 946, 570, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 946, 570, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 946, 570, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 946, 570, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 946, 570, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 946, 570, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 946, 570, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 946, 570, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 946, 570, 272, 80, 28, 40);
		break;
	}
	switch (grazePoint_Num3)
	{
	case 0:
		_bgInformation->render(getMemDC(), 914, 570, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 914, 570, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 914, 570, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 914, 570, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 914, 570, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 914, 570, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 914, 570, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 914, 570, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 914, 570, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 914, 570, 272, 80, 28, 40);
		break;
	}
	switch (grazePoint_Num4)
	{
	case 0:
		_bgInformation->render(getMemDC(), 882, 570, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 882, 570, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 882, 570, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 882, 570, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 882, 570, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 882, 570, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 882, 570, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 882, 570, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 882, 570, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 882, 570, 272, 80, 28, 40);
		break;
	}
	switch (grazePoint_Num5)
	{
	case 0:
		_bgInformation->render(getMemDC(), 850, 570, 188, 0, 28, 40);
		break;
	case 1:
		_bgInformation->render(getMemDC(), 850, 570, 216, 0, 28, 40);
		break;
	case 2:
		_bgInformation->render(getMemDC(), 850, 570, 244, 0, 28, 40);
		break;
	case 3:
		_bgInformation->render(getMemDC(), 850, 570, 272, 0, 28, 40);
		break;
	case 4:
		_bgInformation->render(getMemDC(), 850, 570, 216, 40, 28, 40);
		break;
	case 5:
		_bgInformation->render(getMemDC(), 850, 570, 244, 40, 28, 40);
		break;
	case 6:
		_bgInformation->render(getMemDC(), 850, 570, 272, 40, 28, 40);
		break;
	case 7:
		_bgInformation->render(getMemDC(), 850, 570, 216, 80, 28, 40);
		break;
	case 8:
		_bgInformation->render(getMemDC(), 850, 570, 244, 80, 28, 40);
		break;
	case 9:
		_bgInformation->render(getMemDC(), 850, 570, 272, 80, 28, 40);
		break;
	}

	// 플레이어 봄 알파값 연출
	if (playerBombUse == FALSE)
	{
		playerBomb_alphaCount++;

		if (playerBomb_alphaCount > 2)
		{
			playerBomb_alphaNum -= 50;
			playerBomb_alphaCount = 0;
			if (playerBomb_alphaNum < 0)
			{
				playerBomb_alphaNum = 0;
			}
		}
	}

	// 타이틀 화면
	if (gameStart == FALSE && gameOver == FALSE && gameWin == FALSE)
	{
		_bgTitle->render(getMemDC(), 0, 0);
	}

	// 게임 시작
	if (gameStart == FALSE)
	{
		_bgGameStart->render(getMemDC(), 300, 600);
	}

	// 게임 오버
	if (gameStart == TRUE && gameOver == TRUE && gameWin == FALSE)
	{
		_bgGameOver->render(getMemDC(), 250, 200);
		_bgGameRestart->render(getMemDC(), 100, 600);
	}

	// 게임 승리
	if (gameStart == TRUE && gameOver == TRUE && gameWin == TRUE)
	{
		_bgGameWin->render(getMemDC(), 150, 200);
		_bgGameRestart->render(getMemDC(), 100, 600);
	}

	// 이미지 최종 출력
	this->getBackBuffer()->render(getHDC());

	// 토글키는 보통 디버깅을 할 때에나, 동영상을 촬영할 때에 사용
	// 알파벳이나 숫자 => '0', 'A' => 대문자만 사용 가능
	// if (INPUT->getToggleKey('A'))
	// {
	// 	Rectangle(hdc, _rc);
	// }
}

// 이미지 애니메이션 출력
void mainGame::animation()
{
	// 플레이어 이미지
	switch (_playerState)
	{
	case PLAYER_FRONT:
		player_front_frameCount++;
		_bgPlayer->setFrameY(0);
		if (player_front_frameCount % 6 == 0)
		{
			player_front_frameIndex++;
			if (player_front_frameIndex >= 8)
			{
				player_front_frameIndex = 0;
			}
			_bgPlayer->setFrameX(player_front_frameIndex);
		}
		break;
	case PLAYER_LEFT:
		player_left_frameCount++;
		_bgPlayer->setFrameY(0);
		if (player_left_frameCount % 3 == 0)
		{
			player_left_frameIndex++;
			if (player_left_frameIndex >= 8)
			{
				player_left_frameIndex = 4;
			}
			_bgPlayer->setFrameX(player_left_frameIndex);
		}
		break;
	case PLAYER_RIGHT:
		player_right_frameCount++;
		_bgPlayer->setFrameY(0);
		if (player_right_frameCount % 3 == 0)
		{
			player_right_frameIndex++;
			if (player_right_frameIndex >= 8)
			{
				player_right_frameIndex = 4;
			}
			_bgPlayer->setFrameX(player_right_frameIndex);
		}
		break;
	}

	// 적 이미지
	switch (_enemyState)
	{
	case ENEMY_FRONT:
		enemy_front_frameCount++;
		_bgCharacter->setFrameY(0);
		if (enemy_front_frameCount % 5 == 0)
		{
			enemy_front_frameIndex++;
			if (enemy_front_frameIndex >= 4)
			{
				enemy_front_frameIndex = 0;
			}
			_bgCharacter->setFrameX(enemy_front_frameIndex);
		}
		break;
	case ENEMY_LEFT:
		break;
	case ENEMY_RIGHT:
		break;
	}

	// 탄막 제거 이펙트
	// 플레이어 탄막
	for (int i = 0; i < _bullet_player1_effect.size(); i++)
	{
		_bullet_player1_effect[i].setFrameCount(_bullet_player1_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_player1_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_player1_effect[i].setFrameIndex(_bullet_player1_effect[i].getFrameIndex() + 1);
			if (_bullet_player1_effect[i].getFrameIndex() >= 12)
			{
				_bullet_player1_effect[i].setFrameIndex(11);
				_bullet_player1_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_player1_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 1 탄막 1
	for (int i = 0; i < _bullet_enemyPatternNormal1_1_effect.size(); i++)
	{
		_bullet_enemyPatternNormal1_1_effect[i].setFrameCount(_bullet_enemyPatternNormal1_1_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal1_1_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal1_1_effect[i].setFrameIndex(_bullet_enemyPatternNormal1_1_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal1_1_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal1_1_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal1_1_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal1_1_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 1 탄막 2
	for (int i = 0; i < _bullet_enemyPatternNormal1_2_effect.size(); i++)
	{
		_bullet_enemyPatternNormal1_2_effect[i].setFrameCount(_bullet_enemyPatternNormal1_2_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal1_2_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal1_2_effect[i].setFrameIndex(_bullet_enemyPatternNormal1_2_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal1_2_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal1_2_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal1_2_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal1_2_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 2 탄막 1
	for (int i = 0; i < _bullet_enemyPatternNormal2_1_effect.size(); i++)
	{
		_bullet_enemyPatternNormal2_1_effect[i].setFrameCount(_bullet_enemyPatternNormal2_1_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal2_1_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal2_1_effect[i].setFrameIndex(_bullet_enemyPatternNormal2_1_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal2_1_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal2_1_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal2_1_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal2_1_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 2 탄막 2
	for (int i = 0; i < _bullet_enemyPatternNormal2_2_effect.size(); i++)
	{
		_bullet_enemyPatternNormal2_2_effect[i].setFrameCount(_bullet_enemyPatternNormal2_2_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal2_2_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal2_2_effect[i].setFrameIndex(_bullet_enemyPatternNormal2_2_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal2_2_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal2_2_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal2_2_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal2_2_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 3 탄막 1
	for (int i = 0; i < _bullet_enemyPatternNormal3_1_effect.size(); i++)
	{
		_bullet_enemyPatternNormal3_1_effect[i].setFrameCount(_bullet_enemyPatternNormal3_1_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal3_1_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal3_1_effect[i].setFrameIndex(_bullet_enemyPatternNormal3_1_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal3_1_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal3_1_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal3_1_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal3_1_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 3 탄막 2
	for (int i = 0; i < _bullet_enemyPatternNormal3_2_effect.size(); i++)
	{
		_bullet_enemyPatternNormal3_2_effect[i].setFrameCount(_bullet_enemyPatternNormal3_2_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal3_2_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal3_2_effect[i].setFrameIndex(_bullet_enemyPatternNormal3_2_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal3_2_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal3_2_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal3_2_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal3_2_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 4 탄막 1
	for (int i = 0; i < _bullet_enemyPatternNormal4_1_effect.size(); i++)
	{
		_bullet_enemyPatternNormal4_1_effect[i].setFrameCount(_bullet_enemyPatternNormal4_1_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal4_1_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal4_1_effect[i].setFrameIndex(_bullet_enemyPatternNormal4_1_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal4_1_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal4_1_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal4_1_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal4_1_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 4 탄막 2
	for (int i = 0; i < _bullet_enemyPatternNormal4_2_effect.size(); i++)
	{
		_bullet_enemyPatternNormal4_2_effect[i].setFrameCount(_bullet_enemyPatternNormal4_2_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal4_2_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal4_2_effect[i].setFrameIndex(_bullet_enemyPatternNormal4_2_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal4_2_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal4_2_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal4_2_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal4_2_effect[i].getFrameIndex());
		}
	}
	// 컴퓨터 탄막 패턴 - 통상 5 탄막
	for (int i = 0; i < _bullet_enemyPatternNormal5_effect.size(); i++)
	{
		_bullet_enemyPatternNormal5_effect[i].setFrameCount(_bullet_enemyPatternNormal5_effect[i].getFrameCount() + 1);
		_bgBulletEffect->setFrameY(0);
		if (_bullet_enemyPatternNormal5_effect[i].getFrameCount() % 2 == 0)
		{
			_bullet_enemyPatternNormal5_effect[i].setFrameIndex(_bullet_enemyPatternNormal5_effect[i].getFrameIndex() + 1);
			if (_bullet_enemyPatternNormal5_effect[i].getFrameIndex() >= 12)
			{
				_bullet_enemyPatternNormal5_effect[i].setFrameIndex(11);
				_bullet_enemyPatternNormal5_effect[i].setEraseEffect(TRUE);
			}
			_bgBulletEffect->setFrameX(_bullet_enemyPatternNormal5_effect[i].getFrameIndex());
		}
	}

	// 피탄 이펙트
	if (playerHit == TRUE)
	{
		playerHit_frameCount++;
		_bgHitEffect->setFrameY(0);
		if (playerHit_frameCount % 3 == 0)
		{
			playerHit_frameIndex++;
			if (playerHit_frameIndex >= 7)
			{
				playerHit_frameIndex = 6;
			}
			_bgHitEffect->setFrameX(playerHit_frameIndex);
		}
	}
}

// 컴퓨터 탄막 패턴 - 통상 1 탄막 1 생성
void mainGame::bulletFire_enemyPatternNormal1_1()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_1 && enemyPatternChange == FALSE)
	{
		if (enemyPatternNormal1_bulletDelay1_1 == FALSE)
		{
			enemyPatternNormal1_attackDelay1_1++;

			if (enemyPatternNormal1_bulletTemp1_1 >= 100)
			{
				enemyPatternNormal1_bulletDelay1_1 = TRUE;
				enemyPatternNormal1_bulletTemp1_1 = 0;
			}
		}
	}
	if (enemyPatternNormal1_bulletDelay1_1 == TRUE)
	{
		enemyPatternNormal1_bulletDelayTemp1_1++;

		if (enemyPatternNormal1_bulletDelayTemp1_1 >= 60)
		{
			enemyPatternNormal1_bulletDelay1_1 = FALSE;
			enemyPatternNormal1_bulletDelayTemp1_1 = 0;

			for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
			{
				if (_bullet_enemyPatternNormal1_1[i].getGuidance() == FALSE)
				{
					_bullet_enemyPatternNormal1_1[i].setGuidance(TRUE);
					_bullet_enemyPatternNormal1_1[i].setSpeed(12.0f);
					_bullet_enemyPatternNormal1_1[i].setAngle(getAngle(_bullet_enemyPatternNormal1_1[i].getX(), _bullet_enemyPatternNormal1_1[i].getY(),
						_player.getX(), _player.getY()));
				}
			}
		}
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_1 && enemyPatternChange == FALSE)
	{
		if (enemyPatternNormal1_bulletDelay1_1 == FALSE)
		{
			// 탄막 발사 딜레이
			if (enemyPatternNormal1_attackDelay1_1 >= 1)
			{
				// 탄막 1 생성
				for (int i = 0; i < 4; i++)
				{
					_bullet_enemyPatternNormal1_1.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
				}

				// 탄막 1 스테이터스 설정
				for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
				{
					if (_bullet_enemyPatternNormal1_1[i].getShot() == TRUE)
					{
						continue;
					}
					else
					{
						_bullet_enemyPatternNormal1_1[i].setX(_enemy.getX());
						_bullet_enemyPatternNormal1_1[i].setY(_enemy.getY());
						_bullet_enemyPatternNormal1_1[i].setSpeed(8.0f);
						_bullet_enemyPatternNormal1_1[i].setAngle(PI - (0.0314 * (enemyPatternNormal1_bulletTemp1_1 % 100)) + (1.57 * (i % 4)));
						_bullet_enemyPatternNormal1_1[i].setRadius(8.0f);
						_bullet_enemyPatternNormal1_1[i].setGravity(0.0f);
						_bullet_enemyPatternNormal1_1[i].setShot(TRUE);
						_bullet_enemyPatternNormal1_1[i].setSpeedDown(TRUE);
						_bullet_enemyPatternNormal1_1[i].setGuidance(FALSE);
						_bullet_enemyPatternNormal1_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal1_1[i].getX(), _bullet_enemyPatternNormal1_1[i].getY(),
							_bullet_enemyPatternNormal1_1[i].getRadius() * 2, _bullet_enemyPatternNormal1_1[i].getRadius() * 2));;
						enemyPatternNormal1_bulletTemp1_1++;
					}
				}
				enemyPatternNormal1_attackDelay1_1 = 0;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 1 탄막 1 이동
void mainGame::bulletMove_enemyPatternNormal1_1()
{
	// 탄막 1 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
	{
		// 탄막 1 무빙 처리
		if (_bullet_enemyPatternNormal1_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal1_1[i].setX(_bullet_enemyPatternNormal1_1[i].getX() + (cosf(_bullet_enemyPatternNormal1_1[i].getAngle()) *
				_bullet_enemyPatternNormal1_1[i].getSpeed()));
			_bullet_enemyPatternNormal1_1[i].setY(_bullet_enemyPatternNormal1_1[i].getY() + (-sinf(_bullet_enemyPatternNormal1_1[i].getAngle()) *
				_bullet_enemyPatternNormal1_1[i].getSpeed()));

			_bullet_enemyPatternNormal1_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal1_1[i].getX(), _bullet_enemyPatternNormal1_1[i].getY(),
				_bullet_enemyPatternNormal1_1[i].getRadius() * 2, _bullet_enemyPatternNormal1_1[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal1_1[i].getBulletRect().top >= 800 || _bullet_enemyPatternNormal1_1[i].getBulletRect().bottom <= -400 ||
			_bullet_enemyPatternNormal1_1[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal1_1[i].getBulletRect().left >= 800) &&
			_bullet_enemyPatternNormal1_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal1_1[i].setShot(FALSE);
			_bullet_enemyPatternNormal1_1.erase(_bullet_enemyPatternNormal1_1.begin() + i);
			scorePoint += 100;
		}

		// 탄막 1, 2 속도 처리
		if (_bullet_enemyPatternNormal1_1[i].getSpeedDown() == TRUE && _bullet_enemyPatternNormal1_1[i].getGuidance() == FALSE)
		{
			_bullet_enemyPatternNormal1_1[i].setSpeed(_bullet_enemyPatternNormal1_1[i].getSpeed() - 0.15f);

			if (_bullet_enemyPatternNormal1_1[i].getSpeed() <= 0.0f)
			{
				_bullet_enemyPatternNormal1_1[i].setSpeed(0.0f);
				_bullet_enemyPatternNormal1_1[i].setSpeedDown(FALSE);
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 1 탄막 1 그레이즈 판정
void mainGame::graze_enemyPatternNormal1_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal1_1[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal1_1[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal1_1[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 1 탄막 1 피탄 판정
void mainGame::hit_enemyPatternNormal1_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal1_1.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal1_1[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 1 탄막 2 생성
void mainGame::bulletFire_enemyPatternNormal1_2()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_1 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal1_attackDelay1_2++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_1 && enemyPatternChange == FALSE)
	{
		// 탄막 발사 딜레이
		if (enemyPatternNormal1_attackDelay1_2 >= 30)
		{
			// 탄막 1 생성
			for (int i = 0; i < 50; i++)
			{
				_bullet_enemyPatternNormal1_2.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 1 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal1_2.size(); i++)
			{
				if (_bullet_enemyPatternNormal1_2[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal1_2[i].setX(_enemy.getX());
					_bullet_enemyPatternNormal1_2[i].setY(_enemy.getY());
					_bullet_enemyPatternNormal1_2[i].setSpeed(5.0f);
					_bullet_enemyPatternNormal1_2[i].setAngle((PI - (0.1256 * (enemyPatternNormal1_bulletTemp1_2 % 50))) + (0.0314 * (enemyPatternNormal1_bulletTemp1_2 / 50)));
					_bullet_enemyPatternNormal1_2[i].setRadius(8.0f);
					_bullet_enemyPatternNormal1_2[i].setGravity(0.0f);
					_bullet_enemyPatternNormal1_2[i].setShot(TRUE);
					_bullet_enemyPatternNormal1_2[i].setSpeedDown(FALSE);
					_bullet_enemyPatternNormal1_2[i].setGuidance(FALSE);
					_bullet_enemyPatternNormal1_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal1_2[i].getX(), _bullet_enemyPatternNormal1_2[i].getY(),
						_bullet_enemyPatternNormal1_2[i].getRadius() * 2, _bullet_enemyPatternNormal1_2[i].getRadius() * 2));;
					enemyPatternNormal1_bulletTemp1_2++;
				}
			}
			enemyPatternNormal1_attackDelay1_2 = 0;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 1 탄막 2 이동
void mainGame::bulletMove_enemyPatternNormal1_2()
{
	// 탄막 1 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal1_2.size(); i++)
	{
		// 탄막 1 무빙 처리
		if (_bullet_enemyPatternNormal1_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal1_2[i].setX(_bullet_enemyPatternNormal1_2[i].getX() + (cosf(_bullet_enemyPatternNormal1_2[i].getAngle()) *
				_bullet_enemyPatternNormal1_2[i].getSpeed()));
			_bullet_enemyPatternNormal1_2[i].setY(_bullet_enemyPatternNormal1_2[i].getY() + (-sinf(_bullet_enemyPatternNormal1_2[i].getAngle()) *
				_bullet_enemyPatternNormal1_2[i].getSpeed()));

			_bullet_enemyPatternNormal1_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal1_2[i].getX(), _bullet_enemyPatternNormal1_2[i].getY(),
				_bullet_enemyPatternNormal1_2[i].getRadius() * 2, _bullet_enemyPatternNormal1_2[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal1_2[i].getBulletRect().top >= 800 || _bullet_enemyPatternNormal1_2[i].getBulletRect().bottom <= -400 ||
			_bullet_enemyPatternNormal1_2[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal1_2[i].getBulletRect().left >= 800) &&
			_bullet_enemyPatternNormal1_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal1_2[i].setShot(FALSE);
			_bullet_enemyPatternNormal1_2.erase(_bullet_enemyPatternNormal1_2.begin() + i);
			scorePoint += 100;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 1 탄막 2 그레이즈 판정
void mainGame::graze_enemyPatternNormal1_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal1_2.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal1_2[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal1_2[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal1_2[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 1 탄막 2 피탄 판정
void mainGame::hit_enemyPatternNormal1_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal1_2.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal1_2[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}

// 컴퓨터 탄막 패턴 - 통상 2 탄막 1 생성
void mainGame::bulletFire_enemyPatternNormal2_1()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_2 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal2_attackDelay1_1++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_2 && enemyPatternChange == FALSE)
	{
		// 탄막 발사 딜레이
		if (enemyPatternNormal2_attackDelay1_1 >= 60)
		{
			// 탄막 1 생성
			for (int i = 0; i < 25; i++)
			{
				_bullet_enemyPatternNormal2_1.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 1 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal2_1.size(); i++)
			{
				if (_bullet_enemyPatternNormal2_1[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal2_1[i].setX(_enemy.getX());
					_bullet_enemyPatternNormal2_1[i].setY(_enemy.getY());
					_bullet_enemyPatternNormal2_1[i].setSpeed(8.0f);
					_bullet_enemyPatternNormal2_1[i].setAngle(PI - (0.2512 * (enemyPatternNormal2_bulletTemp1_1 % 25)));
					_bullet_enemyPatternNormal2_1[i].setRadius(20.0f);
					_bullet_enemyPatternNormal2_1[i].setGravity(0.0f);
					_bullet_enemyPatternNormal2_1[i].setShot(TRUE);
					_bullet_enemyPatternNormal2_1[i].setSpeedDown(TRUE);
					_bullet_enemyPatternNormal2_1[i].setGuidance(FALSE);
					_bullet_enemyPatternNormal2_1[i].setSpeedDelay(0);
					_bullet_enemyPatternNormal2_1[i].setRotateDelay(0);
					_bullet_enemyPatternNormal2_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal2_1[i].getX(), _bullet_enemyPatternNormal2_1[i].getY(),
						_bullet_enemyPatternNormal2_1[i].getRadius() * 2, _bullet_enemyPatternNormal2_1[i].getRadius() * 2));;
					enemyPatternNormal2_bulletTemp1_1++;
				}
			}
			enemyPatternNormal2_attackDelay1_1 = 0;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 탄막 1 이동
void mainGame::bulletMove_enemyPatternNormal2_1()
{
	// 탄막 1 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal2_1.size(); i++)
	{
		// 탄막 1 무빙 처리
		if (_bullet_enemyPatternNormal2_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal2_1[i].setX(_bullet_enemyPatternNormal2_1[i].getX() + (cosf(_bullet_enemyPatternNormal2_1[i].getAngle()) *
				_bullet_enemyPatternNormal2_1[i].getSpeed()));
			_bullet_enemyPatternNormal2_1[i].setY(_bullet_enemyPatternNormal2_1[i].getY() + (-sinf(_bullet_enemyPatternNormal2_1[i].getAngle()) *
				_bullet_enemyPatternNormal2_1[i].getSpeed()));

			_bullet_enemyPatternNormal2_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal2_1[i].getX(), _bullet_enemyPatternNormal2_1[i].getY(),
				_bullet_enemyPatternNormal2_1[i].getRadius() * 2, _bullet_enemyPatternNormal2_1[i].getRadius() * 2));

			// 탄막 1 속도 처리
			if (_bullet_enemyPatternNormal2_1[i].getSpeedDelay() <= 2)
			{
				_bullet_enemyPatternNormal2_1[i].setSpeedDelay(_bullet_enemyPatternNormal2_1[i].getSpeedDelay() + 1);
			}
			else
			{
				if (_bullet_enemyPatternNormal2_1[i].getSpeed() >= 2.2f)
				{
					_bullet_enemyPatternNormal2_1[i].setSpeed(_bullet_enemyPatternNormal2_1[i].getSpeed() - 0.2f);
				}
				_bullet_enemyPatternNormal2_1[i].setSpeedDelay(0);
			}

			// 탄막 1 회전 처리
			if (_bullet_enemyPatternNormal2_1[i].getRotateDelay() <= 8)
			{
				_bullet_enemyPatternNormal2_1[i].setRotateDelay(_bullet_enemyPatternNormal2_1[i].getRotateDelay() + 1);
			}
			else
			{
				if (_bullet_enemyPatternNormal2_1[i].getSpeed() >= 2.2f)
				{
					_bullet_enemyPatternNormal2_1[i].setAngle(_bullet_enemyPatternNormal2_1[i].getAngle() + 0.1256f);
				}
				_bullet_enemyPatternNormal2_1[i].setRotateDelay(0);
			}
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal2_1[i].getBulletRect().top >= 800 || _bullet_enemyPatternNormal2_1[i].getBulletRect().bottom <= -400 ||
			_bullet_enemyPatternNormal2_1[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal2_1[i].getBulletRect().left >= 800) &&
			_bullet_enemyPatternNormal2_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal2_1[i].setShot(FALSE);
			_bullet_enemyPatternNormal2_1.erase(_bullet_enemyPatternNormal2_1.begin() + i);
			scorePoint += 100;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 탄막 1 그레이즈 판정
void mainGame::graze_enemyPatternNormal2_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal2_1.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal2_1[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal2_1[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal2_1[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 탄막 1 피탄 판정
void mainGame::hit_enemyPatternNormal2_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal2_1.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal2_1[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 탄막 2 생성
void mainGame::bulletFire_enemyPatternNormal2_2()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_2 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal2_attackDelay1_2++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_2 && enemyPatternChange == FALSE)
	{
		// 탄막 발사 딜레이
		if (enemyPatternNormal2_attackDelay1_2 >= 60)
		{
			// 탄막 2 생성
			for (int i = 0; i < 50; i++)
			{
				_bullet_enemyPatternNormal2_2.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 2 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal2_2.size(); i++)
			{
				if (_bullet_enemyPatternNormal2_2[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal2_2[i].setX(_enemy.getX());
					_bullet_enemyPatternNormal2_2[i].setY(_enemy.getY());
					_bullet_enemyPatternNormal2_2[i].setSpeed(6.0f);
					_bullet_enemyPatternNormal2_2[i].setAngle(PI - (0.1256 * (enemyPatternNormal2_bulletTemp1_2 % 50)));
					_bullet_enemyPatternNormal2_2[i].setRadius(8.0f);
					_bullet_enemyPatternNormal2_2[i].setGravity(0.0f);
					_bullet_enemyPatternNormal2_2[i].setShot(TRUE);
					_bullet_enemyPatternNormal2_2[i].setSpeedDown(TRUE);
					_bullet_enemyPatternNormal2_2[i].setGuidance(FALSE);
					_bullet_enemyPatternNormal2_2[i].setSpeedDelay(0);
					_bullet_enemyPatternNormal2_2[i].setRotateDelay(0);
					_bullet_enemyPatternNormal2_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal2_2[i].getX(), _bullet_enemyPatternNormal2_2[i].getY(),
						_bullet_enemyPatternNormal2_2[i].getRadius() * 2, _bullet_enemyPatternNormal2_2[i].getRadius() * 2));;
					enemyPatternNormal2_bulletTemp1_2++;
				}
			}
			enemyPatternNormal2_attackDelay1_2 = 0;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 탄막 2 이동
void mainGame::bulletMove_enemyPatternNormal2_2()
{
	// 탄막 2 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal2_2.size(); i++)
	{
		// 탄막 2 무빙 처리
		if (_bullet_enemyPatternNormal2_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal2_2[i].setX(_bullet_enemyPatternNormal2_2[i].getX() + (cosf(_bullet_enemyPatternNormal2_2[i].getAngle()) *
				_bullet_enemyPatternNormal2_2[i].getSpeed()));
			_bullet_enemyPatternNormal2_2[i].setY(_bullet_enemyPatternNormal2_2[i].getY() + (-sinf(_bullet_enemyPatternNormal2_2[i].getAngle()) *
				_bullet_enemyPatternNormal2_2[i].getSpeed()));

			_bullet_enemyPatternNormal2_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal2_2[i].getX(), _bullet_enemyPatternNormal2_2[i].getY(),
				_bullet_enemyPatternNormal2_2[i].getRadius() * 2, _bullet_enemyPatternNormal2_2[i].getRadius() * 2));

			// 탄막 2 속도 처리
			if (_bullet_enemyPatternNormal2_2[i].getSpeedDelay() <= 2)
			{
				_bullet_enemyPatternNormal2_2[i].setSpeedDelay(_bullet_enemyPatternNormal2_2[i].getSpeedDelay() + 1);
			}
			else
			{
				if (_bullet_enemyPatternNormal2_2[i].getSpeed() >= 2.0f)
				{
					_bullet_enemyPatternNormal2_2[i].setSpeed(_bullet_enemyPatternNormal2_2[i].getSpeed() - 0.2f);
				}
				_bullet_enemyPatternNormal2_2[i].setSpeedDelay(0);
			}

			// 탄막 2 회전 처리
			if (_bullet_enemyPatternNormal2_2[i].getRotateDelay() <= 8)
			{
				_bullet_enemyPatternNormal2_2[i].setRotateDelay(_bullet_enemyPatternNormal2_2[i].getRotateDelay() + 1);
			}
			else
			{
				if (_bullet_enemyPatternNormal2_2[i].getSpeed() >= 2.2f)
				{
					_bullet_enemyPatternNormal2_2[i].setAngle(_bullet_enemyPatternNormal2_2[i].getAngle() + 0.1256f);
				}
				_bullet_enemyPatternNormal2_2[i].setRotateDelay(0);
			}
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal2_2[i].getBulletRect().top >= 800 || _bullet_enemyPatternNormal2_2[i].getBulletRect().bottom <= -400 ||
			_bullet_enemyPatternNormal2_2[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal2_2[i].getBulletRect().left >= 800) &&
			_bullet_enemyPatternNormal2_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal2_2[i].setShot(FALSE);
			_bullet_enemyPatternNormal2_2.erase(_bullet_enemyPatternNormal2_2.begin() + i);
			scorePoint += 100;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 탄막 2 그레이즈 판정
void mainGame::graze_enemyPatternNormal2_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal2_2.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal2_2[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal2_2[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal2_2[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 탄막 2 피탄 판정
void mainGame::hit_enemyPatternNormal2_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal2_2.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal2_2[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 2 컴퓨터 무빙
void mainGame::comMove_enemyPatternNormal2()
{
	if (enemyPattern == PATTERN_2)
	{
		enemyPatternNormal2_enemyMoveDelay++;
	}
	if (enemyPatternNormal2_enemyMoveDelay > 50)
	{
		enemyPatternNormal2_enemyMove = RANDOM->Range(0, 1);
		enemyPatternNormal2_enemyMoveDelay = 0;
	}
	if (enemyPattern == PATTERN_2)
	{
		if (enemyPatternNormal2_enemyMove == 0)
		{
			_enemy.setX(_enemy.getX() - 3);

			if (_enemy.getPlayerRect().left < 200)
			{
				enemyPatternNormal2_enemyMove = 1;
			}
		}
		else
		{
			_enemy.setX(_enemy.getX() + 3);

			if (_enemy.getPlayerRect().right > 600)
			{
				enemyPatternNormal2_enemyMove = 0;
			}
		}
	}
}

// 컴퓨터 탄막 패턴 - 통상 3 탄막 1 생성
void mainGame::bulletFire_enemyPatternNormal3_1()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_3 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal3_attackDelay1_1++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_3 && enemyPatternChange == FALSE)
	{
		// 탄막 발사 딜레이
		if (enemyPatternNormal3_attackDelay1_1 >= 8)
		{
			// 탄막 1 생성
			for (int i = 0; i < 1; i++)
			{
				_bullet_enemyPatternNormal3_1.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 1 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal3_1.size(); i++)
			{
				if (_bullet_enemyPatternNormal3_1[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal3_1[i].setX(_enemy.getX());
					_bullet_enemyPatternNormal3_1[i].setY(_enemy.getY());
					_bullet_enemyPatternNormal3_1[i].setSpeed(4.0f);
					_bullet_enemyPatternNormal3_1[i].setAngle(PI - (0.1256 * (enemyPatternNormal3_bulletTemp1_1 % 50)) + (3.14 * (enemyPatternNormal3_bulletTemp1_1 % 2)));
					_bullet_enemyPatternNormal3_1[i].setRadius(20.0f);
					_bullet_enemyPatternNormal3_1[i].setGravity(0.0f);
					_bullet_enemyPatternNormal3_1[i].setShot(TRUE);
					_bullet_enemyPatternNormal3_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal3_1[i].getX(), _bullet_enemyPatternNormal3_1[i].getY(),
						_bullet_enemyPatternNormal3_1[i].getRadius() * 2, _bullet_enemyPatternNormal3_1[i].getRadius() * 2));
					enemyPatternNormal3_bulletTemp1_1++;
				}
			}

			// 탄막 발사 딜레이 초기화
			enemyPatternNormal3_attackDelay1_1 = 0;
		}
	}
}

// 컴퓨터 탄막 패턴 - 통상 3 탄막 1 이동
void mainGame::bulletMove_enemyPatternNormal3_1()
{
	// 탄막 1 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal3_1.size(); i++)
	{
		// 탄막 1 무빙 처리
		if (_bullet_enemyPatternNormal3_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal3_1[i].setX(_bullet_enemyPatternNormal3_1[i].getX() + (cosf(_bullet_enemyPatternNormal3_1[i].getAngle()) *
				_bullet_enemyPatternNormal3_1[i].getSpeed()));
			_bullet_enemyPatternNormal3_1[i].setY(_bullet_enemyPatternNormal3_1[i].getY() + (-sinf(_bullet_enemyPatternNormal3_1[i].getAngle()) *
				_bullet_enemyPatternNormal3_1[i].getSpeed()));

			_bullet_enemyPatternNormal3_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal3_1[i].getX(), _bullet_enemyPatternNormal3_1[i].getY(),
				_bullet_enemyPatternNormal3_1[i].getRadius() * 2, _bullet_enemyPatternNormal3_1[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal3_1[i].getBulletRect().top >= WINSIZEY || _bullet_enemyPatternNormal3_1[i].getBulletRect().bottom <= 0 ||
			_bullet_enemyPatternNormal3_1[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal3_1[i].getBulletRect().left >= WINSIZEX) &&
			_bullet_enemyPatternNormal3_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal3_1[i].setShot(FALSE);
			_bullet_enemyPatternNormal3_1.erase(_bullet_enemyPatternNormal3_1.begin() + i);
			scorePoint += 150;
		}
	}

	// 탄막 2 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
	{
		// 탄막 2 무빙 처리
		if (_bullet_enemyPatternNormal3_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal3_2[i].setX(_bullet_enemyPatternNormal3_2[i].getX() + (cosf(_bullet_enemyPatternNormal3_2[i].getAngle()) *
				_bullet_enemyPatternNormal3_2[i].getSpeed()));
			_bullet_enemyPatternNormal3_2[i].setY(_bullet_enemyPatternNormal3_2[i].getY() + (-sinf(_bullet_enemyPatternNormal3_2[i].getAngle()) *
				_bullet_enemyPatternNormal3_2[i].getSpeed()));

			_bullet_enemyPatternNormal3_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal3_2[i].getX(), _bullet_enemyPatternNormal3_2[i].getY(),
				_bullet_enemyPatternNormal3_2[i].getRadius() * 2, _bullet_enemyPatternNormal3_2[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal3_2[i].getBulletRect().top >= WINSIZEY || _bullet_enemyPatternNormal3_2[i].getBulletRect().bottom <= 0 ||
			_bullet_enemyPatternNormal3_2[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal3_2[i].getBulletRect().left >= WINSIZEX) &&
			_bullet_enemyPatternNormal3_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal3_2[i].setShot(FALSE);
			_bullet_enemyPatternNormal3_2.erase(_bullet_enemyPatternNormal3_2.begin() + i);
			scorePoint += 150;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 3 탄막 1 그레이즈 판정
void mainGame::graze_enemyPatternNormal3_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal3_1.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal3_1[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal3_1[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal3_1[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 3 탄막 1 피탄 판정
void mainGame::hit_enemyPatternNormal3_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal3_1.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal3_1[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 3 탄막 2 생성
void mainGame::bulletFire_enemyPatternNormal3_2()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_3 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal3_attackDelay1_2++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_3 && enemyPatternChange == FALSE)
	{
		// 탄막 발사 딜레이
		if (enemyPatternNormal3_attackDelay1_2 >= 8)
		{
			// 탄막 2 생성
			for (int i = 0; i < 25; i++)
			{
				_bullet_enemyPatternNormal3_2.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 2 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
			{
				if (_bullet_enemyPatternNormal3_2[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal3_2[i].setX(_enemy.getX());
					_bullet_enemyPatternNormal3_2[i].setY(_enemy.getY());
					if (enemyPatternNormal3_bulletTemp1_2 % 5 == 0)
					{
						_bullet_enemyPatternNormal3_2[i].setSpeed(4.0f);
					}
					else if (enemyPatternNormal3_bulletTemp1_2 % 5 == 1)
					{
						_bullet_enemyPatternNormal3_2[i].setSpeed(3.5f);
					}
					else if (enemyPatternNormal3_bulletTemp1_2 % 5 == 2)
					{
						_bullet_enemyPatternNormal3_2[i].setSpeed(3.0f);
					}
					else if (enemyPatternNormal3_bulletTemp1_2 % 5 == 3)
					{
						_bullet_enemyPatternNormal3_2[i].setSpeed(2.5f);
					}
					else
					{
						_bullet_enemyPatternNormal3_2[i].setSpeed(2.0f);
					}
					_bullet_enemyPatternNormal3_2[i].setAngle(PI - (1.256 * (i / 5)) + (0.2512 * (enemyPatternNormal3_bulletTemp1_2 / 25)));
					_bullet_enemyPatternNormal3_2[i].setRadius(10.0f);
					_bullet_enemyPatternNormal3_2[i].setGravity(0.0f);
					_bullet_enemyPatternNormal3_2[i].setShot(TRUE);
					_bullet_enemyPatternNormal3_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal3_2[i].getX(), _bullet_enemyPatternNormal3_2[i].getY(),
						_bullet_enemyPatternNormal3_2[i].getRadius() * 2, _bullet_enemyPatternNormal3_2[i].getRadius() * 2));
					enemyPatternNormal3_bulletTemp1_2++;
				}
			}

			// 탄막 발사 딜레이 초기화
			enemyPatternNormal3_attackDelay1_2 = 0;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 3 탄막 2 이동
void mainGame::bulletMove_enemyPatternNormal3_2()
{
	// 탄막 2 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
	{
		// 탄막 2 무빙 처리
		if (_bullet_enemyPatternNormal3_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal3_2[i].setX(_bullet_enemyPatternNormal3_2[i].getX() + (cosf(_bullet_enemyPatternNormal3_2[i].getAngle()) *
				_bullet_enemyPatternNormal3_2[i].getSpeed()));
			_bullet_enemyPatternNormal3_2[i].setY(_bullet_enemyPatternNormal3_2[i].getY() + (-sinf(_bullet_enemyPatternNormal3_2[i].getAngle()) *
				_bullet_enemyPatternNormal3_2[i].getSpeed()));

			_bullet_enemyPatternNormal3_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal3_2[i].getX(), _bullet_enemyPatternNormal3_2[i].getY(),
				_bullet_enemyPatternNormal3_2[i].getRadius() * 2, _bullet_enemyPatternNormal3_2[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal3_2[i].getBulletRect().top >= WINSIZEY || _bullet_enemyPatternNormal3_2[i].getBulletRect().bottom <= 0 ||
			_bullet_enemyPatternNormal3_2[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal3_2[i].getBulletRect().left >= WINSIZEX) &&
			_bullet_enemyPatternNormal3_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal3_2[i].setShot(FALSE);
			_bullet_enemyPatternNormal3_2.erase(_bullet_enemyPatternNormal3_2.begin() + i);
			scorePoint += 150;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 3 탄막 2 그레이즈 판정
void mainGame::graze_enemyPatternNormal3_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal3_2[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal3_2[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal3_2[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 3 탄막 2 피탄 판정
void mainGame::hit_enemyPatternNormal3_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal3_2.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal3_2[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 3 컴퓨터 무빙
void mainGame::comMove_enemyPatternNormal3()
{
	if (enemyPattern == PATTERN_3)
	{
		enemyPatternNormal3_enemyMoveDelay++;
	}
	if (enemyPatternNormal3_enemyMoveDelay > 50)
	{
		enemyPatternNormal3_enemyMove = RANDOM->Range(0, 1);
		enemyPatternNormal3_enemyMoveDelay = 0;
	}
	if (enemyPattern == PATTERN_3)
	{
		if (enemyPatternNormal3_enemyMove == 0)
		{
			_enemy.setX(_enemy.getX() - 3);

			if (_enemy.getPlayerRect().left < 200)
			{
				enemyPatternNormal3_enemyMove = 1;
			}
		}
		else
		{
			_enemy.setX(_enemy.getX() + 3);

			if (_enemy.getPlayerRect().right > 600)
			{
				enemyPatternNormal3_enemyMove = 0;
			}
		}
	}
}

// 컴퓨터 탄막 패턴 - 통상 4 탄막 1 생성
void mainGame::bulletFire_enemyPatternNormal4_1()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_4 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal4_attackDelay1_1++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_4 && enemyPatternChange == FALSE)
	{
		// 탄막 발사 딜레이
		if (enemyPatternNormal4_attackDelay1_1 >= 5)
		{
			// 탄막 1 생성
			for (int i = 0; i < 8; i++)
			{
				_bullet_enemyPatternNormal4_1.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 1 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal4_1.size(); i++)
			{
				if (_bullet_enemyPatternNormal4_1[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal4_1[i].setX(_enemy.getX());
					_bullet_enemyPatternNormal4_1[i].setY(_enemy.getY());
					_bullet_enemyPatternNormal4_1[i].setSpeed(RANDOM->Range(2.0f, 8.0f));
					_bullet_enemyPatternNormal4_1[i].setAngle((PI * 2) - RANDOM->Range(0.0f, 6.28f));
					_bullet_enemyPatternNormal4_1[i].setRadius(8.0f);
					_bullet_enemyPatternNormal4_1[i].setGravity(0.0f);
					_bullet_enemyPatternNormal4_1[i].setShot(TRUE);
					_bullet_enemyPatternNormal4_1[i].setGuidance(FALSE);
					_bullet_enemyPatternNormal4_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal4_1[i].getX(), _bullet_enemyPatternNormal4_1[i].getY(),
						_bullet_enemyPatternNormal4_1[i].getRadius() * 2, _bullet_enemyPatternNormal4_1[i].getRadius() * 2));;
					enemyPatternNormal4_bulletTemp1_1++;
				}
			}
			enemyPatternNormal4_attackDelay1_1 = 0;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 4 탄막 1 이동
void mainGame::bulletMove_enemyPatternNormal4_1()
{
	// 탄막 1 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal4_1.size(); i++)
	{
		// 탄막 1 무빙 처리
		if (_bullet_enemyPatternNormal4_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal4_1[i].setX(_bullet_enemyPatternNormal4_1[i].getX() + (cosf(_bullet_enemyPatternNormal4_1[i].getAngle()) *
				_bullet_enemyPatternNormal4_1[i].getSpeed()));
			_bullet_enemyPatternNormal4_1[i].setY(_bullet_enemyPatternNormal4_1[i].getY() + (-sinf(_bullet_enemyPatternNormal4_1[i].getAngle()) *
				_bullet_enemyPatternNormal4_1[i].getSpeed()));

			_bullet_enemyPatternNormal4_1[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal4_1[i].getX(), _bullet_enemyPatternNormal4_1[i].getY(),
				_bullet_enemyPatternNormal4_1[i].getRadius() * 2, _bullet_enemyPatternNormal4_1[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal4_1[i].getBulletRect().top >= 800 || _bullet_enemyPatternNormal4_1[i].getBulletRect().bottom <= -400 ||
			_bullet_enemyPatternNormal4_1[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal4_1[i].getBulletRect().left >= 800) &&
			_bullet_enemyPatternNormal4_1[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal4_1[i].setShot(FALSE);
			_bullet_enemyPatternNormal4_1.erase(_bullet_enemyPatternNormal4_1.begin() + i);
			scorePoint += 200;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 4 탄막 1 그레이즈 판정
void mainGame::graze_enemyPatternNormal4_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal4_1.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal4_1[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal4_1[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal4_1[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 4 탄막 1 피탄 판정
void mainGame::hit_enemyPatternNormal4_1()
{
	for (int i = 0; i < _bullet_enemyPatternNormal4_1.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal4_1[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 4 탄막 2 생성
void mainGame::bulletFire_enemyPatternNormal4_2()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_4 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal4_attackDelay1_2++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_4 && enemyPatternChange == FALSE)
	{
		// 탄막 발사 딜레이
		if (enemyPatternNormal4_attackDelay1_2 >= 5)
		{
			// 탄막 2 생성
			for (int i = 0; i < 8; i++)
			{
				_bullet_enemyPatternNormal4_2.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 2 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal4_2.size(); i++)
			{
				if (_bullet_enemyPatternNormal4_2[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal4_2[i].setX(_enemy.getX());
					_bullet_enemyPatternNormal4_2[i].setY(_enemy.getY());
					_bullet_enemyPatternNormal4_2[i].setSpeed(RANDOM->Range(5.0f, 12.0f));
					_bullet_enemyPatternNormal4_2[i].setAngle((PI * 2) - RANDOM->Range(0.0f, 6.28f));
					_bullet_enemyPatternNormal4_2[i].setRadius(8.0f);
					_bullet_enemyPatternNormal4_2[i].setGravity(0.0f);
					_bullet_enemyPatternNormal4_2[i].setShot(TRUE);
					_bullet_enemyPatternNormal4_2[i].setGuidance(FALSE);
					_bullet_enemyPatternNormal4_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal4_2[i].getX(), _bullet_enemyPatternNormal4_2[i].getY(),
						_bullet_enemyPatternNormal4_2[i].getRadius() * 2, _bullet_enemyPatternNormal4_2[i].getRadius() * 2));;
					enemyPatternNormal4_bulletTemp1_2++;
				}
			}
			enemyPatternNormal4_attackDelay1_2 = 0;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 4 탄막 2 이동
void mainGame::bulletMove_enemyPatternNormal4_2()
{
	// 탄막 2 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal4_2.size(); i++)
	{
		// 탄막 2 무빙 처리
		if (_bullet_enemyPatternNormal4_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal4_2[i].setX(_bullet_enemyPatternNormal4_2[i].getX() + (cosf(_bullet_enemyPatternNormal4_2[i].getAngle()) *
				_bullet_enemyPatternNormal4_2[i].getSpeed()));
			_bullet_enemyPatternNormal4_2[i].setY(_bullet_enemyPatternNormal4_2[i].getY() + (-sinf(_bullet_enemyPatternNormal4_2[i].getAngle()) *
				_bullet_enemyPatternNormal4_2[i].getSpeed()));

			_bullet_enemyPatternNormal4_2[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal4_2[i].getX(), _bullet_enemyPatternNormal4_2[i].getY(),
				_bullet_enemyPatternNormal4_2[i].getRadius() * 2, _bullet_enemyPatternNormal4_2[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal4_2[i].getBulletRect().top >= 800 || _bullet_enemyPatternNormal4_2[i].getBulletRect().bottom <= -400 ||
			_bullet_enemyPatternNormal4_2[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal4_2[i].getBulletRect().left >= 800) &&
			_bullet_enemyPatternNormal4_2[i].getShot() == TRUE)
		{
			_bullet_enemyPatternNormal4_2[i].setShot(FALSE);
			_bullet_enemyPatternNormal4_2.erase(_bullet_enemyPatternNormal4_2.begin() + i);
			scorePoint += 200;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 4 탄막 2 그레이즈 판정
void mainGame::graze_enemyPatternNormal4_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal4_2.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal4_2[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal4_2[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal4_2[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 4 탄막 2 피탄 판정
void mainGame::hit_enemyPatternNormal4_2()
{
	for (int i = 0; i < _bullet_enemyPatternNormal4_2.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal4_2[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}

// 컴퓨터 탄막 패턴 - 통상 5 탄막 생성
void mainGame::bulletFire_enemyPatternNormal5()
{
	// 딜레이 생성
	if (enemyPattern == PATTERN_5 && enemyPatternChange == FALSE)
	{
		enemyPatternNormal5_attackDelay++;
	}

	// 탄막 생성
	if (enemyPattern == PATTERN_5 && enemyPatternChange == FALSE)
	{
		// 체력에 따른 탄막 랭크 변화
		if (enemyHP <= 1400 && enemyHP >= 1100)
		{
			enemyPatternNormal5_attackRank = 1;
			enemyPatternNormal5_attackDelayTemp = RANDOM->Range(130, 150);
		}
		if (enemyHP < 1100 && enemyHP >= 800)
		{
			enemyPatternNormal5_attackRank = 2;
			enemyPatternNormal5_attackDelayTemp = RANDOM->Range(110, 130);
		}
		if (enemyHP < 800 && enemyHP >= 500)
		{
			enemyPatternNormal5_attackRank = 3;
			enemyPatternNormal5_attackDelayTemp = RANDOM->Range(90, 110);
		}
		if (enemyHP < 500 && enemyHP >= 200)
		{
			enemyPatternNormal5_attackRank = 4;
			enemyPatternNormal5_attackDelayTemp = RANDOM->Range(60, 90);
		}
		if (enemyHP < 200)
		{
			enemyPatternNormal5_attackRank = 5;
			enemyPatternNormal5_attackDelayTemp = RANDOM->Range(30, 60);
		}

		// X, Y 좌표 랜덤 설정
		enemyPatternNormal5_randX = RANDOM->Range(200, 600);
		enemyPatternNormal5_randY = RANDOM->Range(100, 200);

		// 탄막 발사 딜레이
		if (enemyPatternNormal5_attackDelay >= enemyPatternNormal5_attackDelayTemp)
		{
			// 탄막 1 생성
			for (int i = 0; i < 50; i++)
			{
				_bullet_enemyPatternNormal5.push_back(tagBullet(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, FALSE));
			}

			// 탄막 속도 랜덤 설정
			switch (enemyPatternNormal5_attackRank)
			{
			case 1:
				enemyPatternNormal5_speedRand = RANDOM->Range(3.0f, 3.5f);
				break;
			case 2:
				enemyPatternNormal5_speedRand = RANDOM->Range(3.0f, 4.5f);
				break;
			case 3:
				enemyPatternNormal5_speedRand = RANDOM->Range(2.0f, 5.5f);
				break;
			case 4:
				enemyPatternNormal5_speedRand = RANDOM->Range(2.0f, 6.5f);
				break;
			case 5:
				enemyPatternNormal5_speedRand = RANDOM->Range(1.0f, 7.0f);
				break;
			}

			// 탄막 1 스테이터스 설정
			for (int i = 0; i < _bullet_enemyPatternNormal5.size(); i++)
			{
				if (_bullet_enemyPatternNormal5[i].getShot() == TRUE)
				{
					continue;
				}
				else
				{
					_bullet_enemyPatternNormal5[i].setX(enemyPatternNormal5_randX);
					_bullet_enemyPatternNormal5[i].setY(enemyPatternNormal5_randY);
					_bullet_enemyPatternNormal5[i].setSpeed(enemyPatternNormal5_speedRand);
					_bullet_enemyPatternNormal5[i].setAngle(PI - (0.1256 * (enemyPatternNormal5_bulletTemp % 50)));
					_bullet_enemyPatternNormal5[i].setRadius(10.0f);
					_bullet_enemyPatternNormal5[i].setGravity(0.0f);
					_bullet_enemyPatternNormal5[i].setShot(TRUE);
					_bullet_enemyPatternNormal5[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal5[i].getX(), _bullet_enemyPatternNormal5[i].getY(),
						_bullet_enemyPatternNormal5[i].getRadius() * 2, _bullet_enemyPatternNormal5[i].getRadius() * 2));;
					enemyPatternNormal5_bulletTemp++;
				}
			}

			enemyPatternNormal5_attackDelay = 0;
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 5 탄막 이동
void mainGame::bulletMove_enemyPatternNormal5()
{
	// 탄막 1 무빙
	for (int i = 0; i < _bullet_enemyPatternNormal5.size(); i++)
	{
		// 탄막 1 무빙 처리
		if (_bullet_enemyPatternNormal5[i].getShot() == TRUE)
		{
			if (_bullet_enemyPatternNormal5[i].getReflect_X() == FALSE)
			{
				_bullet_enemyPatternNormal5[i].setX(_bullet_enemyPatternNormal5[i].getX() + (cosf(_bullet_enemyPatternNormal5[i].getAngle()) *
					_bullet_enemyPatternNormal5[i].getSpeed()));
			}
			else
			{
				_bullet_enemyPatternNormal5[i].setX(_bullet_enemyPatternNormal5[i].getX() - (cosf(_bullet_enemyPatternNormal5[i].getAngle()) *
					_bullet_enemyPatternNormal5[i].getSpeed()));
			}
			if (_bullet_enemyPatternNormal5[i].getReflect_Y() == FALSE)
			{
				_bullet_enemyPatternNormal5[i].setY(_bullet_enemyPatternNormal5[i].getY() + (-sinf(_bullet_enemyPatternNormal5[i].getAngle()) *
					_bullet_enemyPatternNormal5[i].getSpeed()));
			}
			else
			{
				_bullet_enemyPatternNormal5[i].setY(_bullet_enemyPatternNormal5[i].getY() - (-sinf(_bullet_enemyPatternNormal5[i].getAngle()) *
					_bullet_enemyPatternNormal5[i].getSpeed()));
			}

			_bullet_enemyPatternNormal5[i].setBulletRect(RectMakeCenter(_bullet_enemyPatternNormal5[i].getX(), _bullet_enemyPatternNormal5[i].getY(),
				_bullet_enemyPatternNormal5[i].getRadius() * 2, _bullet_enemyPatternNormal5[i].getRadius() * 2));
		}

		// 화면 밖으로 벗어났을 경우 탄막 제거
		if ((_bullet_enemyPatternNormal5[i].getBulletRect().top >= WINSIZEY || _bullet_enemyPatternNormal5[i].getBulletRect().bottom <= 0 ||
			_bullet_enemyPatternNormal5[i].getBulletRect().right <= 0 || _bullet_enemyPatternNormal5[i].getBulletRect().left >= 800) &&
			_bullet_enemyPatternNormal5[i].getShot() == TRUE)
		{
			if (_bullet_enemyPatternNormal5[i].getReflect() == FALSE)
			{
				if (_bullet_enemyPatternNormal5[i].getY() >= WINSIZEY)
				{
					_bullet_enemyPatternNormal5[i].setReflect(TRUE);
				}
				else if (_bullet_enemyPatternNormal5[i].getX() <= 0 || _bullet_enemyPatternNormal5[i].getX() >= 800)
				{
					_bullet_enemyPatternNormal5[i].setReflect_X(TRUE);
					_bullet_enemyPatternNormal5[i].setReflect(TRUE);
				}
				else if (_bullet_enemyPatternNormal5[i].getY() <= 0)
				{
					_bullet_enemyPatternNormal5[i].setReflect_Y(TRUE);
					_bullet_enemyPatternNormal5[i].setReflect(TRUE);
				}
			}
			else if (_bullet_enemyPatternNormal5[i].getReflect() == TRUE)
			{
				_bullet_enemyPatternNormal5[i].setShot(FALSE);
				_bullet_enemyPatternNormal5.erase(_bullet_enemyPatternNormal5.begin() + i);
				scorePoint += 300;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 5 탄막 그레이즈 판정
void mainGame::graze_enemyPatternNormal5()
{
	for (int i = 0; i < _bullet_enemyPatternNormal5.size(); i++)
	{
		if (collisionEllipseRectangleCheck(_bullet_enemyPatternNormal5[i].getBulletRect(), _playerGraze.getPlayerRect()))
		{
			if (_bullet_enemyPatternNormal5[i].getGraze() == FALSE)
			{
				grazePoint++;
				if (grazePoint <= 100)
				{
					scorePoint += 10;
				}
				else if (grazePoint > 100 && grazePoint <= 500)
				{
					scorePoint += 20;
				}
				else if (grazePoint > 500 && grazePoint <= 1000)
				{
					scorePoint += 30;
				}
				else if (grazePoint > 1000 && grazePoint <= 3000)
				{
					scorePoint += 40;
				}
				else if (grazePoint > 3000 && grazePoint <= 5000)
				{
					scorePoint += 50;
				}
				else if (grazePoint > 5000 && grazePoint <= 7500)
				{
					scorePoint += 60;
				}
				else if (grazePoint > 7500 && grazePoint <= 10000)
				{
					scorePoint += 70;
				}
				else if (grazePoint > 10000 && grazePoint <= 20000)
				{
					scorePoint += 80;
				}
				else if (grazePoint > 20000 && grazePoint <= 30000)
				{
					scorePoint += 90;
				}
				else if (grazePoint > 30000)
				{
					scorePoint += 100;
				}
				_bullet_enemyPatternNormal5[i].setGraze(TRUE);
			}
			else
			{
				continue;
			}
		}
	}
}
// 컴퓨터 탄막 패턴 - 통상 5 탄막 피탄 판정
void mainGame::hit_enemyPatternNormal5()
{
	for (int i = 0; i < _bullet_enemyPatternNormal5.size(); i++)
	{
		if ((collisionEllipseCheck(_playerHitPoint.getPlayerRect(), _bullet_enemyPatternNormal5[i].getBulletRect()) == TRUE) && playerInvincible == FALSE)
		{
			playerHit = TRUE;
			playerAttack = FALSE;
			playerExtendDown = TRUE;

			_playerHitEffect.setX(_player.getX());
			_playerHitEffect.setY(_player.getY());
			_playerHitEffect.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 200, 200));

			_player.setX(400);
			_player.setY(900);
			_player.setPlayerRect(RectMakeCenter(_player.getX(), _player.getY(), 48, 66));
		}
	}
}

// 두 중심점 사이의 거리를 구하는 함수
float mainGame::getDistance(float startX, float startY, float endX, float endY)
{
	float x = endX - startX;
	float y = endY - startY;

	return sqrtf(pow(x, 2) + pow(y, 2));
}

// 두 중심점 사이의 각도를 구하는 함수
float mainGame::getAngle(float startX, float startY, float endX, float endY)
{
	float x = endX - startX;
	float y = endY - startY;

	// 두 중심점 사이의 거리 (빗변) = distance
	float distance = sqrtf(pow(x, 2) + pow(y, 2));

	// 두 중심점 사이의 각도 (역함수 사용) = angle
	// 빗변과 x의 길이를 알고 있으면 각도를 알 수 있다.
	float angle = acosf(x / distance);

	// 예외처리 - 윈도우 API에서 acosf는 0 ~ 180도 까지의 radian값 (0.0f ~ 3.14f)을 리턴시킨다.
	// 즉, 180도 이상의 값에 대한 예외처리를 해줘야 한다.
	if (endY > startY)
	{
		angle = (PI * 2) - angle;
	}

	return angle;
}