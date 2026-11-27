#include "raylib.h"
#include "menu.h"
#include "lane.h"
#include "player.h"


int main(void)
    {InitWindow(700, 700, "Late Na Naman");
    SetTargetFPS(60);

    lane lanes[LANE_COUNT];

    GameScreen currentScreen = MENU;

    Player player;
    InitPlayer(&player, 100.0f, GetScreenHeight() - 80.0f);

    while (!WindowShouldClose())
    {
        if (currentScreen == MENU)
        {
            UpdateMenu(&currentScreen);
        }
        else if(currentScreen == SCORESCREEN)
        {
             if (IsKeyPressed(KEY_ESCAPE))
            {
                currentScreen = MENU;
            }
        }
        else if (currentScreen == GAMEPLAY)
        {
            if (IsKeyPressed(KEY_ESCAPE))
            {
                currentScreen = MENU;
            }
        }


        BeginDrawing();

        ClearBackground(BLACK);

        switch (currentScreen)
        {
            case MENU:
                DrawMenu();
                break;

            case SCORESCREEN:
                ShowScores();
                break;

            case GAMEPLAY:
                ClearBackground(WHITE);
                InitLane(lanes);
                DrawLane(lanes);

                UpdatePlayer(&player, lanes);
                DrawPlayer(player);

                break;

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
