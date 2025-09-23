#ifndef EXIT_PAGE_HPP
#define EXIT_PAGE_HPP

int exitPage = 0;

bool isYesHovering = false;
bool isNoHovering = false;

//exit button
void drawExitPage() {
	iShowImage(0, 0, 1100, 600, prompt);
}

void exitButtonClickHandler() {
	menuPage = 0;
	exitPage = 1;
}

void hoverExitButton() {
	if (isYesHovering) {
		iShowImage(0, 0, 1100, 600, promptYes);
	}
	if (isNoHovering) {
		iShowImage(0, 0, 1100, 600, promptNo);
	}

}

#endif