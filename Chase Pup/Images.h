#ifndef IMAGES_HPP
#define IMAGES_HPP


//Home Screen Name Drop
int imgC, imgH, imgA, imgS, imgE, imgP, imgU, imgP2;

void loadLetterImages() {
	imgC = iLoadImage("images/c.png");
	imgH = iLoadImage("images/h.png");
	imgA = iLoadImage("images/a.png");
	imgS = iLoadImage("images/s.png");
	imgE = iLoadImage("images/e.png");
	imgP = iLoadImage("images/p1.png");
	imgU = iLoadImage("images/u.png");
	imgP2 = iLoadImage("images/p2.png");
}

//Home Screen Continue
int continueButton[2];

void loadContinueButton() {
	continueButton[0] = iLoadImage("images/button/click1.png");
	continueButton[1] = iLoadImage("images/button/click2.png");
}

//Home Screen Paw
int paw;

void loadPaw() {
	paw = iLoadImage("images/button/bar/paw.png");
}

//Home Screen Paw Print
int pawPrint[21];

void loadPawPrint() {
	for (int i = 0; i < 21; i++) {
		char path[100];
		sprintf_s(path, "images/homePaw/%d.png", i + 1);
		pawPrint[i] = iLoadImage(path);
	}
}

//Menu Page
int menuBg, menuStart, menuHowTo, menuCredits, menuExit;

void loadMenu() {
	menuBg = iLoadImage("images/menu/bg/bg.jpg");
	menuStart = iLoadImage("images/menu/whiteButtons/startButton.png");
	menuHowTo = iLoadImage("images/menu/whiteButtons/howToButton.png");
	menuCredits = iLoadImage("images/menu/whiteButtons/creditsButton.png");
	menuExit = iLoadImage("images/menu/whiteButtons/exitButton.png");
}

//Menu Screen Dog
int menuDog[70];

void loadMenuDog() {
	for (int i = 0; i < 70; i++) {
		char path[100];
		sprintf_s(path, "images/menu/menudog/%d.jpg", i + 1);
		menuDog[i] = iLoadImage(path);
	}
}

//Start Level Page
int levelPageBg, levelBg, level_1_Platform, standingDog, pauseBg, gameOverBg, level_2_Platform, reviveBg, level_3_Platform;
int levelCompletedBg0Star, levelCompletedBg1Star, levelCompletedBg2Star, levelCompletedBg3Star, highScoreBg, highScoreButton;
int sniffingDogFlipped[11], sniffingDog[11];

void loadLevelPage() {
	levelPageBg = iLoadImage("images/menu/start/level/levelBg.jpg");
	levelBg = iLoadImage("images/menu/start/level/1/bg.jpg");
	level_1_Platform = iLoadImage("images/menu/start/level/1/lvl1.png");
	standingDog = iLoadImage("images/menu/start/standingDog/standingDog1.png");
	pauseBg = iLoadImage("images/menu/start/level/pausePage/bg.png");
	gameOverBg = iLoadImage("images/menu/start/level/gameOverPage/bg.png");
	reviveBg = iLoadImage("images/menu/start/level/gameOverPage/reviveBg.png");
	levelCompletedBg0Star = iLoadImage("images/menu/start/level/gameOverPage/levelCompletedBg0Star.png");
	levelCompletedBg1Star = iLoadImage("images/menu/start/level/gameOverPage/levelCompletedBg1Star.png");
	levelCompletedBg2Star = iLoadImage("images/menu/start/level/gameOverPage/levelCompletedBg2Star.png");
	levelCompletedBg3Star = iLoadImage("images/menu/start/level/gameOverPage/levelCompletedBg3Star.png");

	level_2_Platform = iLoadImage("images/menu/start/level/2/lvl2.png");
	level_3_Platform = iLoadImage("images/menu/start/level/3/lvl3.png");

	highScoreBg = iLoadImage("images/menu/highScore/highScoreBg.jpg");
	highScoreButton = iLoadImage("images/menu/highScore/highScoreButton.png");
}

