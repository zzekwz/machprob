#include "raylib.h"
#include "gamescreen.h"

int main(void)
{
    InitWindow(700, 700, "Late Na Naman");
    SetTargetFPS(60);

    GameScreen currentScreen = MENU;

    while (!WindowShouldClose())
    {
        UpdateScreen(&currentScreen);

        BeginDrawing();

        DrawScreen(&currentScreen);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
