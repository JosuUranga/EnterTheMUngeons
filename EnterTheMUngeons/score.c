#include "Functions.h"



void InitScore(void) {
	lifestruct.Font = TTF_OpenFont("terminal.ttf", 20);
}

void ScoreRefresh(void) {

	char str[30];
	char str2[30];
	char str3[30];
	SDL_Color Color= { 255, 255, 255 };
	if (levelmanagerstruct.playing == 1) {
		switch (levelmanagerstruct.hizkuntza)
		{
		case (1):
			sprintf(str, "Puntuazioa: %d", lifestruct.score);
			break;
		case(2):
			sprintf(str, "Puntuación: %d", lifestruct.score);
			break;
		case(3):
			sprintf(str, "Score: %d", lifestruct.score);
			break;
		default:
			sprintf(str, "Puntuazioa: %d", lifestruct.score);
			break;
		}
		lifestruct.surfaceMessage[0] = TTF_RenderText_Solid(lifestruct.Font, str, Color);
		lifestruct.Message[0] = SDL_CreateTextureFromSurface(TakeRenderer(), lifestruct.surfaceMessage[0]);
		SDL_FreeSurface(lifestruct.surfaceMessage[0]);

	}
	else if (levelmanagerstruct.playing == 2 || levelmanagerstruct.playing == 3) {
		int penalty;
		int finalscore;
		if (lifestruct.GameOver == 0) {
			penalty = lifestruct.constantFPScounter / 60;
			finalscore = lifestruct.score - penalty;

			switch(levelmanagerstruct.hizkuntza) 
			{
			case (1):
				sprintf(str, "Puntuazioa: %d", lifestruct.score);
				sprintf(str2, "Denbora Penalizazioa: %d", penalty);
				sprintf(str3, "Puntuazio finala: %d", finalscore);
				break;
			case(2):
				sprintf(str, "Puntuación: %d", lifestruct.score);
				sprintf(str2, "Penalización por tiempo: %d", penalty);
				sprintf(str3, "Puntuación total: %d", finalscore);
				break;
			case(3):
				sprintf(str, "Score: %d", lifestruct.score);
				sprintf(str2, "Time penalty: %d", penalty);
				sprintf(str3, "Total Score: %d", finalscore);
				break;
				default:
					sprintf(str, "Puntuazioa: %d", lifestruct.score);
					sprintf(str2, "Denbora Penalizazioa: %d", penalty);
					sprintf(str3, "Puntuazio finala: %d", finalscore);
					break;
				}
			//printf("Score: %d\nPenalty: %d\nTotal Score: %d\n", lifestruct.score, penalty, finalscore);
			lifestruct.Message_rect[0].x = 275;
			lifestruct.Message_rect[0].y = 150;
			lifestruct.Message_rect[0].w = 120;
			lifestruct.Message_rect[0].h = 40;
			lifestruct.Message_rect[1].x = 250;
			lifestruct.Message_rect[1].y = 190;
			lifestruct.Message_rect[1].w = 175;
			lifestruct.Message_rect[1].h = 40;
			lifestruct.Message_rect[2].x = 240;
			lifestruct.Message_rect[2].y = 235;
			lifestruct.Message_rect[2].w = 200;
			lifestruct.Message_rect[2].h = 40;
			lifestruct.surfaceMessage[0] = TTF_RenderText_Solid(lifestruct.Font, str, Color);
			lifestruct.Message[0] = SDL_CreateTextureFromSurface(TakeRenderer(), lifestruct.surfaceMessage[0]);
			lifestruct.surfaceMessage[1] = TTF_RenderText_Solid(lifestruct.Font, str2, Color);
			lifestruct.Message[1] = SDL_CreateTextureFromSurface(TakeRenderer(), lifestruct.surfaceMessage[1]);
			lifestruct.surfaceMessage[2] = TTF_RenderText_Solid(lifestruct.Font, str3, Color);
			lifestruct.Message[2] = SDL_CreateTextureFromSurface(TakeRenderer(), lifestruct.surfaceMessage[2]);
			SDL_FreeSurface(lifestruct.surfaceMessage[0]);
			SDL_FreeSurface(lifestruct.surfaceMessage[1]);
			SDL_FreeSurface(lifestruct.surfaceMessage[2]);
			lifestruct.GameOver = 1;
		}
	}


}
void SumScore(void) {
	for (int i = 0; i <= MAXENEMY; i++)
	{
		if (EnemyV[i].HP == 0 && EnemyV[i].killed == 0) {
			lifestruct.score += 100;
			EnemyV[i].killed = 1;
		}
	}
}