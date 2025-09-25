#include "iGraphics.h"
#include "Images.h"
#include "homeScreen.h"
#include "menuPage.h"
#include "howToPlay.h"
#include "creditPage.h"
#include "exitPage.h"
#include "variables.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "dogProperties.h"
#include "highScorePage.h"

//Start Page
int startPage = 0;
void startButtonClickHandler();

//Level Map
void loadLevelPage();
void drawLevelPage();
void drawPausePage();

void level_1_ClickHandler();
void drawLevel_1_Page();

void level_2_ClickHandler();
void drawLevel_2_Page();

void level_3_ClickHandler();
void drawLevel_3_Page();

//Sniffing Dog
int currentSniffingDog = 0;
void updateSniffingDog();
void drawSniffingDog();
int sniffingDog_X = 227;
bool isFlipped = false;

void drawBoneCounter();
void drawStarCounter();

//Pause 
int pausePage = 0;
void pauseButtonClickHandler();
void drawPausePage();

//Resume
void resumeButtonClickHandler();

//Restart
void restartButtonClickHandler();

//BackToMap
void backtomapButtonClickHandler();

//Reset
void resetGameOverConditions();

//High Score
void highScoreButtonClickHandler();


//RevivePage
void drawRevivePage();
int revivePage = 0;
void reviveButtonClickHandler();

bool isReviving = false;
void confirmRevive();
int reviveBoneCost = 2;
int reviveBackDistance = 396;

//Level Completed
void drawLevelCompletedPage();
void levelCompletedHandler();
int levelCompletedPage = 0;

void bgmSound();

bool levelCompletedSoundPlayed = false;


void iDraw()
{
	iClear();
	iFilledRectangle(0, 0, 1100, 600);
	drawPawPrint();
	iSetColor(255, 151, 26);
	loadHomeC();
	loadHomeH();
	loadHomeA();
	loadHomeS();
	loadHomeE();
	loadHomeP();
	loadHomeU();
	loadHomeP2();
	if (pDone2 == true) {
		hoverContinueButton();
	}
	glLineWidth(3);
	iLine(startX, startY, endX, endY);
	iShowImage(endX-15, 164, 15, 15, paw);
	if (endX == 900) {
		iSetColor(255, 255, 245);
		iFilledRectangle(185, 164, 715, 30);
	}

	iSetColor(255, 255, 245);

	if (menuPage == 1){
		drawMenuPage();
		menuDogAnimation();
		hoverMenuButtons();
	}
	if (highScorePage == 1) {
		drawHighScoreBg();
		sneakingDogAnimation();
	}

	if (levelPage == 1) {
		drawLevelPage();
		drawSniffingDog();
	}
	if (level_1_Page == 1) {
		drawLevel_1_Page();
		drawBoneCounter();
		drawStarCounter();
		drawCollectibles_lvl1();
		checkCollectibleCollision_lvl1();
		checkLevel1Gaps(); 
		updateFall_lvl1(); 
		gameOverHandler();
		levelCompletedHandler();
		checkLevel1Spikes();
		drawRunningDog();
		if (pausePage == 1) {
			drawPausePage();
		}
		if (gameOverPage == 1) {
			drawGameOverPage();
		}
		if (revivePage == 1) {
			drawRevivePage();
		}
		if (levelCompletedPage == 1) {
			drawLevelCompletedPage();
		}
	}
	if (level_2_Page == 1) {
		drawLevel_2_Page();
		drawBoneCounter();
		drawStarCounter();
		drawCollectibles_lvl2();
		checkCollectibleCollision_lvl2();
		checkSecondaryBarCollision_lvl2();
		checkLevel2Gaps(); 
		updateFall_lvl2(); 
		gameOverHandler();
		levelCompletedHandler();
		checkLevel2Spikes();
		drawRunningDog();
		if (pausePage == 1) {
			drawPausePage();
		}
		if (gameOverPage == 1) {
			drawGameOverPage();
		}
		if (revivePage == 1) {
			drawRevivePage();
		}
		if (levelCompletedPage == 1) {
			drawLevelCompletedPage();
		}
	}
	if (level_3_Page == 1) {
		drawLevel_3_Page();
		drawBoneCounter();
		drawStarCounter();
		drawCollectibles_lvl3();
		checkCollectibleCollision_lvl3();
		checkSecondaryBarCollision_lvl3();
		checkLevel3Gaps();
		updateFall_lvl3();
		gameOverHandler();
		levelCompletedHandler();
		checkLevel3Spikes();
		drawRunningDog();
		if (pausePage == 1) {
			drawPausePage();
		}
		if (gameOverPage == 1) {
			drawGameOverPage();
		}
		if (revivePage == 1) {
			drawRevivePage();
		}
		if (levelCompletedPage == 1) {
			drawLevelCompletedPage();
		}
	}
	if (howToPage == 1) {
		drawHowToPage();
		howToDogAnimation();
	}
	if (creditsPage == 1) {
		drawCreditsPage();
		creditsDogAnimation();
	}
	if (exitPage == 1) {
		drawExitPage();
		hoverExitButton();
	}
}

