#pragma once
#include "GameChara.h"
#include <vector>
#include "Bullet.h"

using std::vector;

const int PLAYER_CHR_SIZE{ 48 }; //がぞうさいず
const double PLAYER_RECT_SIZE{ 45 }; //当たり判定用のBBのサイズ
const double PLAYER_MOVE_SPEED{ PLAYER_CHR_SIZE * 4.5 }; //プレイヤーの動作スピード
const int PLAYER_MAX_BULLET_NUM{ 5 };

enum direction
{
	UP, LEFT, DOWN, RIGHT, NONE
};

class EnemyMaster;
//エラー出たら#include "EnemyMaster.h"したほうがいいね。

class Player :
    public GameChara
{
	vector<Bullet *> Gun_;//プレイヤーの銃
	int GetBlankBullet();
public:
	Player();
	~Player();//解放処理ここでやる？
	//Player(int _maxBullet);
	void Initialize();
	void Release();//それともここでやる？
	direction GetDirection();
	void Update() override;
	void Draw() override;
	//ここでやる？
	bool IsMyRectHit(RectF _rect);
	void MyGunVSEnemies();
	//さてどうやって、ベースクラスのリストからエネミーマスター探そうかなぁ。。。
};

//当たり判定をどこでやろうね？
