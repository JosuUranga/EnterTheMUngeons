#include "Functions.h"


void bossFinalCreation() {
	boss.bossRect[4].h = 100;
	boss.bossRect[4].w = 150;
	boss.bossRect[4].x = WINDOW_WIDTH / 2 - 75;
	boss.bossRect[4].y = WINDOW_HEIGHT / 2 - 50;
	boss.hasSpawned[4] = 0;
	boss.healthPoints[4]= FINALBOSSHP;
	final.counter[0] = 0;
	final.counter[1] = -24;
	final.counter[2] = 0;
	final.counter[3] = 0;
	final.health[0] = 118;
	final.health[1] = 118;
	final.health[2] = 118;
	boss.sound[5] = 0;
	boss.sound[6] = 0;
	boss.sound[7] = 0;
}

void finalBoss() {
	final.counter[2]++;
	srand((unsigned int)time(0));
	if (final.counter[2] == 180) {
		final.counter[2] = 0;
		int x = rand() % 2;
		int y = rand() % 2;		
		if (boss.healthPoints[4] > 200) {
			if (x) {
				boss.bossRect[4].x = 50;
			}
			else {
				boss.bossRect[4].x = WINDOW_WIDTH - 40 - boss.bossRect[4].w;
			}
			if (y) {
				boss.bossRect[4].y = 50;
			}
			else {
				boss.bossRect[4].y = WINDOW_HEIGHT - 40 - boss.bossRect[4].h;
			}
		}
		if (boss.healthPoints[4] > 100 && boss.healthPoints[4] <= 200){
			final.health[0] = 0;
			if (boss.sound[6] == 0) { 
				playSound(4);
				boss.sound[6] = 1;
			}
			if (x&&y) {
				boss.bossRect[4].x = WINDOW_WIDTH/2 - 75;
				boss.bossRect[4].y = 50;
			}
			if (!x&&y) {
				boss.bossRect[4].x = WINDOW_WIDTH -50 - 150;
				boss.bossRect[4].y = WINDOW_HEIGHT / 2 - 50;
			}
			if (x&&!y) {
				boss.bossRect[4].x = WINDOW_WIDTH / 2 - 75;
				boss.bossRect[4].y = WINDOW_HEIGHT -50 - 100;
			}
			if (!x&&!y) {
				boss.bossRect[4].x = 50;
				boss.bossRect[4].y = WINDOW_HEIGHT / 2 - 50;
			}
		}
		
	}
	if (boss.healthPoints[4] <= 100) {
		final.health[1] = 0;
		if (boss.sound[7] == 0) {
			EnemyV[0].FPSCounter = 0;
			playSound(4);
			boss.sound[7] = 1;
		}
		boss.bossRect[4].x = WINDOW_WIDTH / 2 - 75;
		boss.bossRect[4].y = WINDOW_HEIGHT / 2 - 50;
	}
	finalAtakeakSortu(playerRect.player, playerRect.Bala);
	ValorRects(&boss.bossLifeFrame,(int)boss.bossRect[4].w, 20, boss.bossRect[4].x, boss.bossRect[4].y - 20);
	ValorRects(&boss.bossLife, (int)final.health[0], 9, boss.bossRect[4].x + 16, boss.bossRect[4].y - 14);
	ValorRects(&boss.bossLife2, (int)final.health[1], 9, boss.bossRect[4].x + 16, boss.bossRect[4].y - 14);
	ValorRects(&boss.bossLife3, (int)final.health[2], 9, boss.bossRect[4].x + 16, boss.bossRect[4].y - 14);
	enemySpawn.enemykilled[0] = 0;
	
}

