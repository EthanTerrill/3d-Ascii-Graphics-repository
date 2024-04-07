class point{
    private:
    char type;
    double x;
    double y;
    double z;
    
    
    
    public:
    
    
    point(){
        
        x = 0;
        y = 0;
        z = 0;
        
        type = '_';
        
    };
    
    point(int x, int y, int z){
        
        this->x = x;
        this->y = y;
        this->z = z;
        
        type = '_';
        
    };
    
    //setter functions
    
    void setX(double x){
        
        this->x = x;
        
        
    }
    
    void setY(double y){
        
        this->y = y;
        
    }
    
    void setZ(double z){
        
        this->z = z;
        
    }
    
    void setType(char newType){
        
        this->type = newType;
    }
    //getter functions
    
    double getX(){
        
        return x;
        
        
    }
    
    double getY(){
        
        return y;
        
    }
    
    double getZ(){
        
        return z;
        
    }
    
    char getType(){
        
        return type;
    }
    
    void move(int x, int y, int z){
        
        this->x += x;
        this->y += y;
        this->z += z;
        
    }
    
    
    double getDistanceFrom(point other){
        
        double nx = x - other.getX();
        double ny = y - other.getY();
         
        return sqrt(nx * nx + ny * ny);
        
        
        
        
    }
    
    void rotate(point p, double thetaX, double thetaY, double thetaZ){
        
        rotate_x(p, thetaX);
        rotate_y(p, thetaY);
        rotate_z(p, thetaZ);
        
    }
    
    void rotate_z(point p, double theta){
        
        theta = theta * 3.141592/180;
        
        double Tx = x - p.getX();
        double Tz = z - p.getZ(); 
        
        double dx = Tx * cos(theta) - Tz * sin(theta);
        double dz = Tz * cos(theta) + Tx * sin(theta);
        
        this->x = dx + p.getX();
        this->z = dz + p.getZ();
    }
    
    void rotate_y(point p, double theta){
        
        theta = theta * 3.141592/180;
        
        double Tx = x - p.getX(); 
        double Ty = y - p.getY();
        
        double dx = Tx * cos(theta) - Ty * sin(theta);
        double dy = Ty * cos(theta) + Tx * sin(theta);
        
        this->x = dx + p.getX();
        this->y = dy + p.getY();
    }
    void rotate_x(point p, double theta){
        
        theta = theta * 3.141592/180;
        
        double Tz = z - p.getZ(); 
        double Ty = y - p.getY();
        
        double dz = Tz * cos(theta) - Ty * sin(theta);
        double dy = Ty * cos(theta) + Tz * sin(theta);
        
        this->z = dz + p.getZ();
        this->y = dy + p.getY();
    }


    float getMagnitude() {
    
    
        return sqrt(x * x + y * y + z*z);
    
    }
    void normalize() {


        float mag = getMagnitude();

        if (mag != 0) {

            x /= mag;
            y /= mag;
            z /= mag;


        }


    }
    void subtr(point a, point b) {

        point ret;

        this->x = a.getX() - b.getX();
        this->y = a.getY() - b.getY();
        this->z = a.getZ() - b.getZ();

    
    }

    //function overloads


    point& operator=(point other) {
        
        this->x = other.getX();
        this->y = other.getY();
        this->z = other.getZ();

        return *this;
    
    }

    point& operator+(point other) {

        point ret(this->x + other.getX(), this->y + other.getY(), this->z + other.getZ());

        return ret;

    }

    point operator-(point other) {

        point ret = point(this->x - other.getX(), this->y - other.getY(), this->z - other.getZ());

        return ret;

    }

    point operator*(float f) {

        point ret = point(this->x *f, this->y * f, this->z * f);

        return ret;

    }

    float operator*(point other) {

        float ret = this->x * other.getX() + this->y * other.getY() + this->z * other.getZ();

        return ret;

    }

    point cross(point other) {
        
        point ret;

        float a, b, c;

        a = this->y * other.getZ() - this->z * other.getY();
        b = this->z * other.getX() - this->x * other.getZ();
        c = this->x * other.getY() - this->y * other.getX();
    
        ret = point(a, b, c);

        return ret;
    }
     


};

