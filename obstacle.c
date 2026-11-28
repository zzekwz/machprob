#include "obstacle.h"

void InitObstacle(Obstacle obs[], const road lanes[])
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        obs[i].currentLane = GetRandomValue(0, LANE_COUNT - 1);

        obs[i].bounds.width = 60.0f;
        obs[i].bounds.height = 70.0f;

        obs[i].bounds.x = lanes[obs[i].currentLane].bounds.x
                        + (lanes[obs[i].currentLane].bounds.width
                        - obs[i].bounds.width) / 2;

        obs[i].bounds.y = -100.0f - (i * 180.0f);

        obs[i].speed = 200.0f;
        obs[i].color = RED;
    }
}

void UpdateObstacle(Obstacle obs[], const road lanes[])
{
    float dt = GetFrameTime();

    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        obs[i].bounds.y += obs[i].speed * dt;

        if (obs[i].bounds.y > GetScreenHeight())
        {
            obs[i].currentLane = GetRandomValue(0, LANE_COUNT - 1);

            obs[i].bounds.x = lanes[obs[i].currentLane].bounds.x
                            + (lanes[obs[i].currentLane].bounds.width
                            - obs[i].bounds.width) / 2;

            obs[i].bounds.y = -100.0f;
        }
    }
}

void DrawObstacle(Obstacle obs[])
{
    for (int i = 0; i < MAX_OBSTACLES; i++)
    {
        DrawRectangleRec(obs[i].bounds, obs[i].color);
    }
}
