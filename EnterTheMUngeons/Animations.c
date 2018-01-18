#include "Functions.h"

void LevelLavaAnim(void) {
		SDL_RenderCopy(TakeRenderer(), levelAnim.lavaTexture[levelmanagerstruct.level], NULL, NULL);
		SDL_SetTextureAlphaMod(levelAnim.lavaTexture[levelmanagerstruct.level], levelAnim.fade);

		if (levelAnim.fadeCounter == 3)levelAnim.fadeCounter = 1;
		switch (levelAnim.fadeCounter)
		{
		case (int)1:
			levelAnim.fade += 4;
			if (levelAnim.fade == 252) levelAnim.fadeCounter++;
			//printf("+%d\n", levelAnim.fade);
			break;
		case(int)2:
			levelAnim.fade -= 4;
			if (levelAnim.fade == 0)levelAnim.fadeCounter++;
			//printf("-%d\n", levelAnim.fade);
			break;
		default:
			break;
		}
}
void LevelSnowAnim(void) {
	if (levelAnim.snowFPS == 7) {
		levelAnim.snowAnim += 1;
		if (levelAnim.snowAnim > 10)levelAnim.snowAnim = 1;
		levelAnim.snowFPS = 0;
	}
		switch (levelAnim.snowAnim)
		{
		case (int)1:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[0], NULL, NULL);
			//printf("Estoy en 1\n");
			break;
		case (int)2:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[1], NULL, NULL);
			//printf("Estoy en 2\n");
			break;
		case(int)3:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[2], NULL, NULL);
			//printf("Estoy en 3\n");
			break;
		case(int)4:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[3], NULL, NULL);
			//printf("Estoy en 4\n");
			break;
		case(int)5:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[4], NULL, NULL);
			//printf("Estoy en 5\n");
			break;
		case (int)6:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[5], NULL, NULL);
			//printf("Estoy en 6\n");
			break;
		case (int)7:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[6], NULL, NULL);
			//printf("Estoy en 7\n");
			break;
		case(int)8:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[7], NULL, NULL);
			//printf("Estoy en 8\n");
			break;
		case(int)9:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[8], NULL, NULL);
			//printf("Estoy en 9\n");
			break;
		case(int)10:
			SDL_RenderCopy(TakeRenderer(), levelAnim.snowTexture[9], NULL, NULL);
			//printf("Estoy en 10\n");
			break;
		default:
			break;
		}
}

void levelDefaultAnim(void) {
	if (levelAnim.defaultFPS == 10) {
		levelAnim.defaultAnim += 1;
		if (levelAnim.defaultAnim > 3)levelAnim.defaultAnim = 1;
		levelAnim.defaultFPS = 0;
	}
	if (levelmanagerstruct.level == 4 || levelmanagerstruct.level == 2) {
		switch (levelAnim.defaultAnim)
		{
		case (int)1:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[0], NULL, NULL);
			//printf("Estoy en 1\n");
			break;
		case (int)2:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[1], NULL, NULL);
			//printf("Estoy en 2\n");
			break;
		case(int)3:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[2], NULL, NULL);
			//printf("Estoy en 3\n");
			break;
		default:
			break;
		}
	}
	if (levelmanagerstruct.level == 10) {
		switch (levelAnim.defaultAnim)
		{
		case (int)1:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[3], NULL, NULL);
			//printf("Estoy en 1\n");
			break;
		case (int)2:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[4], NULL, NULL);
			//printf("Estoy en 2\n");
			break;
		case(int)3:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[5], NULL, NULL);
			//printf("Estoy en 3\n");
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 7) {
		switch (levelAnim.defaultAnim)
		{
		case (int)1:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[6], NULL, NULL);
			//printf("Estoy en 1\n");
			break;
		case (int)2:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[7], NULL, NULL);
			//printf("Estoy en 2\n");
			break;
		case(int)3:
			SDL_RenderCopy(TakeRenderer(), levelAnim.defaultTexture[8], NULL, NULL);
			//printf("Estoy en 3\n");
			break;
		default:
			break;
		}
	}
}






