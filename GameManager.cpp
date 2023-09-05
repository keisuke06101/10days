﻿#include "GameManager.h"

void GameManager::Initialize()
{
	mapCountX = sizeof(map0[0]) / sizeof(map0[0][0]);
	mapCountY = sizeof(map0) / sizeof(map0[0]);
}

void GameManager::Update()
{

	Novice::GetMousePosition(&mousePosX_, &mousePosY_);

	// 四隅の判定
	leftTX = selectWX_ / Size;
	leftTY = selectWY_ / Size;
	leftBX = selectWX_ / Size;
	leftBY = (selectWY_ + selectWR_ - 1) / Size;
	rightTX = (selectWX_ + selectWR_ - 1) / Size;
	rightTY = selectWY_ / Size;
	rightBX = (selectWX_ + selectWR_ - 1) / Size;
	rightBY = (selectWY_ + selectWR_ - 1) / Size;

	if (mousePosX_ >= selectWX_ && mousePosX_ <= selectWX_ + selectWR_ &&
		mousePosY_ >= selectWY_ && mousePosY_ <= selectWY_ + selectWR_ && !isWall)
	{
		selectWColor_ = RED;
	}
	else
	{
		selectWColor_ = WHITE;
	}

	if (selectWColor_ == RED && Novice::IsPressMouse(0))
	{
		isWall = true;
	}

	if (isWall)
	{
		selectWX_ = mousePosX_;
		selectWY_ = mousePosY_;
	}
	// マップとブロックの配置判定
	if (map0[leftTY][leftTX] == BACK && isWall && selectWX_ <= 960)
	{
		backColor_[saveLeftTY][saveLeftTX] = WHITE;
		backColor_[leftTY][leftTX] = RED;
		saveLeftTX = leftTX;
		saveLeftTY = leftTY;
	}

	if (Novice::IsPressMouse(1) && backColor_[leftTY][leftTX] == RED)
	{

		map0[leftTY][leftTX] = WALL;
		isWall = false;
		selectWX_ = 1000;
		selectWY_ = 260;
	}
}

void GameManager::Draw()
{
	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {

			if (stageNumber == STAGE0) {

				// 背景
				if (map0[y][x] == BACK) {
					Novice::DrawSprite(x * Size, y * Size, back, 2, 2, 0, backColor_[y][x]);
				}

				// 壁
				if (map0[y][x] == WALL) {
					Novice::DrawSprite(x * Size, y * Size, wall, 2, 2, 0, WHITE);
				}
			}
		}
	}

	Novice::DrawBox(selectWX_, selectWY_, selectWR_, selectWR_, 0.f, selectWColor_, kFillModeSolid);
	Novice::DrawSprite(selectWX_, selectWY_, wall, 2, 2, 0, selectWColor_);
	Novice::ScreenPrintf(1000, 0, "map[%d][%d]", leftTY, leftTX);
	Novice::ScreenPrintf(1000, 20, "saveMap[%d][%d]", saveLeftTY, saveLeftTX);
}
