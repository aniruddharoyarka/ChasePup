#ifndef HOME_SCREEN_HPP
#define HOME_SCREEN_HPP

#include "Images.h"

int homePage = 1;
int menuPage = 0;

void bgmSound();

//Home Game Name
void loadHomeC();
void loadHomeH();
void loadHomeA();
void loadHomeS();
void loadHomeE();
void loadHomeP();
void loadHomeU();
void loadHomeP2();
void updateHomePosition();

int titleHomeX = 0;
int titleHomeY_C = 350;
int titleHomeY_H = 350;
int titleHomeY_A = 350;
int titleHomeY_S = 350;
int titleHomeY_E = 350;
int titleHomeY_P = 350;
int titleHomeY_U = 350;
int titleHomeY_P2 = 350;

bool cDone = false;
bool hDone = false;
bool aDone = false;
bool sDone = false;
bool eDone = false;
bool pDone = false;
bool uDone = false;
bool pDone2 = false;


void loadHomeC() {
	iShowImage(titleHomeX, titleHomeY_C, 1100, 600, imgC);
}

void loadHomeH() {
	iShowImage(titleHomeX, titleHomeY_H, 1100, 600, imgH);
}

void loadHomeA() {
	iShowImage(titleHomeX, titleHomeY_A, 1100, 600, imgA);
}

void loadHomeS() {
	iShowImage(titleHomeX, titleHomeY_S, 1100, 600, imgS);
}

void loadHomeE() {
	iShowImage(titleHomeX, titleHomeY_E, 1100, 600, imgE);
}

void loadHomeP() {
	iShowImage(titleHomeX, titleHomeY_P, 1100, 600, imgP);
}

void loadHomeU() {
	iShowImage(titleHomeX, titleHomeY_U, 1100, 600, imgU);
}

void loadHomeP2() {
	iShowImage(titleHomeX, titleHomeY_P2, 1100, 600, imgP2);
}

void updateHomePosition() {
	if (titleHomeY_C > 0) {
		titleHomeY_C -= 25;
	}
	else if (!cDone) {
		cDone = true;
	}

	if (cDone && titleHomeY_H > 0) {
		titleHomeY_H -= 25;
	}
	else if (cDone && !hDone && titleHomeY_H <= 0) {
		hDone = true;
	}

	if (hDone && titleHomeY_A > 0) {
		titleHomeY_A -= 25;
	}
	else if (hDone && !aDone && titleHomeY_A <= 0) {
		aDone = true;
	}

	if (aDone && titleHomeY_S > 0) {
		titleHomeY_S -= 25;
	}
	else if (aDone && !sDone && titleHomeY_S <= 0) {
		sDone = true;
	}

	if (sDone && titleHomeY_E > 0) {
		titleHomeY_E -= 25;
	}
	else if (sDone && !eDone && titleHomeY_E <= 0) {
		eDone = true;
	}

	if (eDone && titleHomeY_P > 0) {
		titleHomeY_P -= 25;
	}
	else if (eDone && !pDone && titleHomeY_P <= 0) {
		pDone = true;
	}

	if (pDone && titleHomeY_U > 0) {
		titleHomeY_U -= 25;
	}
	else if (pDone && !uDone && titleHomeY_U <= 0) {
		uDone = true;
	}

	if (uDone && titleHomeY_P2 > 0) {
		titleHomeY_P2 -= 25;
	}
	else if (uDone && !pDone2 && titleHomeY_P2 <= 0) {
		pDone2 = true;
	}
}

//Home Continue Button
bool isHovering = false;

void hoverContinueButton() {
	if (isHovering != true) {
		iShowImage(0, 0, 1100, 600, continueButton[0]);
		if (homePage) {
			mciSendString("play hover from 0", NULL, 0, NULL);
		}
		
	}
	else {
		iShowImage(0, 0, 1100, 600, continueButton[1]);
		
	}
}

//Home Loading bar & paw under bar
int startX = 200, startY = 184;
int endX = 200, endY = 184;
int maxLength = 700;

//Home Paw Print
int currentPaw = 0;
bool showPaw[21] = { false };
void loadPawPrint();
void updatePawPrint();
void drawPawPrint();

//Home Paw Under Bar
void drawLoadingBar() {
	if (endX < startX + maxLength) {
		endX += 5;
	}
}

//Home Paw Print
void updatePawPrint() {
	if (currentPaw < 21) {
		showPaw[currentPaw] = true;
		currentPaw++;
	}
}

void drawPawPrint() {
	for (int i = 0; i < 21; i++){
		if (showPaw[i] && pawPrint[i] != 0){
			iShowImage(0, 0, 1100, 600, pawPrint[i]);
			
		}
	}
}



//cont button click handler
void contButtonClickHandler() {
	menuPage = 1;
	homePage = 0;
	bgmSound();
}


#endif