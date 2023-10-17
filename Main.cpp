# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"
//#include "Enemy.h"
#include "EnemyMaster.h";
namespace SIV3DMAIN
{
	void Initialize()
	{
		FontAsset::Register(U"font", FontMethod::MSDF, 48, Typeface::Bold);
		TextureAsset::Register(U"PLAYER", U"images\\ships\\2.png");
		TextureAsset::Register(U"ENEMY", U"images\\ships\\9.png");
		TextureAsset::Register(U"BULLET", U"images\\shots\\1.png");
		TextureAsset::Register(U"EXPLOSION", U"images\\effects\\fx-7.png");

		// 背景の色を設定する | Set the background color
		Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	}
}

std::vector<GameChara*> objList;

void Main()
{

	SIV3DMAIN::Initialize();

	
	//GameChara** objList;
	//Enemy* e = nullptr;

	Player* p = nullptr;
	p = new Player;
	objList.push_back(p);

	////インスタンス配列を動的に取得すると引数なしのコンストラクタしか呼べない
	//for(int j = 0;j<EnemyLines;j++)
	//{
	//	for (int i = 0; i < EnemyInLine; i++)
	//	{
	//		//(i,j)で敵の座標を調整、とりあえず端から並べる
	//		Vec2 chrSize = { ENEMY_CHR_SIZE, ENEMY_CHR_SIZE };
	//		Vec2 enemyPos = { i * 100, j * 80 };
	//		//e[j * EnemyInLine + i].SetPosition();
	//		e = new Enemy(enemyPos + chrSize);
	//		objList.push_back(e);
	//	}
	//}

	EnemyMaster* em = new EnemyMaster;
	em->InitializeEnemies();
	objList.push_back(em);


	while (System::Update())
	{
		for (auto& theI : objList)
			theI->Update();
		for (auto& theI : objList)
			theI->Draw();
	}

	for (auto& theI : objList)
		delete theI;
	objList.clear();
}


