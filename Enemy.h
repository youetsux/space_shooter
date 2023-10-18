#pragma once
#include "GameChara.h"

const int EnemyInLine{ 8 };
const int EnemyLines{ 5 };
const int EnemyNum{ EnemyInLine * EnemyLines };
const int ENEMY_CHR_SIZE{ 48 }; //がぞうさいず
const double ENEMY_RECT_SIZE{ 45 }; //当たり判定用のBBのサイズ
const double ENEMY_MOVE_SPEED{ ENEMY_CHR_SIZE /2 }; //プレイヤーの動作スピード

class Enemy :
    public GameChara
{
public:
	Enemy(Vec2 _pos);
	Enemy();
	void FlipMove() { moveDir_ = -moveDir_; }
	void MoveDown();
	void Update() override;
	void Draw() override;
};