void finalAtakeakSortu(SDL_Rect player, SDL_Rect bala) {
	if (EnemyV[0].FPSCounter > 50&&boss.healthPoints[4]>100) {
		if (final.finalHasBeenCreated[0] == 0 && final.counter[0] == 0) {
			final.finalRect[0].h = 26;
			final.finalRect[0].w = 26;
			final.finalRect[0].x = boss.bossRect[4].x;
			final.finalRect[0].y = boss.bossRect[4].y + 70;
			final.finalVelY[0] = ATAQUEVEL - 4;
			final.finalVelX[0] = ATAQUEVEL - 4;
			final.finalHasBeenCreated[0] = 1;
			final.deltax = (float)((player).x + (player.w / 2)) - (boss.bossRect[4].x + boss.bossRect[4].w / 2);
			final.deltay = (float)((player).y + (player.h / 2)) - (boss.bossRect[4].y + boss.bossRect[4].h / 2);
			final.distance = (float)sqrt(final.deltax*final.deltax + final.deltay * final.deltay);
		}
		if (final.finalHasBeenCreated[1] == 0 && final.counter[1] == 0) {
			final.finalRect[1].h = 26;
			final.finalRect[1].w = 26;
			final.finalRect[1].x = boss.bossRect[4].x + 70;
			final.finalRect[1].y = boss.bossRect[4].y + 55;
			final.finalVelY[1] = ATAQUEVEL - 4;
			final.finalVelX[1] = ATAQUEVEL - 4;
			final.finalHasBeenCreated[1] = 1;
			final.deltax = (float)((player).x + (player.w / 2)) - (boss.bossRect[4].x + boss.bossRect[4].w / 2);
			final.deltay = (float)((player).y + (player.h / 2)) - (boss.bossRect[4].y + boss.bossRect[4].h / 2);
			final.distance = (float)sqrt(final.deltax*final.deltax + final.deltay * final.deltay);
		}
	}
	finalAtakeakMugitu(player, bala);

}
void finalAtakeakMugitu(SDL_Rect dest, SDL_Rect bala) {
	if (EnemyV[0].FPSCounter > 50) {
		if (boss.healthPoints[4] > 100) {
			if (final.counter[0] <= LAVATTL + 5 && final.counter[1] <= LAVATTL + 5) {
				final.counter[0]++;
				final.counter[1]++;
			}
			if (final.finalHasBeenCreated[0] == 1) {
				final.finalVelX[0] = (final.deltax*(ATAQUEVEL)) / final.distance;
				final.finalVelY[0] = (final.deltay*(ATAQUEVEL)) / final.distance;
				final.finalRect[0].y += (int)final.finalVelY[0];
				final.finalRect[0].x += (int)final.finalVelX[0];
				if (!lifestruct.invencivilty) {
					if (collisioncheck(final.finalRect[0], dest)) {
						final.finalHasBeenCreated[0] = 0;
						lifestruct.lifes--;
						lifestruct.invencivilty = 1;
					}
				}
			}
			if (final.counter[0] == LAVATTL + 5) {
				final.finalHasBeenCreated[0] = 0;
				final.counter[0] = 0;
			}
			if (final.finalHasBeenCreated[1] == 1) {
				final.finalVelX[1] = (final.deltax*(ATAQUEVEL)) / final.distance;
				final.finalVelY[1] = (final.deltay*(ATAQUEVEL)) / final.distance;
				final.finalRect[1].y += (int)final.finalVelY[1];
				final.finalRect[1].x += (int)final.finalVelX[1];
				if (!lifestruct.invencivilty) {
					if (collisioncheck(final.finalRect[1], dest)) {
						final.finalHasBeenCreated[1] = 0;
						lifestruct.lifes--;
						lifestruct.invencivilty = 1;
					}
				}
			}
			if (final.counter[1] == LAVATTL + 5) {
				final.finalHasBeenCreated[1] = 0;
				final.counter[1] = 0;
			}
			if (boss.healthPoints[4] < 102) {
				final.finalRect[0].y = 1000;
				final.finalRect[0].x = 1000;
				final.finalRect[1].y = 1000;
				final.finalRect[1].x = 1000;
				final.finalRect[2].y = 1000 ;
				final.finalRect[2].x = 1000;
				final.finalRect[3].y = 1000;
				final.finalRect[3].x = 1000;
				final.finalRect[4].y = 1000;
				final.finalRect[4].x = 1000;
				final.finalRect[5].y = 1000;
				final.finalRect[5].x = 1000;
				final.finalRect[6].y = 1000;
				final.finalRect[6].x = 1000;
				final.finalRect[7].y = 1000;
				final.finalRect[7].x = 1000;
				//final.finalVelX[0] = ATAQUEVEL;
				//final.finalVelY[0] = -ATAQUEVEL;
			}
		}
		else if(boss.healthPoints[4]<101 ){
			if (final.counter[2] == 60 || final.fase3==0) {
				final.fase3 = 1;
				final.counter[2] = 0;
				final.finalRect[0].y = boss.bossRect[4].y + 50;
				final.finalRect[0].x = boss.bossRect[4].x + 75 - 13;
				final.finalRect[1].y = boss.bossRect[4].y + 50;
				final.finalRect[1].x = boss.bossRect[4].x + 75 - 13;
				final.finalRect[2].y = boss.bossRect[4].y + 50;
				final.finalRect[2].x = boss.bossRect[4].x + 75 - 13;
				final.finalRect[3].y = boss.bossRect[4].y + 50;
				final.finalRect[3].x = boss.bossRect[4].x + 75 - 13;
				final.finalRect[4].y = boss.bossRect[4].y + 50;
				final.finalRect[4].x = boss.bossRect[4].x + 75 - 13;
				final.finalRect[5].y = boss.bossRect[4].y + 50;
				final.finalRect[5].x = boss.bossRect[4].x + 75 - 13;
				final.finalRect[6].y = boss.bossRect[4].y + 50;
				final.finalRect[6].x = boss.bossRect[4].x + 75 - 13;
				final.finalRect[7].y = boss.bossRect[4].y + 50;
				final.finalRect[7].x = boss.bossRect[4].x + 75 - 13;
			}
			
			final.finalVelX[0] = ATAQUEVEL;
			final.finalVelY[0] = -ATAQUEVEL;
			final.finalRect[0].y += (int)final.finalVelY[0];
			final.finalRect[0].x += (int)final.finalVelX[0];
			final.finalVelX[1] = ATAQUEVEL;
			final.finalVelY[1] = 0;
			final.finalRect[1].y += (int)final.finalVelY[1];
			final.finalRect[1].x += (int)final.finalVelX[1];
			final.finalVelX[2] = ATAQUEVEL;
			final.finalVelY[2] = ATAQUEVEL;
			final.finalRect[2].y += (int)final.finalVelY[2];
			final.finalRect[2].x += (int)final.finalVelX[2];
			final.finalVelX[3] = 0;
			final.finalVelY[3] = ATAQUEVEL;
			final.finalRect[3].y += (int)final.finalVelY[3];
			final.finalRect[3].x += (int)final.finalVelX[3];
			final.finalVelX[4] = -ATAQUEVEL;
			final.finalVelY[4] = ATAQUEVEL;
			final.finalRect[4].y += (int)final.finalVelY[4];
			final.finalRect[4].x += (int)final.finalVelX[4];
			final.finalVelX[5] = -ATAQUEVEL;
			final.finalVelY[5] = 0;
			final.finalRect[5].y += (int)final.finalVelY[5];
			final.finalRect[5].x += (int)final.finalVelX[5];
			final.finalVelX[6] = -ATAQUEVEL;
			final.finalVelY[6] = -ATAQUEVEL;
			final.finalRect[6].y += (int)final.finalVelY[6];
			final.finalRect[6].x += (int)final.finalVelX[6];
			final.finalVelX[7] = 0;
			final.finalVelY[7] = -ATAQUEVEL;
			final.finalRect[7].y += (int)final.finalVelY[7];
			final.finalRect[7].x += (int)final.finalVelX[7];

			if (!lifestruct.invencivilty) {
				if (collisioncheck(final.finalRect[0], dest) || collisioncheck(final.finalRect[1], dest) || collisioncheck(final.finalRect[2], dest) || collisioncheck(final.finalRect[3], dest) || collisioncheck(final.finalRect[4], dest) || collisioncheck(final.finalRect[5], dest) || collisioncheck(final.finalRect[6], dest) || collisioncheck(final.finalRect[7], dest)) {
					lifestruct.lifes--;
					lifestruct.invencivilty = 1;
				}
			}

		}
	}
	
	if (collisioncheck(boss.bossRect[4], dest)) {
		lifestruct.lifes = 0;
	}
	if (collisioncheck(bala, boss.bossRect[4])) {
		boss.healthPoints[4] -= 1;
		
		if(boss.healthPoints[4] > 200)final.health[0] -= (float)1.18;
		if (boss.healthPoints[4] > 100 && boss.healthPoints[4] <= 200)final.health[1] -= (float)1.18;
		if (boss.healthPoints[4] <= 100)final.health[2] -= (float)1.18;
		if (boss.healthPoints[4] == 0) {
			levelmanagerstruct.playing = 3;
			lifestruct.score += 1000;
			final.counter[0] = 50;
			final.counter[1] = 50;
			boss.bossRect[4].w = 0;
			boss.bossRect[4].h = 0;
			boss.hasSpawned[4] = 1;
			final.finalRect[0].w = 0;
			final.finalRect[1].w = 0;
			final.finalRect[0].h = 0;
			final.finalRect[0].h = 0;
			playSound(4);
			boss.bossLife.w = 0;
			boss.bossLife.h = 0;
			boss.bossLife2.w = 0;
			boss.bossLife2.h = 0;
			boss.bossLife3.w = 0;
			boss.bossLife3.h = 0;
		}
	}
}