#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)
#define SPEED (250)
#define MAXRECTS (4)
#define MAXENEMY (4)
#define BulletTTL (100)
#define ABSpeed (800)
#define MAX_SOUNDS (10)
#define PROTAHP (3)
#define LAVABOSSVEL (4)
#define ATAQUEVEL (7)
#define LAVATTL (41)
#define LAVAHP (50)
#define NIEVETTL (50)
#define NIEVEBOSSVEL (10)
#define FINALBOSSHP (300)
#include <SDL_image.h>
#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL_timer.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <time.h>

typedef struct {
	SDL_Surface* surface[4];
	SDL_Texture* texture[4];
}MARCO;
MARCO marco;

typedef struct {
	SDL_Surface* lavaSurface[11];
	SDL_Texture* lavaTexture[11];
	SDL_Surface* snowSurface[10];
	SDL_Texture* snowTexture[10];
	SDL_Surface* defaultSurface[9];
	SDL_Texture* defaultTexture[9];
	int fadeCounter;
	int fade;
	int snowFPS;
	int snowAnim;
	int defaultFPS;
	int defaultAnim;
}LevelAnimStruct;
LevelAnimStruct levelAnim;

typedef struct {
	int lifes;
	int tmpLifes;
	int invencivilty;
	int invencivilityFPS;
	int score;
	int tempScore;
	char str[30];
	char str2[30];
	char str3[30];
	SDL_Surface* life_surface[6];
	SDL_Texture* life_texture[6];
	int constantFPScounter;
	TTF_Font* Font;
	SDL_Surface* surfaceMessage[3];
	SDL_Texture* Message[3];
	SDL_Rect Message_rect[3];
	int dieFPS;
	int restartFPS;
	int GameOver;
	SDL_Rect lifeRect;
}lifeStruct;
lifeStruct lifestruct;

typedef struct{
	SDL_Renderer* rend;
	SDL_Rect borde[MAXRECTS + 1];
	int level;
	int close_requested;
	int playing;
	int door1ON;
	int door2ON;
	int door3ON;
	int door4ON;
	int case1x;
	int case2x;
	int case3x;
	int case4x;
	int case1y;
	int case2y;
	int case3y;
	int case4y;
	int hizkuntza;
}levelManagerStruct;
levelManagerStruct levelmanagerstruct;

typedef struct S_MENUTEXTURAK {
	SDL_Surface* surface[8];
	SDL_Texture* texturak[8];
	SDL_Rect dest[3];
	float y1;
	float y2;
	float x1;
	float x2;
	float y1_vel;
	float y2_vel;
}MENUTEXTURAK;
MENUTEXTURAK mt;

typedef struct {
	float x;
	float y;
	float x_vel;
	float y_vel;
	int right;
	int up;
	int down;
	int left;
	float xtemp;
	float ytemp;
	
}posStruct;
posStruct posstruct;

typedef struct {
	int v_y;
	int v_x;
	int numb;
	int BulletCreated;
	float BulletDelta_x;
	float BulletDelta_y;
	float BulletVel_x;
	float BulletVel_y;
	float BulletPos_x;
	float BulletPos_y;
	int FPSCounter;
	int HP;
	int CanCreateB;
	int stopenemycreation;
	int deeadSound;
	int killed;
	
}EnemyVe;
EnemyVe EnemyV[MAXENEMY + 1];

typedef struct {
	int av_y;
	int av_x;
	int anumb;
	int aBulletCreated;
	float aBulletDelta_x;
	float aBulletDelta_y;
	float aBulletVel_x;
	float aBulletVel_y;
	float aBulletPos_x;
	float aBulletPos_y;
	int aFPSCounter;
	int aBulletTTL;

}ProtaBullet;
ProtaBullet ProtaB;

typedef struct {
	int enemyL[11];
	int enemyController[11];
	int hasSpawned[11];
	int enemykilled[11];
	SDL_Rect Bullet[MAXENEMY + 1];
	SDL_Rect Enemy[MAXENEMY + 1];
	int hasSkinChanged;
	int bulletFCreated;
}EnemySpawn;
EnemySpawn enemySpawn;

