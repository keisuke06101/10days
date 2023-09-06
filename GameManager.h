﻿#include <Novice.h>

#pragma once
class GameManager
{
public:

	void Initialize();

	void Update();

	void Draw();

private:

	struct Vector2 {
		float x;
		float y;
	};

	int Size = 64;	// ブロックサイズ

	// ステージ
	int stageNumber = 0;
	enum stageNumber {
		STAGE0,
		STAGE1,
		STAGE2,
		STAGE3,
		STAGE4,
		STAGE5,
		STAGE6,
		STAGE7 //追加分
	};

	// マップ初期値
	int mapCountX = 0, mapCountY = 0;

	//int move = 0;	// プレイヤーの向き 0右 1左

	int map0[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 1
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 2
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 3
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 4
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 5
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 6
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 7
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 8
	  {
		  2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 9
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	enum MapInfo {
		BACK,    // 0 背景
		PLAYER,    // 1 プレイヤー
		WALL,    // 2 壁
		UP,    // 3 上
		RIGHT,    // 4 右
		LEFT,    // 5 左
		DOWN,    // 6 下
		CLEAR
	};

	// マウス
	int mousePosX_ = 0;
	int mousePosY_ = 0;

	// 選択ボックス(仮)
	int selectWX_ = 1000;
	int selectWY_ = 260;
	int selectWR_ = 64;
	int selectWColor_ = WHITE;

	int backColor_[12][15];

	// 四隅の判定
	int leftTX = selectWX_ / Size;
	int leftTY = selectWY_ / Size;
	int saveLeftTX = 0;
	int saveLeftTY = 0;
	int leftBX = selectWX_ / Size;
	int leftBY = (selectWY_ + selectWR_ - 1) / Size;
	int rightTX = (selectWX_ + selectWR_ - 1) / Size;
	int rightTY = (selectWX_ - selectWR_) / Size;
	int rightBX = (selectWX_ + selectWR_ - 1) / Size;
	int rightBY = (selectWY_ + selectWR_ - 1) / Size;

	// フラグ
	bool isWall = 0;

	int back = 0;
	int wall = 0;

};

