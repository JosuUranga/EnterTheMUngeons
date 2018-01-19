#include "Functions.h"

void InitRect(void) {
	playerRect;
	ValorRects(&playerRect.player,30,30, (WINDOW_WIDTH - playerRect.player.w) / 2, (WINDOW_HEIGHT - playerRect.player.h) / 2);
	ValorRects(&levelmanagerstruct.borde[0], 40,480,0,0);
	ValorRects(&levelmanagerstruct.borde[1], 640, 40, 0, 0);
	ValorRects(&levelmanagerstruct.borde[2], 40, 480, 600, 0);
	ValorRects(&levelmanagerstruct.borde[3], 640,40, 0, 440);
	ValorRects(&lifestruct.Message_rect[0], 100,40,520,0);


	

}


void ValorRects(SDL_Rect* a, int b, int c, int d, int e) {
	(*a).w=b;
	(*a).h=c;
	(*a).x=d;
	(*a).y = e;
}