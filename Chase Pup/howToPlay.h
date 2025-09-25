#ifndef HOW_TO_PLAY_HPP
#define HOW_TO_PLAY_HPP

//How to Page

int howToPage = 0;
int howToCurrentAnimation;

void drawHowToPage() {
	iShowImage(0, 0, 1100, 600, howToBg);
}

void updateHowToDogAnimation(){
	if (howToPage) {
		howToCurrentAnimation = (howToCurrentAnimation + 1) % 9;
	}
}

void howToDogAnimation(){
	iShowImage(600, 137, 445, 250, howToDog[howToCurrentAnimation]);
}

void howToButtonClickHandler() {
	menuPage = 0;
	howToPage = 1;
}

#endif