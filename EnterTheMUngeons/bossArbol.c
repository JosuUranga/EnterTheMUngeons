#include "Functions.h"
void bossArbolCreation() {
	boss.bossRect[3].h = 100;
	boss.bossRect[3].w = 100;
	boss.bossRect[3].x = WINDOW_WIDTH/2- 50;
	boss.bossRect[3].y = WINDOW_HEIGHT/2-50;
	boss.hasSpawned[3] = 0;
	boss.healthPoints[3] = LAVAHP * 2;
	arbol.counter[0] = 0;
	arbol.counter[1] = -24;
	boss.sound[3] = 0;
	boss.health[1] = 255;
	arbol.arbolHasBeenCreated[0] = 0;
	arbol.arbolHasBeenCreated[1] = 0;

}

void arbolAtakeakSortu(SDL_Rect player, SDL_Rect bala) {
	if (EnemyV[0].FPSCounter > 50) {
		if (arbol.arbolHasBeenCreated[0] == 0 && arbol.counter[0] == 0) {
			arbol.arbolRect[0].h = 26;
			arbol.arbolRect[0].w = 26;
			arbol.arbolRect[0].x = boss.bossRect[3].x;
			arbol.arbolRect[0].y = boss.bossRect[3].y + 70;
			arbol.arbolVelY[0] = ATAQUEVEL - 4;
			arbol.arbolVelX[0] = ATAQUEVEL - 4;
			arbol.arbolHasBeenCreated[0] = 1;
			arbol.deltax = ((player).x + (player.w / 2)) - (boss.bossRect[3].x + boss.bossRect[3].w / 2);
			arbol.deltay = ((player).y + (player.h / 2)) - (boss.bossRect[3].y + boss.bossRect[3].h / 2);
			arbol.distance = sqrt(arbol.deltax*arbol.deltax + arbol.deltay * arbol.deltay);
		}
		if (arbol.arbolHasBeenCreated[1] == 0 && arbol.counter[1] == 0) {
			arbol.arbolRect[1].h = 26;
			arbol.arbolRect[1].w = 26;
			arbol.arbolRect[1].x = boss.bossRect[3].x + 70;
			arbol.arbolRect[1].y = boss.bossRect[3].y + 55;
			arbol.arbolVelY[1] = ATAQUEVEL - 4;
			arbol.arbolVelX[1] = ATAQUEVEL - 4;
			arbol.arbolHasBeenCreated[1] = 1;
			arbol.deltax = ((player).x + (player.w / 2)) - (boss.bossRect[3].x + boss.bossRect[3].w / 2);
			arbol.deltay = ((player).y + (player.h / 2)) - (boss.bossRect[3].y + boss.bossRect[3].h / 2);
			arbol.distance = sqrt(arbol.deltax*arbol.deltax + arbol.deltay * arbol.deltay);
		}
	}
	arbolAtakeakMugitu(player, bala);

}
void arbolAtakeakMugitu(SDL_Rect dest, SDL_Rect bala) {


	if (arbol.counter[0] <= LAVATTL+5 && arbol.counter[1] <= LAVATTL+5) {
		arbol.counter[0]++;
		arbol.counter[1]++;
		//printf("%d %d \n", arbol.counter[0], arbol.counter[1]);
	}



	if (arbol.arbolHasBeenCreated[0] == 1) {
		arbol.arbolVelX[0] = (arbol.deltax*(ATAQUEVEL)) / arbol.distance;
		arbol.arbolVelY[0] = (arbol.deltay*(ATAQUEVEL)) / arbol.distance;
		arbol.arbolRect[0].y += arbol.arbolVelY[0];
		arbol.arbolRect[0].x += arbol.arbolVelX[0];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(arbol.arbolRect[0], dest)) {
				arbol.arbolHasBeenCreated[0] = 0;
				lifestruct.lifes--;
				lifestruct.invencivilty = 1;
			}
		}
	}
	if (arbol.counter[0] == LAVATTL+5) {
		arbol.arbolHasBeenCreated[0] = 0;
		arbol.counter[0] = 0;
	}
	if (arbol.arbolHasBeenCreated[1] == 1) {
		arbol.arbolVelX[1] = (arbol.deltax*(ATAQUEVEL)) / arbol.distance;
		arbol.arbolVelY[1] = (arbol.deltay*(ATAQUEVEL)) / arbol.distance;
		arbol.arbolRect[1].y += arbol.arbolVelY[1];
		arbol.arbolRect[1].x += arbol.arbolVelX[1];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(arbol.arbolRect[1], dest)) {
				arbol.arbolHasBeenCreated[1] = 0;
				lifestruct.lifes--;
				lifestruct.invencivilty = 1;
			}
		}
	}
	if (arbol.counter[1] == LAVATTL+5) {
		arbol.arbolHasBeenCreated[1] = 0;
		arbol.counter[1] = 0;
	}
	if (collisioncheck(boss.bossRect[3], dest)) {
		lifestruct.lifes = 0;
	}
	if (collisioncheck(bala, boss.bossRect[3])) {
		boss.healthPoints[3] -= 1;
		boss.health[1] -= 2.55;
		if (boss.healthPoints[3] == 0) {
			boss.bossesKilled += 1;
			lifestruct.lifes = 3;
			lifestruct.score += 1000;
			arbol.counter[0] = 50;
			arbol.counter[1] = 50;
			boss.bossRect[3].w = 0;
			boss.bossRect[3].h = 0;
			boss.hasSpawned[3] = 1;
			arbol.arbolRect[0].w = 0;
			arbol.arbolRect[1].w = 0;
			arbol.arbolRect[0].h = 0;
			arbol.arbolRect[0].h = 0;
			if (boss.bossesKilled == 4) lifestruct.lifes = 5;
		}
	}
}