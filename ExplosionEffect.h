#pragma once
#include "GameChara.h"
class ExplosionEffect :
    public GameChara
{
public:
	ExplosionEffect(double _time){}
	~ExplosionEffect(){}
	double CDTimer_;


};

