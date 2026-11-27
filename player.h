#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "lane.h"

typedef struct {
    Rectangle bounds;
    float speed;
    Color color;
} Player;

void InitPlayer(Player *player, float startX, float startY);
void UpdatePlayer(Player *player, const lane lanes[]);
void DrawPlayer(Player player);

#endif

