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
		title_->GetGameClear()->Update(title_->GetGameClear()->GetFIn());
		if (title_->GetGameClear()->IsSceneChange())
		{
			sceneNo_ = StageSelectScene;
			gameManager_->Initialize(stageSelect_->GetStageNo());
			Novice::StopAudio(voiceHandle_[0]);
		}
		break;

	case StageSelectScene:

		if (!title_->GetGameClear()->IsOpen() && !gameManager_->GetGameClear()->IsOpen() && !gameManager_->GetGameOver()->IsOpen())
		{
		    stageSelect_->Update();
		}
		// シーン遷移更新処理
		gameManager_->GetGameClear()->Update(gameManager_->GetGameClear()->GetFIn());
		gameManager_->GetGameOver()->Update(gameManager_->GetGameOver()->GetFIn());
		title_->GetGameClear()->Update(title_->GetGameClear()->GetFIn());
		stageSelect_->GetGameClear()->Update(stageSelect_->GetGameClear()->GetFIn());
		if (stageSelect_->GetGameClear()->IsSceneChange())
		{
			gameManager_->Initialize(stageSelect_->GetStageNo());
			gameManager_->InitializeTutorial();
			sceneNo_ = Game;
			Novice::StopAudio(voiceHandle_[2]);
		}

		break;

	case Game:
		
		gameManager_->Update(stageSelect_->GetStageNo(), keys, preKeys);
		gameManager_->GetGameClear()->Update(gameManager_->GetGameClear()->GetFIn());
		gameManager_->GetGameOver()->Update(gameManager_->GetGameOver()->GetFIn());

		// ゲームクリア処理
		if (gameManager_->GetGameClear()->SelectR() && gameManager_->GetGameClear()->IsSceneChange() && gameManager_->GetGameClear()->GetRad() >= 1400) {
			sceneNo_ = StageSelectScene;
			stageSelect_->Initialize();
			gameManager_->GetGameClear()->Initialize();
			Novice::StopAudio(voiceHandle_[1]);
			Novice::StopAudio(voiceHandle_[3]);
		}
		if (gameManager_->GetGameClear()->SelectL() && gameManager_->GetGameClear()->GetRad() >= 1400) {
			gameManager_->InitializeTutorial();
			gameManager_->MapReset(stageSelect_->GetStageNo());
		}
		if (gameManager_->GetGameClear()->IsSceneChange() && gameManager_->GetGameClear()->GetRad() <= 0 && gameManager_->GetGameClear()->SelectL())
		{
			gameManager_->GetGameClear()->Initialize();
		}

		// ゲームオーバー処理
		if (gameManager_->GetGameOver()->SelectR() && gameManager_->GetGameOver()->IsSceneChange() && gameManager_->GetGameClear()->GetRad() >= 1400) {
			sceneNo_ = StageSelectScene;
			stageSelect_->Initialize();
			gameManager_->GetGameOver()->Initialize();
		}
		if (gameManager_->GetGameOver()->SelectL() && gameManager_->GetGameOver()->GetRad() >= 1400) {
			gameManager_->MapReset(stageSelect_->GetStageNo());
		}
		if (gameManager_->GetGameOver()->IsSceneChange() && gameManager_->GetGameOver()->GetRad() <= 0 && gameManager_->GetGameOver()->SelectL())
		{
			gameManager_->GetGameOver()->Initialize();
		}

		// シーン遷移
		stageSelect_->GetGameClear()->Update(stageSelect_->GetGameClear()->GetFIn());

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

		title_->GetGameClear()->Draw(title_->GetGameClear()->GetFIn());

		//タイトルBGM
		if (Novice::IsPlayingAudio(voiceHandle_[0]) == 0 || voiceHandle_[0] == -1)
		{
			voiceHandle_[0] = Novice::PlayAudio(audioHandle_[0], 0, 0.1f);
		}

		break;

	case StageSelectScene:
		
		//ステージセレクトBGM
		if (Novice::IsPlayingAudio(voiceHandle_[2]) == 0 || voiceHandle_[0] == -1)
		{
			voiceHandle_[2] = Novice::PlayAudio(audioHandle_[2], 0, 0.1f);
		}

		stageSelect_->Draw();

		// シーン遷移描画
		gameManager_->GetGameClear()->Draw(gameManager_->GetGameClear()->GetFIn());

		gameManager_->GetGameOver()->Draw();

		title_->GetGameClear()->Draw(title_->GetGameClear()->GetFIn());

		stageSelect_->GetGameClear()->Draw(stageSelect_->GetGameClear()->GetFIn());

		break;


	case Game:

		gameManager_->Draw(stageSelect_->GetStageNo());

		gameManager_->GetGameClear()->Draw(gameManager_->GetGameClear()->GetFIn());
		
		gameManager_->GetGameOver()->Draw();

		stageSelect_->GetGameClear()->Draw(stageSelect_->GetGameClear()->GetFIn());

		if (stageSelect_->GetStageNo() != 0)
		{
			//ステージセレクトBGM
			if (Novice::IsPlayingAudio(voiceHandle_[1]) == 0 || voiceHandle_[1] == -1)
			{
				voiceHandle_[1] = Novice::PlayAudio(audioHandle_[1], 0, 0.1f);
			}
		}
		if (stageSelect_->GetStageNo() == 0)
		{
			//チュートリアルBGM
			if (Novice::IsPlayingAudio(voiceHandle_[3]) == 0 || voiceHandle_[3] == -1)
			{
				voiceHandle_[3] = Novice::PlayAudio(audioHandle_[3], 0, 0.1f);
			}
		}

		break;

	case GameClearScene:

		break;

	case GameOverScene:
		
		break;

	default:
		break;
	}
}
