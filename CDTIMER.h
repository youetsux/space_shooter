#pragma once
#include "GameChara.h"


const double DEF_TIMER_INTERVAL{ 1 / 24.0 };

class CDTIMER :
    public GameChara
{
	double TIMER_INIT_TIME_;
public:
	CDTIMER() :TIMER_INIT_TIME_(DEF_TIMER_INTERVAL), CDTimer_(TIMER_INIT_TIME_), isTimerRun_(true) {}
	CDTIMER(double _initTime) :TIMER_INIT_TIME_(_initTime), CDTimer_(TIMER_INIT_TIME_), isTimerRun_(true) {}
	double CDTimer_;
	bool IsTimeOver();
	void ResetTimer();
	void StartTimer();
	void STopTimer();
	bool isTimerRun_;
	void Update() override;
};

