#include "SceneManager.h"

void SceneManager::Initialize()
{
	// シングルトンインスタンスを取得する
	input_ = Input::GetInstance();

	// ゲームシーン管理の初期化
	gameManager_ = new GameManager;

	sceneNo_ = Title;
}

void SceneManager::Update(char* keys, char* preKeys)
{
	switch (sceneNo_) {
	case Title:
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		{
			sceneNo_ = StageSelect;
		}
		break;

	case StageSelect:
		if (keys[DIK_1] && preKeys[DIK_1] == 0)
		{
			sceneNo_ = Game;
			gameManager_->Initialize();
		}

		break;

	case Game:
		
		gameManager_->Update();

		break;
	case GameClear:

		break;
	case GameOver:

		if (keys[DIK_BACKSPACE] && preKeys[DIK_BACKSPACE] == 0) {
			sceneNo_ = Game;
			Initialize();
		}

		break;
	default:
		break;
	}
}

void SceneManager::Draw()
{
	switch (sceneNo_) {
	case Title:
		
		break;
	case Game:

		gameManager_->Draw();

		break;
	case GameClear:

		break;
	case GameOver:
		
		break;
	default:
		break;
	}
}
