#include "player.h"
#include "raylib.h"

void InitPlayer(Player *player, float startX, float startY) {
    player->bounds = (Rectangle){ startX, startY, 40.0f, 40.0f };
    player->speed = 250.0f;
    player->color = BLUE;
}

void UpdatePlayer(Player *player, const lane lanes[]) {
    float dt = GetFrameTime();
    if (IsKeyDown(KEY_UP)) player->bounds.y -= player->speed * dt;
    if (IsKeyDown(KEY_LEFT)) player->bounds.x -= player->speed * dt;
    if (IsKeyDown(KEY_DOWN)) player->bounds.y += player->speed * dt;
    if (IsKeyDown(KEY_RIGHT)) player->bounds.x += player->speed * dt;

    float minX = lanes[0].bounds.x;
    float maxX = (lanes[LANE_COUNT - 1].bounds.x + lanes[LANE_COUNT - 1].bounds.width) - player->bounds.width;
    float maxY = (float)GetScreenHeight() - player->bounds.height;

    if (player->bounds.x < minX) player->bounds.x = minX;
    if (player->bounds.x > maxX) player->bounds.x = maxX;
    if (player->bounds.y < 0.0f) player->bounds.y = 0.0f;
    if (player->bounds.y > maxY) player->bounds.y = maxY;

}


void DrawPlayer(Player player) {
    DrawRectangleRec(player.bounds, player.color);
}
