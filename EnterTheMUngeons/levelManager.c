#include "Functions.h"



void levelManager(void) {

	if (levelmanagerstruct.level == 0) {
		enemySpawn.enemykilled[0] = 1;
		levelmanagerstructdoors(1, 1, 1, 1);
		enemySpawn.enemyL[1] = 0;
		enemySpawn.enemyL[2] = 0;
		enemySpawn.enemyL[3] = 0;
		enemySpawn.enemyL[4] = 0;
		if (boss.bossesKilled == 4)enemySpawn.enemykilled[0] = 0;
		switch (doors())
		{
		case 0:
			if (boss.bossesKilled != 4) {
				switch (levelmanagerstruct.hizkuntza)
				{
				case (1):
					SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[0], NULL, NULL);
					break;
				case(2):
					SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[11], NULL, NULL);
					break;
				case(3):
					SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[12], NULL, NULL);
					break;
				default:
					SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[0], NULL, NULL);
					break;
				}
				
				lifestruct.invencivilty = 1;
			}
			else {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[0], NULL, NULL);
				if (boss.hasSpawned[4] == 0) {
					finalBoss();
				}
			}
			break;

		case 1:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[1], NULL, NULL);
			levelmanagerstructcaseprincipal(1, levelmanagerstruct.case1x, levelmanagerstruct.case1y);
			return;
			break;
		case 2:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[4], NULL, NULL);
			levelmanagerstructcaseprincipal(2, levelmanagerstruct.case2x, levelmanagerstruct.case2y);
			return;
			break;
		case 3:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[6], NULL, NULL);
			levelmanagerstructcaseprincipal(3, levelmanagerstruct.case3x, levelmanagerstruct.case3y);
			return;
			break;
		
		case 4:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[9], NULL, NULL);
			levelmanagerstructcaseprincipal(4, levelmanagerstruct.case4x, levelmanagerstruct.case4y);
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 1) {
		levelmanagerstructdoors(0, 0, 1, 1);

		spawnTheEnemies();
		
		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[1], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[1], NULL, NULL);
			break;
		case 3:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[0], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case3x, levelmanagerstruct.case3y,0);
			sonidobossfinal();
			return;
			break;
		case 4:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[2], NULL, NULL);
			levelmanagerstructcasenormal(5, levelmanagerstruct.case4x, levelmanagerstruct.case4y);
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 2) {
		levelmanagerstructdoors(0, 1, 0, 1);
		spawnTheEnemies();
		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[4], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[4], NULL, NULL);
			break;
		case 2:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[5], NULL, NULL);
			levelmanagerstructcasenormal(7, levelmanagerstruct.case2x, levelmanagerstruct.case2y);
			return;
			break;

		case 4:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[0], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case4x, levelmanagerstruct.case4y,0);
			sonidobossfinal();
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 3) {
		levelmanagerstructdoors(1, 1, 0,0);
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[6], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[6], NULL, NULL);
			break;
		case 1:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[0], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case1x, levelmanagerstruct.case1y,0);
			sonidobossfinal();
			return;
			break;
		case 2:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[7], NULL, NULL);
			levelmanagerstructcasenormal(8, levelmanagerstruct.case2x, levelmanagerstruct.case2y);
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 4) {
		levelmanagerstructdoors(0, 1, 0, 1);
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[9], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[9], NULL, NULL);
			break;
		case 2:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[0], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case2x, levelmanagerstruct.case2y,0);
			sonidobossfinal();
			return;
			break;
		case 4:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[10], NULL, NULL);
			levelmanagerstructcasenormal(10, levelmanagerstruct.case4x, levelmanagerstruct.case4y);
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 5) {
		levelmanagerstructdoors(1, 1, 0, 0);
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[2], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[2], NULL, NULL);
			break;
		case 1:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[3], NULL, NULL);
			levelmanagerstructcasenormal(6, levelmanagerstruct.case1x, levelmanagerstruct.case1y);
			return;
			break;
		case 2:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[1], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case2x, levelmanagerstruct.case2y,1);
			return;
			break;

		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 6) {
		levelmanagerstructdoors(0, 0, 1, 0);
		if (boss.hasSpawned[0] == 0) {
			lavaBoss();
			lavaAtakeakSortu();
			ValorRects(&boss.bossLifeFrame, 320, 20, 160,10);
			ValorRects(&boss.bossLife, (int)boss.health[0], 9, 193, 16);
			enemySpawn.enemykilled[6] = 0;
			sonidoboss(0, 2);
		}
		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[3], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[3], NULL, NULL);
			break;
		case 3:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[2], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case3x, levelmanagerstruct.case3y,5);
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 7) {
		levelmanagerstructdoors(0, 0, 0, 1);
		if (boss.hasSpawned[3] == 0) {
			arbolAtakeakSortu(playerRect.player, playerRect.Bala);
			ValorRects(&boss.bossLifeFrame, 320, 20, 160, 10);
			ValorRects(&boss.bossLife, (int)boss.health[1], 9, 193, 16);
			enemySpawn.enemykilled[7] = 0;
			sonidoboss(3, 3);
		}

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[5], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[5], NULL, NULL);
			break;
		case 4:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[4], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case4x, levelmanagerstruct.case4y,2);
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 8) {
		levelmanagerstructdoors(0, 0, 1, 1);
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[7], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[7], NULL, NULL);
			break;
		case 3:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[8], NULL, NULL);
			levelmanagerstructcasenormal(9, levelmanagerstruct.case3x, levelmanagerstruct.case3y);
			return;
			break;
		case 4:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[6], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case4x, levelmanagerstruct.case4y,3);
			break;

		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 9) {
		levelmanagerstructdoors(1, 0, 0, 0);
		if (boss.hasSpawned[2] == 0) {
			nieveBoss();
			nieveAtakeakSortu(playerRect.player, playerRect.Bala);
			ValorRects(&boss.bossLifeFrame, 320, 20, 160, 450);
			ValorRects(&boss.bossLife, (int)boss.health[2], 9, 193, 456);
			enemySpawn.enemykilled[9] = 0;
			sonidoboss(2,1);
		}


		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[8], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[8], NULL, NULL);
			break;
		case 1:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[7], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case1x, levelmanagerstruct.case1y,8);
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 10) {
		levelmanagerstructdoors(0, 1, 0, 0);
		
		if (boss.hasSpawned[1] == 0) {
			esqBoss(playerRect.player);
			esqAtakeakSortu(playerRect.player, playerRect.Bala);
			ValorRects(&boss.bossLifeFrame, 320, 20, 160, 10);
			ValorRects(&boss.bossLife, (int)boss.health[3], 9, 193, 16);
			enemySpawn.enemykilled[10] = 0;
			sonidoboss(1, 0);
		}


		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[10], NULL, NULL);
			}
			else SDL_RenderCopy(levelmanagerstruct.rend, dooropenstruct.texturak[10], NULL, NULL);
			break;
		case 2:
			SDL_RenderCopy(levelmanagerstruct.rend, doorclosetruct.texturak[9], NULL, NULL);
			levelmanagerstructcasevolverprincipal(levelmanagerstruct.case2x, levelmanagerstruct.case2y,4);
			return;
			break;
		default:
			break;
		}
	}

}

