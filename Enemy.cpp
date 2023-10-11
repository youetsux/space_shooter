#include "stdafx.h"
#include "Enemy.h"



Enemy::Enemy(Vec2 _pos)
	:GameChara()
{
	//Vec2 chrMargin{ 0, Scene::Height() / 2 + ENEMY_CHR_SIZE * 2 };
	//pos_ = Scene::Center() + chrMargin;
	pos_ = _pos;
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	moveDir_ = { 0, 0 };
	isAlive_ = true;
}

Enemy::Enemy()
	:GameChara()
{
	//Vec2 chrMargin{ 0, Scene::Height() / 2 + ENEMY_CHR_SIZE * 2 };
	//pos_ = Scene::Center() + chrMargin;
	pos_ = Scene::Center();
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	moveDir_ = { 0, 0 };
	isAlive_ = true;
}

void Enemy::Update()
{
	//うごかない
	SetCharaRect({ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
}

void Enemy::Draw()
{
	if (isAlive_) {
		tex_.resized(ENEMY_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}
