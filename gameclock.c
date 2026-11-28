#include "gameclock.h"

extern float gameTime = 15.0f;

void InitClock(void)
{
    gameTime = 15.0f;
}

void UpdateClock(void)
{
    if (gameTime > 0)
    {
        gameTime -= GetFrameTime();
    }

    if (gameTime < 0)
    {
        gameTime = 0;
    }
}

void DrawClock(void)
{
    DrawText(TextFormat("TIME: %.1f", gameTime),
             (GetScreenWidth()*3)/4 , 20, 30, BLACK);
}
