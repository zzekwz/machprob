#include "raylib.h"
#include "game.h"

void InitGame(road lanes[], Player *player, Obstacle obs[])
{
    InitLane(lanes);

    InitPlayer(player, lanes, GetScreenHeight() - 80.0f);

    InitClock();

    InitObstacle(obs, lanes);
}

void UpdateGame(road lanes[], Player *player, Obstacle obs[])
{
    UpdatePlayer(player, lanes);

    UpdateClock();

    UpdateObstacle(obs, lanes);
}

void DrawGame(road lanes[], Player player, Obstacle obs[])
{
    ClearBackground(WHITE);

    DrawLane(lanes);

    DrawClock();

    DrawPlayer(player);

    DrawObstacle(obs);
}

int CheckGameOver(Player player, Obstacle obs[])
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        if (CheckCollisionRecs(player.bounds, obs[i].bounds))
        {
            return 1;
        }
    }

    if (gameTime == 0)
    {
        return 1;
    }

    return 0;
}
