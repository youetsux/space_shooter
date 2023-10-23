#pragma once
#include "GameChara.h"


const int BULLET_CHR_SIZE{ 20 }; //がぞうさいず
const double BULLET_RECT_SIZE{ 17 }; //当たり判定用のBBのサイズ
const double BULLET_MOVE_SPEED{ 150 }; //プレイヤーの動作スピード
const Vec2 BULLET_INIT_POS{ 0, -BULLET_CHR_SIZE * 2 };


class Bullet :
    public GameChara
{
public:
	Bullet(Vec2 _pos);
	Bullet();
	void Update() override;
	void Draw() override;
};

