#include "Functions.h"

SDL_Window* window = NULL;
//SDL_Renderer* levelmanagerstruct.rend = NULL;
//SDL_Renderer* TakeRenderer(void) { return levelmanagerstruct.rend; }


int main(int argc, char *argv[])
{
	InitRect();
	InitStruct();


	//No disparar al dar a "jugar"
	int canShoot = 0;

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow(
		"Enter the MUngeons",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);
	audioInit();
	initSound();
	playMusic();
	levelmanagerstruct.rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	InitSurfacesAndTextures();
	TTF_Init();
	lifestruct.score = 0;
	InitScore();

	SDL_Surface* iconoo = IMG_Load("resources/roguelike.png");
	SDL_SetWindowIcon(window, iconoo);
	SDL_FreeSurface(iconoo);

	menuSprites();
	levelmanagerstruct.hizkuntza = 1;


	// animation loop
	while (!levelmanagerstruct.close_requested)
	{
		//if (lifestruct.lifes == 0) Restart();

		if (levelmanagerstruct.playing == 1) {
			if (boss.bossesKilled == 4 && boss.sound[4] == 0) {
				boss.sound[4] = 1;
				loadTheMusic(".\\Sounds\\Music\\GritoCueva.mp3");
				playMusic();
			}
			if (canShoot == 60) {
				// Tiro
				AllyBulletCreation(&playerRect.player, &playerRect.Bala);
				MoveAllyBullet(&playerRect.Bala, enemySpawn.Enemy);
			}
			if (canShoot != 60)canShoot++;


			Enemydead();

			// Enemy Bullet Creation&Movement
			if (levelmanagerstruct.level != 0) {
				for (int i = 0; i <= MAXENEMY; i++)
				{
					if (EnemyV[i].BulletCreated == 0 && (EnemyV->stopenemycreation > 0)) {
						if ((EnemyV[i].FPSCounter > 50) && enemySpawn.bulletFCreated == 0) {
							BulletCreation(&enemySpawn.Enemy[i], &EnemyV[i], &enemySpawn.Bullet[i]);
							if (i <= MAXENEMY)enemySpawn.bulletFCreated = 1;
						}
						else if (enemySpawn.bulletFCreated == 1) {
							BulletCreation(&enemySpawn.Enemy[i], &EnemyV[i], &enemySpawn.Bullet[i]);
						}
					}
					MoveEnemyBullet(&enemySpawn.Enemy[i], &EnemyV[i], &enemySpawn.Bullet[i]);

				}
			}
			Enemydeadcounter();
			SumScore();
			
			boss.currentBoss = levelmanagerstruct.level;
		}
		ScoreRefresh();
		//printf("%d\n", boss.healthPoints[4]);
		wallCollision(playerRect.player, levelmanagerstruct.borde);
		windowCollision(playerRect.player);
	

		// set the positions in the struct
		playerRect.player.y = (int)posstruct.y;
		playerRect.player.x = (int)posstruct.x;
		if (EnemyV->stopenemycreation == 0)EnemyV->stopenemycreation = 3;
		// clear the window
		SDL_RenderClear(levelmanagerstruct.rend);

		// draw the image to the window
		if (levelmanagerstruct.playing == 2)GameOver();
		if (levelmanagerstruct.playing == 3)YouWin();
		if (levelmanagerstruct.playing == 0)menu();
		movement();
		if (ProtaB.aBulletCreated == 0) weaponSelector();
		if (levelmanagerstruct.playing == 1) {
			levelManager();
			if (!lifestruct.invencivilty) {
				SDL_RenderCopy(levelmanagerstruct.rend, charactersstruct.player_texture, NULL, &playerRect.player);
			}
			else if (lifestruct.invencivilty && levelmanagerstruct.level == 0 && boss.bossesKilled != 4) {
				SDL_RenderCopy(levelmanagerstruct.rend, charactersstruct.player_texture, NULL, &playerRect.player);
			}
			else if (lifestruct.invencivilityFPS <= 120) {
				SDL_RenderCopy(levelmanagerstruct.rend, charactersstruct.playerInvencivility_texture, NULL, &playerRect.player);
			}

			if(levelmanagerstruct.level==1 || levelmanagerstruct.level == 5 || levelmanagerstruct.level == 6)LevelLavaAnim();
			if (levelmanagerstruct.level == 3 || levelmanagerstruct.level == 8 || levelmanagerstruct.level == 9)LevelSnowAnim();
			if (levelmanagerstruct.level == 4 || levelmanagerstruct.level == 10 || levelmanagerstruct.level == 2 || levelmanagerstruct.level == 7)levelDefaultAnim();

			SDL_RenderCopy(levelmanagerstruct.rend, charactersstruct.playerBullet_texture, NULL, &playerRect.Bala);
			life();
			if (levelmanagerstruct.level == 6) {
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossTex[0], NULL, &boss.bossRect[0]);
				if (lava.lavaHasBeenCreated[0] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, lava.lavaTex[0], NULL, &lava.lavaRect[0]);
				}
				if (lava.lavaHasBeenCreated[1] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, lava.lavaTex[1], NULL, &lava.lavaRect[1]);
				}
				SDL_RenderCopy(levelmanagerstruct.rend, lava.lavaTex[2], NULL, &boss.bossLifeFrame);
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossHealthTex[0], NULL, &boss.bossLife);
				if (boss.hasSpawned[0]) enemySpawn.enemykilled[6] = 1;
			}
			if (levelmanagerstruct.level == 10) {
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossTex[1], NULL, &boss.bossRect[1]);
				if (esq.esqHasBeenCreated[0] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, esq.esqTex[0], NULL, &esq.esqRect[0]);
				}
				if (esq.esqHasBeenCreated[1] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, esq.esqTex[1], NULL, &esq.esqRect[1]);
				}
				SDL_RenderCopy(levelmanagerstruct.rend, lava.lavaTex[2], NULL, &boss.bossLifeFrame);
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossHealthTex[0], NULL, &boss.bossLife);
				if (boss.hasSpawned[1]) enemySpawn.enemykilled[10] = 1;
			}

			if (levelmanagerstruct.level == 9) {
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossTex[2], NULL, &boss.bossRect[2]);
				if (nieve.nieveHasBeenCreated[0] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, nieve.nieveTex[0], NULL, &nieve.nieveRect[0]);
				}
				if (nieve.nieveHasBeenCreated[1] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, nieve.nieveTex[1], NULL, &nieve.nieveRect[1]);
				}
				SDL_RenderCopy(levelmanagerstruct.rend, lava.lavaTex[2], NULL, &boss.bossLifeFrame);
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossHealthTex[0], NULL, &boss.bossLife);
				if (boss.hasSpawned[2]) enemySpawn.enemykilled[9] = 1;
			}

			if (levelmanagerstruct.level == 7) {
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossTex[3], NULL, &boss.bossRect[3]);
				if (arbol.arbolHasBeenCreated[0] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, arbol.arbolTex[0], NULL, &arbol.arbolRect[0]);
				}
				if (arbol.arbolHasBeenCreated[1] == 1) {
					SDL_RenderCopy(levelmanagerstruct.rend, arbol.arbolTex[1], NULL, &arbol.arbolRect[1]);
				}
				SDL_RenderCopy(levelmanagerstruct.rend, lava.lavaTex[2], NULL, &boss.bossLifeFrame);
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossHealthTex[0], NULL, &boss.bossLife);
				if (boss.hasSpawned[3]) enemySpawn.enemykilled[7] = 1;
			}
			if (levelmanagerstruct.level == 0 && boss.bossesKilled == 4) {
				if(boss.healthPoints[4]>200)SDL_RenderCopy(levelmanagerstruct.rend, boss.bossTex[4], NULL, &boss.bossRect[4]);
					else if (boss.healthPoints[4]<=200 && boss.healthPoints[4]>100)SDL_RenderCopy(levelmanagerstruct.rend, boss.bossTex[5], NULL, &boss.bossRect[4]);
					else if (boss.healthPoints[4] <= 100)SDL_RenderCopy(levelmanagerstruct.rend, boss.bossTex[6], NULL, &boss.bossRect[4]);
				
				if (boss.healthPoints[4] > 100) {
					if (final.finalHasBeenCreated[0] == 1) {
						SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[0], NULL, &final.finalRect[0]);
					}
					if (final.finalHasBeenCreated[1] == 1) {
						SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[1], NULL, &final.finalRect[1]);
					}
				}
				else if (boss.healthPoints[4] < 101 && boss.healthPoints[4] > 0) {
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[0], NULL, &final.finalRect[0]);
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[1], NULL, &final.finalRect[1]);
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[2], NULL, &final.finalRect[2]);
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[3], NULL, &final.finalRect[3]);
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[4], NULL, &final.finalRect[4]);
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[5], NULL, &final.finalRect[5]);
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[6], NULL, &final.finalRect[6]);
					SDL_RenderCopy(levelmanagerstruct.rend, final.finalTex[7], NULL, &final.finalRect[7]);
				}
				SDL_RenderCopy(levelmanagerstruct.rend, lava.lavaTex[2], NULL, &boss.bossLifeFrame);
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossHealthTex[0], NULL, &boss.bossLife3);
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossHealthTex[1], NULL, &boss.bossLife2);
				SDL_RenderCopy(levelmanagerstruct.rend, boss.bossHealthTex[2], NULL, &boss.bossLife);
				if (boss.hasSpawned[0]) enemySpawn.enemykilled[0] = 1;

			}


			EnemyTexture();
			
		}
		if (weaponStruct.shotgunTex && levelmanagerstruct.level == 0 && boss.bossesKilled != 4 && levelmanagerstruct.playing == 1) SDL_RenderCopy(levelmanagerstruct.rend, marco.texture[0], NULL, NULL);
		if (weaponStruct.sniperTex && levelmanagerstruct.level == 0 && boss.bossesKilled != 4 && levelmanagerstruct.playing == 1) SDL_RenderCopy(levelmanagerstruct.rend, marco.texture[1], NULL, NULL);
		showWeapon();
		if (levelmanagerstruct.playing == 1) {
			SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.Message[0], NULL, &lifestruct.Message_rect[0]);
		}
		else if ((levelmanagerstruct.playing == 2 || levelmanagerstruct.playing == 3))
		{
			SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.Message[0], NULL, &lifestruct.Message_rect[0]);
			SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.Message[1], NULL, &lifestruct.Message_rect[1]);
			SDL_RenderCopy(levelmanagerstruct.rend, lifestruct.Message[2], NULL, &lifestruct.Message_rect[2]);
		}

		//printf("%d\n", lifestruct.constantFPScounter);
		SDL_RenderPresent(levelmanagerstruct.rend);

		// wait 1/60th of a second
		SDL_Delay(1000 / 60);
		FPSCounter();

	}
	for (int i = 0; i <= MAXENEMY; i++)
	{
		SDL_DestroyTexture(charactersstruct.EnemyTex[i]);
		SDL_DestroyTexture(charactersstruct.EBulletTex[i]);
	}
	SDL_DestroyTexture(boss.bossTex[0]);
	SDL_DestroyTexture(lava.lavaTex[0]);
	SDL_DestroyTexture(lava.lavaTex[1]);
	TTF_Quit();

	SDL_DestroyRenderer(levelmanagerstruct.rend);
	audioTerminate();
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

