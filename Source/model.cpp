
model::model(std::string fileName) {

    std::ifstream f;
    f.open(fileName);
    


    char c = 0;
    point* myPoints = (point*)std::malloc(sizeof(point) * 3);
    //f >> c;
    int line = 0;
    while (!f.eof()) {

        f >> c;

        if (c == 'v') {

            double bufferval[3]{ 0, 0, 0 };
            for (int i = 0; i < 3; i++) {

                float myfloat;
                f >> myfloat;

                bufferval[i] = myfloat;

            }
            line++;
            points.push_back(point(bufferval[0], bufferval[1], bufferval[2]));
        }
        else if (c == 'f') {



            for (int i = 0; i < 3; i++) {
                int myInt;
                f >> myInt;

                if (points.size() > myInt - 1) {
                    myPoints[i] = point();

                    myPoints[i].setX(points[myInt - 1].getX());

                    myPoints[i].setY(points[myInt - 1].getY());

                    myPoints[i].setZ(points[myInt - 1].getZ());
                }

            }

            triangles.push_back(polygon(3, myPoints));
            line++;

        }
        else if (c == '#') {



            while (c != '\n') {
                f >> c;
            }
            line++;
        }
        else if (f.eof()) {
            exit;
        }
        else {
            std::cout << "\nERROR\n charcter: (val)" << (int)c << " (Disp)" << c << " not understood at line " << line << "\n";
            while (1) {}
        }

    }

    this->c = color(0, 0, 0);

}

model::model(std::string fileName, float scaleFactor) {

    std::ifstream f;
    f.open(fileName);

    char c = 0;
    point* myPoints = (point*)std::malloc(sizeof(point) * 3);
    //f >> c;
    int line = 0;
    while (!f.eof()) {

        f >> c;

        if (c == 'v') {

            double bufferval[3]{ 0, 0, 0 };
            for (int i = 0; i < 3; i++) {

                float myfloat;
                f >> myfloat;

                bufferval[i] = myfloat * scaleFactor;

            }
            line++;
            points.push_back(point(bufferval[0], bufferval[1], bufferval[2]));
        }
        else if (c == 'f') {



            for (int i = 0; i < 3; i++) {
                int myInt;
                f >> myInt;

                if (points.size() > myInt - 1) {
                    myPoints[i] = point();

                    myPoints[i].setX(points[myInt - 1].getX());

                    myPoints[i].setY(points[myInt - 1].getY());

                    myPoints[i].setZ(points[myInt - 1].getZ());
                }

            }

            triangles.push_back(polygon(3, myPoints));
            line++;

        }
        else if (c == '#') {



            while (c != '\n') {
                f >> c;
            }
            line++;
        }
        else if (f.eof()) {
            exit;
        }
        else {
            std::cout << "\nERROR\n charcter: (val)" << (int)c << " (Disp)" << c << " not understood at line " << line << "\n";
            while (1) {}
        }

    }

    this->c = color(0, 0, 0);

}

int model::getFaceNum() {


    return triangles.size();

}


polygon model::getFace(int n) {

    return triangles[n];

}

void model::rotate(point p, double thetaX, double thetaY, double thetaZ) {

    for (int i = 0; i < triangles.size(); i++) {

        triangles[i].rotate(p, thetaX, thetaY, thetaZ);

    }
}

void model::move(int x, int y, int z) {

    for (int i = 0; i < triangles.size(); i++) {

        triangles[i].move(x, y, z);

    }

}

void model::move(point p) {

    for (int i = 0; i < triangles.size(); i++) {

        triangles[i].move(p.getX(), p.getY(), p.getZ());

    }

}
