#ifndef LEVEL_3_HPP
#define LEVEL_3_HPP

#include "Images.h"
#include "variables.h"
#include "highScorePage.h"

PlatformGaps_lvl2 gapsLevel_3[] = {
	{ 1625, 176 },
	{ 2035, 158 },
	{ 2430, 212 },
	//{ 3018, 752 },
	{ 4499, 195 },
	{ 4957, 232 },
	{ 5454, 252 },
	{ 6624, 854 },
	{ 8597, 216 }
};

PlatformSpikes_lvl2 spikesLevel_3[] = {
	{ 1091, 80, 25 },
	{ 2936, 80, 25 },
	{ 4086 - 30, 82, 52 },
	{ 6217, 80, 25 },
	{ 7912, 46, 68 }
};

SecondaryBars barLevel3[] = {
	//{ 3080, 635, 237 },
	{ 6656, 799, 237 }
};

bones bonesLevel_3[] = {
	{ 1265, 180, 0 },
	{ 1315, 180, 0 },
	{ 1365, 180, 0 },
	{ 1857, 180, 0 },
	{ 1887, 180, 0 },
	{ 1917, 180, 0 },
	{ 1947, 180, 0 },
	{ 2267, 180, 0 },
	{ 2450, 230, 0 },
	{ 3165, 180, 0 },
	{ 3215, 180, 0 },
	{ 3515, 247, 0 },
	{ 3565, 180, 0 },
	{ 3350, 180, 0 },
	{ 4515, 180, 0 },
	{ 4550, 180, 0 },
	{ 4060, 230, 0 },
	{ 5440, 180, 0 },
	{ 5700, 180, 0 },
	{ 6472, 247, 0 },
	{ 6836, 247, 0 },
	{ 6886, 247, 0 },
	{ 7665, 180, 0 },
	{ 8336, 180, 0 },
	{ 9041, 180, 0 },
	{ 9091, 180, 0 },
	{ 9141, 180, 0 }
};

stars starsLevel_3[] = {
	{ 2700, 180, 0 },
	{ 6040, 180, 0 },
	{ 7509, 230, 0 }
};

void checkSecondaryBarCollision_lvl3() {
	if (isLevel3start) {
		int barCount = sizeof(barLevel3) / sizeof(SecondaryBars);
		isOnSecondaryBar = false;
		currentSecondaryBar = -1;

		int dogPosition = -level_3_start + DOG_X_POSITION;
		int dogRight = dogPosition + DOG_WIDTH;

		for (int i = 0; i < barCount; i++) {
			if (dogRight > barLevel3[i].barX &&
				dogPosition < barLevel3[i].barX + barLevel3[i].barWidth &&
				dog_Y_Axis <= barLevel3[i].barY + 5 &&
				dog_Y_Axis >= barLevel3[i].barY - 10) {

				isOnSecondaryBar = true;
				currentSecondaryBar = i;
				secondaryBarTop = barLevel3[i].barY;
				break;
			}
		}

		// If on a secondary bar, adjust dog's position
		if (isOnSecondaryBar && !isJumping) {
			dog_Y_Axis = secondaryBarTop;
		}
	}
}


void drawLevel_3_Page() {
	iShowImage(0, 0, 1100, 600, levelBg);
	iShowImage(level_3_start, 0, 10999, 600, level_3_Platform);
}

void level_3_ClickHandler() {
	levelPage = 0;
	level_3_Page = 1;
	resetGameOverConditions();
	isLevel3start = true;
	isLevel1start = false;
	isLevel2start = false;
	level_3_start = 0;
}

void updatelevel3Position() {
	if (isLevel3start && level_3_start != -9894) {
		level_3_start -= 6;
	}
}


void checkLevel3Gaps() {
	if (isLevel3start && !isOnSecondaryBar) {
		int gapCount_lvl3 = sizeof(gapsLevel_3) / sizeof(PlatformGaps_lvl2);
		if (isJumping)
			return;

		// legs position
		int backLegPosition = -level_3_start + DOG_X_POSITION;
		int frontLegPosition = backLegPosition + DOG_WIDTH - 60;

		isOverGap_lvl3 = false;

		for (int i = 0; i < gapCount_lvl3; i++) {
			// check gaps
			bool backLegInGap = (backLegPosition > gapsLevel_3[i].gapX) &&
				(backLegPosition < gapsLevel_3[i].gapX + gapsLevel_3[i].gapWidth);

			bool frontLegInGap = (frontLegPosition > gapsLevel_3[i].gapX) &&
				(frontLegPosition < gapsLevel_3[i].gapX + gapsLevel_3[i].gapWidth);

			if (backLegInGap || frontLegInGap) {
				isOverGap_lvl3 = true;
				break;
			}
		}

		// Start falling if over a gap, but don't show game over immediately
		if (isOverGap_lvl3 && !isFalling) {
			isFalling = true;
			mciSendString("play gameOver from 0", NULL, 0, NULL); // Play sound immediately
		}
	}
}

