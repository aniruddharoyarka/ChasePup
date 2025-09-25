#ifndef LEVEL_2_HPP
#define LEVEL_2_HPP

#include "Images.h"
#include "variables.h"
#include "highScorePage.h"

PlatformGaps_lvl2 gapsLevel_2[] = {
	{ 1625, 176 },
	{ 2035, 158 },
	{ 2430, 212 },
	{ 3018, 752 },
	{ 4499, 195 },
	{ 4957, 232 },
	{ 5454, 252 },
	{ 6624, 854 },
	{ 8597, 216}
};

PlatformSpikes_lvl2 spikesLevel_2[] = {
	{ 1091, 80, 25 },
	{ 2936, 80, 25 },
	{ 4086-30, 82, 52},
	{ 6217, 80, 25 },
	{7912, 46, 68}
};

SecondaryBars barLevel2[] = {
	{ 3080, 635, 237 },
	{6656, 799, 237}
};

bones bonesLevel_2[] = {
	{ 1265, 180, 0 },
	{ 1315, 180, 0 },
	{ 1365, 180, 0 },
	{ 1857, 180, 0 },
	{ 2267, 180, 0 },
	{ 2450, 230, 0 },
	{ 3165, 247, 0 },
	{ 3215, 247, 0 },
	{ 3515, 247, 0 },
	{ 3565, 247, 0 },
	{ 3350, 247, 0 },
	{ 4500, 180, 0 },
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

stars starsLevel_2[] = {
	{ 2700, 180, 0 },
	{ 6040, 180, 0 },
	{ 7509, 230, 0 }
};

void checkSecondaryBarCollision_lvl2() {
	if (isLevel2start) {
		int barCount = sizeof(barLevel2) / sizeof(SecondaryBars);
		isOnSecondaryBar = false;
		currentSecondaryBar = -1;

		int dogPosition = -level_2_start + DOG_X_POSITION;
		int dogRight = dogPosition + DOG_WIDTH;

		for (int i = 0; i < barCount; i++) {
			if (dogRight > barLevel2[i].barX &&
				dogPosition < barLevel2[i].barX + barLevel2[i].barWidth &&
				dog_Y_Axis <= barLevel2[i].barY + 5 &&  
				dog_Y_Axis >= barLevel2[i].barY - 10) { 

				isOnSecondaryBar = true;
				currentSecondaryBar = i;
				secondaryBarTop = barLevel2[i].barY;
				break;
			}
		}

		// If on a secondary bar, adjust dog's position
		if (isOnSecondaryBar && !isJumping) {
			dog_Y_Axis = secondaryBarTop;
		}
	}
}


void drawLevel_2_Page() {
	iShowImage(0, 0, 1100, 600, levelBg);
	iShowImage(level_2_start, 0, 10999, 600, level_2_Platform);
}

void level_2_ClickHandler() {
	levelPage = 0;
	level_2_Page = 1;
	resetGameOverConditions();
	isLevel2start = true;
	isLevel1start = false;
	level_2_start = 0;
}

void updatelevel2Position() {
	if (isLevel2start && level_2_start != -9894) {
		level_2_start -= 6;
	}
}


void checkLevel2Gaps() {
	if (isLevel2start && !isOnSecondaryBar) {
		int gapCount_lvl2 = sizeof(gapsLevel_2) / sizeof(PlatformGaps_lvl2);
		if (isJumping)
			return;

		// legs position
		int backLegPosition = -level_2_start + DOG_X_POSITION;
		int frontLegPosition = backLegPosition + DOG_WIDTH - 60;

		isOverGap_lvl2 = false;

		for (int i = 0; i < gapCount_lvl2; i++) {
			// check gaps
			bool backLegInGap = (backLegPosition > gapsLevel_2[i].gapX) &&
				(backLegPosition < gapsLevel_2[i].gapX + gapsLevel_2[i].gapWidth);

			bool frontLegInGap = (frontLegPosition > gapsLevel_2[i].gapX) &&
				(frontLegPosition < gapsLevel_2[i].gapX + gapsLevel_2[i].gapWidth);

			if (backLegInGap || frontLegInGap) {
				isOverGap_lvl2 = true;
				break;
			}
		}

		// Start falling if over a gap, but don't show game over immediately
		if (isOverGap_lvl2 && !isFalling) {
			isFalling = true;
			mciSendString("play gameOver from 0", NULL, 0, NULL); // Play sound immediately
		}
	}
}


void updateFall_lvl2() {
	if (isFalling) {
		dog_Y_Axis -= fallSpeed;

		// Only show game over when dog has fallen off screen
		if (dog_Y_Axis < -100) {
			gameOverPage = 1;
			isLevel2start = false;
			isFalling = false;
		}
	}
	else if (dog_Y_Axis < PLATFORM_TOP && !isOnSecondaryBar) {
		dog_Y_Axis = PLATFORM_TOP;
	}
}

void checkLevel2Spikes() {
	if (isLevel2start) {
		int spikeCount_lvl2 = sizeof(spikesLevel_2) / sizeof(PlatformSpikes_lvl2);

		if (isJumping) return;

		int backLegPosition = -level_2_start + DOG_X_POSITION;
		int frontLegPosition = backLegPosition + DOG_WIDTH - 60;

		isOverSpike_lvl2 = false;
		spikeCollision_lvl2 = false;

		for (int i = 0; i < spikeCount_lvl2; i++) {
			if (backLegPosition > spikesLevel_2[i].spikeX &&
				backLegPosition < spikesLevel_2[i].spikeX + spikesLevel_2[i].spikeWidth &&
				dog_Y_Axis < PLATFORM_TOP + spikesLevel_2[i].spikeHeight) {
				isOverSpike_lvl2 = true;
				break;
			}
		}

		for (int j = 0; j < spikeCount_lvl2; j++) {
			if (frontLegPosition >= spikesLevel_2[j].spikeX &&
				frontLegPosition <= spikesLevel_2[j].spikeX + spikesLevel_2[j].spikeWidth) {
				spikeCollision_lvl2 = true;
				break;
			}
		}

		// Start falling if spike collision detected
		if ((isOverSpike_lvl2 || spikeCollision_lvl2) && !isFalling) {
			isFalling = true;
			mciSendString("play gameOver from 0", NULL, 0, NULL); // Play sound immediately
		}
	}
}
void drawCollectibles_lvl2() {
	if (isLevel2start) {
		//bones
		int boneCount = sizeof(bonesLevel_2) / sizeof(bones);
		for (int i = 0; i < boneCount; i++) {
			if (!bonesLevel_2[i].isCollected) {
				int boneScreenX = bonesLevel_2[i].boneX + level_2_start;

				//draw when on scren
				if (boneScreenX >= -50 && boneScreenX <= 1100) {
					iShowImage(boneScreenX, bonesLevel_2[i].boneY, 50, 50, bone);
				}
			}
		}
		//stars
		int starCount = sizeof(starsLevel_2) / sizeof(stars);
		for (int i = 0; i < starCount; i++) {
			if (!starsLevel_2[i].isCollected) {
				int starScreenX = starsLevel_2[i].starX + level_2_start;

				if (starScreenX >= -50 && starScreenX <= 1100) {
					iShowImage(starScreenX, starsLevel_2[i].starY, 40, 40, star);
				}
			}
		}

	}
}

void checkCollectibleCollision_lvl2() {
	if (isLevel2start) {
		//bones
		int boneCount = sizeof(bonesLevel_2) / sizeof(bones);

		for (int i = 0; i < boneCount; i++) {
			if (!bonesLevel_2[i].isCollected) {
				int boneScreenX = bonesLevel_2[i].boneX + level_2_start;

				if (abs(DOG_X_POSITION - boneScreenX) < 70 &&
					abs(dog_Y_Axis - bonesLevel_2[i].boneY) < 20) {
					bonesLevel_2[i].isCollected = true;
					mciSendString("play bone from 0", NULL, 0, NULL);
					collectedBones_lvl2++;
					totalBones++;
					updateHighScore();
				}
			}
		}
		//stars
		int starCount = sizeof(starsLevel_2) / sizeof(stars);

		for (int i = 0; i < starCount; i++) {
			if (!starsLevel_2[i].isCollected) {
				int starScreenX = starsLevel_2[i].starX + level_2_start;

				if (abs(DOG_X_POSITION - starScreenX) < 60 &&
					abs(dog_Y_Axis - starsLevel_2[i].starY) < 40) {
					starsLevel_2[i].isCollected = true;
					mciSendString("play star from 0", NULL, 0, NULL);
					collectedStars++;
					// sound
				}
			}
		}

	}
}

#endif