void levelmanagerstructdoors(int a, int b, int c, int d) {

	levelmanagerstruct.door1ON = a;
	levelmanagerstruct.door2ON =b;
	levelmanagerstruct.door3ON = c;
	levelmanagerstruct.door4ON = d;
}
void levelmanagerstructcaseprincipal(int a, int b, int c) {
	posstruct.x = (float)b;
	posstruct.y = (float)c;
	levelmanagerstruct.level = a;
	enemySpawn.enemyController[a] = 1;
	enemySpawn.enemyL[a] = 1;
	resetBullet();
	lifestruct.invencivilty = 0;
}
void levelmanagerstructcasenormal(int a, int b, int c) {
		posstruct.x = (float)b;
		posstruct.y = (float)c;
		enemySpawn.enemyL[a] = 1;
		enemySpawn.enemyController[a] = 1;
		enemySpawn.enemyController[levelmanagerstruct.level] = 0;
		levelmanagerstruct.level = a;
		resetBullet();
	}
void levelmanagerstructcasevolverprincipal(int b, int c,int a) {
	posstruct.x = (float)b;
	posstruct.y = (float)c;
	enemySpawn.enemyController[levelmanagerstruct.level] = 0;
	levelmanagerstruct.level = a;
	resetBullet();
}

void sonidobossfinal(void) {
	if (boss.sound[5] == 0 && boss.bossesKilled == 4) {
		boss.sound[5] = 1;
		loadTheMusic(".\\Sounds\\Music\\FinalBoss.wav");
		playMusic();
		playSound(4);
	}
}

void sonidoboss(int a, int b) {
	if (boss.sound[a] == 0) {
		playSound(b);
		boss.sound[a] = 1;
	}
}