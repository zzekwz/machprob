#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include "raylib.h"

extern float gameTime;

void InitClock(void);
void DrawClock(void);
void UpdateClock(void);

void InitTimeOrb(void);
void DrawTimeOrb(void);
void UpdateTimeOrb(void);

#endif
