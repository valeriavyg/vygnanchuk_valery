#include <raylib.h>
#include <math.h>

int main() 
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Rotating Square - Blue Fill");

    Vector2 point = {500, 500}; 
    float squareSize = 150;
    float angle = 0;
    float rotationSpeed = 90; 

    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();
        angle += rotationSpeed * dt;

        Vector2 localVerts[4] = {
            {0, 0},
            {squareSize, 0},
            {squareSize, squareSize},
            {0, squareSize}
        };

        Vector2 verts[4];
        float rad = angle * DEG2RAD;
        float cosA = cosf(rad);
        float sinA = sinf(rad);

        for (int i = 0; i < 4; i++) {
            verts[i].x = point.x + localVerts[i].x * cosA - localVerts[i].y * sinA;
            verts[i].y = point.y + localVerts[i].x * sinA + localVerts[i].y * cosA;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawLineV(verts[0], verts[1], WHITE);
        DrawLineV(verts[1], verts[2], WHITE);
        DrawLineV(verts[2], verts[3], WHITE);
        DrawLineV(verts[3], verts[0], WHITE);
        DrawCircleV(point, 5, RED); 
        EndDrawing();
    }

    CloseWindow();
}