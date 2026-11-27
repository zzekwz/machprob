#include "raylib.h"
#include "menu.h"

typedef struct {
    char name[20];
    int score;
} PlayerScore;

PlayerScore topScores[5] = {
    {"Player 1", 0},
    {"Player 2", 0},
    {"Player 3", 0},
    {"Player 4", 0},
    {"Player 5", 0},
};

void UpdateMenu(GameScreen *currentScreen)
{
    int width = GetScreenWidth();

    Rectangle startButton = {(width - 200) / 2, 250, 200, 60};
    Rectangle scoreButton = {(width - 200) / 2, 350, 200, 60};

    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, startButton) &&
        IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        *currentScreen = GAMEPLAY;
    }
    else if (CheckCollisionPointRec(mouse, scoreButton) &&
             IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        *currentScreen = SCORESCREEN;
    }
}

void DrawMenu(void)
{
    int width = GetScreenWidth();

    Rectangle startButton = {(width - 200) / 2, 250, 200, 60};
    Rectangle scoreButton = {(width - 200) / 2, 350, 200, 60};

    DrawRectangle(10, 10, width - 20, GetScreenHeight() - 20, GRAY);

    DrawText("Late na naman",
             (width - MeasureText("Late na naman", 40)) / 2,
             140, 40, WHITE);

    DrawRectangleRec(startButton, DARKGRAY);
    DrawText("START", (width - MeasureText("START", 25)) / 2,
             265, 25, WHITE);

    DrawRectangleRec(scoreButton, DARKGRAY);
    DrawText("SCORES", (width - MeasureText("SCORES", 25)) / 2,
             365, 25, WHITE);
}

void ShowScores(void)
{
    int width = GetScreenWidth();

    DrawRectangle(10, 10, width - 20, GetScreenHeight() - 20, GRAY);

    DrawText("TOP SCORES", 250, 100, 20, WHITE);
    DrawText("Rank", 50, 150, 20, WHITE);
    DrawText("Score", width - 150, 150, 20, WHITE);

    for (int i = 0; i < 5; i++)
    {
        Color textColor = WHITE;

        switch (i)
        {
            case 0: textColor = GOLD; break;
            case 1: textColor = LIGHTGRAY; break;
            case 2: textColor = BROWN; break;
        }

        DrawText(topScores[i].name, 50, 200 + (i * 50),
                 25, textColor);

        DrawText(TextFormat("%d", topScores[i].score),
                 width - 150, 200 + (i * 50), 25, textColor);
    }
}

void GameOver(void)
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    DrawRectangle(10, 10, width - 20, height - 20, GRAY);

    DrawText("GAME OVER",
             (width - MeasureText("GAME OVER", 50)) / 2,
             height / 2, 50, WHITE);

    DrawText("Press ENTER to return to menu",
             (width - MeasureText("Press ENTER to return to menu", 20)) / 2,
             height / 2 + 70, 20, WHITE);
}
