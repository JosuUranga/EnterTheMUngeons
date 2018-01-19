#include "Functions.h"
void bossEsqueletoCreation() {
	ValorRects(&boss.bossRect[1], 82, 100, 50, 50);
	boss.bossVelX[1] = 25;
	boss.bossVelY[1] = 25;
	boss.hasSpawned[1] = 0;
	boss.healthPoints[1] = LAVAHP;
	boss.sound[1] = 0;
	boss.health[3] = 255;
}

void esqBoss(SDL_Rect player) {
	
	float deltax, deltay, distance;

	deltax = (float)(player).x - boss.bossRect[1].x;
	deltay = (float)(player).y - boss.bossRect[1].y;
	distance = (float)sqrt(deltax*deltax + deltay*deltay);
	boss.bossVelX[1] = (deltax*(LAVABOSSVEL)) / distance;
	boss.bossVelY[1] = (deltay*(LAVABOSSVEL)) / distance;

	boss.bossRect[1].x += (int)boss.bossVelX[1];
	boss.bossRect[1].y += (int)boss.bossVelY[1];

}
void esqAtakeakSortu(SDL_Rect player, SDL_Rect bala) {
	if (EnemyV[0].FPSCounter > 50) {
		if (esq.esqHasBeenCreated[0] == 0 && esq.counter[0] == 0) {
			ValorRects(&esq.esqRect[0], 26, 26, boss.bossRect[1].x + 41, boss.bossRect[1].y + 50);
			esq.esqVelY[0] = ATAQUEVEL - 2;
			esq.esqVelX[0] = ATAQUEVEL - 2;
			esq.esqHasBeenCreated[0] = 1;

		}
		if (esq.esqHasBeenCreated[1] == 0 && esq.counter[1] == 0) {
			ValorRects(&esq.esqRect[1], 26, 26, boss.bossRect[1].x + 41, boss.bossRect[1].y + 50);
			esq.esqVelY[1] = ATAQUEVEL - 2;
			esq.esqVelX[1] = ATAQUEVEL - 2;
			esq.esqHasBeenCreated[1] = 1;

		}
	}
	esqAtakeakMugitu(player, bala);
}
void esqAtakeakMugitu(SDL_Rect dest, SDL_Rect bala) {
	float deltax, deltay, distance;
	if (esq.counter[0] <= LAVATTL && esq.counter[1] <= LAVATTL) {
		esq.counter[0]++;
		esq.counter[1]++;
	}

	deltax = (float)(dest).x + (dest).w / 2 - boss.bossRect[1].x;
	deltay = (float)(dest).y + (dest).h / 2 - boss.bossRect[1].y;
	distance = (float)sqrt(deltax*deltax + deltay * deltay);
	
	if (esq.esqHasBeenCreated[0] == 1) {
		esq.esqVelX[0] = (deltax*(ATAQUEVEL)) / distance;
		esq.esqVelY[0] = (deltay*(ATAQUEVEL)) / distance;
		esq.esqRect[0].y += (int)esq.esqVelY[0];
		esq.esqRect[0].x += (int)esq.esqVelX[0];
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
		esq.esqRect[1].y += (int)esq.esqVelY[1];
		esq.esqRect[1].x += (int)esq.esqVelX[1];
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
		boss.health[3] -= (float)5.1;
		//printf("%d\n", boss.healthPoints[0]);
		if (boss.healthPoints[1] == 0) {
			lifestruct.lifes = 3;
			boss.bossesKilled += 1;
			lifestruct.score += 1000;
			lifestruct.lifes = 3;
			esq.counter[0] = 50;
			esq.counter[1] = 50;
			ValorRects(&boss.bossRect[1], 0, 0, 0, 0);
			boss.hasSpawned[1] = 1;
			ValorRects(&esq.esqRect[0], 0, 0, 0, 0);
			ValorRects(&esq.esqRect[1], 0, 0, 0, 0);
			if (boss.bossesKilled == 4) lifestruct.lifes = 5;
		}
	}
}