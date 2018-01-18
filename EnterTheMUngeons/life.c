#include "Functions.h"

void life(SDL_Rect player, SDL_Rect* bullet) {

	SDL_Rect lifeRect;
	lifeRect.h = 40;
	lifeRect.w = 146;
	lifeRect.x = 0;
	lifeRect.y = 0;
	if (enemySpawn.enemyController[levelmanagerstruct.level]) {
		for (int i = 0; i <= MAXENEMY; i++)
		{
			if (!lifestruct.invencivilty) {
				if (collisioncheck(player, bullet[i])) {
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
		SDL_RenderCopy(TakeRenderer(),lifestruct.life_texture[0], NULL, &lifeRect);
		break;
	case (int)1:
		SDL_RenderCopy(TakeRenderer(), lifestruct.life_texture[1], NULL, &lifeRect);
		break;
	case (int)2:
		 SDL_RenderCopy(TakeRenderer(), lifestruct.life_texture[2], NULL, &lifeRect);
		break;
	case (int)3:
		SDL_RenderCopy(TakeRenderer(), lifestruct.life_texture[3], NULL, &lifeRect);
		break;
	case (int)4:
		SDL_RenderCopy(TakeRenderer(), lifestruct.life_texture[4], NULL, &lifeRect);
		break;
	case (int)5:
		SDL_RenderCopy(TakeRenderer(), lifestruct.life_texture[5], NULL, &lifeRect);
		break;
	default:
		break;
	}

}


