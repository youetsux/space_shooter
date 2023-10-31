#include "stdafx.h"
#include "CDTimer.h"

bool CDTIMER::IsTimeOver()
{
	return(CDTimer_ < 0);
}

void CDTIMER::ResetTimer()
{
	CDTimer_ = TIMER_INIT_TIME_;
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
}
