#include "stdafx.h"
#include "GameChara.h"

GameChara::GameChara(Vec2 _pos)//メンバイニシャライザ
	:pos_(_pos),isAlive_(false), speed_(0.0f), rect_({0,0,0,0 }),moveDir_({0,0})
{

}
GameChara::GameChara()
{
	pos_ = { 0,0 };
	isAlive_ = false;
	speed_ = 0.0f;
	rect_ = { 0,0,0,0 };
	moveDir_ = { 0,0 };
}
void GameChara::SetCharaRect(SizeF _size)
{
	Vec2 adjustVal = { _size.x / 2.0, _size.y / 2.0 };
	rect_ = { pos_ - adjustVal, _size.x, _size.y };
}
//とりあえず空
void GameChara::Update()
{
}
//とりあえず空
void GameChara::Draw()
{
	Print << U"GC Draw";
}