void iMouseMove(int mx, int my)
{
	
}

void iPassiveMouseMove(int mx, int my)
{
	//continue button hover
	if ((mx >= 345 && mx <= 753) && (my >= 272 && my <= 297)) {
		isHovering = true;
		//mciSendString("play hover from 0", NULL, 0, NULL);
	}
	else {
		isHovering = false;
	}

	//start button hover
	if (menuPage && (mx >= 152 && mx <= 294) && (my >= 364 && my <= 402)) {
		isStartHovering = true;
		//mciSendString("play hover from 0", NULL, 0, NULL);
	}
	else {
		isStartHovering = false;
	}

	//how to button hover
	if (menuPage && (mx >= 152 && mx <= 447) && (my >= 307 && my <= 343)) {
		isHowToPlayHovering = true;
		//mciSendString("play hover from 0", NULL, 0, NULL);
	}
	else {
		isHowToPlayHovering = false;
	}

	//credit button hover
	if (menuPage && (mx >= 152 && mx <= 346) && (my >= 248 && my <= 283)) {
		isCreditsHovering = true;
		//mciSendString("play hover from 0", NULL, 0, NULL);
	}
	else {
		isCreditsHovering = false;
	}

	//exit button hover
	if (menuPage && (mx >= 152 && mx <= 256) && (my >= 188 && my <= 224)) {
		isExitHovering = true;
		//mciSendString("play hover from 0", NULL, 0, NULL);
	}
	else {
		isExitHovering = false;
	}

	//High Score button hover
	if (menuPage && (mx >= 978 && mx <= 1039) && (my >= 493 && my <= 552)) {
		isHighScoreHovering = true;
		//mciSendString("play hover from 0", NULL, 0, NULL);
	}
	else {
		isHighScoreHovering = false;
	}

	//exit yes no hover
	if (exitPage == 1) {
		if ((mx >= 407 && mx <= 463) && (my >= 234 && my <= 259)) {
			isYesHovering = true;
		}
		else {
			isYesHovering = false;
		}
		if ((mx >= 650 && mx <= 686) && (my >= 234 && my <= 259)) {
			isNoHovering = true;
		}
		else {
			isNoHovering = false;
		}
	}
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		printf("x: %d y:%d\n", mx, my);
		mciSendString("play click from 50", NULL, 0, NULL);
	//Home screen continue button check
	if (homePage == 1 && (mx >= 345 && mx <= 753) && (my >= 272 && my <= 297)){
		contButtonClickHandler();
	}

	//Start Page
	if (menuPage == 1 && (mx >= 152 && mx <= 294) && (my >= 364 && my <= 402)) {
		startButtonClickHandler();
	}

	//High Score Page
	if (menuPage == 1 && (mx >= 978 && mx <= 1039) && (my >= 493 && my <= 552)) {
		highScoreButtonClickHandler();
	}

	//Level 1
	if (levelPage == 1 && (mx >= 235 && mx <= 307) && (my >= 258 && my <= 326)) {
		level_1_ClickHandler();
		level_1_start = 0;
	}
	if (level_1_Page == 1 && isLevel1start == 1 && (mx >= 83 && mx <= 136) && (my >= 501 && my <= 556)) {
		pauseButtonClickHandler();
	}

	//Level 2 
	if (levelPage == 1 && (mx >= 406 && mx <= 477) && (my >= 335 && my <= 396)) {
		level_2_ClickHandler();
		level_2_start = 0;
	}
	if (level_2_Page == 1 && isLevel2start == 1 && (mx >= 83 && mx <= 136) && (my >= 501 && my <= 556)) {
		pauseButtonClickHandler();
	}

	//Level 3 
	if (levelPage == 1 && (mx >= 408 && mx <= 469) && (my >= 147 && my <= 199)) {
		level_3_ClickHandler();
		level_3_start = 0;
	}
	if (level_3_Page == 1 && isLevel3start == 1 && (mx >= 83 && mx <= 136) && (my >= 501 && my <= 556)) {
		pauseButtonClickHandler();
	}

	//pause Buttons
	if (pausePage == 1 && (mx >= 412 && mx <= 686) && (my >= 326 && my <= 390)) {
		resumeButtonClickHandler();
	}
	if (pausePage == 1 && (mx >= 412 && mx <= 686) && (my >= 236 && my <= 301)) {
		restartButtonClickHandler();
	}
	if (pausePage == 1 && (mx >= 412 && mx <= 686) && (my >= 155 && my <= 216)) {
		backtomapButtonClickHandler();
		level_1_start = 0;
	}

	//Game Over Buttons
	if (gameOverPage == 1 && (mx >= 412 && mx <= 686) && (my >= 326 && my <= 390)) {
		reviveButtonClickHandler();
	}
	if (revivePage == 1 && (mx >= 759 && mx <= 857) && (my >= 295 && my <= 344)) {
		confirmRevive();
	}
	if (revivePage == 1 && (mx >= 866 && mx <= 966) && (my >= 295 && my <= 344)) {
		revivePage = 0;
	}
	if (gameOverPage == 1 && revivePage == 0 && (mx >= 412 && mx <= 686) && (my >= 236 && my <= 301)) {
		restartButtonClickHandler();
	}
	if (gameOverPage == 1 && revivePage == 0 && (mx >= 412 && mx <= 686) && (my >= 155 && my <= 216)) {
		backtomapButtonClickHandler();
	}

	//Level Completed
	if (levelCompletedPage == 1  && (mx >= 412 && mx <= 686) && (my >= 236 && my <= 301)) {
		restartButtonClickHandler();
	}
	if (levelCompletedPage == 1 && (mx >= 412 && mx <= 686) && (my >= 155 && my <= 216)) {
		backtomapButtonClickHandler();
	}

	//how to page
	if (menuPage == 1 && (mx >= 152 && mx <= 447) && (my >= 307 && my <= 343)){
		howToButtonClickHandler();
	}

	//credits page
	if (menuPage == 1 && (mx >= 152 && mx <= 346) && (my >= 248 && my <= 283)){
		creditsButtonClickHandler();
	}

	//exit page
	if (menuPage == 1 && (mx >= 152 && mx <= 256) && (my >= 188 && my <= 224)){
		exitButtonClickHandler();
	}

	//exit page yes no
	if (exitPage == 1 && (mx >= 407 && mx <= 463) && (my >= 234 && my <= 259)) {
		exit(0);
	}
	if (exitPage == 1 && (mx >= 650 && mx <= 686) && (my >= 234 && my <= 259)) {
		exitPage = 0;
		menuPage = 1;
	}

	//back Buttons
	if (levelPage && (mx >= 83 && mx <= 136) && (my >= 501 && my <= 556)) {
		levelPage = 0;
		menuPage = 1;
		
	}
	if (howToPage && (mx >= 83 && mx <= 136) && (my >= 501 && my <= 556)) {
		howToPage = 0;
		menuPage = 1;
	}
	if (creditsPage && (mx >= 83 && mx <= 136) && (my >= 501 && my <= 556)) {
		creditsPage = 0;
		menuPage = 1;
	}
	if (highScorePage && (mx >= 83 && mx <= 136) && (my >= 501 && my <= 556)) {
		highScorePage = 0;
		menuPage = 1;
	}



}

