#pragma once
#include "GameChara.h"
#include <vector>

using std::vector;

const SizeF PLAYER_CHR_SIZE{ 48, 48 }; //がぞうさいず
const SizeF PLAYER_RECT_SIZE{ 48, 48 }; //当たり判定用のBBのサイズ
const double PLAYER_MOVE_SPEED{ PLAYER_CHR_SIZE.x * 1.0 }; //プレイヤーの動作スピード
const int MAX_FRAME_NUM{ 9 };//アニメのコマ数
const double ANIME_INTERVAL{ 1 / 15.0 };


class CDTIMER {
public:
	CDTIMER() :CDTimer_(ANIME_INTERVAL), isTimerRun_(true) {}
	double CDTimer_;
	bool IsTimeOver();
	void ResetTimer();
	void StartTimer();
	void STopTimer();
	bool isTimerRun_;
	void Update();
};

class SpriteAnime :
    public GameChara
{
	int frameNum;//今のアニメフレームは何フレーム目？
public:
	SpriteAnime(Texture _tex);
	~SpriteAnime();//解放処理ここでやる？
	CDTIMER timer;
	vector<RectF> frames_;
	void Initialize(); //初期化用
	void Release(); //解放用
	void Update() override;
	void Draw() override;
};

