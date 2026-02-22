#include <raylib.h>

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Moving Circle");

    float circleX = 500;
    const float circleY = 500;
    const float radius = 100;
    const float speed = 300;

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();

        circleX += speed * dt;

        if (circleX - radius > screenWidth) 
        {
            circleX = -radius;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle((int)circleX, (int)circleY, radius, BLACK);
        EndDrawing();
    }

    CloseWindow();
}