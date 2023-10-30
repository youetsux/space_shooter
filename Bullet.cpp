#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Vec2 _pos)
{
	pos_ = _pos;
	speed_ = BULLET_MOVE_SPEED;
	tex_ = TextureAsset(U"BULLET");
	SetCharaRect(SizeF{ BULLET_RECT_SIZE, BULLET_RECT_SIZE });
	moveDir_ = { 0, -1 };
	isAlive_ = true;
}

Bullet::Bullet()
	:GameChara(BULLET_INIT_POS)
{
	speed_ = BULLET_MOVE_SPEED;
	tex_ = TextureAsset(U"BULLET");
	SetCharaRect(SizeF{ BULLET_RECT_SIZE, BULLET_RECT_SIZE });
	moveDir_ = { 0, -1 };
	isAlive_ = false;
}

void Bullet::Update()
{
	if (isAlive_) {
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect({ BULLET_CHR_SIZE, BULLET_CHR_SIZE });
	}
	if (pos_.y < 0) {
		isAlive_ = false;
		pos_ = BULLET_INIT_POS;
	}
}

void Bullet::Draw()
{
	if (isAlive_) {
		tex_.resized(BULLET_CHR_SIZE).drawAt(pos_);
		//rect_.drawFrame(1, 1, Palette::Red);
	}
}
