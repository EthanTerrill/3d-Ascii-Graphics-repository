class camera{
    private:
    point p;
    float thetaX;
    float thetaY;
    float thetaZ;
    
    double fov;
    public:
    
    camera(){
        
        
        this->p = *new point(0, 0, 0);
        
        thetaX = 0;
        thetaY = 0;
        thetaZ = 0;
        
        fov = 90;
        
    }
    
    camera(point p){
        
        this->p = p;
        
        thetaX = 0;
        thetaY = 0;
        thetaZ = 0;
        
        fov = 90;
        
        
    }
    
    camera(point p, int fov){
        
        this->p = p;
        
        
        thetaX = 0;
        thetaY = 0;
        thetaZ = 0;
        
        fov = 90;
    }
    
    
    void setFov(int fov){
        
        this->fov = fov;
        
    }
    
    void moveX(double dx){
        
        p.setX(p.getX() + dx);
        
    }
    
    void moveY(double dy){
        
        p.setY(p.getY() + dy);
        
    }
    
    void moveZ(double dz){
        
        p.setZ(p.getZ() + dz);
        
    }
    
    double getX(){
        
        return p.getX();
    }
    
    double getY(){
        
        return p.getY();
    }
    
    double getZ(){
        
        return p.getZ();
    }
    double getFOV(){
        
        return fov;
    }
};