#include "raylib.h"
#include "lane.h"

const int roadwidth = (800 / 5) * 4;
const int lanewidth = roadwidth / 6;

void InitLane(road lanes[])
{
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    for (int i = 0; i < LANE_COUNT; i++) {
        lanes[i].bounds.x = 0 + (i*lanewidth);
        lanes[i].bounds.y = 0;
        lanes[i].bounds.width = lanewidth - 5;
        lanes[i].bounds.height = width;
    }
}

void DrawLane(road lanes[])
{
    for (int i = 0; i < LANE_COUNT; i++) {
        DrawRectangleRec(lanes[i].bounds, DARKGRAY);
    }
}
