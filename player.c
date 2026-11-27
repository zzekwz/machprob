#include "player.h"
#include "raylib.h"

void InitPlayer(Player *player, const road lane[], float startY) {

    player->currentLane = 1;

    player->bounds.width = 60.0f;
    player->bounds.height = 70.0f;

    player->bounds.x = lane[player->currentLane].bounds.x
                     + (lane[player->currentLane].bounds.width
                     - player->bounds.width) / 2;

    player->bounds.y = startY;

    player->speed = 250.0f;
    player->color = BLUE;
}

void UpdatePlayer(Player *player, const road lane[]) {

   if (IsKeyPressed(KEY_LEFT) && player->currentLane > 0)
{
    player->currentLane--;
    player->bounds.x = lane[player->currentLane].bounds.x
                     + (lane[player->currentLane].bounds.width
                     - player->bounds.width) / 2;
}

if (IsKeyPressed(KEY_RIGHT) && player->currentLane < LANE_COUNT - 1)
{
    player->currentLane++;

    player->bounds.x = lane[player->currentLane].bounds.x
                     + (lane[player->currentLane].bounds.width
                     - player->bounds.width) / 2;
}
}


void DrawPlayer(Player player) {
    DrawRectangleRec(player.bounds, player.color);
}
