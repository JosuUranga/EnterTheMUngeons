#include "Functions.h"

void weaponSelector(void) {
	if (weaponStruct.shotgun) {
		ProtaB->aBulletTTL = 10;
		weaponStruct.sniperTex = 0;
		weaponStruct.shotgunTex = 1;
		printf("%d shotgun\n", ProtaB->aBulletTTL);
		//weaponStruct.shotgun = 0;
	}
	if (weaponStruct.sniper) {
		ProtaB->aBulletTTL = 50;
		weaponStruct.sniperTex = 1;
		weaponStruct.shotgunTex = 0;
		printf("%d Sniper\n", ProtaB->aBulletTTL);
		//weaponStruct.sniper = 0;
	}
}

void showWeapon(void) {
	if (levelmanagerstruct.playing == 1) {
		if (levelmanagerstruct.level != 0 || boss.bossesKilled == 4) {
			if (weaponStruct.sniperTex == 1 && weaponStruct.shotgunTex == 0) {
				SDL_RenderCopy(TakeRenderer(), marco.texture[3], NULL, NULL);
			}
			else
			{
				SDL_RenderCopy(TakeRenderer(), marco.texture[2], NULL, NULL);
			}
		}
	}


}