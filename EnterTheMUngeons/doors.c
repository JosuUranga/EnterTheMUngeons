#include "Functions.h"

int doors(void) {
	if (levelmanagerstruct.door1ON) {
		SDL_Rect door1;
		ValorRects(&door1, 40, 20, 300, 40);
		if (!enemySpawn.enemykilled[levelmanagerstruct.level])	return 0;
		if (checkCollision(door1, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[1])) {
			playSound(9);
			return 1;
		}
	}

	if (levelmanagerstruct.door2ON) {
		SDL_Rect door2;
		ValorRects(&door2, 20,40,580,220);
		if (!enemySpawn.enemykilled[levelmanagerstruct.level]) return 0;
		if (checkCollision(door2, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[2])) {
			playSound(9);
			return 2;
		}
	}
	if (levelmanagerstruct.door3ON) {
		SDL_Rect door3;
		ValorRects(&door3, 40,20,300,420);
		if (!enemySpawn.enemykilled[levelmanagerstruct.level]) return 0;
		if (checkCollision(door3, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[3])) {
			playSound(9);
			return 3;
		}
	}
	if (levelmanagerstruct.door4ON) {
		SDL_Rect door4;
		ValorRects(&door4, 20,40, 40,220);
		if (!enemySpawn.enemykilled[levelmanagerstruct.level]) return 0;
		if (checkCollision(door4, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[0])) {
			playSound(9);
			return 4;
		}
	}
	
	return 0;
}