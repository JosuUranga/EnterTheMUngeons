#include "Functions.h"

void life(void) {

	
	lifestruct.lifeRect.h = 40;
	lifestruct.lifeRect.w = 146;
	lifestruct.lifeRect.x = 0;
	lifestruct.lifeRect.y = 0;
	if (enemySpawn.enemyController[levelmanagerstruct.level]) {
		for (int i = 0; i <= MAXENEMY; i++)
		{
			if (!lifestruct.invencivilty) {
				if (collisioncheck(playerRect.player, enemySpawn.Bullet[i])) {
					if (lifestruct.lifes > 0)lifestruct.lifes--;
					lifestruct.invencivilty = 1;
					printf("%d\n", lifestruct.invencivilty);

				}
			}
		}
	}
	if (lifestruct.lifes == 0) {
		levelmanagerstruct.playing = 2;
	}

	lifestruct.tmpLifes = lifestruct.lifes;
	switch (lifestruct.lifes)
	{
	case (int)0:
		SDL_RenderCopy(levelmanagerstruct.rend,lifestruct.life_texture[0], NULL, &lifestruct.lifeRect);
		break;
	case (int)1:
		SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.life_texture[1], NULL, &lifestruct.lifeRect);
		break;
	case (int)2:
		 SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.life_texture[2], NULL, &lifestruct.lifeRect);
		break;
	case (int)3:
		SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.life_texture[3], NULL, &lifestruct.lifeRect);
		break;
	case (int)4:
		SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.life_texture[4], NULL, &lifestruct.lifeRect);
		break;
	case (int)5:
		SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.life_texture[5], NULL, &lifestruct.lifeRect);
		break;
	default:
		break;
	}

}


