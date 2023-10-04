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

	Player p;
	Enemy e({ Scene::Width() / 2,Scene::Height() / 2 - 100 });

	while (System::Update())
	{
		p.Update();
		p.Draw();
		e.Update();
		e.Draw();
	}
}


