#include <raylib.h>

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Task 6: Mouse Collision");
    

    Rectangle rect = {300, 400, 400, 200}; 
    Color base_color = GREEN;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) 
    {
        Vector2 mousePos = GetMousePosition();
        
        bool collision = CheckCollisionPointRec(mousePos, rect);
        if (CheckCollisionPointRec(mousePos, rect)) 
        {
            base_color = RED;
        }
        else 
        {
            base_color = GREEN;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(rect, base_color);       
        EndDrawing();
    }
    
    CloseWindow();
}