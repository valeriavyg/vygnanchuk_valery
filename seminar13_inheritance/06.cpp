#include "raylib.h"
#include <iostream>
#include <algorithm>

class Slider
{
protected:
    Rectangle mTrackRect{};
    Rectangle mThumbRect{};

    bool mIsPressed{false};

public:
    Slider(Vector2 centerPosition, Vector2 trackSize, Vector2 thumbSize)
    {
        mTrackRect.width = trackSize.x;
        mTrackRect.height = trackSize.y;
        mTrackRect.x = centerPosition.x - trackSize.x / 2.0f;
        mTrackRect.y = centerPosition.y - trackSize.y / 2.0f;

        mThumbRect.width = thumbSize.x;
        mThumbRect.height = thumbSize.y;
        mThumbRect.x = centerPosition.x - thumbSize.x / 2.0f;
        mThumbRect.y = centerPosition.y - thumbSize.y / 2.0f;
    }

    void draw()
    {
        DrawRectangleRec(mTrackRect, {200, 200, 220, 255});
        DrawRectangleRec(mThumbRect, {150, 150, 240, 255});
    }

    void setRestrictedThumbPosition(Vector2 position)
    {
        float min = mTrackRect.x;
        float max = mTrackRect.x + mTrackRect.width;
        float clampedX = std::clamp(position.x, min, max);
        mThumbRect.x = clampedX - mThumbRect.width / 2.0f;
    }

    bool handleEvent()
    {
        Vector2 mousePosition = GetMousePosition();
        bool result = false;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mousePosition, mThumbRect) ||
                CheckCollisionPointRec(mousePosition, mTrackRect))
            {
                mIsPressed = true;
                setRestrictedThumbPosition(mousePosition);
                result = true;
            }
        }

        if (mIsPressed && (GetMouseDelta().x != 0 || GetMouseDelta().y != 0))
        {
            setRestrictedThumbPosition(mousePosition);
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            mIsPressed = false;
        }

        return result;
    }

    bool isPressed() const
    {
        return mIsPressed;
    }

    float getValue() const
    {
        float start = mTrackRect.x;
        float finish = mTrackRect.x + mTrackRect.width;
        float position = mThumbRect.x + mThumbRect.width / 2.0f;
        return 100.0f * (position - start) / (finish - start);
    }
};

int main()
{

    const int screenWidth = 1000;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Три слайдера");
    SetTargetFPS(60);

    Slider rSlider({300, 150}, {500, 20}, {25, 50});
    Slider gSlider({300, 300}, {500, 20}, {25, 50});
    Slider bSlider({300, 450}, {500, 20}, {25, 50});

    float rValue = 0.0f;
    float gValue = 0.0f;
    float bValue = 0.0f;

    Vector2 circleCenter = {800, 300};
    float circleRadius = 100.0f;

    while (!WindowShouldClose())
    {
        rSlider.handleEvent();
        gSlider.handleEvent();
        bSlider.handleEvent();

     
        rValue = rSlider.getValue() * 2.55f;    
        gValue = gSlider.getValue() * 2.55f;
        bValue = bSlider.getValue() * 2.55f;

        if (rSlider.isPressed())
        {
            std::cout << "Red: " << rValue << std::endl;
        }
        if (gSlider.isPressed())
        {
            std::cout << "Green: " << gValue << std::endl;
        }
        if (bSlider.isPressed())
        {
            std::cout << "Blue: " << bValue << std::endl;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(circleCenter, circleRadius, Color{(unsigned char)rValue, (unsigned char)gValue, (unsigned char)bValue, 255});
        rSlider.draw();
        gSlider.draw();
        bSlider.draw();

        EndDrawing();
    }

    CloseWindow();
}