
#include "Functions.h"





void CreateEnemy(SDL_Rect* Enemy) {

	int x = 0;
	x = rand() % 400;
	int y = 0;
	y = rand() % 250;
	while (x < 200 || y < 150) {
		if (x < 200) x = rand() % 400;
		if (y < 150)y = rand() % 250;
	}

	Enemy->x = x;
	Enemy->y = y;
	Enemy->h = 40;
	Enemy->w = 40;
}

void SpawnEnemy (void)
{
	if (!enemySpawn.hasSpawned[levelmanagerstruct.level]) {
		EnemyV->stopenemycreation = 3;
	}
	//enemySpawn.hasSpawned[levelmanagerstruct.level] = 0;
	// Enemy creation
	srand(time(0));
	if ((EnemyV->stopenemycreation) == 3) {
		for (int i = 0; i <= MAXENEMY; i++)
		{
			CreateEnemy(&enemySpawn.Enemy[i]);
			if (i == MAXENEMY) EnemyV->stopenemycreation = 1;
			// Enemy Detection Area Creation
		}
	}
	else if (EnemyV->stopenemycreation == 1)
	{
		// Enemy movement
		for (int i = 0; i <= MAXENEMY; i++)
		{
			MoveEnemy(&enemySpawn.Enemy[i], levelmanagerstruct.borde, &EnemyV[i]);
		}
	}

}

void MoveEnemy(SDL_Rect* Enemy, SDL_Rect* borde, EnemyVe* EnemyV) {
	int collisionWall = 0;
	int collisionEnem = 0;
	int Wall;
	for (int i = 0; i <= MAXRECTS; i++)
	{
		if (collisioncheck(*Enemy, borde[i]) == 1) {
			Wall = i;
			collisionWall = 1;
		}
	}
	if ((collisionWall == 1)) {
		switch (Wall)
		{
		case (int)0:
			(*EnemyV).v_x *= -1;
			break;
		case(int)1:
			(*EnemyV).v_y *= -1;
			break;
		case(int)2:
			(*EnemyV).v_x *= -1;
			break;
		case(int)3:
			(*EnemyV).v_y *= -1;
			break;
		default:
			break;
		}
	}
	Enemy->x += (*EnemyV).v_x;
	Enemy->y += (*EnemyV).v_y;
}
void BulletCreation(SDL_Rect* dest, SDL_Rect* Enemy, EnemyVe* EnemyV, SDL_Rect* Bullet) {
	float distance;
	if ((*EnemyV).BulletCreated == 0 && (*EnemyV).CanCreateB == 0) {
		(*Bullet).h = 10;
		(*Bullet).w = 10;
		(*Bullet).x = (*Enemy).x + ((*Enemy).w / 2);
		(*Bullet).y = (*Enemy).y + ((*Enemy).h / 2);
		(*EnemyV).BulletCreated = 1;
		(*EnemyV).BulletDelta_x = ((*dest).x + ((*dest).w / 2)) - (*Bullet).x;
		(*EnemyV).BulletDelta_y = ((*dest).y + ((*dest).h / 2)) - (*Bullet).y;
		distance = sqrt((*EnemyV).BulletDelta_x*(*EnemyV).BulletDelta_x + (*EnemyV).BulletDelta_y*(*EnemyV).BulletDelta_y);
		(*EnemyV).BulletVel_x = ((*EnemyV).BulletDelta_x*(SPEED)) / distance;
		(*EnemyV).BulletVel_y = ((*EnemyV).BulletDelta_y*(SPEED)) / distance;
		(*EnemyV).BulletPos_x = (*Bullet).x;
		(*EnemyV).BulletPos_y = (*Bullet).y;
		(*EnemyV).FPSCounter = 0;
	}
}
void MoveEnemyBullet(SDL_Rect* Enemy, EnemyVe* EnemyV, SDL_Rect* Bullet, SDL_Rect* borde, SDL_Rect* dest) {
	if ((*EnemyV).BulletCreated == 1 && (*EnemyV).CanCreateB == 0) 
		{
		(*EnemyV).BulletPos_x += (*EnemyV).BulletVel_x / 60;
		(*EnemyV).BulletPos_y += (*EnemyV).BulletVel_y / 60;
		(*Bullet).x = (int)(*EnemyV).BulletPos_x;
		(*Bullet).y = (int)(*EnemyV).BulletPos_y;
		if ((collisioncheck((*Bullet), (*dest))) == 1) (*EnemyV).BulletCreated = 0;
		if ((*EnemyV).FPSCounter == BulletTTL) (*EnemyV).BulletCreated = 0;
	}
}

