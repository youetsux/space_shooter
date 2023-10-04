#pragma once
#include "GameChara.h"
class Enemy :
    public GameChara
{
public:
	Enemy(Vec2 _pos);
	void Update() override;
	void Draw() override;
};

