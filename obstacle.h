#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "lane.h"
#include "player.h"

typedef struct {
    int currentLane;
    Rectangle bounds;
    float speed;
    Color color;
} Obstacle;

void InitObstacle(Obstacle *obs, road lane[], float startY);
void UpdateObstacle(Obstacle *obs, const road lanes[]);
void DrawObstacle(Obstacle obs);

#endif

