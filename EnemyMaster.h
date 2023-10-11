#pragma once
#include "GameChara.h"
#include "Enemy.h"
#include <vector>

using std::vector;

class EnemyMaster :
    public GameChara
{
	vector<Enemy *> enemies;
public:
	EnemyMaster();
	~EnemyMaster();
	void Draw() override;
	void Update() override;
};

