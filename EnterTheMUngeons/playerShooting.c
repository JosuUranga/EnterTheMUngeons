#include "Functions.h"
#include <stdio.h>
#include <SDL.h>


/*int collisioncheck(struct SDL_Rect dest, struct SDL_Rect borde1) {
	int CollisionResult = 0;
	if (SDL_HasIntersection(&dest, &borde1) == 1) CollisionResult = 1;
	return CollisionResult;
}*/

void AllyBulletCreation(SDL_Rect* dest, SDL_Rect* Bala) {
	int mouse_x, mouse_y;
	float distance;
	int buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
	if (buttons && SDL_BUTTON(SDL_BUTTON_LEFT)) {
		if (ProtaB.aBulletCreated == 0) {
			(*Bala).h = 15;
			(*Bala).w = 15;
			(*Bala).x = (*dest).x + ((*dest).w / 2);
			(*Bala).y = (*dest).y + ((*dest).h / 2);
			ProtaB.aBulletCreated = 1;
			ProtaB.aBulletDelta_x = (float)(mouse_x - (*Bala).w / 2) - (*Bala).x;
			ProtaB.aBulletDelta_y = (float)(mouse_y - (*Bala).h / 2) - (*Bala).y;
			distance = (float)sqrt(ProtaB.aBulletDelta_x*ProtaB.aBulletDelta_x + ProtaB.aBulletDelta_y*ProtaB.aBulletDelta_y);
			ProtaB.aBulletVel_x = (ProtaB.aBulletDelta_x*(ABSpeed)) / distance;
			ProtaB.aBulletVel_y = (ProtaB.aBulletDelta_y*(ABSpeed)) / distance;
			ProtaB.aBulletPos_x = (float)(*Bala).x;
			ProtaB.aBulletPos_y = (float)(*Bala).y;
			ProtaB.aFPSCounter = 0;
		}
	}
}

void MoveAllyBullet(SDL_Rect* Bala,SDL_Rect* Enemy) {
	if (ProtaB.aBulletCreated == 1) {
		ProtaB.aBulletPos_x += ProtaB.aBulletVel_x / 60;
		ProtaB.aBulletPos_y += ProtaB.aBulletVel_y / 60;
		(*Bala).x = (int)ProtaB.aBulletPos_x;
		(*Bala).y = (int)ProtaB.aBulletPos_y;
		for (int i = 0; i <= MAXENEMY; i++)
		{
			if (collisioncheck((*Bala), Enemy[i])) {
				(*Bala).h = 0;
				(*Bala).w = 0;
				if (EnemyV[i].HP != 0) {
					EnemyV[i].HP -= 1;
				}

			}
		}
		if (ProtaB.aFPSCounter == ProtaB.aBulletTTL) {
			(*Bala).h = 0;
			(*Bala).w = 0;
			ProtaB.aBulletCreated = 0;
		}
	}
}
