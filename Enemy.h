#pragma once
#include "GameChara.h"

const int EnemyInLine{ 11 };
const int EnemyLines{ 5 };
const int EnemyNum{ EnemyInLine * EnemyLines };

class Enemy :
    public GameChara
{
public:
	Enemy(Vec2 _pos);
	Enemy();
	void SetPosition(Vec2 _pos);
	void Update() override;
	void Draw() override;
};

