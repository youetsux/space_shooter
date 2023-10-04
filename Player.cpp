#include "stdafx.h"
#include "Player.h"

Player::Player()
	:GameChara()
{
	Vec2 chrMargin{ 0, Scene::Height() / 2 - PLAYER_CHR_SIZE * 2 };
	pos_ = Scene::Center() + chrMargin;
	speed_ = PLAYER_MOVE_SPEED;
	tex_ = TextureAsset(U"PLAYER");
	SetCharaRect(SizeF{ PLAYER_RECT_SIZE,PLAYER_RECT_SIZE });
	moveDir_ = { 0, 0 };
	isAlive_ = true;
}

direction Player::GetDirection()
{
	if ((KeyUp | KeyW).pressed())
	{
		return UP;
	}
	else if ((KeyLeft | KeyA).pressed())
	{
		return LEFT;
	}
	else if ((KeyDown | KeyS).pressed())
	{
		return DOWN;
	}
	else if ((KeyRight | KeyD).pressed())
	{
		return RIGHT;
	}
	else
		return NONE;
}

void Player::Update()
{   //寿命短い変数は名前も少し適当でいいよ
	direction d = GetDirection();
	switch (d)
	{
	case LEFT:
		moveDir_ = { -1.0, 0 };
		break;
	case RIGHT:
		moveDir_ = { 1.0, 0 };
		break;
	default:
		return;
	}
	pos_ = pos_ + speed_ * Scene::DeltaTime() * moveDir_;
	SetCharaRect(SizeF{ PLAYER_RECT_SIZE,PLAYER_RECT_SIZE });
}

void Player::Draw()
{
	if (isAlive_) {
		tex_.resized(PLAYER_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}
