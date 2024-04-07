class polygon {

private:

    int pointNum;
    line* l;
    point* points;
    point normalVec;


    
    
    public:
    

    polygon(int pointNum, point* points);

    void updateNormal();

    int getNum();
    
    void setPoint(int n, point p);
    
    void rotate(point p, double thetaX, double thetaY, double thetaZ);
    
    void move(int x, int y, int z);


    line getLine(int n);

    point getPoint(int n);


    point getNormal();
};