void loadSniffingDog() {
	sniffingDog[0] = iLoadImage("images/menu/start/sniffingDog/1.png");
	sniffingDog[1] = iLoadImage("images/menu/start/sniffingDog/2.png");
	sniffingDog[2] = iLoadImage("images/menu/start/sniffingDog/3.png");
	sniffingDog[3] = iLoadImage("images/menu/start/sniffingDog/4.png");
	sniffingDog[4] = iLoadImage("images/menu/start/sniffingDog/5.png");
	sniffingDog[5] = iLoadImage("images/menu/start/sniffingDog/6.png");
	sniffingDog[6] = iLoadImage("images/menu/start/sniffingDog/7.png");
	sniffingDog[7] = iLoadImage("images/menu/start/sniffingDog/8.png");
	sniffingDog[8] = iLoadImage("images/menu/start/sniffingDog/9.png");
	sniffingDog[9] = iLoadImage("images/menu/start/sniffingDog/10.png");
	sniffingDog[10] = iLoadImage("images/menu/start/sniffingDog/11.png");
}

void loadSniffingDogFlipped() {
	sniffingDogFlipped[0] = iLoadImage("images/menu/start/sniffingDogFlipped/1.png");
	sniffingDogFlipped[1] = iLoadImage("images/menu/start/sniffingDogFlipped/2.png");
	sniffingDogFlipped[2] = iLoadImage("images/menu/start/sniffingDogFlipped/3.png");
	sniffingDogFlipped[3] = iLoadImage("images/menu/start/sniffingDogFlipped/4.png");
	sniffingDogFlipped[4] = iLoadImage("images/menu/start/sniffingDogFlipped/5.png");
	sniffingDogFlipped[5] = iLoadImage("images/menu/start/sniffingDogFlipped/6.png");
	sniffingDogFlipped[6] = iLoadImage("images/menu/start/sniffingDogFlipped/7.png");
	sniffingDogFlipped[7] = iLoadImage("images/menu/start/sniffingDogFlipped/8.png");
	sniffingDogFlipped[8] = iLoadImage("images/menu/start/sniffingDogFlipped/9.png");
	sniffingDogFlipped[9] = iLoadImage("images/menu/start/sniffingDogFlipped/10.png");
	sniffingDogFlipped[10] = iLoadImage("images/menu/start/sniffingDogFlipped/11.png");
}

int sneakingDog[72];

