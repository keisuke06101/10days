#include "SceneManager.h"

SceneManager::~SceneManager()
{
	delete gameManager_;
	delete title_;
	delete stageSelect_;
}

void SceneManager::Initialize()
{
	// ゲーム管理の初期化
	gameManager_ = new GameManager;

	// タイトル管理の初期化
	title_ = new Title;
	title_->Initialize();

	// ステージセレクトの初期化
	stageSelect_ = new StageSelect;
	stageSelect_->Initialize();

	sceneNo_ = TitleScene;
}

void SceneManager::Update(char* keys, char* preKeys)
{
	switch (sceneNo_) {
	case TitleScene:

		title_->Update();

		if (title_->GetIsStart() == true)
		{
			sceneNo_ = StageSelectScene;
			gameManager_->Initialize();
			
		}
		break;

	case StageSelectScene:

		stageSelect_->Update();
		gameManager_->GetGameClear()->Update(gameManager_->GetGameClear()->GetFIn());
		if (stageSelect_->IsGameStart() == true)
		{
			gameManager_->Initialize();
			sceneNo_ = Game;
		}

		break;

	case Game:
		
		gameManager_->Update(stageSelect_->GetStageNo(), keys);
		gameManager_->GetGameClear()->Update(gameManager_->GetGameClear()->GetFIn());

		if (gameManager_->GetGameClear()->SelectR() && gameManager_->GetGameClear()->IsSceneChange()) {
			sceneNo_ = StageSelectScene;
			stageSelect_->Initialize();
			gameManager_->GetGameClear()->Initialize();
		}

		if (gameManager_->GetGameClear()->SelectL() && gameManager_->GetGameClear()->GetRad() >= 1400) {
			gameManager_->MapReset();
		}
		if (gameManager_->GetGameClear()->IsSceneChange() && gameManager_->GetGameClear()->GetRad() <= 0 && gameManager_->GetGameClear()->SelectL())
		{
			gameManager_->GetGameClear()->Initialize();
		}
		
		break;
	case GameClearScene:

		break;
	case GameOverScene:

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
	case TitleScene:
		
		title_->Draw();

		break;

	case StageSelectScene:
		
		stageSelect_->Draw();

		gameManager_->GetGameClear()->Draw();

		break;


	case Game:

		gameManager_->Draw(stageSelect_->GetStageNo());

		gameManager_->GetGameClear()->Draw();

		break;

	case GameClearScene:

		break;

	case GameOverScene:
		
		break;

	default:
		break;
	}
}
