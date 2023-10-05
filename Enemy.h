#pragma once
#include "GameChara.h"

const int EnemyInLine{ 3 };
const int EnemyLines{ 3 };
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