void fixedUpdate() {
	if (isKeyPressed(' ')) {
		dogJumpHandler();
	}
	if (homePage == 1 && isSpecialKeyPressed(GLUT_KEY_HOME)) {
		contButtonClickHandler();
	}
}

//Level Page
void drawLevelPage() {
	iShowImage(0, 0, 1100, 600, levelPageBg);
}

void updateSniffingDog(){
	if (levelPage) {
		currentSniffingDog = (currentSniffingDog + 1) % 11;
	}

	//UpdateSniffingDog_X
	if (levelPage == 1 && sniffingDog_X <= 779 && !isFlipped) {
		sniffingDog_X += 3;
		if (sniffingDog_X == 779) {
			isFlipped = true;
		}
	}
	else if (levelPage == 1 && sniffingDog_X <= 779 && isFlipped) {
		sniffingDog_X -= 3;
		if (sniffingDog_X == 227) {
			isFlipped = false;
		}
	}
}

void drawBoneCounter() {
	if (level_1_Page == 1 || level_2_Page == 1 || level_3_Page == 1) {
		iShowImage(1005, 25, 30, 30, bone);
		iSetColor(255, 255, 255);
		//iText(1000, 20, "Bones: ", GLUT_BITMAP_TIMES_ROMAN_24);
		char countText[10];
		sprintf_s(countText, "%d", totalBones);
		iText(1040, 30, countText, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void drawStarCounter() {
	if (level_1_Page == 1 || level_2_Page == 1 || level_3_Page == 1) {
		iShowImage(55, 25, 30, 30, star);
		iSetColor(255, 255, 255);
		//iText(1000, 20, "Bones: ", GLUT_BITMAP_TIMES_ROMAN_24);
		char countText[10];
		sprintf_s(countText, "%d", collectedStars);
		iText(90, 30, countText, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void drawSniffingDog() {
	if (!isFlipped) {
		iShowImage(sniffingDog_X, 444, 100, 100, sniffingDog[currentSniffingDog]);
	}
	else {
		iShowImage(sniffingDog_X, 444, 100, 100, sniffingDogFlipped[currentSniffingDog]);
	}

}

void startButtonClickHandler() {
	menuPage = 0;
	levelPage = 1;
}

void drawPausePage(){
	iPauseTimer(level_1_PlatformTimer);
	iPauseTimer(level_2_PlatformTimer);
	iPauseTimer(level_3_PlatformTimer);
	iPauseTimer(dogTimer);
	iShowImage(0, 0, 1100, 600, pauseBg);
}

void gameOverHandler() {
	
	if (isLevel1start && (isOverSpike_lvl1 || spikeCollision_lvl1)) {
		//mciSendString("play gameOver from 0", NULL, 0, NULL);
		updateHighScore();
		gameOverPage = 1;
		isLevel1start = false;
		

	}
	else if (isLevel2start && (isOverSpike_lvl2 || spikeCollision_lvl2)) {
		//mciSendString("play gameOver from 0", NULL, 0, NULL);
		updateHighScore();
		gameOverPage = 1;
		isLevel2start = false;
		
	}
	else if (isLevel3start && (isOverSpike_lvl3 || spikeCollision_lvl3)) {
		//mciSendString("play gameOver from 0", NULL, 0, NULL);
		updateHighScore();
		gameOverPage = 1;
		isLevel3start = false;
	}
	
}

void resetGameOverConditions() {
	isOverGap_lvl1 = false;
	isOverSpike_lvl1 = false;
	spikeCollision_lvl1 = false;

	isOverGap_lvl2 = false;
	isOverSpike_lvl2 = false;
	spikeCollision_lvl2 = false;

	isOverGap_lvl3 = false;
	isOverSpike_lvl3 = false;
	spikeCollision_lvl3 = false;

	gameOverPage = 0;
	isFalling = false;

	int boneCount = sizeof(bonesLevel_1) / sizeof(bones);
	for (int i = 0; i < boneCount; i++) {
		bonesLevel_1[i].isCollected = false;
	}
	collectedBones_lvl1 = 0;

	boneCount = sizeof(bonesLevel_2) / sizeof(bones);
	for (int i = 0; i < boneCount; i++) {
		bonesLevel_2[i].isCollected = false;
	}
	collectedBones_lvl2 = 0;

	boneCount = sizeof(bonesLevel_3) / sizeof(bones);
	for (int i = 0; i < boneCount; i++) {
		bonesLevel_3[i].isCollected = false;
	}
	collectedBones_lvl3 = 0;

	int starCount = sizeof(starsLevel_1) / sizeof(stars);
	for (int i = 0; i < starCount; i++) {
		starsLevel_1[i].isCollected = false;
	}
	collectedStars = 0;

	starCount = sizeof(starsLevel_2) / sizeof(stars);
	for (int i = 0; i < starCount; i++) {
		starsLevel_2[i].isCollected = false;
	}

	starCount = sizeof(starsLevel_3) / sizeof(stars);
	for (int i = 0; i < starCount; i++) {
		starsLevel_3[i].isCollected = false;
	}

}

void drawGameOverPage() {
	iShowImage(0, 0, 1100, 600, gameOverBg);
}

void drawRevivePage() {
	iShowImage(0, 0, 1100, 600, reviveBg);
}

void reviveButtonClickHandler() {
	if (totalBones >= reviveBoneCost) {
		revivePage = 1;  
	}
	else {
		gameOverPage = 1;
		revivePage = 0;
	}
}

void confirmRevive() {
	if (totalBones >= reviveBoneCost) {
		totalBones -= reviveBoneCost;
		isReviving = true;
		if (level_1_Page) {
			level_1_start += reviveBackDistance;
			isOverGap_lvl1 = false;
			isOverSpike_lvl1 = false;
			spikeCollision_lvl1 = false;

			if (level_1_start > 0) {
				level_1_start = 0;
			}
			isLevel1start = true;
		}
		else if (level_2_Page) {
			level_2_start += reviveBackDistance;
			isOverGap_lvl2 = false;
			isOverSpike_lvl2 = false;
			spikeCollision_lvl2 = false;

			if (level_2_start > 0) {
				level_2_start = 0;
			}
			isLevel2start = true;
		}

		else if (level_3_Page) {
			level_3_start += reviveBackDistance;
			isOverGap_lvl3 = false;
			isOverSpike_lvl3 = false;
			spikeCollision_lvl3 = false;

			if (level_3_start > 0) {
				level_3_start = 0;
			}
			isLevel3start = true;
		}

		isFalling = false;
		dog_Y_Axis = PLATFORM_TOP;
		gameOverPage = 0;
		revivePage = 0;

		resumeButtonClickHandler();

		
	}
	else {
		revivePage = 0;
		gameOverPage = 1;
	}
}

void pauseButtonClickHandler() {
	pausePage = 1;
}

void resumeButtonClickHandler() {
	pausePage = 0;
	iResumeTimer(level_1_PlatformTimer);
	iResumeTimer(level_2_PlatformTimer);
	iResumeTimer(level_3_PlatformTimer);
	iResumeTimer(dogTimer);
}

void restartButtonClickHandler() {
	dog_Y_Axis = 170;
	levelCompletedPage = 0;
	levelCompletedSoundPlayed = false;
	resetGameOverConditions();
	isOnSecondaryBar = false;
	currentSecondaryBar = -1; 

	if (level_1_Page) {
		level_1_start = 0;
		isLevel1start = true;
	}
	else if (level_2_Page) {
		level_2_start = 0;
		isLevel2start = true;
	}
	else if (level_3_Page) {
		level_3_start = 0;
		isLevel3start = true;
	}
	resumeButtonClickHandler();
}

void backtomapButtonClickHandler() {
	level_1_Page = 0;
	level_2_Page = 0;
	level_3_Page = 0;

	levelPage = 1;

	level_1_start = 0;
	level_2_start = 0;
	level_3_start = 0;

	levelCompletedSoundPlayed = false;

	resetGameOverConditions();
	resumeButtonClickHandler();

	isLevel1start = false;
	isLevel2start = false;
	isLevel3start = false;

	dog_Y_Axis = 170;
	isFalling = false;
	levelCompletedPage = 0;

	isOnSecondaryBar = false;
	currentSecondaryBar = -1;

	secondaryBarTop = 0;

	isOverGap_lvl1 = false;
	isOverSpike_lvl1 = false;
	spikeCollision_lvl1 = false;

	isOverGap_lvl2 = false;
	isOverSpike_lvl2 = false;
	spikeCollision_lvl2 = false;

	isOverGap_lvl3 = false;
	isOverSpike_lvl3 = false;
	spikeCollision_lvl3 = false;
}

void drawLevelCompletedPage() {
	if (collectedStars == 1) {
		iShowImage(0, 0, 1100, 600, levelCompletedBg1Star);
	}
	else if (collectedStars == 2) {
		iShowImage(0, 0, 1100, 600, levelCompletedBg2Star);
	}
	else if (collectedStars == 3) {
		iShowImage(0, 0, 1100, 600, levelCompletedBg3Star);
	}
	else {
		iShowImage(0, 0, 1100, 600, levelCompletedBg0Star);
	}
}

void levelCompletedHandler() {
	if (level_1_start == -7266 || level_2_start == -9894 || level_3_start == -9894) {
		updateHighScore();
		levelCompletedPage = 1;

		if (!levelCompletedSoundPlayed) {
			mciSendString("play levelCompleted from 0", NULL, 0, NULL);
			levelCompletedSoundPlayed = true;
		}
	}
}

//Dog Properties
void updateRunningDog() {
	if (level_1_Page || level_2_Page || level_3_Page) {
		runningDogCurrentAnimation = (runningDogCurrentAnimation + 1) % 9;
	}
}

void drawRunningDog() {
	if (isLevel1start) {
		if (isJumping) {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[0]);
		}
		else if (level_1_start == -7266) {
			iShowImage(477, dog_Y_Axis, 147, 83, standingDog);
		}
		else if (isOverGap_lvl1 || isOverSpike_lvl1 || spikeCollision_lvl1) {
			iShowImage(477, dog_Y_Axis, 109, 83, runningDog[4]);
		}
		else {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[runningDogCurrentAnimation]);
		}
	}
	
	if (isLevel2start) {
		if (isJumping && !isOnSecondaryBar) {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[0]);
		}
		else if (level_2_start == -9894) {
			iShowImage(477, dog_Y_Axis, 147, 83, standingDog);
		}
		else if (isOverGap_lvl2 || isOverSpike_lvl2 || spikeCollision_lvl2) {
			iShowImage(477, dog_Y_Axis, 109, 83, runningDog[4]);
		}
		else if (isOnSecondaryBar) {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[runningDogCurrentAnimation]);
		}
		else {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[runningDogCurrentAnimation]);
		}
	}

	if (isLevel3start) {
		if (isJumping && !isOnSecondaryBar) {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[0]);
		}
		else if (level_3_start == -9894) {
			iShowImage(477, dog_Y_Axis, 147, 83, standingDog);
		}
		else if (isOverGap_lvl3 || isOverSpike_lvl3 || spikeCollision_lvl3) {
			iShowImage(477, dog_Y_Axis, 109, 83, runningDog[4]);
		}
		else if (isOnSecondaryBar) {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[runningDogCurrentAnimation]);
		}
		else {
			iShowImage(477, dog_Y_Axis, DOG_WIDTH, 83, runningDog[runningDogCurrentAnimation]);
		}
	}
}

