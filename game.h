#ifndef GAME_H
#define GAME_H

#include "lane.h"
#include "player.h"
#include "obstacle.h"

void InitGame(road lanes[], Player *player, Obstacle *obs);
void UpdateGame(road lanes[], Player *player, Obstacle *obs);
void DrawGame(road lanes[], Player player, Obstacle obs);
int CheckGameOver(Player player, Obstacle obs);

#endif

