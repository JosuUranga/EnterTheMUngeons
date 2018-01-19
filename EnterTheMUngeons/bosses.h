#ifndef BOSSES_H
#define BOSSES_H
#define LAVABOSSVEL (4)
#define ATAQUEVEL (7)
#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)
#define LAVATTL (41)
#define LAVAHP (50)
#define NIEVETTL (50)
#define NIEVEBOSSVEL (10)
#define FINALBOSSHP (300)
#include <stdio.h>
#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Functions.h"

typedef struct S_BOSSES {
	SDL_Surface* bossHealthSur[3];
	SDL_Texture* bossHealthTex[3];
	SDL_Surface* bossSur[7];
	SDL_Texture* bossTex[7];
	SDL_Rect bossRect[6];
	SDL_Rect bossLife;
	SDL_Rect bossLife2;
	SDL_Rect bossLife3;
	SDL_Rect bossLifeFrame;
	float health[4];
	float bossVelX[6];
	float bossVelY[6];
	int hasSpawned[6];
	int healthPoints[6];
	int currentBoss;
	int sound[9];
	int bossesKilled;
}BOSSES;
BOSSES boss;

typedef struct S_LAVABOSS {
	SDL_Surface* lavaSur[3];
	SDL_Texture* lavaTex[3];
	SDL_Rect lavaRect[3];
	float lavaVelY[3];
	int lavaBullet[3];
	int lavaHasBeenCreated[3];
	int counter[3];
}LAVABOSS;
LAVABOSS lava;

typedef struct S_ESQBOSS {
	SDL_Surface* esqSur[3];
	SDL_Texture* esqTex[3];
	SDL_Rect esqRect[3];
	float esqVelY[3];
	float esqVelX[3];
	int esqBullet[3];
	int esqHasBeenCreated[3];
	int counter[3];
}ESQBOSS;
ESQBOSS esq;

typedef struct S_NIEVEBOSS {
	SDL_Surface* nieveSur[3];
	SDL_Texture* nieveTex[3];
	SDL_Rect nieveRect[3];
	float nieveVelY[3];
	float nieveVelX[3];
	int nieveBullet[3];
	int nieveHasBeenCreated[3];
	int counter[3];
	float deltax[2];
	float deltay[2];
	float distance[2];
}NIEVEBOSS;
NIEVEBOSS nieve;

typedef struct S_ARBOLBOSS {
	SDL_Surface* arbolSur[3];
	SDL_Texture* arbolTex[3];
	SDL_Rect arbolRect[3];
	float arbolVelY[3];
	float arbolVelX[3];
	int arbolBullet[3];
	int arbolHasBeenCreated[3];
	int counter[3];
	float deltax;
	float deltay;
	float distance;
}ARBOLBOSS;
ARBOLBOSS arbol;

typedef struct S_FINALBOSS {
	SDL_Surface* finalSur[8];
	SDL_Texture* finalTex[8];
	SDL_Rect finalRect[8];
	float finalVelY[8];
	float finalVelX[8];
	int finalBullet[8];
	int finalHasBeenCreated[8];
	int counter[8];
	float deltax;
	float deltay;
	float distance;
	float health[4];
	int fase3;
}FINALBOSS;
FINALBOSS final;


void lavaAtakeakSortu(void);
void lavaAtakeakMugitu(void);
void lavaBossCreation(void);
void lavaBoss(void);

void bossEsqueletoCreation();
void esqBoss(SDL_Rect player);
void esqAtakeakSortu(SDL_Renderer *rend, SDL_Rect player, SDL_Rect bala);
void esqAtakeakMugitu(SDL_Renderer* rend, SDL_Rect dest, SDL_Rect bala);

void nieveAtakeakSortu(SDL_Rect player, SDL_Rect bala);
void nieveAtakeakMugitu(SDL_Rect dest, SDL_Rect bala);
void bossNieveCreation();
void nieveBoss();

void bossArbolCreation();
void arbolAtakeakSortu(SDL_Rect player, SDL_Rect bala);
void arbolAtakeakMugitu(SDL_Rect dest, SDL_Rect bala);

void bossFinalCreation();
void finalBoss();
void finalAtakeakSortu(SDL_Rect player, SDL_Rect bala);
void finalAtakeakMugitu(SDL_Rect dest, SDL_Rect bala);

void sonidobossfinal(void);
void sonidoboss(int a, int b);


#endif