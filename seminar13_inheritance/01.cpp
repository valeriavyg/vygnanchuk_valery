#include <iostream>
#include <cmath>


struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = {left.x + right.x, left.y + right.y};
    return result;
}

Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = {left.x * right, left.y * right};
    return result;
}

Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = {left * right.x, left * right.y};
    return result;
}

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

float getDistance(Vector2f a, Vector2f b)
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

std::ostream& operator<<(std::ostream& out, Vector2f right)
{
    out << "(" << right.x << ", " << right.y << ")";
    return out;
}

class Shape
{
private:  
    Vector2f mPosition;

public:
    Shape() : mPosition({0, 0}) {}
    
    Vector2f getPosition() const 
    {
        return mPosition;
    }
    
    void setPosition(Vector2f newPosition)
    {
        mPosition = newPosition;
    }
    
    void move(Vector2f change)
    {
        mPosition += change;
    }
};

class Circle : public Shape 
{
private:
    float mRadius;

public:
    Circle(float radius) : mRadius(radius) {}

    float calculatePerimeter() const  
    {
        return 2 * 3.14 * mRadius;
    }
};

class Rectangle : public Shape 
{
private:
    float mWidth;
    float mHeight;

public:
    Rectangle(float width, float height) : mWidth(width), mHeight(height) {}

    float calculatePerimeter() const
    {
        return 2 * (mWidth + mHeight);
    }
};

class Triangle : public Shape 
{
private:
    Vector2f mPointA;
    Vector2f mPointB;
    Vector2f mPointC;

public:
    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC) : mPointA(pointA), mPointB(pointB), mPointC(pointC) {}

    float calculatePerimeter() const
    {
        return getDistance(mPointA, mPointB) + getDistance(mPointB, mPointC) + getDistance(mPointC, mPointA);
    }
};

int main()
{
    Circle c1(5);
    c1.setPosition({10, 20});
    std::cout << "circle at " << c1.getPosition() << std::endl;
    c1.move({1, 1});
    std::cout << "circle moved to " << c1.getPosition() << std::endl;
    std::cout << "perimeter " << c1.calculatePerimeter() << std::endl;
    std::cout << std::endl;
    
    Rectangle r1(30, 40);
    r1.setPosition({-5, -5});
    std::cout << "rectangle at " << r1.getPosition() << std::endl;
    r1.move({2, -2});
    std::cout << "rectangle moved to " << r1.getPosition() << std::endl;
    std::cout << "perimeter " << r1.calculatePerimeter() << std::endl;
    std::cout << std::endl;
    
    Triangle t1({0,0}, {3,0}, {0,4});
    t1.setPosition({100, 100});
    std::cout << "triangle at " << t1.getPosition() << std::endl;
    t1.move({-50, 25});
    std::cout << "triangle moved to " << t1.getPosition() << std::endl;
    std::cout << "perimeter " << t1.calculatePerimeter() << std::endl;
}