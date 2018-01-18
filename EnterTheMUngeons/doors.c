#include "Functions.h"

int doors(void) {
	if (levelmanagerstruct.door1ON) {
		SDL_Rect door1;
		door1.h = 20;
		door1.w = 40;
		door1.x = 300;
		door1.y = 40;
		if (!enemySpawn.enemykilled[levelmanagerstruct.level])	return 0;
		if (checkCollision(door1, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[1])) {
			playSound(9);
			return 1;
		}
	}

	if (levelmanagerstruct.door2ON) {
		SDL_Rect door2;
		door2.h = 40;
		door2.w = 20;
		door2.x = 580;
		door2.y = 220;
		if (!enemySpawn.enemykilled[levelmanagerstruct.level]) return 0;
		if (checkCollision(door2, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[2])) {
			playSound(9);
			return 2;
		}
	}
	if (levelmanagerstruct.door3ON) {
		SDL_Rect door3;
		door3.h = 20;
		door3.w = 40;
		door3.x = 300;
		door3.y = 420;
		if (!enemySpawn.enemykilled[levelmanagerstruct.level]) return 0;
		if (checkCollision(door3, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[3])) {
			playSound(9);
			return 3;
		}
	}
	if (levelmanagerstruct.door4ON) {
		SDL_Rect door4;
		door4.h = 40;
		door4.w = 20;
		door4.x = 40;
		door4.y = 220;
		if (!enemySpawn.enemykilled[levelmanagerstruct.level]) return 0;
		if (checkCollision(door4, playerRect.player) && !checkCollision(playerRect.player, levelmanagerstruct.borde[0])) {
			playSound(9);
			return 4;
		}
	}
	
	return 0;
}