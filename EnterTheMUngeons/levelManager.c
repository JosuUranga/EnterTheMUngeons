#include "Functions.h"



void levelManager(void) {

	if (levelmanagerstruct.level == 0) {
		enemySpawn.enemykilled[0] = 1;
		levelmanagerstruct.door1ON = 1;
		levelmanagerstruct.door2ON = 1;
		levelmanagerstruct.door3ON = 1;
		levelmanagerstruct.door4ON = 1;
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
					SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[0], NULL, NULL);
					break;
				case(2):
					SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[11], NULL, NULL);
					break;
				case(3):
					SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[12], NULL, NULL);
					break;
				default:
					SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[0], NULL, NULL);
					break;
				}
				
				lifestruct.invencivilty = 1;
			}
			else {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[0], NULL, NULL);
				if (boss.hasSpawned[4] == 0) {
					finalBoss();
					finalAtakeakSortu(playerRect.player, playerRect.Bala);
					boss.bossLifeFrame.w = boss.bossRect[4].w;
					boss.bossLifeFrame.h = 20;//6
					boss.bossLifeFrame.x = boss.bossRect[4].x;
					boss.bossLifeFrame.y = boss.bossRect[4].y - 20;
					boss.bossLife.w = final.health[0];
					boss.bossLife.h = 9;
					boss.bossLife.x = boss.bossRect[4].x + 16;
					boss.bossLife.y = boss.bossRect[4].y - 14;
					boss.bossLife2.w = final.health[1];
					boss.bossLife2.h = 9;
					boss.bossLife2.x = boss.bossRect[4].x + 16;
					boss.bossLife2.y = boss.bossRect[4].y - 14;
					boss.bossLife3.w = final.health[2];
					boss.bossLife3.h = 9;
					boss.bossLife3.x = boss.bossRect[4].x + 16;
					boss.bossLife3.y = boss.bossRect[4].y - 14;
					enemySpawn.enemykilled[0] = 0;
				}
			}
			break;

		case 1:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[1], NULL, NULL);
			posstruct.x = levelmanagerstruct.case1x;
			posstruct.y = levelmanagerstruct.case1y;
			printf("Entrando por puerta numero 1\n");
			levelmanagerstruct.level = 1;
			enemySpawn.enemyController[1] = 1;
			enemySpawn.enemyL[1] = 1;
			resetBullet();
			lifestruct.invencivilty = 0;
			return;
			break;
		case 2:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[4], NULL, NULL);
			posstruct.x = levelmanagerstruct.case2x;
			posstruct.y = levelmanagerstruct.case2y;
			levelmanagerstruct.level = 2;
			enemySpawn.enemyL[2] = 1;
			enemySpawn.enemyController[2] = 1;
			resetBullet();
			printf("Entrando por puerta numero 2\n");
			lifestruct.invencivilty = 0;
			return;
			break;
		case 3:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[6], NULL, NULL);
			posstruct.x = levelmanagerstruct.case3x;
			posstruct.y = levelmanagerstruct.case3y;
			levelmanagerstruct.level = 3;
			enemySpawn.enemyL[3] = 1;
			enemySpawn.enemyController[3] = 1;
			resetBullet();
			printf("Entrando por puerta numero 3\n");
			lifestruct.invencivilty = 0;
			return;
			break;
		
		case 4:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[9], NULL, NULL);
			posstruct.x = levelmanagerstruct.case4x;
			posstruct.y = levelmanagerstruct.case4y;
			levelmanagerstruct.level = 4;
			enemySpawn.enemyL[4] = 1;
			enemySpawn.enemyController[4] = 1;
			resetBullet();
			printf("Entrando por puerta numero 4\n");
			lifestruct.invencivilty = 0;
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 1) {
		levelmanagerstruct.door1ON = 0;
		levelmanagerstruct.door2ON = 0;
		levelmanagerstruct.door3ON = 1;
		levelmanagerstruct.door4ON = 1;
		spawnTheEnemies();
		
		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[1], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[1], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 3:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[0], NULL, NULL);
			posstruct.x = levelmanagerstruct.case3x;
			posstruct.y = levelmanagerstruct.case3y;
			levelmanagerstruct.level = 0;
			enemySpawn.enemyController[1] = 0;
			enemySpawn.enemyController[0] = 0;
			resetBullet();
			if (boss.sound[5] == 0 && boss.bossesKilled == 4) {
				boss.sound[5] = 1;
				loadTheMusic(".\\Sounds\\Music\\FinalBoss.wav");
				playMusic();
				playSound(4);
			}
			printf("Entrando por puerta numero 3\n");
			return;
			break;
		case 4:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[2], NULL, NULL);
			posstruct.x = levelmanagerstruct.case4x;
			posstruct.y = levelmanagerstruct.case4y;
			printf("Entrando por puerta numero 4\n");
			levelmanagerstruct.level = 5;
			enemySpawn.enemyL[5] = 1;
			enemySpawn.enemyController[5] = 1;
			enemySpawn.enemyController[1] = 0;
			resetBullet();
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 2) {
		levelmanagerstruct.door1ON = 0;
		levelmanagerstruct.door2ON = 1;
		levelmanagerstruct.door3ON = 0;
		levelmanagerstruct.door4ON = 1;
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[4], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[4], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;

		case 2:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[5], NULL, NULL);
			posstruct.x = levelmanagerstruct.case2x;
			posstruct.y = levelmanagerstruct.case2y;
			printf("Entrando por puerta numero 2\n");
			levelmanagerstruct.level = 7;
			enemySpawn.enemyL[7] = 1;
			enemySpawn.enemyController[2] = 0;
			enemySpawn.enemyController[7] = 1;
			resetBullet();
			return;
			break;

		case 4:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[0], NULL, NULL);
			posstruct.x = levelmanagerstruct.case4x;
			posstruct.y = levelmanagerstruct.case4y;
			printf("Entrando por puerta numero 4\n");
			levelmanagerstruct.level = 0;
			enemySpawn.enemyController[2] = 0;
			resetBullet();
			if (boss.sound[5] == 0 && boss.bossesKilled == 4) {
				boss.sound[5] = 1;
				loadTheMusic(".\\Sounds\\Music\\FinalBoss.wav");
				playMusic();
				playSound(4);
			}
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 3) {
		levelmanagerstruct.door1ON = 1;
		levelmanagerstruct.door2ON = 1;
		levelmanagerstruct.door3ON = 0;
		levelmanagerstruct.door4ON = 0;
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[6], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[6], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 1:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[0], NULL, NULL);
			posstruct.x = levelmanagerstruct.case1x;
			posstruct.y = levelmanagerstruct.case1y;
			printf("Entrando por puerta numero 1\n");
			levelmanagerstruct.level = 0;
			enemySpawn.enemyController[3] = 0;
			resetBullet();
			if (boss.sound[5] == 0 && boss.bossesKilled == 4) {
				boss.sound[5] = 1;
				loadTheMusic(".\\Sounds\\Music\\FinalBoss.wav");
				playMusic();
				playSound(4);
			}
			return;
			break;
		case 2:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[7], NULL, NULL);
			posstruct.x = levelmanagerstruct.case2x;
			posstruct.y = levelmanagerstruct.case2y;
			printf("Entrando por puerta numero 2\n");
			enemySpawn.enemyL[8] = 1;
			enemySpawn.enemyController[3] = 0;
			enemySpawn.enemyController[8] = 1;
			levelmanagerstruct.level = 8;
			resetBullet();
			break;

		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 4) {
		levelmanagerstruct.door1ON = 0;
		levelmanagerstruct.door2ON = 1;
		levelmanagerstruct.door3ON = 0;
		levelmanagerstruct.door4ON = 1;
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[9], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[9], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 2:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[0], NULL, NULL);
			posstruct.x = levelmanagerstruct.case2x;
			posstruct.y = levelmanagerstruct.case2y;
			printf("Entrando por puerta numero 2\n");
			levelmanagerstruct.level = 0;
			enemySpawn.enemyController[4] = 0;
			resetBullet();
			if (boss.sound[5] == 0 && boss.bossesKilled == 4) {
				boss.sound[5] = 1;
				loadTheMusic(".\\Sounds\\Music\\FinalBoss.wav");
				playMusic();
				playSound(4);
			}
			return;
			break;
		case 4:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[10], NULL, NULL);
			posstruct.x = levelmanagerstruct.case4x;
			posstruct.y = levelmanagerstruct.case4y;
			printf("Entrando por puerta numero 4\n");
			enemySpawn.enemyL[10] = 1;
			levelmanagerstruct.level = 10;
			enemySpawn.enemyController[10] = 1;
			enemySpawn.enemyController[4] = 0;
			resetBullet();
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 5) {
		levelmanagerstruct.door1ON = 1;
		levelmanagerstruct.door2ON = 1;
		levelmanagerstruct.door3ON = 0;
		levelmanagerstruct.door4ON = 0;
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[2], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[2], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 1:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[3], NULL, NULL);
			posstruct.x = levelmanagerstruct.case1x;
			posstruct.y = levelmanagerstruct.case1y;
			printf("Entrando por puerta numero 1\n");
			levelmanagerstruct.level = 6;
			enemySpawn.enemyL[6] = 1;
			enemySpawn.enemyController[5] = 0;
			enemySpawn.enemyController[6] = 1;
			resetBullet();
			return;
			break;
		case 2:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[1], NULL, NULL);
			posstruct.x = levelmanagerstruct.case2x;
			posstruct.y = levelmanagerstruct.case2y;
			printf("Entrando por puerta numero 2\n");
			enemySpawn.enemyController[5] = 0;
			levelmanagerstruct.level = 1;
			resetBullet();
			return;
			break;

		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 6) {
		levelmanagerstruct.door1ON = 0;
		levelmanagerstruct.door2ON = 0;
		levelmanagerstruct.door3ON = 1;
		levelmanagerstruct.door4ON = 0;

		if (boss.hasSpawned[0] == 0) {
			lavaBoss();
			lavaAtakeakSortu(TakeRenderer(), playerRect.player, playerRect.Bala);
			boss.bossLifeFrame.w = 320;
			boss.bossLifeFrame.h = 20;
			boss.bossLifeFrame.x = 160;
			boss.bossLifeFrame.y = 10;
			boss.bossLife.w = boss.health[0];
			boss.bossLife.h = 9;
			boss.bossLife.x = 193;
			boss.bossLife.y = 16;
			enemySpawn.enemykilled[6] = 0;
			if (boss.sound[0] == 0) { 
			playSound(2); 
			boss.sound[0] = 1;
			}
		}


		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[3], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[3], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 3:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[2], NULL, NULL);
			posstruct.x = levelmanagerstruct.case3x;
			posstruct.y = levelmanagerstruct.case3y;
			levelmanagerstruct.level = 5;
			enemySpawn.enemyController[6] = 0;
			printf("Entrando por puerta numero 3\n");
			resetBullet();
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 7) {
		levelmanagerstruct.door1ON = 0;
		levelmanagerstruct.door2ON = 0;
		levelmanagerstruct.door3ON = 0;
		levelmanagerstruct.door4ON = 1;
		if (boss.hasSpawned[3] == 0) {
			arbolAtakeakSortu(playerRect.player, playerRect.Bala);
			boss.bossLifeFrame.w = 320;
			boss.bossLifeFrame.h = 20;
			boss.bossLifeFrame.x = 160;
			boss.bossLifeFrame.y = 10;
			boss.bossLife.w = boss.health[1];
			boss.bossLife.h = 9;
			boss.bossLife.x = 193;
			boss.bossLife.y = 16;
			enemySpawn.enemykilled[7] = 0;
			if (boss.sound[3] == 0) {
				playSound(3);
				boss.sound[3] = 1;
			}
		}

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[5], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[5], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 4:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[4], NULL, NULL);
			posstruct.x = levelmanagerstruct.case4x;
			posstruct.y = levelmanagerstruct.case4y;
			printf("Entrando por puerta numero 4\n");
			levelmanagerstruct.level = 2;
			enemySpawn.enemyController[7] = 0;
			resetBullet();
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 8) {
		levelmanagerstruct.door1ON = 0;
		levelmanagerstruct.door2ON = 0;
		levelmanagerstruct.door3ON = 1;
		levelmanagerstruct.door4ON = 1;
		spawnTheEnemies();

		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[7], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[7], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 3:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[8], NULL, NULL);
			posstruct.x = levelmanagerstruct.case3x;
			posstruct.y = levelmanagerstruct.case3y;
			printf("Entrando por puerta numero 1\n");
			enemySpawn.enemyL[9] = 1;
			levelmanagerstruct.level = 9;
			enemySpawn.enemyController[9] = 1;
			enemySpawn.enemyController[8] = 0;
			resetBullet();
			return;
			break;
		case 4:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[6], NULL, NULL);
			posstruct.x = levelmanagerstruct.case4x;
			posstruct.y = levelmanagerstruct.case4y;
			printf("Entrando por puerta numero 2\n");
			enemySpawn.enemyController[8] = 0;
			levelmanagerstruct.level = 3;
			resetBullet();
			break;

		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 9) {
		levelmanagerstruct.door1ON = 1;
		levelmanagerstruct.door2ON = 0;
		levelmanagerstruct.door3ON = 0;
		levelmanagerstruct.door4ON = 0;
		if (boss.hasSpawned[2] == 0) {
			nieveBoss();
			nieveAtakeakSortu(playerRect.player, playerRect.Bala);
			boss.bossLifeFrame.w = 320;
			boss.bossLifeFrame.h = 20;
			boss.bossLifeFrame.x = 160;
			boss.bossLifeFrame.y = 450;
			boss.bossLife.w = boss.health[2];
			boss.bossLife.h = 9;
			boss.bossLife.x = 193;
			boss.bossLife.y = 456;
			enemySpawn.enemykilled[9] = 0;
			if (boss.sound[2] == 0) {
				playSound(1);
				boss.sound[2] = 1;
			}
		}


		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[8], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[8], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 1:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[7], NULL, NULL);
			posstruct.x = levelmanagerstruct.case1x;
			posstruct.y = levelmanagerstruct.case1y;
			printf("Entrando por puerta numero 1\n");
			levelmanagerstruct.level = 8;
			enemySpawn.enemyController[9] = 0;
			resetBullet();
			return;
			break;
		default:
			break;
		}
	}

	if (levelmanagerstruct.level == 10) {
		levelmanagerstruct.door1ON = 0;
		levelmanagerstruct.door2ON = 1;
		levelmanagerstruct.door3ON = 0;
		levelmanagerstruct.door4ON = 0;
		
		if (boss.hasSpawned[1] == 0) {
			esqBoss(playerRect.player);
			esqAtakeakSortu(TakeRenderer(), playerRect.player, playerRect.Bala);
			boss.bossLifeFrame.w = 320;
			boss.bossLifeFrame.h = 20;
			boss.bossLifeFrame.x = 160;
			boss.bossLifeFrame.y = 10;
			boss.bossLife.w = boss.health[3];
			boss.bossLife.h = 9;
			boss.bossLife.x = 193;
			boss.bossLife.y = 16;
			enemySpawn.enemykilled[10] = 0;
			if (boss.sound[1] == 0) {
				playSound(0);
				boss.sound[1] = 1;
			}
		}


		switch (doors())
		{
		case 0:
			if (!enemySpawn.enemykilled[levelmanagerstruct.level]) {
				SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[10], NULL, NULL);
			}
			else SDL_RenderCopy(TakeRenderer(), dooropenstruct.texturak[10], NULL, NULL);
			//printf("No entro por ninguna puerta\n");
			break;
		case 2:
			SDL_RenderCopy(TakeRenderer(), doorclosetruct.texturak[9], NULL, NULL);
			posstruct.x = levelmanagerstruct.case2x;
			posstruct.y = levelmanagerstruct.case2y;
			printf("Entrando por puerta numero 1\n");
			levelmanagerstruct.level = 4;
			enemySpawn.enemyController[10] = 0;
			resetBullet();
			return;
			break;
		default:
			break;
		}
	}

	return levelmanagerstruct.level;
}

void spawnTheEnemies() {
	if (enemySpawn.enemyL[levelmanagerstruct.level]) {
		SpawnEnemy();

		if (!enemySpawn.hasSpawned[levelmanagerstruct.level]) {
			for (int i = 0; i <= MAXENEMY; i++) {
				EnemyV[i].HP = 3;
				EnemyV[i].CanCreateB = 0;
				EnemyV[i].deeadSound = 0;
				EnemyV[i].killed = 0;
			}

			enemySpawn.enemykilled[levelmanagerstruct.level] = 0;
			enemySpawn.hasSkinChanged = 0;
		}
		enemySpawn.hasSpawned[levelmanagerstruct.level] = 1;
	}
}

void resetBullet() {
	for (int i = 0; i <= MAXENEMY; i++)
	{
		EnemyV[i].BulletCreated = 0;
		EnemyV[i].FPSCounter = 0;
		enemySpawn.bulletFCreated = 0;
		enemySpawn.Bullet[i].h = 0;
		enemySpawn.Bullet[i].w = 0;
	}
}