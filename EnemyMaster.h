#pragma once
#include "GameChara.h"
#include <vector>

using std::vector;
class Enemy;

class EnemyMaster :
    public GameChara
{
	void SetEnemiesRect();//敵全体を囲うバウンディングボックス
public:
	EnemyMaster();
	~EnemyMaster();
	vector<Enemy*> enemies;//所属する敵のリスト
	void InitializeEnemies();//所属する敵と自分のパラメータを作成＆初期設定
	void Update() override; //自分（大枠）と敵のリストをアップデート（敵もこっちでやっちゃおう）
	void Draw() override;//自分（大枠）と敵のリストをドロー（敵もこっちでやっちゃおう）
	
};

