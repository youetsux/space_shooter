# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"
#include "Enemy.h"


void Main()
{
	FontAsset::Register(U"font", FontMethod::MSDF, 48, Typeface::Bold);
	TextureAsset::Register(U"PLAYER", U"images\\ships\\2.png");
	TextureAsset::Register(U"ENEMY", U"images\\ships\\9.png");
	TextureAsset::Register(U"BULLET", U"images\\shots\\1.png");
	TextureAsset::Register(U"EXPLOSION", U"images\\effects\\fx-7.png");

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	//インスタンス　クラスから作った変数の事（クラスの実体）
	//Player p;

	Player* p = nullptr;
	Enemy* e = nullptr;
	////何も引数書かないと、引数なしのコンストラクタが呼ばれる
	p = new Player;
	//int* arr = nullptr;
	//arr = new int[10];
	//PlayerもEnemyもDrawとUpdateをオーバーライドしてね
	e = new Enemy[EnemyNum];
	//インスタンス配列を動的に取得すると引数なしのコンストラクタしか呼べない
	for(int j = 0;j<EnemyLines;j++)
	{
		for (int i = 0; i < EnemyInLine; i++)
		{
			//(i,j)で敵の座標を調整、とりあえず端から並べる
			Vec2 chrSize = { ENEMY_CHR_SIZE, ENEMY_CHR_SIZE };
			Vec2 enemyPos = { i * 100, j * 80 };
			e[j * EnemyInLine + i].SetPosition(enemyPos + chrSize);
		}
		
	}

	while (System::Update())
	{
		p->Update();
		p->Draw();
		for (int i = 0; i < EnemyNum; i++) {
			e[i].Update();
			e[i].Draw();
			//(e+i)->Update();
			//(e+i)->Draw();
		}
		
	}
	delete p;
	delete[] e;
}


