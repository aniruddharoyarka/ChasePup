#ifndef HIGH_SCORE_PAGE_HPP
#define HIGH_SCORE_PAGE_HPP

int highestScore;

int sneakingDogCurrentAnimation = 0;
int highScorePage = 0;

void drawHighScoreBg() {
	iShowImage(0, 0, 1100, 600, highScoreBg);

	iSetColor(0, 0, 0);
	char highScoreText[50];
	sprintf_s(highScoreText, "Highest Bones Collected: %d", highestScore);
	iText(200, 300, highScoreText, GLUT_BITMAP_TIMES_ROMAN_24);
}

void updateSneakingDogAnimation(){
	if (highScorePage) {
		sneakingDogCurrentAnimation = (sneakingDogCurrentAnimation + 1) % 72;
	}
}

void sneakingDogAnimation(){
	iShowImage(550, 0, 469, 352, sneakingDog[sneakingDogCurrentAnimation]);
}

void highScoreButtonClickHandler() {
	menuPage = 0;
	highScorePage = 1;
}

void readHighScore() {
	FILE *ptr;
	if (fopen_s(&ptr, "highscore.txt", "r") == 0 && ptr != NULL) {
		fscanf_s(ptr, "%d", &highestScore);
		fclose(ptr);
	}
	else {
		// If file doesn't exist, set default high score to 0
		highestScore = 0;
	}
}

void writeHighscore(int num) {
	FILE *ptr;
	if (fopen_s(&ptr, "highscore.txt", "w") == 0 && ptr != NULL) {
		fprintf_s(ptr, "%d", num);
		fclose(ptr);
	}
}

// New function to update high score if current bones beat the record
void updateHighScore() {
	if (totalBones > highestScore) {
		highestScore = totalBones;
		writeHighscore(highestScore);
	}
}

#endif