#pragma once
point::point() {

    x = 0;
    y = 0;
    z = 0;

    type = '_';

};

point::point(int x, int y, int z) {

    this->x = x;
    this->y = y;
    this->z = z;

    type = '_';

};

void point::setX(double x) {

    this->x = x;


}

void point::setY(double y) {

    this->y = y;

}

void point::setZ(double z) {

    this->z = z;

}

void point::setType(char newType) {

    this->type = newType;
}

double point::getX() {

    return x;


}

double point::getY() {

    return y;

}

double point::getZ() {

    return z;

}

char point::getType() {

    return type;
}

void point::move(int x, int y, int z) {

    this->x += x;
    this->y += y;
    this->z += z;

}


double point::getDistanceFrom(point other) {

    double nx = x - other.getX();
    double ny = y - other.getY();

    return sqrt(nx * nx + ny * ny);




}

void point::rotate(point p, double thetaX, double thetaY, double thetaZ) {

    rotate_x(p, thetaX);
    rotate_y(p, thetaY);
    rotate_z(p, thetaZ);

}

void point::rotate_z(point p, double theta) {

    theta = theta * 3.141592 / 180;

    double Tx = x - p.getX();
    double Tz = z - p.getZ();

    double dx = Tx * cos(theta) - Tz * sin(theta);
    double dz = Tz * cos(theta) + Tx * sin(theta);

    this->x = dx + p.getX();
    this->z = dz + p.getZ();
}

void point::rotate_y(point p, double theta) {

    theta = theta * 3.141592 / 180;

    double Tx = x - p.getX();
    double Ty = y - p.getY();

    double dx = Tx * cos(theta) - Ty * sin(theta);
    double dy = Ty * cos(theta) + Tx * sin(theta);

    this->x = dx + p.getX();
    this->y = dy + p.getY();
}

void point::rotate_x(point p, double theta) {

    theta = theta * 3.141592 / 180;

    double Tz = z - p.getZ();
    double Ty = y - p.getY();

    double dz = Tz * cos(theta) - Ty * sin(theta);
    double dy = Ty * cos(theta) + Tz * sin(theta);

    this->z = dz + p.getZ();
    this->y = dy + p.getY();
}


float point::getMagnitude() {


    return sqrt(x * x + y * y + z * z);

}

void point::normalize() {


    float mag = getMagnitude();

    if (mag != 0) {

        x /= mag;
        y /= mag;
        z /= mag;


    }


}

void point::subtr(point a, point b) {

    point ret;

    this->x = a.getX() - b.getX();
    this->y = a.getY() - b.getY();
    this->z = a.getZ() - b.getZ();


}



point& point::operator=(point other) {

    this->x = other.getX();
    this->y = other.getY();
    this->z = other.getZ();

    return *this;

}

point& point::operator+(point other) {

    point ret(this->x + other.getX(), this->y + other.getY(), this->z + other.getZ());

    return ret;

}

point point::operator-(point other) {

    point ret = point(this->x - other.getX(), this->y - other.getY(), this->z - other.getZ());

    return ret;

}

point point::operator*(float f) {

    point ret = point(this->x * f, this->y * f, this->z * f);

    return ret;

}

float point::operator*(point other) {

    float ret = this->x * other.getX() + this->y * other.getY() + this->z * other.getZ();

    return ret;

}

point point::cross(point other) {

    point ret;

    float a, b, c;

    a = this->y * other.getZ() - this->z * other.getY();
    b = this->z * other.getX() - this->x * other.getZ();
    c = this->x * other.getY() - this->y * other.getX();

    ret = point(a, b, c);

    return ret;
}
