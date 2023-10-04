#include "stdafx.h"
#include "Enemy.h"

const int ENEMY_CHR_SIZE{ 48 }; //がぞうさいず
const double ENEMY_RECT_SIZE{ 45 }; //当たり判定用のBBのサイズ
const double ENEMY_MOVE_SPEED{ ENEMY_CHR_SIZE * 4.5 }; //プレイヤーの動作スピード


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

void Enemy::Update()
{
	//うごかない
}

void Enemy::Draw()
{
	if (isAlive_) {
		tex_.resized(ENEMY_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}
