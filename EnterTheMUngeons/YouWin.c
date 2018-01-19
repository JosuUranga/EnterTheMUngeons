#include "Functions.h"

void YouWin(void) {
	switch (levelmanagerstruct.hizkuntza)
	{
	case (1):
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[0], NULL, NULL);
		break;
	case(2):
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[1], NULL, NULL);
		break;
	case(3):
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[2], NULL, NULL);
		break;
	default:
		SDL_RenderCopy(levelmanagerstruct.rend, winOrDie.texture[0], NULL, NULL);
		break;
	}
	
	if (lifestruct.dieFPS < 120)lifestruct.dieFPS += 1;
	if (winOrDie.goMusic == 0) {
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
