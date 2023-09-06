#include "Title.h"

void Title::Initialize()
{
	title_ = Novice::LoadTexture("./Resource/images/title.png");
	start_ = Novice::LoadTexture("./Resource/images/start.png");
}

void Title::Update()
{
	Novice::GetMousePosition(&mousePosX_, &mousePosY_);

	if (mousePosX_ >= selectStartX_ && mousePosX_ <= selectStartX_ + selectStartW_ && mousePosY_ >= selectStartY_ && mousePosY_ <= selectStartY_ + selectStartH_ &&
		mousePosX_ >= selectStartX_ && mousePosX_ <= selectStartY_ + selectStartW_ + spiritR && mousePosY_ >= selectStartY_ && mousePosY_ <= selectStartY_ + selectStartH_)
	{

	}

}

void Title::Draw()
{
}
