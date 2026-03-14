#include "raylib.h"
#include <vector>

class Toggle
{
private:
    Rectangle mBounds;      
    bool mIsOn;             
    bool mIsPressed;        
    
public:

    Toggle(Vector2 position, float width, float height)
    {
        mBounds.x = position.x;
        mBounds.y = position.y;
        mBounds.width = width;
        mBounds.height = height;
        
        mIsOn = false;      
        mIsPressed = false;
    }
    
    void handleEvent()
    {
        Vector2 mousePoint = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mousePoint, mBounds))
            {
                mIsPressed = true;
            }
        }
        
        if (mIsPressed && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mousePoint, mBounds))
            {
                mIsOn = !mIsOn; 
            }
            mIsPressed = false;
        }
        
        if (mIsPressed && !CheckCollisionPointRec(mousePoint, mBounds))
        {
            mIsPressed = false;
        }
    }
    
    void draw()
    {
        Color bgColor;
        if (mIsOn)
        {
            bgColor = GREEN;     
        }
        else
        {
            bgColor = GRAY;       
        }
        
        DrawRectangleRec(mBounds, bgColor);
    
        float switchSize = mBounds.height * 0.7f;  
        float margin = (mBounds.height - switchSize) / 2.0f;
        
        float switchX;
        if (mIsOn)
        {
            switchX = mBounds.x + mBounds.width - switchSize - margin;
        }
        else
        {
            switchX = mBounds.x + margin;
        }
        
        float switchY = mBounds.y + margin;
        float centerX = switchX + switchSize / 2.0f;
        float centerY = switchY + switchSize / 2.0f;
        float radius = switchSize / 2.0f;
    
        DrawCircleV({centerX, centerY}, radius, WHITE);
    }

    bool isOn() const
    {
        return mIsOn;
    }
    
    void setState(bool on)
    {
        mIsOn = on;
    }
};

int main()
{
    const int screenWidth = 400;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "10 тумблеров ");
    SetTargetFPS(60);

    std::vector<Toggle> toggles;
    
    float startX = 150;      
    float startY = 50;       
    float toggleWidth = 70;   
    float toggleHeight = 40;  
    float spacing = 15;      
    

    for (int i = 0; i < 10; i++)
    {
        float posY = startY + i * (toggleHeight + spacing);
        toggles.emplace_back(Vector2{startX, posY}, toggleWidth, toggleHeight);
    }

    while (!WindowShouldClose())
    {
        for (auto& toggle : toggles)
        {
            toggle.handleEvent();
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (auto& toggle : toggles)
        {
            toggle.draw();
        }

        EndDrawing();
    }
    CloseWindow();
}