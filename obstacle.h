#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "lane.h"

#define MAX_OBSTACLES 5

typedef struct {
    int currentLane;
    Rectangle bounds;
    float speed;
    Color color;
} Obstacle;

void InitObstacle(Obstacle obs[], const road lanes[]);
void UpdateObstacle(Obstacle obs[], const road lanes[]);
void DrawObstacle(Obstacle obs[]);

#endif