void updateFall_lvl3() {
	if (isFalling) {
		dog_Y_Axis -= fallSpeed;

		// Only show game over when dog has fallen off screen
		if (dog_Y_Axis < -100) {
			gameOverPage = 1;
			isLevel3start = false;
			isFalling = false;
		}
	}
	else if (dog_Y_Axis < PLATFORM_TOP && !isOnSecondaryBar) {
		dog_Y_Axis = PLATFORM_TOP;
	}
}

void checkLevel3Spikes() {
	if (isLevel3start) {
		int spikeCount_lvl3 = sizeof(spikesLevel_3) / sizeof(PlatformSpikes_lvl2);

		if (isJumping) return;

		int backLegPosition = -level_3_start + DOG_X_POSITION;
		int frontLegPosition = backLegPosition + DOG_WIDTH - 60;

		isOverSpike_lvl3 = false;
		spikeCollision_lvl3 = false;

		for (int i = 0; i < spikeCount_lvl3; i++) {
			if (backLegPosition > spikesLevel_3[i].spikeX &&
				backLegPosition < spikesLevel_3[i].spikeX + spikesLevel_3[i].spikeWidth &&
				dog_Y_Axis < PLATFORM_TOP + spikesLevel_3[i].spikeHeight) {
				isOverSpike_lvl3 = true;
				break;
			}
		}

		for (int j = 0; j < spikeCount_lvl3; j++) {
			if (frontLegPosition >= spikesLevel_3[j].spikeX &&
				frontLegPosition <= spikesLevel_3[j].spikeX + spikesLevel_3[j].spikeWidth) {
				spikeCollision_lvl3 = true;
				break;
			}
		}

		// Start falling if spike collision detected
		if ((isOverSpike_lvl3 || spikeCollision_lvl3) && !isFalling) {
			isFalling = true;
			mciSendString("play gameOver from 0", NULL, 0, NULL); // Play sound immediately
		}
	}
}

void drawCollectibles_lvl3() {
	if (isLevel3start) {
		//bones
		int boneCount = sizeof(bonesLevel_3) / sizeof(bones);
		for (int i = 0; i < boneCount; i++) {
			if (!bonesLevel_3[i].isCollected) {
				int boneScreenX = bonesLevel_3[i].boneX + level_3_start;

				//draw when on scren
				if (boneScreenX >= -50 && boneScreenX <= 1100) {
					iShowImage(boneScreenX, bonesLevel_3[i].boneY, 50, 50, bone);
				}
			}
		}
		//stars
		int starCount = sizeof(starsLevel_2) / sizeof(stars);
		for (int i = 0; i < starCount; i++) {
			if (!starsLevel_3[i].isCollected) {
				int starScreenX = starsLevel_3[i].starX + level_3_start;

				if (starScreenX >= -50 && starScreenX <= 1100) {
					iShowImage(starScreenX, starsLevel_3[i].starY, 40, 40, star);
				}
			}
		}

	}
}

void checkCollectibleCollision_lvl3() {
	if (isLevel3start) {
		//bones
		int boneCount = sizeof(bonesLevel_3) / sizeof(bones);

		for (int i = 0; i < boneCount; i++) {
			if (!bonesLevel_3[i].isCollected) {
				int boneScreenX = bonesLevel_3[i].boneX + level_3_start;

				if (abs(DOG_X_POSITION - boneScreenX) < 70 &&
					abs(dog_Y_Axis - bonesLevel_3[i].boneY) < 20) {
					bonesLevel_3[i].isCollected = true;
					mciSendString("play bone from 0", NULL, 0, NULL);
					collectedBones_lvl3++;
					totalBones++;
					updateHighScore();
				}
			}
		}
		//stars
		int starCount = sizeof(starsLevel_3) / sizeof(stars);

		for (int i = 0; i < starCount; i++) {
			if (!starsLevel_3[i].isCollected) {
				int starScreenX = starsLevel_3[i].starX + level_3_start;

				if (abs(DOG_X_POSITION - starScreenX) < 60 &&
					abs(dog_Y_Axis - starsLevel_3[i].starY) < 40) {
					starsLevel_3[i].isCollected = true;
					mciSendString("play star from 0", NULL, 0, NULL);
					collectedStars++;
				}
			}
		}

	}
}

#endif