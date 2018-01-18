#include "bosses.h"
#include "Functions.h"

void lavaBoss(void) {
	boss.bossRect[0].x += boss.bossVelX[0];

	if (boss.bossRect[0].x > 500) {
		boss.bossVelX[0] *= -1;
	}
	if (boss.bossRect[0].x < 40) {
		boss.bossVelX[0] *= -1;
	}

}

void lavaBossCreation(void) {
	boss.bossRect[0].h = 100;
	boss.bossRect[0].w = 100;
	boss.bossRect[0].x = 50;
	boss.bossRect[0].y = 50;
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
			lava.lavaRect[0].h = 26;
			lava.lavaRect[0].w = 26;
			lava.lavaRect[0].x = boss.bossRect[0].x + 50;
			lava.lavaRect[0].y = boss.bossRect[0].y + 80;
			lava.lavaVelY[0] = ATAQUEVEL;
			lava.lavaHasBeenCreated[0] = 1;

		}
		if (lava.lavaHasBeenCreated[1] == 0 && lava.counter[1] == 0) {
			lava.lavaRect[1].h = 26;
			lava.lavaRect[1].w = 26;
			lava.lavaRect[1].x = boss.bossRect[0].x + 50;
			lava.lavaRect[1].y = boss.bossRect[0].y + 80;
			lava.lavaVelY[1] = ATAQUEVEL;
			lava.lavaHasBeenCreated[1] = 1;

		}
	}
		lavaAtakeakMugitu(TakeRenderer(), playerRect.player, playerRect.Bala);
}
void lavaAtakeakMugitu(void) {
	if (lava.counter[0] <= LAVATTL && lava.counter[1] <= LAVATTL) {
		lava.counter[0]++;
		lava.counter[1]++;
	}

	if (lava.lavaHasBeenCreated[0] == 1) {
		lava.lavaRect[0].y += lava.lavaVelY[0];
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
		lava.lavaRect[1].y += lava.lavaVelY[1];
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
		boss.health[0] -= 5.1;
		//printf("%d\n", boss.healthPoints[0]);
		if (boss.healthPoints[0] == 0) {
			lifestruct.lifes = 3;
			boss.bossesKilled += 1;
			lifestruct.score += 1000;
			lifestruct.lifes = 3;
			lava.counter[0] = 50;
			lava.counter[1] = 50;
			boss.bossRect[0].w = 0;
			boss.bossRect[0].h = 0;
			boss.hasSpawned[0] = 1;
			lava.lavaRect[0].w = 0;
			lava.lavaRect[1].w = 0;
			lava.lavaRect[0].h = 0;
			lava.lavaRect[0].h = 0;
			if (boss.bossesKilled == 4) lifestruct.lifes = 5;
		}
	}
}

