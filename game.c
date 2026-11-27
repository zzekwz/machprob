#include "raylib.h"
#include "game.h"

void InitGame(road lanes[], Player *player, Obstacle *obs)
{
    InitLane(lanes);

    InitPlayer(player, lanes, GetScreenHeight() - 80.0f);

    InitObstacle(obs, lanes, -50.0f);
}

void UpdateGame(road lanes[], Player *player, Obstacle *obs)
{
    UpdatePlayer(player, lanes);

    UpdateObstacle(obs, lanes);
}

void DrawGame(road lanes[], Player player, Obstacle obs)
{
    ClearBackground(WHITE);

    DrawLane(lanes);

    DrawPlayer(player);

    DrawObstacle(obs);
}

int CheckGameOver(Player player, Obstacle obs)
{
    return CheckCollisionRecs(player.bounds, obs.bounds);
}

