#include "Functions.h"
void bossEsqueletoCreation() {
	boss.bossRect[1].h = 100;
	boss.bossRect[1].w = 82;
	boss.bossRect[1].x = 50;
	boss.bossRect[1].y = 50;
	boss.bossVelX[1] = 25;
	boss.bossVelY[1] = 25;
	boss.hasSpawned[1] = 0;
	boss.healthPoints[1] = LAVAHP;
	boss.sound[1] = 0;
	boss.health[3] = 255;
}

void esqBoss(SDL_Rect player) {
	
	float deltax, deltay, distance;

	deltax = (player).x - boss.bossRect[1].x;
	deltay = (player).y - boss.bossRect[1].y;
	distance = sqrt(deltax*deltax + deltay*deltay);
	boss.bossVelX[1] = (deltax*(LAVABOSSVEL)) / distance;
	boss.bossVelY[1] = (deltay*(LAVABOSSVEL)) / distance;

	boss.bossRect[1].x += boss.bossVelX[1];
	boss.bossRect[1].y += boss.bossVelY[1];

}
void esqAtakeakSortu(SDL_Renderer *rend, SDL_Rect player, SDL_Rect bala) {
	if (EnemyV[0].FPSCounter > 50) {
		if (esq.esqHasBeenCreated[0] == 0 && esq.counter[0] == 0) {
			esq.esqRect[0].h = 26;
			esq.esqRect[0].w = 26;
			esq.esqRect[0].x = boss.bossRect[1].x + 41;
			esq.esqRect[0].y = boss.bossRect[1].y + 50;
			esq.esqVelY[0] = ATAQUEVEL - 2;
			esq.esqVelX[0] = ATAQUEVEL - 2;
			esq.esqHasBeenCreated[0] = 1;

		}
		if (esq.esqHasBeenCreated[1] == 0 && esq.counter[1] == 0) {
			esq.esqRect[1].h = 26;
			esq.esqRect[1].w = 26;
			esq.esqRect[1].x = boss.bossRect[1].x + 41;
			esq.esqRect[1].y = boss.bossRect[1].y + 50;
			esq.esqVelY[1] = ATAQUEVEL - 2;
			esq.esqVelX[1] = ATAQUEVEL - 2;
			esq.esqHasBeenCreated[1] = 1;

		}
	}
	esqAtakeakMugitu(rend, player, bala);
}
void esqAtakeakMugitu(SDL_Renderer* rend, SDL_Rect dest, SDL_Rect bala) {
	float deltax, deltay, distance;
	if (esq.counter[0] <= LAVATTL && esq.counter[1] <= LAVATTL) {
		esq.counter[0]++;
		esq.counter[1]++;
	}

	deltax = (dest).x + (dest).w / 2 - boss.bossRect[1].x;
	deltay = (dest).y + (dest).h / 2 - boss.bossRect[1].y;
	distance = sqrt(deltax*deltax + deltay * deltay);
	
	if (esq.esqHasBeenCreated[0] == 1) {
		esq.esqVelX[0] = (deltax*(ATAQUEVEL)) / distance;
		esq.esqVelY[0] = (deltay*(ATAQUEVEL)) / distance;
		esq.esqRect[0].y += esq.esqVelY[0];
		esq.esqRect[0].x += esq.esqVelX[0];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(esq.esqRect[0], dest)) {
				esq.esqHasBeenCreated[0] = 0;
				lifestruct.lifes--;
				lifestruct.invencivilty = 1;
			}
		}
	}
	if (esq.counter[0] == LAVATTL) {
		esq.esqHasBeenCreated[0] = 0;
		esq.counter[0] = 0;
	}
	if (esq.esqHasBeenCreated[1] == 1) {
		esq.esqVelX[1] = (deltax*(ATAQUEVEL)) / distance;
		esq.esqVelY[1] = (deltay*(ATAQUEVEL)) / distance;
		esq.esqRect[1].y += esq.esqVelY[1];
		esq.esqRect[1].x += esq.esqVelX[1];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(esq.esqRect[1], dest)) {
				esq.esqHasBeenCreated[1] = 0;
				lifestruct.lifes--;
				lifestruct.invencivilty = 1;
			}
		}
	}
	if (esq.counter[1] == LAVATTL) {
		esq.esqHasBeenCreated[1] = 0;
		esq.counter[1] = 0;
	}
	if (collisioncheck(boss.bossRect[1], dest)) {
		lifestruct.lifes = 0;
	}
	if (collisioncheck(bala, boss.bossRect[1])) {
		boss.healthPoints[1] -= 1;
		boss.health[3] -= 5.1;
		//printf("%d\n", boss.healthPoints[0]);
		if (boss.healthPoints[1] == 0) {
			lifestruct.lifes = 3;
			boss.bossesKilled += 1;
			lifestruct.score += 1000;
			lifestruct.lifes = 3;
			esq.counter[0] = 50;
			esq.counter[1] = 50;
			boss.bossRect[1].w = 0;
			boss.bossRect[1].h = 0;
			boss.hasSpawned[1] = 1;
			esq.esqRect[0].w = 0;
			esq.esqRect[1].w = 0;
			esq.esqRect[0].h = 0;
			esq.esqRect[0].h = 0;
			if (boss.bossesKilled == 4) lifestruct.lifes = 5;
		}
	}
}