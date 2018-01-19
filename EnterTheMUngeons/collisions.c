#include "Functions.h"

int checkCollision(SDL_Rect A, SDL_Rect B)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	//Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return 0;
	}

	if (topA >= bottomB)
	{
		return 0;
	}

	if (rightA <= leftB)
	{
		return 0;
	}

	if (leftA >= rightB)
	{
		return 0;
	}

	//If none of the sides from A are outside B
	return 1;
}

void windowCollision(SDL_Rect dest) {
	if (posstruct.x <= 0) posstruct.x = 0;
	if (posstruct.y <= 0) posstruct.y = 0;

	if (posstruct.x >= WINDOW_WIDTH - dest.w) posstruct.x = (float)WINDOW_WIDTH - dest.w;
	if (posstruct.y >= WINDOW_HEIGHT - dest.h) posstruct.y = (float)WINDOW_HEIGHT - dest.h;

	// set the positions in the struct
	dest.y = (int)posstruct.y;
	dest.x = (int)posstruct.x;
}


void wallCollision(SDL_Rect dest, SDL_Rect* borde) {
	int WallCountCollision = 0;
	for (int i = 0; i <= MAXRECTS; i++)
	{
		WallCountCollision += checkCollision(dest, borde[i]);
	}
	if (WallCountCollision >= 1) {
		posstruct.x_vel = 0;
		posstruct.y_vel = 0;
		
	}

	if (checkCollision(dest, borde[0])) posstruct.x = (float)(posstruct.xtemp + 0.2);
	if (checkCollision(dest, borde[1])) posstruct.y = (float)(posstruct.ytemp + 0.2);
	if (checkCollision(dest, borde[2])) posstruct.x = (float)(posstruct.xtemp - 0.2);
	if (checkCollision(dest, borde[3])) posstruct.y = (float)(posstruct.ytemp - 0.2);

	posstruct.xtemp = posstruct.x;
	posstruct.ytemp = posstruct.y;
}

int collisioncheck(struct SDL_Rect dest, struct SDL_Rect borde1) {
	int CollisionResult = 0;
	if (SDL_HasIntersection(&dest, &borde1) == 1) CollisionResult = 1;
	return CollisionResult;
}


