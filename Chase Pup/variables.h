#ifndef Variables_HPP
#define Variables_HPP

//Dog Properties 
int runningDogCurrentAnimation = 0;
void loadRunningDog();
void drawRunningDog();
void dogJumpHandler();
void updateJump();

bool isJumping = false;
bool isGoingUp = false;
bool isGoingDown = false;
int jumpHeight = 80;
int jumpSpeed = 4;
int dogTimer;

int dogFeetPosition;
int dog_Y_Axis = 170;
// Add these with level one variables
const int DOG_X_POSITION = 477; // Your fixed dog x position
const int PLATFORM_TOP = 170; // Y position where platform meets dog
const int DOG_WIDTH = 109;

//level 1
int levelPage = 0;
int level_1_start = 0;
int level_1_PlatformTimer;
int level_1_Page = 0;

bool isLevel1start = false;
bool isFalling = false;
bool isOverGap_lvl1 = false;
bool isOverSpike_lvl1 = false;
bool spikeCollision_lvl1 = false;

bool isOverGap_lvl2 = false;
bool isOverSpike_lvl2 = false;
bool spikeCollision_lvl2 = false;

int fallSpeed = 5; 

int totalBones_lvl1 = 0;
int collectedBones_lvl1 = 0;
int collectedBones_lvl2 = 0;
int collectedBones_lvl3 = 0;

int totalStar_lvl1 = 0;
int collectedStars = 0;

int totalBones = 0;

void resetGameOverConditions();

struct PlatformGaps_lvl1
{
	int gapX;
	int gapWidth;
};

struct PlatformSpikes_lvl1
{
	int spikeX;
	int spikeWidth;
	int spikeHeight;
};

struct PlatformGaps_lvl2
{
	int gapX;
	int gapWidth;
};

struct PlatformSpikes_lvl2
{
	int spikeX;
	int spikeWidth;
	int spikeHeight;
};

//struct for bone
struct bones {
	int boneX;
	int boneY;
	bool isCollected;
};


int collectedBones;

struct stars {
	int starX;
	int starY;
	int isCollected;
};

bool isOnSecondaryBar = false;
int currentSecondaryBar = -1;
int secondaryBarTop = 0;

struct SecondaryBars {
	int barX;
	int barWidth;
	int barY;
};

//Level 2
int level_2_start = 0;
int level_2_PlatformTimer;
int level_2_Page = 0;

bool isLevel2start = false;

//Level 3
int level_3_start = 0;
int level_3_PlatformTimer;
int level_3_Page = 0;

bool isLevel3start = false;

bool isOverGap_lvl3 = false;
bool isOverSpike_lvl3 = false;
bool spikeCollision_lvl3 = false;

//GameOverPage
int gameOverPage = 0;
void drawGameOverPage();
void gameOverHandler();

#endif