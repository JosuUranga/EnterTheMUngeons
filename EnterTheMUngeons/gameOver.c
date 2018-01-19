#include "Functions.h"

void GameOver(void) {
	lifestruct.tempScore = lifestruct.score;
	switch (levelmanagerstruct.hizkuntza)
	{
	case (1):
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[3], NULL, NULL);
		break;
	case(2):
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[4], NULL, NULL);
		break;
	case(3):
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[5], NULL, NULL);
		break;
	default:
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[3], NULL, NULL);
		break;
	}
	if (lifestruct.dieFPS < 120)lifestruct.dieFPS += 1;
	if(winOrDie.goMusic==0){
		loadTheMusic(".\\Sounds\\Music\\Soundtrack1.wav");
		playMusic();
		winOrDie.goMusic = 1;
	}
	switch (WinDieBotoiak())
	{
	case 0:
		return;
		break;
	case 1:
		levelmanagerstruct.close_requested = 1;
		return;
		break;
	case 2:
		Restart();
		return;
		break;
	default:
		break;
	}
	
}

int WinDieBotoiak(void) {
	int mousex, mousey;
	int buttons = SDL_GetMouseState(&mousex, &mousey);

	if (buttons ) {
		if (mousex > 275 && mousex < 388 && mousey<456 && mousey>380 && lifestruct.dieFPS == 120) {
			/*Itxi*/printf("Itxi\n");
			return 1;

		} else if (mousex > 220 && mousex < 440 && mousey<360 && mousey>285 && lifestruct.dieFPS == 120) {
			/*Restart*/printf("Restart\n");
			return 2;

		}
		
	}
	return 0;
}