#include "stdafx.h"
#include "SpriteAnimation.h"


SpriteAnimation::SpriteAnimation(int _max_frame, double _interval)
	:GameChara(),frameNum_(0),timer_(_interval),maxFrame_(_max_frame)
{
	ActivateMe();
}

//自分で、textureセットしたとき用（横並びの画像）
void SpriteAnimation::InitializeFrame(SizeF _size)
{
	
	RectF tmp;
	for (int i = 0; i < maxFrame_; i++)
	{
		tmp = { {_size.x * i,0},_size.x, _size.y };
		frameRects_.push_back(tmp);
	}
}
//textureを自分でセットして、フレーム情報もセット
void SpriteAnimation::InitializeFrame(vector<RectF> _frames)
{
	frameRects_ = _frames;
}
//textureをセットしたら、横並びなのでフレーム情報は計算できるとき用
void SpriteAnimation::InitializeFrame(Texture& _tex, SizeF _size)
{
	tex_ = _tex;
	RectF tmp;
	for (int i = 0; i < maxFrame_; i++)
	{
		tmp = { {_size.x * i,0},_size.x, _size.y };
		frameRects_.push_back(tmp);

	}
}
//texureをセットしつつ、フレームもセット
void SpriteAnimation::InitializeFrame(Texture& _tex, vector<RectF> _frames)
{
	tex_ = _tex;
	frameRects_ = _frames;
}

void SpriteAnimation::Update()
{
	if (isActive()) {
		if (timer_.IsTimeOver()) {
			frameNum_ = (frameNum_ + 1);
			{
				if (frameNum_ >= maxFrame_) {
					frameNum_ = 0;
					if(!isRepeated_)
						DeActivateMe();
				}
			}
			timer_.ResetTimer();
		}
		else
			timer_.Update();
	}
}

void SpriteAnimation::Draw()
{
	if(isActive())
		tex_(frameRects_[frameNum_]).resized(frameRects_[frameNum_].size).drawAt(pos_);
	//rect_.drawFrame(1, 1, Palette::Red);

}
