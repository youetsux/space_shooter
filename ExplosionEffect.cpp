#include "stdafx.h"
#include "ExplosionEffect.h"

ExplosionEffect::ExplosionEffect(Vec2 _pos)
	:GameChara(_pos),CDTimer_(EXPLOSION_EXPLODE_TIME)
{
	pos_ = _pos;
	speed_ = 0;
	tex_ = TextureAsset(U"EXPLOSION");
	SetCharaRect(SizeF{ EXPLOSION_RECT_SIZE, EXPLOSION_RECT_SIZE });
	moveDir_ = { 1, 0 };
	isAlive_ = true;
}

void ExplosionEffect::Draw()
{
	if(isAlive_)
		tex_(96, 48, 48, 48).resized(48,48).drawAt(pos_);
}

void ExplosionEffect::Update()
{
	if (CDTimer_ < 0)
		isAlive_ = false;
	else
		CDTimer_ = CDTimer_ - Scene::DeltaTime();
}
