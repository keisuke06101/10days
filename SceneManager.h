#include "Input.h"
#include "GameManager.h"
#include <Novice.h>

#pragma once
class SceneManager
{
public:

	~SceneManager();

	void Initialize();

	void Update(char* keys, char* preKeys);

	void Draw();

private:

	enum scene {
		Title,
		StageSelect,
		Game,
		GameClear,
		GameOver
	};

	int sceneNo_ = 0;

	Input* input_ = nullptr;

	GameManager* gameManager_ = nullptr;

};

