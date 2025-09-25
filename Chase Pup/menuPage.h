#ifndef MENUPAGE_HPP
#define MENUPAGE_HPP

//Menu Starts
void drawMenuPage() {
	iShowImage(0, 0, 1100, 600, menuBg);
}

int currentAnimation = 0;

void menuDogAnimation(){
	iShowImage(640, 95, 350, 396, menuDog[currentAnimation]);
}

void updateDogAnimation(){
	if (menuPage) {
		currentAnimation = (currentAnimation + 1) % 69;
	}
}


//MENU HOVER
bool isStartHovering = false;
bool isHowToPlayHovering = false;
bool isCreditsHovering = false;
bool isExitHovering = false;
bool isHighScoreHovering = false;

void hoverMenuButtons() {
	if (isStartHovering == true) {
		iShowImage(0, 0, 1100, 600, menuStart);
	}
	else if (isHowToPlayHovering == true) {
		iShowImage(0, 0, 1100, 600, menuHowTo);
	}
	else if (isCreditsHovering == true) {
		iShowImage(0, 0, 1100, 600, menuCredits);
	}
	else if (isExitHovering == true) {
		iShowImage(0, 0, 1100, 600, menuExit);
	}
	else if (isHighScoreHovering == true) {
		iShowImage(0, 0, 1100, 600, highScoreButton);
	}
}

#endif