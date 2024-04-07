void polygon::updateNormal() {


    points[0] = l[0].getA();
    points[1] = l[1].getA();
    points[2] = l[2].getA();
    point t1 = point(0, 0, 0);
    t1.subtr(points[1], points[0]);
    point t2 = point(0, 0, 0);
    t2.subtr(points[2], points[0]);

    normalVec = t1.cross(t2);

    normalVec.normalize();
}

polygon::polygon(int pointNum, point* points) {

    this->pointNum = pointNum;

    this->points = points;

    l = (line*)std::malloc(sizeof(line) * pointNum);

    for (int i = 0; i < pointNum - 1; i++) {
        l[i] = line(points[i], points[i + 1]);
    }

    l[pointNum - 1] = line(points[pointNum - 1], points[0]);


    updateNormal();

    shapeColor = color(0, 0, rand() % 10);
    edgeColor  = color(0, 0, rand() % 10);
}

line polygon::getLine(int n) {

    return l[n];
}
point polygon::getPoint(int n) {

    return points[n];
}



int polygon::getNum() {

    return pointNum;
}

void polygon::setPoint(int n, point p) {

    points[n - 1] = p;

    for (int i = 0; i < pointNum - 1; i++) {
        l[i] = line(points[i], points[i + 1]);
    }

    l[pointNum - 1] = line(points[pointNum - 1], points[0]);

}

void polygon::rotate(point p, double thetaX, double thetaY, double thetaZ) {

    for (int i = 0; i < pointNum; i++) {
        points[i].rotate(p, thetaX, thetaY, thetaZ);
    }


    for (int i = 0; i < pointNum; i++) {
        l[i].rotate(p, thetaX, thetaY, thetaZ);
    }

}

void polygon::move(int x, int y, int z) {


    for (int i = 0; i < pointNum; i++) {
        l[i].move(x, y, z);
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