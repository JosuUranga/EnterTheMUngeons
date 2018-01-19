
#include "Functions.h"





void InitSurfacesAndTextures(void){



	///TEXTURES AND SURFACES
	dooropenstruct.surface[0] = IMG_Load("resources/Maps/0EUS.png");
	dooropenstruct.surface[1] = IMG_Load("resources/Maps/1OffO.png");
	dooropenstruct.surface[2] = IMG_Load("resources/Maps/14OffO.png");
	dooropenstruct.surface[3] = IMG_Load("resources/Maps/141OffO.png");
	dooropenstruct.surface[4] = IMG_Load("resources/Maps/2O.png");
	dooropenstruct.surface[5] = IMG_Load("resources/Maps/22O.png");
	dooropenstruct.surface[6] = IMG_Load("resources/Maps/3O.png");
	dooropenstruct.surface[7] = IMG_Load("resources/Maps/32O.png");
	dooropenstruct.surface[8] = IMG_Load("resources/Maps/323O.png");
	dooropenstruct.surface[9] = IMG_Load("resources/Maps/4O.png");
	dooropenstruct.surface[10] = IMG_Load("resources/Maps/44O.png");
	//CAMBIAR ESTAS
	dooropenstruct.surface[11] = IMG_Load("resources/Maps/0ES.png");
	dooropenstruct.surface[12] = IMG_Load("resources/Maps/0EN.png");
	//
	doorclosetruct.surface[0] = IMG_Load("resources/Maps/0C.png");
	doorclosetruct.surface[1] = IMG_Load("resources/Maps/1OffC.png");
	doorclosetruct.surface[2] = IMG_Load("resources/Maps/14OffC.png");
	doorclosetruct.surface[3] = IMG_Load("resources/Maps/141OffC.png");
	doorclosetruct.surface[4] = IMG_Load("resources/Maps/2C.png");
	doorclosetruct.surface[5] = IMG_Load("resources/Maps/22C.png");
	doorclosetruct.surface[6] = IMG_Load("resources/Maps/3C.png");
	doorclosetruct.surface[7] = IMG_Load("resources/Maps/32C.png");
	doorclosetruct.surface[8] = IMG_Load("resources/Maps/323C.png");
	doorclosetruct.surface[9] = IMG_Load("resources/Maps/4C.png");
	doorclosetruct.surface[10] = IMG_Load("resources/Maps/44C.png");
	mt.surface[0] = IMG_Load("resources/Maps/MenuEUS.png");
	mt.texturak[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[0]);
	mt.surface[1] = IMG_Load("resources/Characters/enemigo1.png");
	mt.texturak[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[1]);
	mt.surface[2] = IMG_Load("resources/Characters/enemigo.png");
	mt.texturak[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[2]);
	mt.surface[3] = IMG_Load("resources/Maps/Kredituak.png");
	mt.texturak[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[3]);
	mt.surface[4] = IMG_Load("resources/Maps/MenuES.png");
	mt.texturak[4] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[4]);
	mt.surface[5] = IMG_Load("resources/Maps/MenuEN.png");
	mt.texturak[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[5]);

	mt.surface[6] = IMG_Load("resources/Maps/KredituakES.png");
	mt.texturak[6] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[6]);

	mt.surface[7] = IMG_Load("resources/Maps/KredituakEN.png");
	mt.texturak[7] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, mt.surface[7]);



	lifestruct.life_surface[0] = IMG_Load("resources/0vidas.png");
	lifestruct.life_surface[1] = IMG_Load("resources/1vidas.png");
	lifestruct.life_surface[2] = IMG_Load("resources/2vidas.png");
	lifestruct.life_surface[3] = IMG_Load("resources/3vidas.png");
	lifestruct.life_surface[4] = IMG_Load("resources/4vidas.png");
	lifestruct.life_surface[5] = IMG_Load("resources/5vidas.png");
	lifestruct.life_texture[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lifestruct.life_surface[0]);
	lifestruct.life_texture[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lifestruct.life_surface[1]);
	lifestruct.life_texture[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lifestruct.life_surface[2]);
	lifestruct.life_texture[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lifestruct.life_surface[3]);
	lifestruct.life_texture[4] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lifestruct.life_surface[4]);
	lifestruct.life_texture[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lifestruct.life_surface[5]);

	winOrDie.surface[0] = IMG_Load("resources/Maps/YouWinEUS.png");
	winOrDie.texture[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, winOrDie.surface[0]);
	winOrDie.surface[1] = IMG_Load("resources/Maps/YouWinES.png");
	winOrDie.texture[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, winOrDie.surface[1]);
	winOrDie.surface[2] = IMG_Load("resources/Maps/YouWinEN.png");
	winOrDie.texture[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, winOrDie.surface[2]);
	winOrDie.surface[3] = IMG_Load("resources/Maps/GameOverEUS.png");
	winOrDie.texture[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, winOrDie.surface[3]);
	winOrDie.surface[4] = IMG_Load("resources/Maps/GameOverES.png");
	winOrDie.texture[4] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, winOrDie.surface[4]);
	winOrDie.surface[5] = IMG_Load("resources/Maps/GameOverEN.png");
	winOrDie.texture[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, winOrDie.surface[5]);

	for (int i = 0; i < 13; i++)
	{
		dooropenstruct.texturak[i] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, dooropenstruct.surface[i]);
		SDL_FreeSurface(dooropenstruct.surface[i]);
		if (i <= 5) {
			SDL_FreeSurface(mt.surface[i]);
			SDL_FreeSurface(lifestruct.life_surface[i]);
		}

	}
	for (int i = 0; i < 11; i++) {
		doorclosetruct.texturak[i] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, doorclosetruct.surface[i]);
		SDL_FreeSurface(doorclosetruct.surface[i]);

	}

	charactersstruct.player_surface = IMG_Load("resources/Characters/roguelike.png");
	charactersstruct.playerInvencivility_surface = IMG_Load("resources/Characters/protagonistaInvencible.png");
	charactersstruct.playerBullet_surface = IMG_Load("resources/Characters/defaultTiro.png");
	charactersstruct.player_texture = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, charactersstruct.player_surface);
	charactersstruct.playerInvencivility_texture = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, charactersstruct.playerInvencivility_surface);
	charactersstruct.playerBullet_texture = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, charactersstruct.playerBullet_surface);

	marco.surface[0] = IMG_Load("resources/marco1.png");
	marco.texture[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, marco.surface[0]);
	marco.surface[1] = IMG_Load("resources/marco2.png");
	marco.texture[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, marco.surface[1]);

	//ARMAS CAMBIAR
	marco.surface[2] = IMG_Load("resources/ShotgunSelected.png");
	marco.texture[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, marco.surface[2]);
	marco.surface[3] = IMG_Load("resources/SniperSelected.png");
	marco.texture[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, marco.surface[3]);



	boss.bossHealthSur[0] = IMG_Load("resources/Bosses/bossHealth.jpg");
	boss.bossHealthTex[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossHealthSur[0]);

	boss.bossHealthSur[1] = IMG_Load("resources/Bosses/cuadradoamarillo.jpg");
	boss.bossHealthTex[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossHealthSur[1]);

	boss.bossHealthSur[2] = IMG_Load("resources/Bosses/color-azul.png");
	boss.bossHealthTex[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossHealthSur[2]);

	//Boss Lava
	boss.bossSur[0] = IMG_Load("resources/Bosses/lavaBoss.png");
	boss.bossTex[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossSur[0]);
	SDL_QueryTexture(boss.bossTex[0], NULL, NULL, &boss.bossRect[0].w, &boss.bossRect[0].h);

	lava.lavaSur[0] = IMG_Load("resources/Bosses/Tiros/lava.png");
	lava.lavaTex[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lava.lavaSur[0]);
	lava.lavaSur[1] = IMG_Load("resources/Bosses/Tiros/lava.png");
	lava.lavaTex[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lava.lavaSur[1]);
	lava.lavaSur[2] = IMG_Load("resources/healthBar.png");
	lava.lavaTex[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, lava.lavaSur[2]);
	SDL_QueryTexture(lava.lavaTex[0], NULL, NULL, &lava.lavaRect[0].w, &lava.lavaRect[0].h);
	SDL_QueryTexture(lava.lavaTex[1], NULL, NULL, &lava.lavaRect[1].w, &lava.lavaRect[1].h);
	
	//Boss Esqueleto
	boss.bossSur[1] = IMG_Load("resources/Bosses/esqueletoBoss.png");
	boss.bossTex[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossSur[1]);
	SDL_QueryTexture(boss.bossTex[1], NULL, NULL, &boss.bossRect[1].w, &boss.bossRect[1].h);

	esq.esqSur[0] = IMG_Load("resources/Bosses/Tiros/default.png");
	esq.esqTex[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, esq.esqSur[0]);
	esq.esqSur[1] = IMG_Load("resources/Bosses/Tiros/default.png");
	esq.esqTex[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, esq.esqSur[1]);
	SDL_QueryTexture(esq.esqTex[0], NULL, NULL, &esq.esqRect[0].w, &esq.esqRect[0].h);
	SDL_QueryTexture(esq.esqTex[1], NULL, NULL, &esq.esqRect[1].w, &esq.esqRect[1].h);

	//Boss Nieve
	boss.bossSur[2] = IMG_Load("resources/Bosses/nieveBoss.png");
	boss.bossTex[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossSur[2]);
	SDL_QueryTexture(boss.bossTex[2], NULL, NULL, &boss.bossRect[2].w, &boss.bossRect[2].h);

	nieve.nieveSur[0] = IMG_Load("resources/Bosses/Tiros/nieve.png");
	nieve.nieveTex[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, nieve.nieveSur[0]);
	nieve.nieveSur[1] = IMG_Load("resources/Bosses/Tiros/nieve.png");
	nieve.nieveTex[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, nieve.nieveSur[1]);
	SDL_QueryTexture(nieve.nieveTex[0], NULL, NULL, &nieve.nieveRect[0].w, &nieve.nieveRect[0].h);
	SDL_QueryTexture(nieve.nieveTex[1], NULL, NULL, &nieve.nieveRect[1].w, &nieve.nieveRect[1].h);

	//Boss Arbol
	boss.bossSur[3] = IMG_Load("resources/Bosses/verdeBoss.png");
	boss.bossTex[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossSur[3]);
	SDL_QueryTexture(boss.bossTex[3], NULL, NULL, &boss.bossRect[3].w, &boss.bossRect[3].h);

	arbol.arbolSur[0] = IMG_Load("resources/Bosses/Tiros/verde.png");
	arbol.arbolTex[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, arbol.arbolSur[0]);
	arbol.arbolSur[1] = IMG_Load("resources/Bosses/Tiros/verde.png");
	arbol.arbolTex[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, arbol.arbolSur[1]);
	SDL_QueryTexture(arbol.arbolTex[0], NULL, NULL, &arbol.arbolRect[0].w, &arbol.arbolRect[0].h);
	SDL_QueryTexture(arbol.arbolTex[1], NULL, NULL, &arbol.arbolRect[1].w, &arbol.arbolRect[1].h);

	//Boss FINAL
	boss.bossSur[4] = IMG_Load("resources/Bosses/FinalBoss/finalBoss.png");
	boss.bossTex[4] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossSur[4]);
	boss.bossSur[5] = IMG_Load("resources/Bosses/FinalBoss/finalBoss2.png");
	boss.bossTex[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossSur[5]);
	boss.bossSur[6] = IMG_Load("resources/Bosses/FinalBoss/finalBoss3.png");
	boss.bossTex[6] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, boss.bossSur[6]);

	final.finalSur[0] = IMG_Load("resources//Bosses/FinalBoss/final1.png");
	final.finalTex[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[0]);
	final.finalSur[1] = IMG_Load("resources//Bosses/FinalBoss/final2.png");
	final.finalTex[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[1]);
	final.finalSur[2] = IMG_Load("resources//Bosses/FinalBoss/final1.png");
	final.finalTex[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[2]);
	final.finalSur[3] = IMG_Load("resources//Bosses/FinalBoss/final2.png");
	final.finalTex[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[3]);
	final.finalSur[4] = IMG_Load("resources//Bosses/FinalBoss/final1.png");
	final.finalTex[4] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[4]);
	final.finalSur[5] = IMG_Load("resources//Bosses/FinalBoss/final2.png");
	final.finalTex[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[5]);
	final.finalSur[6] = IMG_Load("resources//Bosses/FinalBoss/final1.png");
	final.finalTex[6] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[6]);
	final.finalSur[7] = IMG_Load("resources//Bosses/FinalBoss/final2.png");
	final.finalTex[7] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, final.finalSur[7]);
	SDL_QueryTexture(final.finalTex[0], NULL, NULL, &final.finalRect[0].w, &final.finalRect[0].h);
	SDL_QueryTexture(final.finalTex[1], NULL, NULL, &final.finalRect[1].w, &final.finalRect[1].h);
	SDL_QueryTexture(final.finalTex[2], NULL, NULL, &final.finalRect[2].w, &final.finalRect[2].h);
	SDL_QueryTexture(final.finalTex[3], NULL, NULL, &final.finalRect[3].w, &final.finalRect[3].h);
	SDL_QueryTexture(final.finalTex[4], NULL, NULL, &final.finalRect[4].w, &final.finalRect[4].h);
	SDL_QueryTexture(final.finalTex[5], NULL, NULL, &final.finalRect[5].w, &final.finalRect[5].h);
	SDL_QueryTexture(final.finalTex[6], NULL, NULL, &final.finalRect[6].w, &final.finalRect[6].h);
	SDL_QueryTexture(final.finalTex[7], NULL, NULL, &final.finalRect[7].w, &final.finalRect[7].h);

	levelAnim.lavaSurface[1] = IMG_Load("resources/Maps/1On.png");
	levelAnim.lavaSurface[5] = IMG_Load("resources/Maps/14On.png");
	levelAnim.lavaSurface[6] = IMG_Load("resources/Maps/141On.png");
	levelAnim.lavaTexture[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.lavaSurface[1]);
	levelAnim.lavaTexture[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.lavaSurface[5]);
	levelAnim.lavaTexture[6] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.lavaSurface[6]);

	levelAnim.snowSurface[0] = IMG_Load("resources/Maps/frame_1.gif");
	levelAnim.snowSurface[1] = IMG_Load("resources/Maps/frame_2.gif");
	levelAnim.snowSurface[2] = IMG_Load("resources/Maps/frame_3.gif");
	levelAnim.snowSurface[3] = IMG_Load("resources/Maps/frame_4.gif");
	levelAnim.snowSurface[4] = IMG_Load("resources/Maps/frame_5.gif");
	levelAnim.snowSurface[5] = IMG_Load("resources/Maps/frame_6.gif");
	levelAnim.snowSurface[6] = IMG_Load("resources/Maps/frame_7.gif");
	levelAnim.snowSurface[7] = IMG_Load("resources/Maps/frame_8.gif");
	levelAnim.snowSurface[8] = IMG_Load("resources/Maps/frame_9.gif");
	levelAnim.snowSurface[9] = IMG_Load("resources/Maps/frame_10.gif");
	levelAnim.snowTexture[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[0]);
	levelAnim.snowTexture[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[1]);
	levelAnim.snowTexture[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[2]);
	levelAnim.snowTexture[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[3]);
	levelAnim.snowTexture[4] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[4]);
	levelAnim.snowTexture[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[0]);
	levelAnim.snowTexture[6] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[1]);
	levelAnim.snowTexture[7] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[2]);
	levelAnim.snowTexture[8] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[3]);
	levelAnim.snowTexture[9] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.snowSurface[4]);

	levelAnim.defaultSurface[0] = IMG_Load("resources/Maps/4i.png");
	levelAnim.defaultSurface[1] = IMG_Load("resources/Maps/4ii.png");
	levelAnim.defaultSurface[2] = IMG_Load("resources/Maps/4iii.png");
	levelAnim.defaultSurface[3] = IMG_Load("resources/Maps/44i.png");
	levelAnim.defaultSurface[4] = IMG_Load("resources/Maps/44ii.png");
	levelAnim.defaultSurface[5] = IMG_Load("resources/Maps/44iii.png");
	levelAnim.defaultSurface[6] = IMG_Load("resources/Maps/444i.png");
	levelAnim.defaultSurface[7] = IMG_Load("resources/Maps/444ii.png");
	levelAnim.defaultSurface[8] = IMG_Load("resources/Maps/444iii.png");
	levelAnim.defaultTexture[0] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[0]);
	levelAnim.defaultTexture[1] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[1]);
	levelAnim.defaultTexture[2] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[2]);
	levelAnim.defaultTexture[3] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[3]);
	levelAnim.defaultTexture[4] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[4]);
	levelAnim.defaultTexture[5] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[5]);
	levelAnim.defaultTexture[6] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[6]);
	levelAnim.defaultTexture[7] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[7]);
	levelAnim.defaultTexture[8] = SDL_CreateTextureFromSurface(levelmanagerstruct.rend, levelAnim.defaultSurface[8]);



	SDL_FreeSurface(charactersstruct.EBullet_surface);
	SDL_FreeSurface(charactersstruct.enemy_surface);
	SDL_FreeSurface(charactersstruct.player_surface);
	SDL_FreeSurface(charactersstruct.playerBullet_surface);
}