class point{
    private:
    char type;
    double x;
    double y;
    double z;
    
    
    
    public:
    
    
    point();
    
    point(int x, int y, int z);
    
    //setter functions
    
    void setX(double x);
    
    void setY(double y);
    
    void setZ(double z);
    
    void setType(char newType);

    //getter functions
    
    double getX();
    
    double getY();
    
    double getZ();
    
    char getType();
    
    void move(int x, int y, int z);
    
    double getDistanceFrom(point other);
    
    void rotate(point p, double thetaX, double thetaY, double thetaZ);
    
    void rotate_z(point p, double theta);

    void rotate_y(point p, double theta);
    
    void rotate_x(point p, double theta);


    float getMagnitude();

    void normalize();

    void subtr(point a, point b);

    //function overloads


    point& operator=(point other);

    point& operator+(point other);

    point operator-(point other);

    point operator*(float f);

    float operator*(point other);

    point cross(point other);
     


};

