#include <Novice.h>

#pragma once
class Title
{
public:
	void Initialize();

	void Update();

	void Draw();

private:

	//�X�^�[�g�Z���N�g�{�b�N�X�i�Q�[���J�n�̂��߂́j
	float selectStartX_ = 430;
	float selectStartY_ = 500;
	float selectStartH_ = 100;
	float selectStartW_ = 420;
	int selectStartColor_ = WHITE;

	// �}�E�X�|�W�V����
	int mousePosX_ = 0;
	int mousePosY_ = 0;

	// �e�N�X�`��
	int title_ = 0;
	int start_ = 0;

	// �t���O
	bool isStart_ = 0;

};

