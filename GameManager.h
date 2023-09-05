#include <Novice.h>

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

	int map0[12][15];

	enum MapInfo {
		BACK,	// 0 背景
		FLOOR,	// 1 床
		WALL,	// 2 壁
		BELT,	// 3 ベルトコンベア
		BELT2,  // 4
		BELT3,  // 5
		BELT4,  // 6
		ELEC,	// 7 ビリビリ壁
		DOOR,	// 8 ドア
		DOOR1,  // 9 ドア１
		DOOR2,   // 10 ドア2
		DOOR3,   // 11 ドア3
		FLAG,    //12  クリアフラグ
		BELT5,   //13 14追加分ベルト
		BELT6,
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

	int back = Novice::LoadTexture("./Resource/images/floor.png");                      //背景
	int wall = Novice::LoadTexture("./Resource/images/metaru.png");                      //壁

};

