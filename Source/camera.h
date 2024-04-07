#pragma once
class camera{
    private:
    point p;
    float thetaX;
    float thetaY;
    float thetaZ;
    
    double fov;
    public:
    
    camera();
    
    camera(point p);
    
    camera(point p, int fov);

    void move(point p);
    
    void rotate(float thetaX, float thetaY, float thetaZ);

    void setFov(int fov);
    
    void moveX(double dx);
    
    void moveY(double dy);
    
    void moveZ(double dz);
    
    double getX();
    
    double getY();
    
    double getZ();

    double getThetaX();

    double getThetaY();

    double getThetaZ();

    double getFOV();

    point getPoint();
};