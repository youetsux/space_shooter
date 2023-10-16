#include "stdafx.h"
#include "EnemyMaster.h"
#include "Enemy.h"

void EnemyMaster::SetEnemiesRect()
{
}

EnemyMaster::EnemyMaster()
{
}

EnemyMaster::~EnemyMaster()
{
}

void EnemyMaster::InitializeEnemies(vector<GameChara*>& _objList)
{
	for (int j = 0; j < EnemyLines; j++)
	{
		for (int i = 0; i < EnemyInLine; i++)
		{
			//(i,j)で敵の座標を調整、とりあえず端から並べる
			Vec2 chrSize = { ENEMY_CHR_SIZE, ENEMY_CHR_SIZE };
			Vec2 enemyPos = { i * 100, j * 80 };
			//e[j * EnemyInLine + i].SetPosition();
			Enemy *e = new Enemy(enemyPos + chrSize);
			enemies.push_back(e);
			_objList.push_back(e);
		}
	}
}

void EnemyMaster::Update()
{

}

void EnemyMaster::Draw()
{
}