typedef struct {
	SDL_Rect player;
	SDL_Rect Bala;
	int playerFPS;
}PlayerRect;
PlayerRect playerRect;

typedef struct {
	SDL_Surface* surface[6];
	SDL_Texture* texture[6];
	int goMusic;
}WinOrDie;
WinOrDie winOrDie;

typedef struct {
	SDL_Surface* surface[13];
	SDL_Texture* texturak[13];
}DoorOpenStruct;
DoorOpenStruct dooropenstruct;

typedef struct {
	SDL_Surface* surface[11];
	SDL_Texture* texturak[11];
}DoorCloseStruct;
DoorCloseStruct doorclosetruct;

typedef struct {
	SDL_Surface* player_surface;
	SDL_Surface* playerInvencivility_surface;
	SDL_Surface* playerBullet_surface;
	SDL_Surface* enemy_surface;
	SDL_Surface* EBullet_surface;
	SDL_Texture* player_texture;
	SDL_Texture* playerInvencivility_texture;
	SDL_Texture* playerBullet_texture;
	SDL_Texture* EnemyTex[MAXENEMY + 1];
	SDL_Texture* EBulletTex[MAXENEMY + 1];
}CharactersStruct;
CharactersStruct charactersstruct;

typedef struct {
	int shotgun;
	int sniper;
	int shotgunTex;
	int sniperTex;
} WeaponStruct;
WeaponStruct weaponStruct;

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

void levelDefaultAnim(void);
void LevelSnowAnim(void);
void LevelLavaAnim(void);
int WinDieBotoiak(void);
void YouWin(void);
void FPSCounter(void);
void SumScore(void);
void ScoreRefresh(void);
void InitScore(void);
void GameOver(void);
void EnemyTexture(void);
void InitSurfacesAndTextures(void);
void InitRect(void);
void InitStruct(void);
void Enemydeadcounter(void);
void Enemydead(void);
void SpawnEnemy(void);
int collisioncheck(struct SDL_Rect dest, struct SDL_Rect borde1);
void AllyBulletCreation(SDL_Rect* dest, SDL_Rect* Bala);
void MoveAllyBullet(SDL_Rect* Bala, SDL_Rect* Enemy);
void MoveEnemy(SDL_Rect* Enemy, SDL_Rect* borde, EnemyVe* EnemyV);
void BulletCreation(SDL_Rect* Enemy, EnemyVe* EnemyV, SDL_Rect* Bullet);
void MoveEnemyBullet(SDL_Rect* Enemy, EnemyVe* EnemyV, SDL_Rect* Bullet);
void CreateEnemy(SDL_Rect* Enemy);
int collisioncheck(struct SDL_Rect dest, struct SDL_Rect borde1);
void wallCollision(SDL_Rect dest, SDL_Rect* borde);
void menu();
void movement(void);
void life(void);
int checkCollision(SDL_Rect A, SDL_Rect B);
void windowCollision(SDL_Rect dest);
int doors(void);
void Restart(void);
void levelManager(void);
void audioInit();
int loadSound(char *fileName);
int loadTheMusic(char *fileName);
int playSound(int idSound);
int playMusic(void);
void toggleMusic(void);
void audioTerminate();
void initSound();
void spawnTheEnemies();
void resetBullet();
void hizkuntza(void);
void showWeapon(void);
void levelmanagerstructdoors(int a, int b, int c, int d);
void ValorRects(SDL_Rect* a,int b, int c, int d, int e);
void levelmanagerstructcaseprincipal(int a, int b, int c);
void levelmanagerstructcasenormal(int a, int b, int c);
void levelmanagerstructcasevolverprincipal(int b, int c, int a);
void weaponSelector(void);
void menuSprites(void);
void lavaAtakeakSortu(void);
void lavaAtakeakMugitu(void);
void lavaBossCreation(void);
void lavaBoss(void);

void bossEsqueletoCreation();
void esqBoss(SDL_Rect player);
void esqAtakeakSortu(SDL_Rect player, SDL_Rect bala);
void esqAtakeakMugitu(SDL_Rect dest, SDL_Rect bala);

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