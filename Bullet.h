#pragma once
#include "GameChara.h"


const int BULLET_CHR_SIZE{ 20 }; //がぞうさいず
const double BULLET_RECT_SIZE{ 17 }; //当たり判定用のBBのサイズ
const double BULLET_MOVE_SPEED{ 150 }; //プレイヤーの動作スピード


class Bullet :
    public GameChara
{
public:
	Bullet(Vec2 _pos);
	void Update() override;
	void Draw() override;
};

