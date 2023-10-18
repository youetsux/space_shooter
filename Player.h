#pragma once
#include "GameChara.h"
#include <vector>

const int PLAYER_CHR_SIZE{ 48 }; //がぞうさいず
const double PLAYER_RECT_SIZE{ 45 }; //当たり判定用のBBのサイズ
const double PLAYER_MOVE_SPEED{ PLAYER_CHR_SIZE * 4.5 }; //プレイヤーの動作スピード
const int PLAYER_MAX_BULLET_NUM{ 5 };

enum direction
{
	UP, LEFT, DOWN, RIGHT, NONE
};


class Player :
    public GameChara
{

public:
	Player();
	Player(int _maxBullet);
	void Initialize();
	direction GetDirection();
	void Update() override;
	void Draw() override;
};

