class polygon {

private:
    color shapeColor;
    color edgeColor;


    int pointNum;
    line* l;

    point* tPoints;
    point* points;
    point normalVec;





public:


    polygon(int pointNum, point* points);

    void updateNormal();

    int getNum();

    void setPoint(int n, point p);

    void rotate(point p, double thetaX, double thetaY, double thetaZ);

    void move(int x, int y, int z);


    void updateTpoints(camera C);


    line getLine(int n);

    point getPoint(int n);

    point getTPoint(int n);

    point getNormal();
    point getTNormal();


    color getColor();

    color getEdgeColor();

};