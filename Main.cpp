# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"
//#include "Enemy.h"
#include "EnemyMaster.h";
#include "Bullet.h"

namespace SIV3DMAIN
{
	void Initialize()
	{
		FontAsset::Register(U"font", FontMethod::MSDF, 48, Typeface::Bold);
		TextureAsset::Register(U"PLAYER", U"images\\ships\\2.png");
		TextureAsset::Register(U"ENEMY", U"images\\ships\\9.png");
		TextureAsset::Register(U"BULLET", U"images\\shots\\3.png");
		TextureAsset::Register(U"EXPLOSION", U"images\\effects\\fx-7.png");

		// 背景の色を設定する | Set the background color
		Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	}
}

std::vector<GameChara*> objList;

void Main()
{

	SIV3DMAIN::Initialize();

	EnemyMaster* em = new EnemyMaster;
	em->InitializeEnemies();
	objList.push_back(em);

	Player* p = nullptr;
	p = new Player;
	p->Initialize();
	objList.push_back(p);


	while (System::Update())
	{
		for (auto& theI : objList)
			theI->Update();
		for (auto& theI : objList)
			theI->Draw();
	}

	//p->Release();
	for (auto& theI : objList)
		delete theI;
	objList.clear();
}


