#pragma once
camera::camera() {


    this->p = *new point(0, 0, 0);

    thetaX = 0;
    thetaY = 0;
    thetaZ = 0;

    fov = 90;

}

camera::camera(point p) {

    this->p = p;

    thetaX = 0;
    thetaY = 0;
    thetaZ = 0;

    fov = 90;


}

camera::camera(point p, int fov) {

    this->p = p;


    thetaX = 0;
    thetaY = 0;
    thetaZ = 0;

    fov = 90;
}

void camera::rotate(float dthetaX, float dthetaY, float dthetaZ) {

    
    this->thetaX += dthetaX;
    this->thetaY += dthetaY;
    this->thetaZ += dthetaZ;

}
void camera::setFov(int fov) {

    this->fov = fov;

}


void camera::move(point p) {

    this->p.setX(this->p.getX() + p.getX());
    this->p.setY(this->p.getY() + p.getY());
    this->p.setZ(this->p.getZ() + p.getZ());
    
};
void camera::moveX(double dx) {

    p.setX(p.getX() + dx);

}

void camera::moveY(double dy) {

    p.setY(p.getY() + dy);

}

void camera::moveZ(double dz) {

    p.setZ(p.getZ() + dz);

}

double camera::getX() {

    return p.getX();
}

double camera::getY() {

    return p.getY();
}

double camera::getZ() {

    return p.getZ();
}

double camera::getThetaX() {

    return thetaX;
}

double camera::getThetaY() {

    return thetaY;
}

double camera::getThetaZ() {

    //exit(0);
    return thetaZ;
}


double camera::getFOV() {

    return fov;
}

point camera::getPoint() {

    return p;
}