void dogJumpHandler() {
	if (!isJumping && (dog_Y_Axis == PLATFORM_TOP || isOnSecondaryBar)) {
		isJumping = true;
		isGoingUp = true;
	}
}

void updateJump() {
	if (isJumping) {
		if (isGoingUp) {
			dog_Y_Axis += jumpSpeed;
			int targetY;
			if (isOnSecondaryBar) {
				targetY = secondaryBarTop + jumpHeight;
			}
			else {
				targetY = PLATFORM_TOP + jumpHeight;
			}
			if (dog_Y_Axis >= targetY) {
				isGoingUp = false;
				isGoingDown = true;
			}
		}
		else if (isGoingDown) {
			dog_Y_Axis -= jumpSpeed;

			// Check if we're landing on a secondary bar
			bool landedOnBar = false;
			if (isLevel2start) {
				int barCount = sizeof(barLevel2) / sizeof(SecondaryBars);
				int dogPosition = -level_2_start + DOG_X_POSITION;
				int dogRight = dogPosition + DOG_WIDTH;

				for (int i = 0; i < barCount; i++) {
					if (dogRight > barLevel2[i].barX &&
						dogPosition < barLevel2[i].barX + barLevel2[i].barWidth &&
						dog_Y_Axis <= barLevel2[i].barY + 5) {
						landedOnBar = true;
						isOnSecondaryBar = true;
						currentSecondaryBar = i;
						secondaryBarTop = barLevel2[i].barY;
						dog_Y_Axis = secondaryBarTop;
						break;
					}
				}
			}

			if (isLevel3start) {
				int barCount = sizeof(barLevel3) / sizeof(SecondaryBars);
				int dogPosition = -level_3_start + DOG_X_POSITION;
				int dogRight = dogPosition + DOG_WIDTH;

				for (int i = 0; i < barCount; i++) {
					if (dogRight > barLevel3[i].barX &&
						dogPosition < barLevel3[i].barX + barLevel3[i].barWidth &&
						dog_Y_Axis <= barLevel3[i].barY + 5) {
						landedOnBar = true;
						isOnSecondaryBar = true;
						currentSecondaryBar = i;
						secondaryBarTop = barLevel3[i].barY;
						dog_Y_Axis = secondaryBarTop;
						break;
					}
				}
			}

			int platformTop;
			if (isOnSecondaryBar) {
				platformTop = secondaryBarTop;
			}
			else {
				platformTop = PLATFORM_TOP;
			}

			if (dog_Y_Axis <= platformTop && !landedOnBar) {
				dog_Y_Axis = platformTop;
				isJumping = false;
				isGoingDown = false;
				isOnSecondaryBar = false;
				currentSecondaryBar = -1;
				checkLevel1Gaps();
				checkLevel2Gaps();
				checkLevel3Gaps();
			}
		}
	}
}

