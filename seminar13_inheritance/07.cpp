#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>

class DropList
{
private:
    inline static const Color kDefaultColor {190,210,190,255};
    inline static const Color kHoverColor {150,170,150,255};
    inline static const Color kTextColor {0,0,0,255};
    inline static const Color kBoxColor {220,220,240,255};
    inline static const Color kBorderColor {100,100,150,255};

    inline static const int kCharacterSize = 22;
    inline static const int kTextLeftIndent = 10;
    inline static const int kTextRightIndent = 20;
    inline static const int kTextTopIndent = 4;
    inline static const int kTextBottomIndent = 4;

    std::vector<std::string> mItems;    
    Rectangle mMainBox;   
    Vector2 mPosition;          
    float mWidth = 200;
    float mItemHeight = 0;
    
    bool mIsOpened = false;                
    bool mIsUpdated = false;
    int mHoverPosition = -1;
    int mSelectedItem = 0;                   
    Font mFont;

public:
    DropList(Vector2 position, float width)
    {
        mPosition = position; 
        mWidth = width;
        mFont = GetFontDefault();

        mMainBox.x = position.x;
        mMainBox.y = position.y;
        mMainBox.width = width;
        mMainBox.height = 40; 
    }

    void addItem(const std::string& name)
    {
        mItems.push_back(name);
        mIsUpdated = false;
    }

    int handleInput()
    {
        Vector2 mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse, mMainBox))
            {
                mIsOpened = !mIsOpened; 
            }
        }
        
        if (mIsOpened && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            for (int i = 0; i < mItems.size(); i++)
            {
                Rectangle itemRect = {
                    mPosition.x,
                    mPosition.y + mMainBox.height + i * mItemHeight,
                    mWidth,
                    mItemHeight
                };
                
                if (CheckCollisionPointRec(mouse, itemRect))
                {
                    mSelectedItem = i;        
                    mIsOpened = false;        
                    return i;                 
                }
            }
        }

        if (mIsOpened)
        {
            mHoverPosition = -1;
            for (int i = 0; i < mItems.size(); i++)
            {
                Rectangle itemRect = {
                    mPosition.x,
                    mPosition.y + mMainBox.height + i * mItemHeight,
                    mWidth,
                    mItemHeight
                };
                
                if (CheckCollisionPointRec(mouse, itemRect))
                {
                    mHoverPosition = i;
                    break;
                }
            }
        }
        
        return -1;
    }

    void draw()
    {
        if (!mIsUpdated && !mItems.empty())
        {

            Vector2 textSize = MeasureTextEx(mFont, mItems[0].c_str(), kCharacterSize, 1);
            mItemHeight = textSize.y + kTextTopIndent + kTextBottomIndent;
            mIsUpdated = true;
        }
        
        DrawRectangleRec(mMainBox, kBoxColor);
        DrawRectangleLinesEx(mMainBox, 2, kBorderColor);
        
        float arrowSize = 10;
        float arrowX = mMainBox.x + mMainBox.width - 25;
        float arrowY = mMainBox.y + mMainBox.height / 2;
        
        if (mIsOpened)
        {
            DrawTriangle(
                {arrowX, arrowY - arrowSize/2},
                {arrowX + arrowSize, arrowY - arrowSize/2},
                {arrowX + arrowSize/2, arrowY - arrowSize*1.5f},
                kBorderColor
            );
        }
        else
        {
            DrawTriangle(
                {arrowX, arrowY + arrowSize/2},
                {arrowX + arrowSize, arrowY + arrowSize/2},
                {arrowX + arrowSize/2, arrowY + arrowSize*1.5f},
                kBorderColor
            );
        }
        
        if (!mItems.empty())
        {
            DrawTextEx(mFont, mItems[mSelectedItem].c_str(), 
                      {mPosition.x + kTextLeftIndent, mPosition.y + kTextTopIndent}, 
                      kCharacterSize, 1, kTextColor);
        }
        
        if (mIsOpened && !mItems.empty())
        {
            float listHeight = mItemHeight * mItems.size();
            Rectangle listRect = {
                mPosition.x,
                mPosition.y + mMainBox.height,
                mWidth,
                listHeight
            };
            
            DrawRectangleRec(listRect, kDefaultColor);
            DrawRectangleLinesEx(listRect, 1, kBorderColor);

            for (int i = 0; i < mItems.size(); i++)
            {
                float itemY = mPosition.y + mMainBox.height + i * mItemHeight;

                if (i == mHoverPosition)
                {
                    DrawRectangle(mPosition.x, itemY, mWidth, mItemHeight, kHoverColor);
                }
                if (i > 0)
                {
                    DrawLine(mPosition.x, itemY, mPosition.x + mWidth, itemY, kBorderColor);
                }
                
                DrawTextEx(mFont, mItems[i].c_str(), 
                          {mPosition.x + kTextLeftIndent, itemY + kTextTopIndent}, 
                          kCharacterSize, 1, kTextColor);
            }
        }
    }
    
    int getSelectedItem() const
    {
        return mSelectedItem;
    }
    
    std::string getSelectedText() const
    {
        if (!mItems.empty() && mSelectedItem >= 0 && mSelectedItem < mItems.size())
            return mItems[mSelectedItem];
        return "";
    }
};

int main()
{
    InitWindow(800, 600, "Выпадающий список");
    SetTargetFPS(60);

    DropList dropList({300, 100}, 200);
    
    dropList.addItem("Circle");
    dropList.addItem("Square");
    dropList.addItem("Triangle");

    Vector2 shapeCenter = {400, 400};
    float shapeSize = 80;

    while (!WindowShouldClose())
    {
        int result = dropList.handleInput();
        if (result >= 0) 
        {
            std::cout << "Selected shape: " << dropList.getSelectedText() << std::endl;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        dropList.draw();
        std::string selected = dropList.getSelectedText();
        
        if (selected == "Circle")
        {
            DrawCircleV(shapeCenter, shapeSize, BLUE);
        }
        else if (selected == "Square")
        {
            DrawRectangle(shapeCenter.x - shapeSize/2, shapeCenter.y - shapeSize/2, 
                         shapeSize, shapeSize, GREEN);
        }
        else if (selected == "Triangle")
        {
            Vector2 v1 = {shapeCenter.x, shapeCenter.y - shapeSize};
            Vector2 v2 = {shapeCenter.x - shapeSize * 0.866f, shapeCenter.y + shapeSize * 0.5f};
            Vector2 v3 = {shapeCenter.x + shapeSize * 0.866f, shapeCenter.y + shapeSize * 0.5f};
            
            DrawTriangle(v1, v2, v3, RED);
        }

        EndDrawing();
    }

    CloseWindow();
}
