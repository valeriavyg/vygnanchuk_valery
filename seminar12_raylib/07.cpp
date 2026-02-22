#include <raylib.h>

int main() 
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Moving Circle");
    
    float circleX = screenWidth / 2;
    float circleY = screenHeight / 2;
    float radius = 50;
    float speed = 300;
    
    Color currentColor = BLUE;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) 
    {
        float dt = GetFrameTime();
        
        if (IsKeyDown(KEY_UP))    circleY -= speed * dt;
        if (IsKeyDown(KEY_DOWN))  circleY += speed * dt;
        if (IsKeyDown(KEY_LEFT))  circleX -= speed * dt;
        if (IsKeyDown(KEY_RIGHT)) circleX += speed * dt;

        if (IsKeyPressed(KEY_SPACE)) {
            currentColor = {
                (unsigned char)GetRandomValue(0, 255),
                (unsigned char)GetRandomValue(0, 255),
                (unsigned char)GetRandomValue(0, 255),
                255
            };
        }
        
        if (circleX < radius) circleX = radius;
        if (circleX > screenWidth - radius) circleX = screenWidth - radius;
        if (circleY < radius) circleY = radius;
        if (circleY > screenHeight - radius) circleY = screenHeight - radius;
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawCircleV({circleX, circleY}, radius, currentColor);        
        EndDrawing();
    }
    
    CloseWindow();
}