
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "lane.h"

typedef struct {
    int currentLane;
    Rectangle bounds;
    float speed;
    Color color;
} Player;

void InitPlayer(Player *player, const road lane[], float startY);
void UpdatePlayer(Player *player, const road lane[]);
void DrawPlayer(Player player);

#endif
