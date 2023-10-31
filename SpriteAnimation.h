#pragma once
#include "GameChara.h"
#include <vector>
#include "CDTimer.h"

using std::vector;


class SpriteAnimation :
    public GameChara
{
	vector<RectF> frameRects_;
	int frameNum_;//今のアニメフレームは何フレーム目？
	int maxFrame_;
	CDTIMER timer_;
	bool isRepeated_;
	bool isValidated_;//更新しなきゃないかどうか
public:
	SpriteAnimation(int _max_frame, double _interval);
	void InitializeFrame(SizeF _size);//横並びで枚数が決まってるときはこれでいける
	void InitializeFrame(vector<RectF> _frames);//フレームの位置やサイズががばらばらの時はこれで無理やり初期化
	void InitializeFrame(Texture& _tex, SizeF _size);//横並びで枚数が決まってるときはこれでいける
	void InitializeFrame(Texture& _tex, vector<RectF> _frames);//フレームの位置やサイズががばらばらの時はこれで無理やり初期化
	void SetTexture(Texture& _tex) { tex_ = _tex; }
	void RepeatOn() { isRepeated_ = true; }
	void RepeatOff() { isRepeated_ = false; }
	void ValidateFrame() { isValidated_ = true; }
	void InValidateFrame() { isValidated_ = false; }
	bool NeedsFrameRefresh() { return(isValidated_); }
	void Update() override;
	void Draw() override;
};

