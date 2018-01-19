#include "Functions.h"
void bossNieveCreation() {
	ValorRects(&boss.bossRect[2], 82, 100, 520, 50);
	boss.bossVelX[2] = 0;
	boss.bossVelY[2] = (NIEVEBOSSVEL);
	boss.hasSpawned[2] = 0;
	boss.healthPoints[2] = LAVAHP;
	nieve.counter[0] = 0;
	nieve.counter[1] = -24;
	boss.sound[2] = 0;
	boss.health[2] = 255;
}

void nieveBoss() {
	
	boss.bossRect[2].x += (int)boss.bossVelX[2];
	boss.bossRect[2].y += (int)boss.bossVelY[2];
	
	if (boss.bossRect[2].y > WINDOW_HEIGHT - 50 - boss.bossRect[2].h) {
		boss.bossRect[2].y = WINDOW_HEIGHT - 50 - boss.bossRect[2].h;
		boss.bossVelY[2] = 0;
		boss.bossVelX[2] = -(NIEVEBOSSVEL);
	}
	if (boss.bossRect[2].x < 50) {
		boss.bossRect[2].x = 50;
		boss.bossVelY[2] = -(NIEVEBOSSVEL);
		boss.bossVelX[2] = 0;
	}
	if (boss.bossRect[2].y < 50) {
		boss.bossRect[2].y = 50;
		boss.bossVelY[2] = 0;
		boss.bossVelX[2] = (NIEVEBOSSVEL);
	}
	if (boss.bossRect[2].x > WINDOW_WIDTH - 50 - boss.bossRect[2].w) {
		boss.bossRect[2].x = WINDOW_WIDTH - 50 - boss.bossRect[2].w;
		boss.bossVelY[2] = (NIEVEBOSSVEL);
		boss.bossVelX[2] = 0;
	}

}
void nieveAtakeakSortu(SDL_Rect player, SDL_Rect bala) {
	if (EnemyV[0].FPSCounter > 50) {
		if (nieve.nieveHasBeenCreated[0] == 0 && nieve.counter[0] == 0) {
			ValorRects(&nieve.nieveRect[0], 26, 26, boss.bossRect[2].x + 41, boss.bossRect[2].y + 50);
			nieve.nieveVelY[0] = ATAQUEVEL - 4;
			nieve.nieveVelX[0] = ATAQUEVEL - 4;
			nieve.nieveHasBeenCreated[0] = 1;
			nieve.deltax[0] = (float)((player).x + (player.w / 2)) - (boss.bossRect[2].x + boss.bossRect[2].w / 2);
			nieve.deltay[0] = (float)((player).y + (player.h / 2)) - (boss.bossRect[2].y + boss.bossRect[2].h / 2);
			nieve.distance[0] = (float)sqrt(nieve.deltax[0] *nieve.deltax[0] + nieve.deltay[0] * nieve.deltay[0]);
		}
		if (nieve.nieveHasBeenCreated[1] == 0 && nieve.counter[1] == 0) {
			ValorRects(&nieve.nieveRect[1], 26, 26, boss.bossRect[2].x + 41, boss.bossRect[2].y + 50);
			nieve.nieveVelY[1] = ATAQUEVEL - 4;
			nieve.nieveVelX[1] = ATAQUEVEL - 4;
			nieve.nieveHasBeenCreated[1] = 1;
			nieve.deltax[1] = (float)((player).x + (player.w / 2)) - (boss.bossRect[2].x + boss.bossRect[2].w / 2);
			nieve.deltay[1] = (float)((player).y + (player.h / 2)) - (boss.bossRect[2].y + boss.bossRect[2].h / 2);
			nieve.distance[1] = (float)sqrt(nieve.deltax[1] *nieve.deltax[1] + nieve.deltay[1] * nieve.deltay[1]);
		}
	}
	nieveAtakeakMugitu(player, bala);

}
void nieveAtakeakMugitu(SDL_Rect dest, SDL_Rect bala) {
	

	if (nieve.counter[0] <= NIEVETTL && nieve.counter[1] <= NIEVETTL) {
		nieve.counter[0]++;
		nieve.counter[1]++;
		printf("%d %d \n", nieve.counter[0], nieve.counter[1]);
	}

	

	if (nieve.nieveHasBeenCreated[0] == 1) {
		nieve.nieveVelX[0] = (nieve.deltax[0] *(ATAQUEVEL)) / nieve.distance[0];
		nieve.nieveVelY[0] = (nieve.deltay[0] *(ATAQUEVEL)) / nieve.distance[0];
		nieve.nieveRect[0].y += (int)nieve.nieveVelY[0];
		nieve.nieveRect[0].x += (int)nieve.nieveVelX[0];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(nieve.nieveRect[0], dest)) {
				nieve.nieveHasBeenCreated[0] = 0;
				lifestruct.lifes--;
			}
		}
	}
	if (nieve.counter[0] == NIEVETTL) {
		nieve.nieveHasBeenCreated[0] = 0;
		nieve.counter[0] = 0;
	}
	if (nieve.nieveHasBeenCreated[1] == 1) {
		nieve.nieveVelX[1] = (nieve.deltax[1] *(ATAQUEVEL)) / nieve.distance[1];
		nieve.nieveVelY[1] = (nieve.deltay[1] *(ATAQUEVEL)) / nieve.distance[1];
		nieve.nieveRect[1].y += (int)nieve.nieveVelY[1];
		nieve.nieveRect[1].x += (int)nieve.nieveVelX[1];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(nieve.nieveRect[1], dest)) {
				nieve.nieveHasBeenCreated[1] = 0;
				lifestruct.lifes--;
			}
		}
	}
	if (nieve.counter[1] == NIEVETTL) {
		nieve.nieveHasBeenCreated[1] = 0;
		nieve.counter[1] = 0;
	}
	if (collisioncheck(boss.bossRect[2], dest)) {
		lifestruct.lifes = 0;
	}
	if (collisioncheck(bala, boss.bossRect[2])) {
		boss.healthPoints[2] -= 1;
		boss.health[2] -= (float)5.1;
		if (boss.healthPoints[2] == 0) {
			lifestruct.lifes = 3;
			boss.bossesKilled += 1;
			lifestruct.score += 1000;
			nieve.counter[0] = 50;
			nieve.counter[1] = 50;
			ValorRects(&boss.bossRect[2], 0, 0, 0, 0);
			boss.hasSpawned[2] = 1;
			ValorRects(&nieve.nieveRect[0], 0, 0, 0, 0);
			ValorRects(&nieve.nieveRect[1], 0, 0, 0, 0);
			lifestruct.tempScore = lifestruct.score;
			if (boss.bossesKilled == 4) lifestruct.lifes = 5;
		}
	}
}