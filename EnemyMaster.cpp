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
			Enemy* e = new Enemy;
			enemies.push_back(e);
		}
	}

	
	const int W_MARGIN{ ENEMY_CHR_SIZE/3 };
	const int H_MARGIN{ ENEMY_CHR_SIZE/10 };
	
	//Vec2 Lmargin = { (Scene::Width() - ENEMY_CHR_SIZE * EnemyInLine) / 2.0, ENEMY_CHR_SIZE };

	for (int j = 0; j < EnemyLines; j++) {
		for (int i = 0; i < EnemyInLine; i++) {
			enemies[j * EnemyInLine + i]->speed_ = ENEMY_MOVE_SPEED;
			enemies[j * EnemyInLine + i]->pos_
				= Vec2{ i * (ENEMY_CHR_SIZE + H_MARGIN), j * (ENEMY_CHR_SIZE + W_MARGIN)} + Vec2{ENEMY_CHR_SIZE, ENEMY_CHR_SIZE}/2;
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
			theI->FlipMove();
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
