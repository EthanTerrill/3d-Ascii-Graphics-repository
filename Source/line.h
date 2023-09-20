class line{
    
    private:
    point A;
    point B;
    double slope;
    bool vert;
    public:
    line(point A, point B){
        
        this->A = A;
        this->B = B;
        
        vert = (A.getX() == B.getX());
        
        if (!vert) {
            slope = (double(A.getY() - B.getY()) / double(A.getX() - B.getX()));
        }
        
        slope = slope * (!vert);
        
    }
    
    line(int x1, int y1, int x2, int y2){
        
        
    }
    
    void setA(point A){
        
        this->A = A;
        
        vert = (A.getX() == B.getX());
        
        slope = ( double(A.getY() - B.getY())/double(A.getX() - B.getX()) );
        
        slope = slope * (!vert);
    }
    
    void setB(point B){
        
        this->B = B;
        
        vert = (A.getX() == B.getX());
        
        slope = ( double(A.getY() - B.getY())/double(A.getX() - B.getX()) );
        
        slope = slope * (!vert);
        
    }
    
    point getA(){
        
        return A;
    }
    
    point getB(){
        
        return B;
    }
    
    int getLength(){
        
        int a = (A.getX() - B.getX());
        int b = (A.getY() - B.getY());
        
        int c = sqrt(a * a  + b * b);
        
        return c;
    }
    double getSlope(){
        
        return slope;
    }
    
    bool isVertical(){
        
        return vert;
    }
    void move(int x, int y, int z){
        
        A.move(x, y, z);
        B.move(x, y, z);
        
    }
    void rotate(point p, double tx, double ty, double tz){
        
        A.rotate(p, tx, ty, tz);
        B.rotate(p, tx, ty, tz);
    }
    
};