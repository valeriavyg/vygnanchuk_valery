#include <raylib.h>
#include <cmath>

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Circular Circle");
    
    float centerX = screenWidth / 2;
    float centerY = screenHeight / 2;
    float orbitRadius = 200;  
    

    float circleRadius = 50;
    float angle = 0;  
    float angularSpeed = 2; 
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) 
    {

        float dt = GetFrameTime();
        angle += angularSpeed * dt;
        
        float circleX = centerX + orbitRadius * cosf(angle);
        float circleY = centerY + orbitRadius * sinf(angle);
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawCircleV({centerX, centerY}, 3, BLUE);
        DrawCircleV({circleX, circleY}, circleRadius, BLUE);

        EndDrawing();
    }
    CloseWindow();
}