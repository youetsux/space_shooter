#include "stdafx.h"
#include "SpriteAnime.h"

SpriteAnime::SpriteAnime(Texture _tex)
{
	tex_ = _tex;
}

SpriteAnime::~SpriteAnime()
{
}

void SpriteAnime::Initialize()
{
}

void SpriteAnime::Release()
{
}

void SpriteAnime::Update()
{
	//CDTimerが<0になったら、フレームナムを１増加させ、CDTimerをリセット（ANIME_INTERVALにもどす）
	if (timer.IsTimeOver()) {
		frameNum = (frameNum + 1) % MAX_FRAME_NUM;
		timer.ResetTimer();
	}
	timer.Update();
}

void SpriteAnime::Draw()
{
	tex_(frames_[frameNum]).resized(PLAYER_CHR_SIZE * 3).drawAt(pos_);
	rect_.drawFrame(1, 1, Palette::Red);
}

bool CDTIMER::IsTimeOver()
{
	return(CDTimer_ < 0);
}

void CDTIMER::ResetTimer()
{
	CDTimer_ = ANIME_INTERVAL;
	StartTimer();
}

void CDTIMER::StartTimer()
{
	isTimerRun_ = true;
}

void CDTIMER::STopTimer()
{
	isTimerRun_ = false;
}

void CDTIMER::Update()
{
	if (isTimerRun_)
		CDTimer_ = CDTimer_ - Scene::DeltaTime();
	//Print << CDTimer_;
}
