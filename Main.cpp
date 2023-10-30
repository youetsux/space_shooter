# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"
#include "Enemy.h"
#include "EnemyMaster.h"
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
		TextureAsset::Register(U"BGIMAGE", U"images\\bg.png");


		// 背景の色を設定する | Set the background color
		Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	}
}

std::vector<GameChara*> objList;
//mainは何のクラス作ったかわかるので、ここでやっちゃうパターン
//当たり判定でやるのは、次のアップデートのためにそれぞれのisAliveを更新すること
//各エネミーのrect_にアクセスできないとダメなのでGameCharaクラスにGetCharaRectを作成
//プレイヤーのGunの中にある弾丸にアクセスできないとダメなので、GetGunBulletを作成
//当たり判定は、すべてのキャラがする可能性があるから、GameChara型のメンバー化
void PlayerVSEnemies(Player* p, EnemyMaster* em);

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
		PlayerVSEnemies(p, em);//ココだけ我慢して、そのままのポインタ使う（妥協の極み）
		for (auto& theI : objList)
			theI->Update();

		//背景描画
		TextureAsset(U"BGIMAGE").resized(Scene::Size()).draw();
		for (auto& theI : objList)
			theI->Draw();
	}

	//p->Release();
	for (auto& theI : objList)
		delete theI;
	objList.clear();
}

void PlayerVSEnemies(Player* p, EnemyMaster* em)
{
	for (auto& theJ : p->GetGunBullet())
	{
		if (!theJ->isActive())
			continue;
		for (auto& theI : em->enemies)
		{
			if (!theI->isActive())
				continue;
			if (theJ->IsMyRectHit(theI->GetCharaRect()))
			{
				theJ->DeActivateMe();
				theI->DeActivateMe();
			}
		}
	}
}
