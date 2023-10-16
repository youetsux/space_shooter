#pragma once
#include "GameChara.h"
#include <vector>

using std::vector;
class Enemy;

class EnemyMaster :
    public GameChara
{
	void SetEnemiesRect();
public:
	EnemyMaster();
	~EnemyMaster();
	vector<Enemy*> enemies;
	void InitializeEnemies();
	void Update() override;
	void Draw() override;
	
};

