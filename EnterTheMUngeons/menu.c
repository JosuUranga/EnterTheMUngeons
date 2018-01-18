#include "Functions.h"

int menua = 0;

int botoiak();
void kreditu();

void menu() {
	if (lifestruct.restartFPS < 60)lifestruct.restartFPS += 1;
	//Enemigo
	mt.y1 += mt.y1_vel / 100;
	mt.y2 += mt.y2_vel / 100;

	if (mt.y1 > (WINDOW_HEIGHT - 80) || mt.y1<(WINDOW_HEIGHT / 2 - mt.dest[0].h - 20) || mt.y2 >(WINDOW_HEIGHT - 80) || mt.y2 < (WINDOW_HEIGHT / 2 - mt.dest[1].h - 20)) {
		mt.y1_vel *= -1;
		mt.y2_vel *= -1;
	}
	hizkuntza();
	// set the positions in the struct
	mt.dest[0].y = (int)mt.y1;
	mt.dest[0].x = (int)mt.x1;
	mt.dest[1].y = (int)mt.y2;
	mt.dest[1].x = (int)mt.x2;

	// clear the window
	SDL_RenderClear(TakeRenderer());

	// draw the image to the window
	switch (menua) {
	case 0:
		switch (levelmanagerstruct.hizkuntza)
		{
		case (1):
			SDL_RenderCopy(TakeRenderer(), mt.texturak[0], NULL, NULL);
			break;
		case(2):
			SDL_RenderCopy(TakeRenderer(), mt.texturak[4], NULL, NULL);
			break;
		case(3):
			SDL_RenderCopy(TakeRenderer(), mt.texturak[5], NULL, NULL);
			break;
		default:
			SDL_RenderCopy(TakeRenderer(), mt.texturak[0], NULL, NULL);
			break;
		}
		
		levelmanagerstruct.close_requested = botoiak();
		break;
	case 1:
		switch (levelmanagerstruct.hizkuntza)
		{
		case (1):
			SDL_RenderCopy(TakeRenderer(), mt.texturak[3], NULL, NULL);
			break;
		case(2):
			SDL_RenderCopy(TakeRenderer(), mt.texturak[6], NULL, NULL);
			break;
		case(3):
			SDL_RenderCopy(TakeRenderer(), mt.texturak[7], NULL, NULL);
			break;
		default:
			SDL_RenderCopy(TakeRenderer(), mt.texturak[3], NULL, NULL);
			break;
		}
		
		kreditu();
		break;
	}

	SDL_RenderCopy(TakeRenderer(), mt.texturak[1], NULL, &mt.dest[0]);
	SDL_RenderCopy(TakeRenderer(), mt.texturak[2], NULL, &mt.dest[1]);
}

int botoiak() {
	int mousex, mousey;
	int buttons = SDL_GetMouseState(&mousex, &mousey);
	if (buttons) {
		if (mousex > 140 && mousex < WINDOW_WIDTH - 140 && mousey>WINDOW_HEIGHT / 2 && mousey<(WINDOW_HEIGHT / 2 + 40) && lifestruct.restartFPS == 60) {
			/*Hasieratu*/printf("Hasiera\n");
			levelmanagerstruct.playing = 1;
			for (int i = 0; i <= MAXENEMY; i++)
			{
				EnemyV[i].FPSCounter = 0;

			}
		}
		if (mousex > 140 && mousex < WINDOW_WIDTH - 140 && mousey>(WINDOW_HEIGHT / 2 + 60) && mousey<(WINDOW_HEIGHT / 2 + 100) && lifestruct.restartFPS == 60) {
			/*Kredituak*/printf("Kredituak\n");
			menua = 1;
		}
		if (mousex > 140 && mousex < WINDOW_WIDTH - 140 && mousey>(WINDOW_HEIGHT / 2 + 120) && mousey<(WINDOW_HEIGHT - 80) && lifestruct.restartFPS == 60) {
			/*Itxi*/printf("Itxi\n");
			return 1;

		}
	}
	return 0;
}
void kreditu() {
	int mousex, mousey;
	int buttons = SDL_GetMouseState(&mousex, &mousey);
	if (buttons) {
		if (mousex > 40 && mousex < 120 && mousey<80 && mousey>40) {
			/*Atzeratu*/printf("Kredituak\n");
			menua = 0;
		}
	}
}
void menuSprites() {
	// get and scale the dimensions of texture (menu enemy)
	SDL_QueryTexture(mt.texturak[1], NULL, NULL, &mt.dest[0].w, &mt.dest[0].h);
	mt.dest[0].w = 20;
	mt.dest[0].h = 20;
	SDL_QueryTexture(mt.texturak[2], NULL, NULL, &mt.dest[1].w, &mt.dest[1].h);
	mt.dest[1].w = 20;
	mt.dest[1].h = 20;

	// start menu in center of screen    
	mt.x1 = (WINDOW_WIDTH - 100);
	mt.y1 = (WINDOW_HEIGHT / 2 - mt.dest[0].h - 20);
	mt.y1_vel = (SPEED);
	mt.x2 = (80);
	mt.y2 = (WINDOW_HEIGHT / 2 - mt.dest[1].h - 20);
	mt.y2_vel = (SPEED);
}

void hizkuntza(void) {
	int mousex, mousey, hizkuntza= levelmanagerstruct.hizkuntza;
	int buttons = SDL_GetMouseState(&mousex, &mousey);
	if (buttons) {
		if (mousex >  WINDOW_WIDTH - 160 && mousex < WINDOW_WIDTH - 120 && mousey<40 && lifestruct.restartFPS == 60) {
			/*Hasieratu*/printf("Euskara\n");
			hizkuntza = 1;
		}
		if (mousex >  WINDOW_WIDTH - 120 && mousex < WINDOW_WIDTH - 80 && mousey<40 && lifestruct.restartFPS == 60) {
			/*Kredituak*/printf("Gaztelania\n");
			hizkuntza = 2;
		}
		if (mousex >  WINDOW_WIDTH - 80 && mousex < WINDOW_WIDTH - 40 && mousey<40 && lifestruct.restartFPS == 60) {
			/*Itxi*/printf("Ingelesa\n");
			hizkuntza = 3;

		}
	}
	levelmanagerstruct.hizkuntza = hizkuntza;
	
}
	