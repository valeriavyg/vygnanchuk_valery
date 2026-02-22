#include <raylib.h>
#include <string>

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Mouse Coordinates");
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) 
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        
        std::string text = "Mouse: (" + std::to_string(mouseX) + ", " + std::to_string(mouseY) + ")";
        
    
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText(text.c_str(), 10, 10, 50, BLACK);

        EndDrawing();
    }
    CloseWindow();
}