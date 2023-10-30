#pragma once
#include "GameChara.h"

const int EXPLOSION_CHR_SIZE{ 48 }; //がぞうさいず
const double EXPLOSION_RECT_SIZE{ 48 }; //当たり判定用のBBのサイズ
const double EXPLOSION_MOVE_SPEED{ 0 }; //プレイヤーの動作スピード
const double EXPLOSION_EXPLODE_TIME{ 2.0 }; //爆発の持続時間

class ExplosionEffect :
    public GameChara
{
	double CDTimer_;
public:
	ExplosionEffect(Vec2 _pos);
	~ExplosionEffect(){}
	void Draw() override;
	void Update() override;
};

