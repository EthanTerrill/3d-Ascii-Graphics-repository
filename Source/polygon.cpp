void polygon::updateNormal() {


    point t1 = points[1] - points[0];

    point t2 = points[2] - points[0];

    normalVec = t1.cross(t2);

    normalVec.normalize();

}

polygon::polygon(int pointNum, point* points) {

    this->pointNum = pointNum;

    this->points = new point[pointNum];
    for (int i = 0; i < pointNum; i++) {
        this->points[i] = points[i];
    }


    l = (line*)std::malloc(sizeof(line) * pointNum);
    tPoints = new point[pointNum];
    for (int i = 0; i < pointNum - 1; i++) {
        l[i] = line(points[i], points[i + 1]);
    }

    l[pointNum - 1] = line(points[pointNum - 1], points[0]);


    updateNormal();

    //shapeColor = color(rand() % 255, rand() % 255, rand() % 255);
    //edgeColor  = color(rand() % 255, rand() % 255, rand() % 255);


    shapeColor = color(255, 255, 255);
    edgeColor = color(0, 0,0);
}


void polygon::updateTpoints(camera C) {

    for (int i = 0; i < pointNum; i++) {


        tPoints[i] = points[i] - C.getPoint();

        tPoints[i].rotate(origin, C.getThetaX(), C.getThetaY(), C.getThetaZ());;

    }
};


line polygon::getLine(int n) {

    //return l[n];
    if (n < 2) {

        return line(points[n], points[n + 1]);
    
    }
    else {
        return line(points[2], points[0]);
    }

}
point polygon::getPoint(int n) {

    return points[n - 1];
}
point polygon::getTPoint(int n) {

    return tPoints[n];
}


int polygon::getNum() {

    return pointNum;
}

void polygon::setPoint(int n, point p) {

    points[n] = p;
    /*
    for (int i = 0; i < pointNum - 1; i++) {
        l[i] = line(points[i], points[i + 1]);
    }

    l[pointNum - 1] = line(points[pointNum - 1], points[0]);
    */
}

void polygon::rotate(point p, double thetaX, double thetaY, double thetaZ) {

    for (int i = 0; i < pointNum; i++) {
        points[i].rotate(p, thetaX, thetaY, thetaZ);
    }


    for (int i = 0; i < pointNum; i++) {
      //  l[i].rotate(p, thetaX, thetaY, thetaZ);
    }

}

void polygon::move(int x, int y, int z) {




    for (int i = 0; i < pointNum; i++) {
        points[i].move(x, y, z);
    }
}

point polygon::getNormal() {



    updateNormal();

    return normalVec;

}




color polygon::getColor() {

    return shapeColor;
}
color polygon::getEdgeColor() {

    return edgeColor;
}