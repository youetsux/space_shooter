#include "stdafx.h"
#include "EnemyMaster.h"
#include "Enemy.h"
#include <algorithm>

void EnemyMaster::SetEnemiesRect()
{
	float xmin = Scene::Width(), xmax = 0;
	float ymin = Scene::Height(), ymax = 0;
	for (auto& theI : enemies)
	{
		if (xmin > theI->pos_.x)
			xmin = theI->pos_.x;
		if (ymin > theI->pos_.y)
			ymin = theI->pos_.y;
		if (xmax <= theI->pos_.x)
			xmax = theI->pos_.x;
		if (ymax <= theI->pos_.y)
			ymax = theI->pos_.y;
	}

	Vec2 adjustVal = { ENEMY_CHR_SIZE / 2, ENEMY_CHR_SIZE / 2 };
	rect_ = { {Vec2{xmin, ymin} - adjustVal}, xmax - xmin + ENEMY_CHR_SIZE, ymax - ymin + ENEMY_CHR_SIZE };
}

EnemyMaster::EnemyMaster()
	:GameChara()
{
	SetSpeed(ENEMY_MOVE_SPEED);
}

EnemyMaster::~EnemyMaster()
{
}

void EnemyMaster::InitializeEnemies()
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
		}
	}

	Vec2 Mmargin = { ENEMY_CHR_SIZE / 3.0, 0 };
	Vec2 Lmargin = { (Scene::Width() - ENEMY_CHR_SIZE * EnemyInLine) / 2.0, ENEMY_CHR_SIZE };

	for (int j = 0; j < EnemyLines; j++) {
		for (int i = 0; i < EnemyInLine; i++) {
			enemies[j * EnemyInLine + i]->speed_ = ENEMY_MOVE_SPEED;
			enemies[j * EnemyInLine + i]->pos_ = Lmargin + Vec2{ i * (ENEMY_CHR_SIZE + Mmargin.x), j * ENEMY_CHR_SIZE };
			enemies[j * EnemyInLine + i]->isAlive_ = true;
			enemies[j * EnemyInLine + i]->tex_ = TextureAsset(U"ENEMY");
			enemies[j * EnemyInLine + i]->moveDir_ = { 1.0, 0.0 };
			enemies[j * EnemyInLine + i]->SetCharaRect(Size{ ENEMY_CHR_SIZE, ENEMY_CHR_SIZE});
		}
	}

	speed_ = ENEMY_MOVE_SPEED; //枠の移動スピードも、エネミー個体と同じ
	SetEnemiesRect(); //全体枠自体の更新
	moveDir_ = { 1.0, 0.0 };//枠の移動方向も、エネミー個体と同じ
}

void EnemyMaster::Update()
{
	for (auto& theI : enemies)
		theI->Update();
	if (KeySpace.down())
	{
		for (auto& theI : enemies)
			theI->SetMoveDir(-theI->moveDir_);
	}
	if (KeyDown.down())
	{
		for (auto& theI : enemies)
			theI->MoveDown();
	}
	SetEnemiesRect();

}

void EnemyMaster::Draw()
{
	for (auto& theI : enemies) {
		theI->Draw();
	}
	rect_.drawFrame(1, 1, Palette::Yellow);
}
