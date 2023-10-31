﻿#pragma once
#include "GameChara.h"
#include <vector>
#include "CDTimer.h"
#include "SpriteAnimation.h"

using std::vector;

const int EXPLOSION_CHR_SIZE{ 48 }; //がぞうさいず
const SizeF EXPLOSION_RECT_SIZE{ 48, 48 }; //当たり判定用のBBのサイズ
const double EXPLOSION_MOVE_SPEED{ 0 }; //プレイヤーの動作スピード
const double EXPLOSION_EXPLODE_TIME{ 4.0 }; //爆発の持続時間
const int MAX_FRAME_NUM{ 9 };//アニメのコマ数
const double ANIME_INTERVAL{ 1 / 10.0 };

class ExplosionEffect :
    public GameChara
{
	SpriteAnimation animeTex_;
public:
	ExplosionEffect(Vec2 _pos);
	~ExplosionEffect(){}
	void Draw() override;
	void Update() override;
};