void loadSneakingDog() {
	sneakingDog[0] = iLoadImage("images/menu/highScore/sneakingDog/1.jpg");
	sneakingDog[1] = iLoadImage("images/menu/highScore/sneakingDog/2.jpg");
	sneakingDog[2] = iLoadImage("images/menu/highScore/sneakingDog/3.jpg");
	sneakingDog[3] = iLoadImage("images/menu/highScore/sneakingDog/4.jpg");
	sneakingDog[4] = iLoadImage("images/menu/highScore/sneakingDog/5.jpg");
	sneakingDog[5] = iLoadImage("images/menu/highScore/sneakingDog/6.jpg");
	sneakingDog[6] = iLoadImage("images/menu/highScore/sneakingDog/7.jpg");
	sneakingDog[7] = iLoadImage("images/menu/highScore/sneakingDog/8.jpg");
	sneakingDog[8] = iLoadImage("images/menu/highScore/sneakingDog/9.jpg");
	sneakingDog[9] = iLoadImage("images/menu/highScore/sneakingDog/10.jpg");
	sneakingDog[10] = iLoadImage("images/menu/highScore/sneakingDog/11.jpg");
	sneakingDog[11] = iLoadImage("images/menu/highScore/sneakingDog/12.jpg");
	sneakingDog[12] = iLoadImage("images/menu/highScore/sneakingDog/13.jpg");
	sneakingDog[13] = iLoadImage("images/menu/highScore/sneakingDog/14.jpg");
	sneakingDog[14] = iLoadImage("images/menu/highScore/sneakingDog/15.jpg");
	sneakingDog[15] = iLoadImage("images/menu/highScore/sneakingDog/16.jpg");
	sneakingDog[16] = iLoadImage("images/menu/highScore/sneakingDog/17.jpg");
	sneakingDog[17] = iLoadImage("images/menu/highScore/sneakingDog/18.jpg");
	sneakingDog[18] = iLoadImage("images/menu/highScore/sneakingDog/19.jpg");
	sneakingDog[19] = iLoadImage("images/menu/highScore/sneakingDog/20.jpg");
	sneakingDog[20] = iLoadImage("images/menu/highScore/sneakingDog/21.jpg");
	sneakingDog[21] = iLoadImage("images/menu/highScore/sneakingDog/22.jpg");
	sneakingDog[22] = iLoadImage("images/menu/highScore/sneakingDog/23.jpg");
	sneakingDog[23] = iLoadImage("images/menu/highScore/sneakingDog/24.jpg");
	sneakingDog[24] = iLoadImage("images/menu/highScore/sneakingDog/25.jpg");
	sneakingDog[25] = iLoadImage("images/menu/highScore/sneakingDog/26.jpg");
	sneakingDog[26] = iLoadImage("images/menu/highScore/sneakingDog/27.jpg");
	sneakingDog[27] = iLoadImage("images/menu/highScore/sneakingDog/28.jpg");
	sneakingDog[28] = iLoadImage("images/menu/highScore/sneakingDog/29.jpg");
	sneakingDog[29] = iLoadImage("images/menu/highScore/sneakingDog/30.jpg");
	sneakingDog[30] = iLoadImage("images/menu/highScore/sneakingDog/31.jpg");
	sneakingDog[31] = iLoadImage("images/menu/highScore/sneakingDog/32.jpg");
	sneakingDog[32] = iLoadImage("images/menu/highScore/sneakingDog/33.jpg");
	sneakingDog[33] = iLoadImage("images/menu/highScore/sneakingDog/34.jpg");
	sneakingDog[34] = iLoadImage("images/menu/highScore/sneakingDog/35.jpg");
	sneakingDog[35] = iLoadImage("images/menu/highScore/sneakingDog/36.jpg");
	sneakingDog[36] = iLoadImage("images/menu/highScore/sneakingDog/37.jpg");
	sneakingDog[37] = iLoadImage("images/menu/highScore/sneakingDog/38.jpg");
	sneakingDog[38] = iLoadImage("images/menu/highScore/sneakingDog/39.jpg");
	sneakingDog[39] = iLoadImage("images/menu/highScore/sneakingDog/40.jpg");
	sneakingDog[40] = iLoadImage("images/menu/highScore/sneakingDog/41.jpg");
	sneakingDog[41] = iLoadImage("images/menu/highScore/sneakingDog/42.jpg");
	sneakingDog[42] = iLoadImage("images/menu/highScore/sneakingDog/43.jpg");
	sneakingDog[43] = iLoadImage("images/menu/highScore/sneakingDog/44.jpg");
	sneakingDog[44] = iLoadImage("images/menu/highScore/sneakingDog/45.jpg");
	sneakingDog[45] = iLoadImage("images/menu/highScore/sneakingDog/46.jpg");
	sneakingDog[46] = iLoadImage("images/menu/highScore/sneakingDog/47.jpg");
	sneakingDog[47] = iLoadImage("images/menu/highScore/sneakingDog/48.jpg");
	sneakingDog[48] = iLoadImage("images/menu/highScore/sneakingDog/49.jpg");
	sneakingDog[49] = iLoadImage("images/menu/highScore/sneakingDog/50.jpg");
	sneakingDog[50] = iLoadImage("images/menu/highScore/sneakingDog/51.jpg");
	sneakingDog[51] = iLoadImage("images/menu/highScore/sneakingDog/52.jpg");
	sneakingDog[52] = iLoadImage("images/menu/highScore/sneakingDog/53.jpg");
	sneakingDog[53] = iLoadImage("images/menu/highScore/sneakingDog/54.jpg");
	sneakingDog[54] = iLoadImage("images/menu/highScore/sneakingDog/55.jpg");
	sneakingDog[55] = iLoadImage("images/menu/highScore/sneakingDog/56.jpg");
	sneakingDog[56] = iLoadImage("images/menu/highScore/sneakingDog/57.jpg");
	sneakingDog[57] = iLoadImage("images/menu/highScore/sneakingDog/58.jpg");
	sneakingDog[58] = iLoadImage("images/menu/highScore/sneakingDog/59.jpg");
	sneakingDog[59] = iLoadImage("images/menu/highScore/sneakingDog/60.jpg");
	sneakingDog[60] = iLoadImage("images/menu/highScore/sneakingDog/61.jpg");
	sneakingDog[61] = iLoadImage("images/menu/highScore/sneakingDog/62.jpg");
	sneakingDog[62] = iLoadImage("images/menu/highScore/sneakingDog/63.jpg");
	sneakingDog[63] = iLoadImage("images/menu/highScore/sneakingDog/64.jpg");
	sneakingDog[64] = iLoadImage("images/menu/highScore/sneakingDog/65.jpg");
	sneakingDog[65] = iLoadImage("images/menu/highScore/sneakingDog/66.jpg");
	sneakingDog[66] = iLoadImage("images/menu/highScore/sneakingDog/67.jpg");
	sneakingDog[67] = iLoadImage("images/menu/highScore/sneakingDog/68.jpg");
	sneakingDog[68] = iLoadImage("images/menu/highScore/sneakingDog/69.jpg");
	sneakingDog[69] = iLoadImage("images/menu/highScore/sneakingDog/70.jpg");
	sneakingDog[70] = iLoadImage("images/menu/highScore/sneakingDog/71.jpg");
	sneakingDog[71] = iLoadImage("images/menu/highScore/sneakingDog/72.jpg");
}





