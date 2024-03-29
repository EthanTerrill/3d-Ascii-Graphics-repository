class polygon {

private:

    int pointNum;
    line* l;
    point* points;
    point normalVec;


    
    
    public:
    void updateNormal() {


        points[0] = l[0].getA();
        points[1] = l[1].getA();
        points[2] = l[2].getA();
        point t1 = point(0, 0, 0);
        t1.subtr(points[1], points[0]);
        point t2 = point(0, 0, 0); 
        t2.subtr(points[2], points[0]);

        normalVec = t1.cross(t2);

        normalVec.normalize();
    }

    polygon(int pointNum, point* points){
        
        this->pointNum = pointNum;
        
        this->points = points;
        
        l = (line*)std::malloc(sizeof(line) * pointNum);
        
        for(int  i = 0; i < pointNum - 1; i++){
            l[i] = line(points[i], points[ i + 1]);
        }
        
        l[pointNum - 1] =  line(points[pointNum - 1], points[0]);
        
        
        updateNormal(); 
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
            points[i].rotate(p, thetaX, thetaY, thetaZ);
        }
        
        
       for(int i = 0; i < pointNum; i++){
            l[i].rotate(p, thetaX, thetaY, thetaZ);
        }
      
      // updateNormal();
    }
    
    void move(int x, int y, int z){ 
       // updateNormal();
       for(int i = 0; i < pointNum; i++){
            l[i].move(x, y, z);
        }
    }

    point getNormal() {

        

        updateNormal();

        return normalVec;
    
    }
};