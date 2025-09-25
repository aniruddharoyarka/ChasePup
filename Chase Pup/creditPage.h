#ifndef CREDIT_PAGE_HPP
#define CREDIT_PAGE_HPP

int creditsPage = 0;
int creditsCurrentAnimation = 0;

void drawCreditsPage() {
	iShowImage(0, 0, 1100, 600, creditsBg);
}

void creditsButtonClickHandler() {
	menuPage = 0;
	creditsPage = 1;
}

void updateCreditsDogAnimation(){
	if (creditsPage) {
		creditsCurrentAnimation = (creditsCurrentAnimation + 1) % 37;
	}
}

void creditsDogAnimation(){
	iShowImage(305, 0, 490, 330, creditDog[creditsCurrentAnimation]);
}


#endif