void bgmSound() {
	mciSendString("play bgm repeat from 1000", NULL, 0, NULL);
}


int main()
{

	mciSendString("open \"Audios//background.mp3\" alias bgsong", NULL, 0, NULL);
	mciSendString("open \"Audios//gameover.mp3\" alias ggsong", NULL, 0, NULL);
	mciSendString("open \"Audios//hover.mp3\" alias hover", NULL, 0, NULL);
	mciSendString("open \"Audios//click.mp3\" alias click", NULL, 0, NULL);
	mciSendString("open \"Audios//bgm.mp3\" alias bgm", NULL, 0, NULL);
	mciSendString("open \"Audios//star.mp3\" alias star", NULL, 0, NULL);
	mciSendString("open \"Audios//bone.mp3\" alias bone", NULL, 0, NULL);
	mciSendString("open \"Audios//gameOver.mp3\" alias gameOver", NULL, 0, NULL);
	mciSendString("open \"Audios//levelCompleted.mp3\" alias levelCompleted", NULL, 0, NULL);

	readHighScore();

	iInitialize(1100, 600, "CHASE PUP");
	loadLetterImages();
	loadContinueButton();
	loadPaw();
	loadPawPrint();
	loadMenu();
	loadMenuDog();
	loadLevelPage();
	loadSniffingDog();
	loadSniffingDogFlipped();
	loadSneakingDog();
	loadCollectibles();
	loadRunningDog();
	loadHowTo();
	loadCreditsDog();
	loadExitPage();
	iSetTimer(16, drawLoadingBar);
	iSetTimer(20, updateHomePosition);
	iSetTimer(165, updatePawPrint);
	level_1_PlatformTimer = iSetTimer(1, updatelevel1Position);
	level_2_PlatformTimer = iSetTimer(1, updatelevel2Position);
	level_3_PlatformTimer = iSetTimer(1, updatelevel3Position);
	dogTimer = iSetTimer(30, updateRunningDog);
	iSetTimer(16, updateJump);
	iSetTimer(40, updateSniffingDog);
	iSetTimer(40, updateDogAnimation);
	iSetTimer(40, updateHowToDogAnimation);
	iSetTimer(40, updateCreditsDogAnimation);
	iSetTimer(30, updateSneakingDogAnimation);
	iStart();
	return 0;
}
