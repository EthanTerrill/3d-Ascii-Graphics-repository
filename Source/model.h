class model{
    
    private:
    
    std::vector<polygon> triangles;
    std::vector<point>      points;
    
    
    public:
    
    
    model(std::string fileName);

    model(std::string fileName, float scaleFactor);
    
    void rotate(point p, double thetaX, double thetaY, double thetaZ);
    
    void move(int x, int y, int z);

    void move(point p);
    
    int getFaceNum();

    polygon getFace(int n);

    
};