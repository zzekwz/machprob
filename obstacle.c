#include "obstacle.h"

void InitObstacle(Obstacle *obs, road lanes[], float startY)
{
    obs->currentLane = GetRandomValue(0, LANE_COUNT - 1);

    obs->bounds.width = 60.0f;
    obs->bounds.height = 70.0f;

    obs->bounds.x = lanes[obs->currentLane].bounds.x + (lanes[obs->currentLane].bounds.width - obs->bounds.width) / 2;
    obs->bounds.y = startY;

    obs->speed = 200.0f;
    obs->color = RED;
}

  void UpdateObstacle(Obstacle *obs, const road lanes[])
{
    float dt = GetFrameTime();

    obs->bounds.y += obs->speed * dt;

    if (obs->bounds.y > GetScreenHeight())
    {
        obs->currentLane = GetRandomValue(0, LANE_COUNT - 1);

        obs->bounds.x = lanes[obs->currentLane].bounds.x
                      + (lanes[obs->currentLane].bounds.width
                      - obs->bounds.width) / 2;

        obs->bounds.y = -50.0f;
    }
}


void DrawObstacle(Obstacle obs)
{
    DrawRectangleRec(obs.bounds, obs.color);
}

