#include "Functions.h"

void Restart(void) {
	InitStruct();
	InitRect();
	levelmanagerstruct.playing = 0;
	lifestruct.score = 0;
	resetBullet();
}