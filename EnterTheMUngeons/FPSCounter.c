#include "Functions.h"

void FPSCounter(void) {
	ProtaB[0].aFPSCounter += 1;
	if (lifestruct.invencivilty) {
		lifestruct.invencivilityFPS += 1;
		playerRect.playerFPS += 1;
	}
	if (lifestruct.invencivilityFPS == 120) {
		lifestruct.invencivilty = 0;
		lifestruct.invencivilityFPS = 0;
	}
	if (playerRect.playerFPS = 60) playerRect.playerFPS = 0;
	for (int i = 0; i <= MAXENEMY; i++)
	{
		EnemyV[i].FPSCounter += 1;

	}

	if (levelAnim.snowFPS < 7) {
		levelAnim.snowFPS += 1;
	}
	if (levelmanagerstruct.playing == 1) lifestruct.constantFPScounter += 1;
	if (levelAnim.defaultFPS < 10) {
		levelAnim.defaultFPS += 1;
	}
}
	
		