//Dog Properties
int runningDog[9];

//Dog Properties
void loadRunningDog() {
	runningDog[0] = iLoadImage("images/menu/start/runningDog/1.png");
	runningDog[1] = iLoadImage("images/menu/start/runningDog/2.png");
	runningDog[2] = iLoadImage("images/menu/start/runningDog/3.png");
	runningDog[3] = iLoadImage("images/menu/start/runningDog/4.png");
	runningDog[4] = iLoadImage("images/menu/start/runningDog/5.png");
	runningDog[5] = iLoadImage("images/menu/start/runningDog/6.png");
	runningDog[6] = iLoadImage("images/menu/start/runningDog/7.png");
	runningDog[7] = iLoadImage("images/menu/start/runningDog/8.png");
	runningDog[8] = iLoadImage("images/menu/start/runningDog/9.png");
}

int bone, star;

void loadCollectibles() {
	bone = iLoadImage("images/menu/start/collectibles/bone.png");
	star = iLoadImage("images/menu/start/collectibles/star.png");
}

//How To Screen
int howToBg, howToDog[9];

void loadHowTo() {
	howToBg = iLoadImage("images/menu/howtoplay/howToPlayBg.jpg");

	for (int i = 0; i < 9; i++) {
		char path[100];
		sprintf_s(path, "images/menu/howtoplay/howtodog/%d.jpg", i + 1);
		howToDog[i] = iLoadImage(path);
	}
}

//Credit Screen
int creditDog[37], creditsBg;

void loadCreditsDog() {
	creditsBg = iLoadImage("images/menu/credit/creditBg.jpg");

	for (int i = 0; i < 37; i++) {
		char path[100];
		sprintf_s(path, "images/menu/credit/creditdog/%d.jpg", i + 1);
		creditDog[i] = iLoadImage(path);
	}
}

//Exit Screen
int prompt, promptYes, promptNo;

void loadExitPage() {
	prompt = iLoadImage("images/menu/exitButton/exitPrompt.jpg");
	promptYes = iLoadImage("images/menu/exitButton/exitYes.png");
	promptNo = iLoadImage("images/menu/exitButton/exitNo.png");
}


#endif
