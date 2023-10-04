#pragma once
#include "GameChara.h"


const int PLAYER_CHR_SIZE{ 48 }; //がぞうさいず
const double PLAYER_RECT_SIZE{ 45 }; //当たり判定用のBBのサイズ
const double PLAYER_MOVE_SPEED{ PLAYER_CHR_SIZE * 4.5 }; //プレイヤーの動作スピード

enum direction
{
	UP, LEFT, DOWN, RIGHT, NONE
};


class Player :
    public GameChara
{
public:
	Player();
	direction GetDirection();
	void Update() override;
	void Draw() override;
};

