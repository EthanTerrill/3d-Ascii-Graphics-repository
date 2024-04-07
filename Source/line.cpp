
line::line(point A, point B) {

    this->A = A;
    this->B = B;

    vert = (A.getX() == B.getX());

    if (!vert) {
        slope = (double(A.getY() - B.getY()) / double(A.getX() - B.getX()));
    }

    slope = slope * (!vert);

}

line::line(int x1, int y1, int x2, int y2) {


}

void line::setA(point A) {

    this->A = A;

    vert = (A.getX() == B.getX());

    slope = (double(A.getY() - B.getY()) / double(A.getX() - B.getX()));

    slope = slope * (!vert);
}

void line::setB(point B) {

    this->B = B;

    vert = (A.getX() == B.getX());

    slope = (double(A.getY() - B.getY()) / double(A.getX() - B.getX()));

    slope = slope * (!vert);

}

point line::getA() {

    return A;
}

point line::getB() {

    return B;
}

int line::getLength() {

    int a = (A.getX() - B.getX());
    int b = (A.getY() - B.getY());

    int c = sqrt(a * a + b * b);

    return c;
}
double line::getSlope() {

    return slope;
}

bool line::isVertical() {

    return vert;
}
void line::move(int x, int y, int z) {

    A.move(x, y, z);
    B.move(x, y, z);

}
void line::rotate(point p, double tx, double ty, double tz) {

    A.rotate(p, tx, ty, tz);
    B.rotate(p, tx, ty, tz);
}