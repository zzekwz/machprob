#include "raylib.h"
#include "menu.h"



Rectangle startButton;
Rectangle scoreButton;

typedef struct {
    char name[20];
    int score;
}PlayerScore;



PlayerScore topScores[5] = {
 { "Player 1", 0 },
 { "Player 2", 0 },
 { "Player 3", 0 },
 { "Player 4", 0 },
 { "Player 5", 0 },
};


void UpdateMenu(GameScreen *currentScreen)
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();

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
    int height = GetScreenHeight();

    Rectangle startButton = {(width - 200) / 2, 250, 200, 60};
    Rectangle scoreButton = {(width - 200) / 2, 350, 200, 60};

    DrawRectangle(10, 10, width - 20, height - 20, GRAY);

    DrawText("TITLE", (width - MeasureText("TITLE", 40))/2 , 140, 40, WHITE);

    DrawRectangleRec(startButton, DARKGRAY);
    DrawText("START", (width - MeasureText("START",25)) / 2, 265, 25, WHITE);

    DrawRectangleRec(scoreButton, DARKGRAY);
    DrawText("SCORES", (width - MeasureText("SCORES",25)) / 2, 365, 25, WHITE);
}

void ShowScores(void)
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    DrawRectangle(10, 10, width - 20, height - 20, GRAY);

    DrawText("TOP SCORES", 250, 100, 20, WHITE);
    DrawText("Rank", 50, 150, 20, WHITE);
    DrawText("Score", width - 150, 150, 20, WHITE);

    for (int i = 0; i < 5; i++) {
            switch (i) {
            case 0:
                DrawText(topScores[i].name, 50, 200 + (i*50) , 25, GOLD);
                DrawText(TextFormat("%d", topScores[i].score), width - 150, 200 + (i*50), 25, GOLD);
                break;
            case 1:
                DrawText(topScores[i].name, 50, 200 + (i*50) , 25, LIGHTGRAY);
                DrawText(TextFormat("%d", topScores[i].score), width - 150, 200 + (i*50), 25, LIGHTGRAY);
                break;
            case 2:
                DrawText(topScores[i].name, 50, 200 + (i*50) , 25, BROWN);
                DrawText(TextFormat("%d", topScores[i].score), width - 150, 200 + (i*50), 25, BROWN);
                break;
            default:
                DrawText(topScores[i].name, 50, 200 + (i*50) , 25, WHITE);
                DrawText(TextFormat("%d", topScores[i].score), width - 150, 200 + (i*50), 25, WHITE);
            };
    }

}

