
#include "Functions.h"

void lavaBoss(void) {
	boss.bossRect[0].x += (int)boss.bossVelX[0];

	if (boss.bossRect[0].x > 500) {
		boss.bossVelX[0] *= -1;
	}
	if (boss.bossRect[0].x < 40) {
		boss.bossVelX[0] *= -1;
	}

}

void lavaBossCreation(void) {
	ValorRects(&boss.bossRect[0], 100, 100, 50,50);
	boss.bossVelX[0] = LAVABOSSVEL;
	boss.hasSpawned[0] = 0;
	boss.healthPoints[0] = LAVAHP;
	lava.lavaHasBeenCreated[0] = 0;
	lava.lavaHasBeenCreated[1] = 0;
	lava.counter[0] = 0;
	lava.counter[1] = -21;
	boss.health[0] = 255;
	boss.sound[0] = 0;

	
}

void lavaAtakeakSortu(void) {
	if (EnemyV[0].FPSCounter > 50) {
		if (lava.lavaHasBeenCreated[0] == 0 && lava.counter[0] == 0) {
			ValorRects(&lava.lavaRect[0], 26,26, boss.bossRect[0].x + 50 , boss.bossRect[0].y + 80);
			lava.lavaVelY[0] = ATAQUEVEL;
			lava.lavaHasBeenCreated[0] = 1;

		}
		if (lava.lavaHasBeenCreated[1] == 0 && lava.counter[1] == 0) {
			ValorRects(&lava.lavaRect[1], 26, 26, boss.bossRect[0].x + 50, boss.bossRect[0].y + 80);
			lava.lavaVelY[1] = ATAQUEVEL;
			lava.lavaHasBeenCreated[1] = 1;

		}
	}
		lavaAtakeakMugitu();
}
void lavaAtakeakMugitu(void) {
	if (lava.counter[0] <= LAVATTL && lava.counter[1] <= LAVATTL) {
		lava.counter[0]++;
		lava.counter[1]++;
	}

	if (lava.lavaHasBeenCreated[0] == 1) {
		lava.lavaRect[0].y += (int)lava.lavaVelY[0];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(lava.lavaRect[0], playerRect.player)) {
				lava.lavaHasBeenCreated[0] = 0;
				lifestruct.lifes--;
				lifestruct.invencivilty = 1;
			}
		}
	}
	if (lava.counter[0] == LAVATTL) {
		lava.lavaHasBeenCreated[0] = 0;
		lava.counter[0] = 0;
	}
	if (lava.lavaHasBeenCreated[1] == 1) {
		lava.lavaRect[1].y += (int)lava.lavaVelY[1];
		if (!lifestruct.invencivilty) {
			if (collisioncheck(lava.lavaRect[1], playerRect.player)) {
				lava.lavaHasBeenCreated[1] = 0;
				lifestruct.lifes--;
				lifestruct.invencivilty = 1;
			}
		}
	}
	if (lava.counter[1] == LAVATTL) {
		lava.lavaHasBeenCreated[1] = 0;
		lava.counter[1] = 0;
	}
	if (collisioncheck(boss.bossRect[0], playerRect.player)) {
		lifestruct.lifes = 0;
	}
	if (collisioncheck(playerRect.Bala, boss.bossRect[0])) {
		boss.healthPoints[0] -=1;
		boss.health[0] -= (float)5.1;
		//printf("%d\n", boss.healthPoints[0]);
		if (boss.healthPoints[0] == 0) {
			lifestruct.lifes = 3;
			boss.bossesKilled += 1;
			lifestruct.score += 1000;
			lifestruct.lifes = 3;
			lava.counter[0] = 50;
			lava.counter[1] = 50;
			ValorRects(&boss.bossRect[0], 0, 0, 0, 0);
			boss.hasSpawned[0] = 1;
			ValorRects(&lava.lavaRect[0], 0, 0, 0, 0);
			ValorRects(&lava.lavaRect[1], 0, 0, 0, 0);
			lifestruct.tempScore = lifestruct.score;
			if (boss.bossesKilled == 4) lifestruct.lifes = 5;
		}
	}
}

