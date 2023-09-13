#include "Title.h"

void Title::Initialize()
{
	titleLogo_ = Novice::LoadTexture("./Resource/images/titleLogo.png");
	titleBack_ = Novice::LoadTexture("./Resource/images/titleBack.png");
	start_ = Novice::LoadTexture("./Resource/images/start.png");

	gameClear_ = new GameClear;
	gameClear_->Initialize();
}

void Title::Update()
{
	Novice::GetMousePosition(&mousePosX_, &mousePosY_);

	// クリックスタートボックスのマウスとの判定
	if (mousePosX_ >= selectStartX_ && mousePosX_ <= selectStartX_ + selectStartW_ && mousePosY_ >= selectStartY_ && mousePosY_ <= selectStartY_ + selectStartH_)
	{
		selectStartColor_ = RED;
	}
	else
	{
		selectStartColor_ = WHITE;
		Novice::StopAudio(voiceHandle_[0]);
	}

	if (selectStartColor_ == RED && Novice::IsTriggerMouse(0))
	{
		isStart_ = true;
		Novice::StopAudio(voiceHandle_[0]);
	}
	if (isStart_)
	{
		gameClear_->SetOpen(true);
	}
	else
	{
		Novice::StopAudio(voiceHandle_[1]);
	}
	
	// アニメーション
	Animetion();
}

void Title::Draw()
{
	Novice::DrawSprite(0, 0, titleBack_, 1.f, 1.f, 0.f, WHITE);
	Novice::DrawSpriteRect(140, 100, titleScrX_, 0, titleScrW_, 237,  titleLogo_, 0.07f, 0.8f, 0.f, WHITE);
	Novice::DrawSprite(selectStartX_, selectStartY_, start_, 1.f, 1.f, 0.f, selectStartColor_);
	if (selectStartColor_ == RED)
	{
		//セレクト
		if (Novice::IsPlayingAudio(voiceHandle_[0]) == 0 || voiceHandle_[0] == -1)
		{
			voiceHandle_[0] = Novice::PlayAudio(audioHandle_[0], 0, 0.5f);
		}
	}
	if (selectStartColor_ == RED && Novice::IsTriggerMouse(0))
	{
		//決定
		if (Novice::IsPlayingAudio(voiceHandle_[1]) == 0 || voiceHandle_[1] == -1)
		{
			voiceHandle_[1] = Novice::PlayAudio(audioHandle_[1], 0, 0.5f);
		}
	}
}

void Title::Animetion()
{
	animetionTimer += 1;

	if (animetionTimer >= 7)
	{
		titleScrX_ += 899;
		animetionTimer = 0;
		if (titleScrX_ >= scrLimitX_)
		{
			titleScrX_ = 0;
		}
	}
}
