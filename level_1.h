#ifndef LEVEL_1_HPP
#define LEVEL_1_HPP

#include "variables.h"
#include "highScorePage.h"


PlatformGaps_lvl1 gapsLevel_1[] = {
	{ 1840, 176 },
	{ 3095, 176 },
	{ 5826, 125 },
	{ 6148, 125 }

};

PlatformSpikes_lvl1 spikesLevel_1[] = {
	{ 1238, 80, 25 },
	{ 2390, 80, 25 },
	{ 3586, 80, 25 },
	{ 4012, 80, 25 },
	{ 6570, 80, 25 }
};

bones bonesLevel_1 [] = {
	{ 1000, 180, 0 },
	{ 1500, 180, 0 },
	{ 1550, 180, 0 },
	{ 2120, 180, 0 },
	{ 2450, 230, 0 },
	{ 3350, 180, 0 },
	{ 4500, 180, 0 },
	{ 4550, 180, 0 },
	{ 4060, 230, 0 },
	{ 5440, 180, 0 },
	{ 5700, 180, 0 },
	{ 6592, 230, 0 },
	{ 6740, 180, 0 },
	{ 7150, 180, 0 }
};

stars starsLevel_1[] = {
	{ 2700, 180, 0 },
	{ 3700, 180, 0 },
	{ 6040, 180, 0 }
};


void drawLevel_1_Page() {
	iShowImage(0, 0, 1100, 600, levelBg);
	iShowImage(level_1_start, 0, 8370, 600, level_1_Platform);
}

void level_1_ClickHandler() {
	levelPage = 0;
	level_1_Page = 1;
	resetGameOverConditions();
	isLevel1start = true;
	isLevel2start = false;
	level_1_start = 0;

	totalBones_lvl1 = sizeof(bonesLevel_1) / sizeof(bones);
}

void updatelevel1Position() {
	if (isLevel1start && level_1_start != -7266) {
		level_1_start -= 6;
	}
}

void checkLevel1Gaps() {
	if (isLevel1start) {
		int gapCount_lvl1 = sizeof(gapsLevel_1) / sizeof(PlatformGaps_lvl1);
		if (isJumping)
			return;

		int backLegPosition = -level_1_start + DOG_X_POSITION;
		int frontLegPosition = backLegPosition + DOG_WIDTH - 60;

		isOverGap_lvl1 = false;

		for (int i = 0; i < gapCount_lvl1; i++) {
			bool backLegInGap = (backLegPosition > gapsLevel_1[i].gapX) &&
				(backLegPosition < gapsLevel_1[i].gapX + gapsLevel_1[i].gapWidth);

			bool frontLegInGap = (frontLegPosition > gapsLevel_1[i].gapX) &&
				(frontLegPosition < gapsLevel_1[i].gapX + gapsLevel_1[i].gapWidth);

			if (backLegInGap || frontLegInGap) {
				isOverGap_lvl1 = true;
				break;
			}
		}

		// Start falling if over a gap, but don't show game over immediately
		if (isOverGap_lvl1 && !isFalling) {
			isFalling = true;
			mciSendString("play gameOver from 0", NULL, 0, NULL); // Play sound immediately
		}
	}
}

void updateFall_lvl1() {
	if (isFalling) {
		dog_Y_Axis -= fallSpeed;

		// Only show game over when dog has fallen off screen
		if (dog_Y_Axis < 0) {
			gameOverPage = 1;
			isLevel1start = false;
			isFalling = false;
		}
	}
	else if (dog_Y_Axis < PLATFORM_TOP) {
		dog_Y_Axis = PLATFORM_TOP;
	}
}


void checkLevel1Spikes() {
	if (isLevel1start) {
		int spikeCount_lvl1 = sizeof(spikesLevel_1) / sizeof(PlatformSpikes_lvl1);

		if (isJumping) return;

		int backLegPosition = -level_1_start + DOG_X_POSITION;
		int frontLegPosition = backLegPosition + DOG_WIDTH - 60;

		isOverSpike_lvl1 = false;
		spikeCollision_lvl1 = false;

		for (int i = 0; i < spikeCount_lvl1; i++) {
			if (backLegPosition > spikesLevel_1[i].spikeX &&
				backLegPosition < spikesLevel_1[i].spikeX + spikesLevel_1[i].spikeWidth &&
				dog_Y_Axis < PLATFORM_TOP + spikesLevel_1[i].spikeHeight) {
				isOverSpike_lvl1 = true;
				break;
			}
		}

		for (int j = 0; j < spikeCount_lvl1; j++) {
			if (frontLegPosition >= spikesLevel_1[j].spikeX &&
				frontLegPosition <= spikesLevel_1[j].spikeX + spikesLevel_1[j].spikeWidth) {
				spikeCollision_lvl1 = true;
				break;
			}
		}

		// Start falling if spike collision detected
		if ((isOverSpike_lvl1 || spikeCollision_lvl1) && !isFalling) {
			//isFalling = true;
			mciSendString("play gameOver from 0", NULL, 0, NULL); // Play sound immediately
		}
	}
}

void drawCollectibles_lvl1() {
	if (isLevel1start) {
		//bones
		int boneCount = sizeof(bonesLevel_1) / sizeof(bones);
		for (int i = 0; i < boneCount; i++) {
			if (!bonesLevel_1[i].isCollected) {
				int boneScreenX = bonesLevel_1[i].boneX + level_1_start;

				//draw when on scren
				if (boneScreenX >= -50 && boneScreenX <= 1100) {
					iShowImage(boneScreenX, bonesLevel_1[i].boneY, 50, 50, bone);
				}
			}
		}
		//stars
		int starCount = sizeof(starsLevel_1) / sizeof(stars);
		for (int i = 0; i < starCount; i++) {
			if (!starsLevel_1[i].isCollected) {
				int starScreenX = starsLevel_1[i].starX + level_1_start;

				//draw when on scren
				if (starScreenX >= -50 && starScreenX <= 1100) {
					iShowImage(starScreenX, starsLevel_1[i].starY, 40, 40, star);
				}
			}
		}

	}
}

void checkCollectibleCollision_lvl1() {
	if (isLevel1start) {
		//bones
		int boneCount = sizeof(bonesLevel_1) / sizeof(bones);

		for (int i = 0; i < boneCount; i++) {
			if (!bonesLevel_1[i].isCollected) {
				int boneScreenX = bonesLevel_1[i].boneX + level_1_start;

				if (abs(DOG_X_POSITION - boneScreenX) < 70 &&
					abs(dog_Y_Axis - bonesLevel_1[i].boneY) < 20) {
					bonesLevel_1[i].isCollected = true;
					mciSendString("play bone from 0", NULL, 0, NULL);
					collectedBones_lvl1++;
					totalBones++;
					updateHighScore();
					// sound
				}
			}
		}
		//stars
		int starCount = sizeof(starsLevel_1) / sizeof(stars);

		for (int i = 0; i < starCount; i++) {
			if (!starsLevel_1[i].isCollected) {
				
				int starScreenX = starsLevel_1[i].starX + level_1_start;

				
				if (abs(DOG_X_POSITION - starScreenX) < 60 &&
					abs(dog_Y_Axis - starsLevel_1[i].starY) < 40) {
					
					starsLevel_1[i].isCollected = true;
					mciSendString("play star from 0", NULL, 0, NULL);
					collectedStars++;
				}
			}
		}

	}
}


#endif