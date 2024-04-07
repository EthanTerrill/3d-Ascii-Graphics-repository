class line{
    
    private:
    point A;
    point B;
    double slope;
    bool vert;
    public:
    line(point A, point B);
    
    line(int x1, int y1, int x2, int y2);
    
    void setA(point A);
    
    void setB(point B);
    
    point getA();
    
    point getB();
    
    int getLength();
    double getSlope();
    
    bool isVertical();
    void move(int x, int y, int z);
    void rotate(point p, double tx, double ty, double tz);
    
};