#include "stdafx.h"
#include "EnemyMaster.h"

const float ENEMIES_MOVE_SPEED{ ENEMY_CHR_SIZE * 3.0 };
const SizeF DEFAULT_RECT_SIZE{ EnemyInLine * ENEMY_CHR_SIZE * 1.2,EnemyLines * ENEMY_CHR_SIZE * 1.2 };


EnemyMaster::EnemyMaster()
	:GameChara()
{
	for (int j = 0; j < EnemyLines; j++)
	{
		for (int i = 0; i < EnemyInLine; i++)
		{
			//(i,j)で敵の座標を調整、とりあえず端から並べる
			Vec2 chrSize = { ENEMY_CHR_SIZE, ENEMY_CHR_SIZE };
			Vec2 enemyPos = { i * 100, j * 80 };
			Enemy* e = new Enemy(enemyPos+chrSize);
			enemies.push_back(e);
			//e[j * EnemyInLine + i].SetPosition(enemyPos + chrSize);
		}
	}
	SetCharaRect(DEFAULT_RECT_SIZE);
}

EnemyMaster::~EnemyMaster()
{
	for (auto& theI : enemies)
		delete theI;
	enemies.clear();
}

void EnemyMaster::Draw()
{
	for (auto& theI : enemies){
			theI->Draw();
	}
	rect_.drawFrame(1, 1, Palette::Yellow);
}

void EnemyMaster::Update()
{
	for (auto& theI : enemies)
		theI->Update();
}