void Enemydead(SDL_Rect* Enemy, EnemyVe* EnemyV, SDL_Rect* Bullet) {
	for (int i = 0; i <= MAXENEMY; i++)
	{

		if (EnemyV[i].HP == 0) {
			Enemy[i].h = 0;
			Enemy[i].w = 0;
			EnemyV[i].CanCreateB = 1;
			if ((levelmanagerstruct.level == 1 || levelmanagerstruct.level == 5) && EnemyV[i].deeadSound == 0) {
				playSound(7);
				EnemyV[i].deeadSound = 1;
			}
			if (levelmanagerstruct.level == 2 && EnemyV[i].deeadSound == 0) {
				playSound(8);
				EnemyV[i].deeadSound = 1;
			}
			if ((levelmanagerstruct.level == 3 || levelmanagerstruct.level == 8) && EnemyV[i].deeadSound == 0) {
				playSound(6);
				EnemyV[i].deeadSound = 1;
			}
			if (levelmanagerstruct.level == 4 && EnemyV[i].deeadSound == 0) {
				playSound(5);
				EnemyV[i].deeadSound = 1;
			}
			//Enemy[i].x = 10000;
			//Enemy[i].y = 10000;
			

		}
		if ((EnemyV[i]).CanCreateB == 1) {
			(Bullet[i]).h = 0;
			(Bullet[i]).w = 0;
		}
	}

}

void Enemydeadcounter(void) {
	int Deadcounter = 0;
	for (int i = 0; i <= MAXENEMY; i++)
	{
		if (EnemyV[i].HP == 0)Deadcounter += 1;
	}
	//printf("%d \n", Deadcounter);
	if (Deadcounter == MAXENEMY +1)enemySpawn.enemykilled[levelmanagerstruct.level] = 1;
}

void EnemyTexture(void) {
	if (levelmanagerstruct.level == 1 || levelmanagerstruct.level == 5) {
		if (!enemySpawn.hasSkinChanged) {
			charactersstruct.enemy_surface = IMG_Load("resources/Enemies/lavaEnemy.png");
			charactersstruct.EBullet_surface = IMG_Load("resources/Enemies/lavaTiro.png");

			for (int i = 0; i <= MAXENEMY; i++)
			{
				charactersstruct.EBulletTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.EBullet_surface);
				charactersstruct.EnemyTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.enemy_surface);
			}
			enemySpawn.hasSkinChanged = 1;
		}
		if (enemySpawn.enemyController[levelmanagerstruct.level]) {
			for (int i = 0; i <= MAXENEMY; i++)
			{
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EnemyTex[i], NULL, &enemySpawn.Enemy[i]);
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EBulletTex[i], NULL, &enemySpawn.Bullet[i]);
			}
			enemySpawn.hasSkinChanged = 1;
			
		}
	}
	if (levelmanagerstruct.level == 2) {
		if (!enemySpawn.hasSkinChanged) {
			charactersstruct.enemy_surface = IMG_Load("resources/Enemies/verdeEnemy.png");
			charactersstruct.EBullet_surface = IMG_Load("resources/Enemies/verdeTiro.png");

			for (int i = 0; i <= MAXENEMY; i++)
			{
				charactersstruct.EBulletTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.EBullet_surface);
				charactersstruct.EnemyTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.enemy_surface);
			}
			enemySpawn.hasSkinChanged = 1;
		}
		if (enemySpawn.enemyController[levelmanagerstruct.level]) {
			for (int i = 0; i <= MAXENEMY; i++)
			{
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EnemyTex[i], NULL, &enemySpawn.Enemy[i]);
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EBulletTex[i], NULL, &enemySpawn.Bullet[i]);
			}
		}
	}
	if (levelmanagerstruct.level == 3 || levelmanagerstruct.level == 8) {
		if (!enemySpawn.hasSkinChanged) {
			charactersstruct.enemy_surface = IMG_Load("resources/Enemies/nieveEnemy.png");
			charactersstruct.EBullet_surface = IMG_Load("resources/Enemies/nieveTiro.png");

			for (int i = 0; i <= MAXENEMY; i++)
			{
				charactersstruct.EBulletTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.EBullet_surface);
				charactersstruct.EnemyTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.enemy_surface);
			}
			enemySpawn.hasSkinChanged = 1;
		}
		if (enemySpawn.enemyController[levelmanagerstruct.level]) {
			for (int i = 0; i <= MAXENEMY; i++)
			{
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EnemyTex[i], NULL, &enemySpawn.Enemy[i]);
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EBulletTex[i], NULL, &enemySpawn.Bullet[i]);
			}
		}
	}
	if (levelmanagerstruct.level == 4 ) {
		if (!enemySpawn.hasSkinChanged) {
			charactersstruct.enemy_surface = IMG_Load("resources/Enemies/dungeonEnemy.png");
			charactersstruct.EBullet_surface = IMG_Load("resources/Enemies/defaultTiro.png");

			for (int i = 0; i <= MAXENEMY; i++)
			{
				charactersstruct.EBulletTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.EBullet_surface);
				charactersstruct.EnemyTex[i] = SDL_CreateTextureFromSurface(TakeRenderer(), charactersstruct.enemy_surface);
			}
			enemySpawn.hasSkinChanged = 1;
		}
		if (enemySpawn.enemyController[levelmanagerstruct.level]) {
			for (int i = 0; i <= MAXENEMY; i++)
			{
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EnemyTex[i], NULL, &enemySpawn.Enemy[i]);
				SDL_RenderCopy(TakeRenderer(), charactersstruct.EBulletTex[i], NULL, &enemySpawn.Bullet[i]);
			}
		}
	}

}
