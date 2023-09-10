class polygon{
    
    private:
    
    int pointNum;
    line* l;
    point* points;
    
    
    public:
    
    polygon(int pointNum, point* points){
        
        this->pointNum = pointNum;
        
        this->points = points;
        
        l = (line*)std::malloc(sizeof(line) * pointNum);
        
        for(int  i = 0; i < pointNum - 1; i++){
            l[i] = line(points[i], points[ i + 1]);
        }
        
        l[pointNum - 1] =  line(points[pointNum - 1], points[0]);
        
        
    }
    
    line getLine(int n){
        
        return l[n];
    }
    point getPoint(int n){
        
        return points[n];
    }
    
    int getNum(){
        
        return pointNum;
    }
    
    void setPoint(int n, point p){
        
        points[n - 1] = p;
        
        for(int  i = 0; i < pointNum - 1; i++){
            l[i] =  line(points[i], points[ i + 1]);
        }
        
        l[pointNum - 1] =  line(points[pointNum - 1], points[0]);
        
    }
    
    void rotate(point p, double thetaX, double thetaY, double thetaZ){
        
        for(int i = 0; i < pointNum; i++){
           // points[i].rotate(p, theta);
        }
        
        
       for(int i = 0; i < pointNum; i++){
            l[i].rotate(p, thetaX, thetaY, thetaZ);
        }
    }
    
    void move(int x, int y, int z){ 
        
       for(int i = 0; i < pointNum; i++){
            l[i].move(x, y, z);
        }
    }
};