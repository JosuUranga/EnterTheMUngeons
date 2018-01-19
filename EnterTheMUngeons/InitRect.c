#include "Functions.h"

void InitRect(void) {
	playerRect;
	playerRect.player.w = 30;
	playerRect.player.h = 30;
	playerRect.player.x =(WINDOW_WIDTH - playerRect.player.w)/2;
	playerRect.player.y = (WINDOW_HEIGHT - playerRect.player.h)/2;
	levelmanagerstruct.borde[0].x = 0;
	levelmanagerstruct.borde[0].y = 0;
	levelmanagerstruct.borde[0].w = 40;
	levelmanagerstruct.borde[0].h = 480;
	levelmanagerstruct.borde[1].x = 0;
	levelmanagerstruct.borde[1].y = 0;
	levelmanagerstruct.borde[1].w = 640;
	levelmanagerstruct.borde[1].h = 40;
	levelmanagerstruct.borde[2].x = 600;
	levelmanagerstruct.borde[2].y = 0;
	levelmanagerstruct.borde[2].w = 40;
	levelmanagerstruct.borde[2].h = 480;
	levelmanagerstruct.borde[3].x = 0;
	levelmanagerstruct.borde[3].y = 440;
	levelmanagerstruct.borde[3].w = 640;
	levelmanagerstruct.borde[3].h = 40;

	lifestruct.Message_rect[0].x = 520;  //controls the rect's x coordinate 
	lifestruct.Message_rect[0].y = 0; // controls the rect's y coordinte
	lifestruct.Message_rect[0].w = 100; // controls the width of the rect
	lifestruct.Message_rect[0].h = 40; // controls the height of the rect


	

}


void ValorRects(SDL_Rect* a, int b, int c, int d, int e) {
	(*a).w=b;
	(*a).h=c;
	(*a).x=d;
	(*a).y = e;
}