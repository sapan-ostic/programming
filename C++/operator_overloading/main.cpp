#include<iostream>

struct Vector2
{
    /* data */
    float x, y;

    Vector2(float x, float y):
        x(x), y(y){}

    Vector2 Add(const Vector2& other) const {
        return Vector2(x+other.x, y+other.y);
    }

    Vector2 Multiply(const Vector2& other) const {
        return Vector2(x*other.x, y*other.y);
    }
};

int main()