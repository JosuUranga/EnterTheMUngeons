#include "Functions.h"

void InitStruct(void) {

	levelmanagerstruct.level = 0;
	lifestruct.lifes = PROTAHP;
	ProtaB.aBulletCreated = 0;
	ProtaB.aFPSCounter = 0;
	EnemyV->stopenemycreation = 0;
	enemySpawn.hasSkinChanged = 0;
	enemySpawn.bulletFCreated = 0;
	lifestruct.invencivilityFPS = 0;
	lifestruct.invencivilty = 0;
	lavaBossCreation();
	bossEsqueletoCreation();
	bossNieveCreation();
	bossArbolCreation();
	bossFinalCreation();
	boss.bossesKilled = 0;
	lifestruct.score = 0;
	ProtaB.aBulletTTL = 10;
	lifestruct.dieFPS = 0;
	lifestruct.restartFPS = 0;
	final.fase3 = 0;
	levelAnim.fadeCounter = 1;
	levelAnim.fade = 0;
	levelAnim.snowFPS = 0;
	levelAnim.snowAnim = 1;
	levelAnim.defaultFPS = 0;
	levelAnim.defaultAnim = 1;
	lifestruct.GameOver = 0;
	lifestruct.constantFPScounter = 0;
	winOrDie.goMusic = 0;
	lifestruct.tempScore = 0;


	weaponStruct.shotgunTex = 1;
	weaponStruct.sniperTex = 0;

	for (int i = 0; i <= 11; i++)
	{
		enemySpawn.hasSpawned[i] = 0;
		enemySpawn.enemykilled[i] = 0;
		//printf("%d\n", enemySpawn.enemykilled[i]);
	}

	for (int i = 0; i <= MAXENEMY; i++)
	{
		if (i % 2 == 0) {
			EnemyV[i].v_x = 1;
			EnemyV[i].v_y = 1;
		}
		else
		{
			EnemyV[i].v_x = -1;
			EnemyV[i].v_y = -1;
		}
		EnemyV[i].numb = i;
		EnemyV[i].BulletCreated = 0;
		EnemyV[i].FPSCounter = 0;

		EnemyV[i].CanCreateB = 0;
		EnemyV[i].HP = 3;
		enemySpawn.enemyL[i] = 1;
	}
	// start sprite in center of screen
	posstruct.x = (float)(WINDOW_WIDTH - playerRect.player.w) / 2;
	posstruct.y = (float)(WINDOW_HEIGHT - playerRect.player.h) / 2;
	posstruct.x_vel = 0;
	posstruct.y_vel = 0;

	// keep track of which inputs are given
	posstruct.up = 0;
	posstruct.down = 0;
	posstruct.left = 0;
	posstruct.right = 0;


	// set to 1 when window close button is pressed
	levelmanagerstruct.close_requested = 0;

	levelmanagerstruct.case1x = (WINDOW_WIDTH - playerRect.player.w) / 2;
	levelmanagerstruct.case2x = 60;
	levelmanagerstruct.case3x = (WINDOW_WIDTH - playerRect.player.w) / 2;
	levelmanagerstruct.case4x = 550;
	levelmanagerstruct.case1y = 390;
	levelmanagerstruct.case2y = (WINDOW_HEIGHT - playerRect.player.h) / 2;
	levelmanagerstruct.case3y = 60;
	levelmanagerstruct.case4y = (WINDOW_HEIGHT - playerRect.player.h) / 2;

	//sniper/shotgun
	weaponStruct.shotgun = 0;
	weaponStruct.sniper = 0;
}