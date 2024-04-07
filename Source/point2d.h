#pragma once

const double ys = 2;

class point2d {
private:
    char type;
    double x;
    double y;
    bool canDraw;

public:
    point2d();

    point2d(int x, int y);

    point2d(point p, camera camera, int bufferWidth, int bufferHeight);

    bool drawable();

    void setX(double x);

    void setY(double y);

    void setType(char newType);

    double getX();

    double getY();

    char getType();

    void move(int x, int y, int z);

    double getDistanceFrom(point other);

    float getMagnitude();

    void normalize();

    void subtr(point2d a, point2d b);

    point2d& operator=(point other);

    point2d& operator+(point2d other);

    point2d operator-(point2d other);

    float operator*(point other);

    float cross(point other);
};


bool sortByHeight(point2d a, point2d b)
{
    return (a.getY()) > (b.getY());
}

bool sortByX(point2d a, point2d b)
{
    return (a.getX()) > (b.getX());
}