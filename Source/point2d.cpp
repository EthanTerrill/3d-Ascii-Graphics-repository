point2d::point2d() {

    x = 0;
    y = 0;

    type = '_';
    canDraw = true;
};

point2d::point2d(int x, int y) {

    this->x = x;
    this->y = y;

    type = '_';
    canDraw = true;

};

point2d::point2d(point p, camera camera, int bufferWidth, int bufferHeight) {


    point pT = p - camera.getPoint();

    pT.rotate(camera.getPoint(), camera.getThetaX(), camera.getThetaY(), camera.getThetaZ());


    float z = pT.getZ();



    if (z > 0) {



        //create ratio value

        float ratio = 1;// float(bufferWidth) / float(bufferHeight);

        x = pT.getX() * ratio / z;
        y = pT.getY() / z;


        x += 1.0;
        y += 1.0;


        x *= 0.5 * bufferWidth;
        y *= 0.5 * bufferHeight * ys;


        if (y >= 0 && x >= 0 && y < bufferHeight && x < bufferWidth) {

            canDraw = true;


        }
        else {

            canDraw = false;
            x = 0;
            y = 0;
        }

    }
    else {

        canDraw = false;
        x = 0;
        y = 0;
    }

};

bool point2d::drawable() {

    return canDraw;
}

void point2d::setX(double x) {

    this->x = x;


}

void point2d::setY(double y) {

    this->y = y;

}


void point2d::setType(char newType) {

    this->type = newType;
}

double point2d::getX() {

    return x;


}

double point2d::getY() {

    return y;

}


char point2d::getType() {

    return type;
}

void point2d::move(int x, int y, int z) {

    this->x += x;
    this->y += y;

}


double point2d::getDistanceFrom(point other) {

    double nx = x - other.getX();
    double ny = y - other.getY();

    return sqrt(nx * nx + ny * ny);




}

float point2d::getMagnitude() {


    return sqrt(x * x + y * y);

}

void point2d::normalize() {


    float mag = getMagnitude();

    if (mag != 0) {

        x /= mag;
        y /= mag;


    }


}

void point2d::subtr(point2d a, point2d b) {

    point ret;

    this->x = a.getX() - b.getX();
    this->y = a.getY() - b.getY();

}

point2d& point2d::operator=(point other) {

    this->x = other.getX();
    this->y = other.getY();

    return *this;

}

point2d& point2d::operator+(point2d other) {

    point2d ret(this->x + other.getX(), this->y + other.getY());

    return ret;

}

point2d point2d::operator-(point2d other) {

    point2d ret = point2d(this->x - other.getX(), this->y - other.getY());

    return ret;

}

float point2d::operator*(point other) {

    float ret = this->x * other.getX() + this->y * other.getY();

    return ret;

}

float point2d::cross(point other) {

    float ret = this->x * other.getY() - this->y * other.getX();


    return ret;
}
