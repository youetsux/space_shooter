#pragma once
#include "GameChara.h"
#include <vector>

using std::vector;

class SpriteAnimation :
    public GameChara
{
	vector<RectF> frameRects_;
public:
	SpriteAnimation(int _max_frame, double _interval);
	void InitializeFrame(SizeF _size);//横並びで枚数が決まってるときはこれでいける
	void InitializeFrame(vector<RectF> _frames);//フレームの位置やサイズががばらばらの時はこれで無理やり初期化
	void Update() override;
	void Draw() override;
};

