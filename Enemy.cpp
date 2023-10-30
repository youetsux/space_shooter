#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(Vec2 _pos)
	:GameChara()
{
	pos_ = _pos;
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	moveDir_ = { 1, 0 };
	isAlive_ = true;
}

Enemy::Enemy()
	:GameChara()
{
	pos_ = Scene::Center();
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	moveDir_ = { 1, 0 };
	isAlive_ = true;
}

void Enemy::MoveDown()
{
	Vec2 yMoveVec = { 0, ENEMY_CHR_SIZE / 4 };
	pos_ = pos_ + yMoveVec;
}

void Enemy::Update()
{
	if (isAlive_) {
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect({ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	}
}

void Enemy::Draw()
{
	if (isAlive_) {
		tex_.resized(ENEMY_CHR_SIZE).drawAt(pos_);
		//rect_.drawFrame(1, 1, Palette::Red);
	}
}
