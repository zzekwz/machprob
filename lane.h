#ifndef LANE_H
#define LANE_H

#include "raylib.h"

#define LANE_COUNT 4

typedef struct {
Rectangle bounds;
} road;

void InitLane(road lanes[]);
void DrawLane(road lanes[]);

#endif

