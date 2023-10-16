﻿#pragma once
class GameChara
{
public:
	Vec2 pos_;    //場所
	bool isAlive_; //生死
	Texture tex_;  //キャラクタの画像
	double speed_; //移動スピード
	RectF rect_;   //バウンディングボックス
	Vec2 moveDir_; //移動方向

public:
	GameChara(Vec2 _pos);  //コンストラクタのオーバーロード
	GameChara();
	~GameChara(){}

	void SetAlive(bool _alive) { isAlive_ = _alive; }
	void SetSpeed(double _speed) { speed_ = _speed; }
	void SetMoveDir(Vec2 _movedir) { moveDir_ = _movedir; }
	void SetCharaRect(SizeF _size);
	void SetPosition(Vec2 _pos);
	virtual void Update();
	virtual void Draw();
};

