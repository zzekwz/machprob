#include "raylib.h"
#include "gamescreen.h"
#include "menu.h"
#include "game.h"

road lanes[LANE_COUNT];
Player player;
Obstacle obs[MAX_OBSTACLES];

int gameInitialized = 0;

void UpdateScreen(GameScreen *currentScreen)
{
    switch (*currentScreen)
    {
        case MENU:
            UpdateMenu(currentScreen);
            break;

        case SCORESCREEN:
            if (IsKeyPressed(KEY_ENTER))
            {
                *currentScreen = MENU;
            }
            break;

        case GAMEPLAY:
            if (!gameInitialized)
            {
                InitGame(lanes, &player, obs);
                gameInitialized = 1;
            }

            if (IsKeyPressed(KEY_ESCAPE))
            {
                *currentScreen = MENU;
                gameInitialized = 0;
            }
            else
            {
                UpdateGame(lanes, &player, obs);

                if (CheckGameOver(player, obs))
                {
                    *currentScreen = GAMEOVER;
                }
            }
            break;

        case GAMEOVER:
            if (IsKeyPressed(KEY_ENTER))
            {
                *currentScreen = MENU;
                gameInitialized = 0;
            }
            break;
    }
}

void DrawScreen(GameScreen *currentScreen)
{
    ClearBackground(BLACK);

    switch (*currentScreen)
    {
        case MENU:
            DrawMenu();
            break;

        case SCORESCREEN:
            ShowScores();
            break;

        case GAMEPLAY:
            DrawGame(lanes, player, obs);
            break;

        case GAMEOVER:
            GameOver();
            break;
    }
}
