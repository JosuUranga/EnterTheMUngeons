#include "Functions.h"

void movement(void) {
	// process events
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			levelmanagerstruct.close_requested = 1;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_1:
				weaponStruct.shotgun = 1;
				break;
			case SDL_SCANCODE_2:
				weaponStruct.sniper = 1;
				break;
			case SDL_SCANCODE_W:
			case SDL_SCANCODE_UP:
				if (levelmanagerstruct.playing)posstruct.up = 1;
				break;
			case SDL_SCANCODE_A:
			case SDL_SCANCODE_LEFT:
				if (levelmanagerstruct.playing)posstruct.left = 1;
				break;
			case SDL_SCANCODE_S:
			case SDL_SCANCODE_DOWN:
				if (levelmanagerstruct.playing)posstruct.down = 1;
				break;
			case SDL_SCANCODE_D:
			case SDL_SCANCODE_RIGHT:
				if (levelmanagerstruct.playing)posstruct.right = 1;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_1:
				weaponStruct.shotgun = 0;
				break;
			case SDL_SCANCODE_2:
				weaponStruct.sniper = 0;
				break;
			case SDL_SCANCODE_W:
			case SDL_SCANCODE_UP:
				if (levelmanagerstruct.playing)posstruct.up = 0;
				break;
			case SDL_SCANCODE_A:
			case SDL_SCANCODE_LEFT:
				if (levelmanagerstruct.playing)posstruct.left = 0;
				break;
			case SDL_SCANCODE_S:
			case SDL_SCANCODE_DOWN:
				if (levelmanagerstruct.playing)posstruct.down = 0;
				break;
			case SDL_SCANCODE_D:
			case SDL_SCANCODE_RIGHT:
				if (levelmanagerstruct.playing)posstruct.right = 0;
				break;
			}
			break;
		}
	}
	if (levelmanagerstruct.playing) {
		// determine velocity
		posstruct.x_vel = posstruct.y_vel = 0;
		if (posstruct.up && !posstruct.down) posstruct.y_vel = -SPEED;
		if (posstruct.down && !posstruct.up) posstruct.y_vel = SPEED;
		if (posstruct.left && !posstruct.right) posstruct.x_vel = -SPEED;
		if (posstruct.right && !posstruct.left) posstruct.x_vel = SPEED;
		posstruct.x += posstruct.x_vel / 60;
		posstruct.y += posstruct.y_vel / 60;
	}
	for (int i = 0; i < MAXENEMY + 1; i++)
	{
		if (!lifestruct.invencivilty) {
			if (checkCollision(playerRect.player, enemySpawn.Enemy[i]) && EnemyV[i].HP != 0) {
				lifestruct.lifes--;
				EnemyV[i].HP = 0;
				lifestruct.invencivilty = 1;
			}
		}
	}

}