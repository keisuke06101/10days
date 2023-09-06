#include <Novice.h>

#pragma once
class Title
{
public:
	void Initialize();

	void Update();

	void Draw();

private:

	//スタートセレクトボックス（ゲーム開始のための）
	float selectStartX_ = 430;
	float selectStartY_ = 500;
	float selectStartH_ = 100;
	float selectStartW_ = 420;
	int selectStartColor_ = WHITE;

	// マウスポジション
	int mousePosX_ = 0;
	int mousePosY_ = 0;

	// テクスチャ
	int title_ = 0;
	int start_ = 0;

	// フラグ
	bool isStart_ = 0;

};

